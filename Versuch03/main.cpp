/**
 * @file main.cpp
 *
 * Provides functions for the game Reversi
 */

/**
* @mainpage Reversi
*
* Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
*
* @author Can Oezmaden
* @date 2017
*/

#define HUMAN 1
#define COMPUTER 2

#include "test.h"
#include "config.h"
#include "Reversi_KI.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function providing first initialization of a new field
 *
 * This function fills an existing field with zeros and creates the starting pattern.
 *
 * @param field The field which will be initialized
 */
void initialize_field(int field[SIZE_Y][SIZE_X])
{
	for (int j = 0; j < SIZE_Y; j++)
		{
			for(int i = 0; i < SIZE_X; i++)
			{
				field[j][i] = 0;
			}
		}
		field[SIZE_Y / 2 - 1][SIZE_X / 2 - 1] = 1;
		field[SIZE_Y / 2][SIZE_X / 2 - 1] = 2;
		field[SIZE_Y / 2 - 1][SIZE_X / 2] = 2;
		field[SIZE_Y / 2][SIZE_X / 2] = 1;
}



/**
* @brief Prints the playing field to the console.
*
* This function gets the current playing field as parameter (two dimensional array)
* with entries of 0 (field is empty), 1 (field belongs to player 1), 2 (field belongs to player 2).
* <br>The function prints the playing field, grid included, to the console.
* Crosses symbolize player 1 while circles symbolize player 2.
*
*  @param field  The field which is going to be printed
*/
void show_field(const int field[SIZE_Y][SIZE_X])
{
	std::cout << "  ";

//Start at ASCII 65 = A
	for (int j = 65; j < 65 + SIZE_Y; j++)
		std::cout << ((char) j) << " " ;

	std::cout << std::endl;

	for (int j = 0; j < SIZE_Y; j++)
	{
		std::cout << j + 1;
		for (int i = 0; i < SIZE_X; i++)
		{
			switch (field[j][i])
			{
				case 0:
					std::cout << "  " ;
					break;
				case 1:
					std::cout << " X";
					break;
				case 2:
					std::cout << " O";
					break;
				default:
					std::cout << "Inconsistent data in field!" << std::endl;
					std::cout << "Aborting .... " << std::endl;
					exit(0);
					break;
			}
		}
		std::cout << std::endl;
	}
}

/**
* @brief Determines the winner of the game
*
* 	This function goes through the playing field (two dimensional array) and checks the number of
* 	stones belonging to each player in order to determine the winner of the game. The numbers are
* 	then saved into seperate counter variables for player 1 and player 2 which are compared at the end.
* 	After the comparison the function returns 1 if the player 1 wins the game, 2 if the player 2
* 	and 0 in case of a draw.
*
*  @param field  The field to be checked in order to determine the winner
*  @return 1 for Player 1, 2 for Player 2, 0 for the draw case
*
*/
int winner(const int field[SIZE_Y][SIZE_X])
{
	int count_p1 = 0; // Initializing stone counters for each player
	int count_p2 = 0;

	for (int j = 0; j < SIZE_Y; j++)
	{
		for (int i = 0; i < SIZE_X; i++)
		{
			//loop through all fields + counting of X (1) and O (2)
			if (field[i][j] == 1)
			{
				count_p1++;
			}
			else if (field[i][j] == 2)
			{
				count_p2++;
			}
		}
	}
	if (count_p1 == count_p2)
	{
		return 0;
	}
	if (count_p2 > count_p1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
* @brief Checks the coordinates for validilty of a new move
*
* 	This function gets the current state of the playing field together with the information
* 	on which player's turn it is and which coordinates they have selected to put their stone on.
* 	Thereafter, those coordinates are checked if the field is valid for the given turn. This is
* 	implemented in a way that, first of all, the coordinates are checked whether or not they are
* 	occupied and then the neighbouring fields are iteratively gone through and checked for an
* 	opponent stone. In case an opponent stone is found, the whole row/column/diagonal in the
* 	direction of the found opponent stone is gone through, until a stone is found beloning to the
* 	player. IF AND ONLY IF these two conditions are fulfilled the selected coordinates are flagged
* 	as valid and the function returns a positive result.
*
*  @param field  The current state of the game field
*  @param player Player whose turn it is to make a move, 1 for P1, 2 for P2
*  @param pos_x  The X coordinate the player has selected
*  @param pos_y  The Y coordinate the player has selected
*
*  @return FALSE if the turn is not valid, TRUE if the turn is valid
*
*/
bool turn_valid(const int field[SIZE_Y][SIZE_X], const int player,
		const int pos_x, const int pos_y)
{
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
	                           // if player = 2 -> opponent = 1

	if (field[pos_y][pos_x] != 0) //check if field is currently empty
	{
		return false;
	}

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (field[pos_y + j][pos_x + i] != opponent) //Continue the search if field is unnocupied
			{
				continue;
			}

			int curr_pos_y = pos_y;
			int curr_pos_x = pos_x;

			while ((curr_pos_x += i) >= 0 && curr_pos_x < SIZE_X //Making sure to stay in bounds
			&& (curr_pos_y += j) >= 0 && curr_pos_y < SIZE_Y)
			{
				if (field[curr_pos_y][curr_pos_x] == player) //Player's stone found
				{
					return true;
				}
				else if (field[curr_pos_y][curr_pos_x] == 0) //Empty field
				{
					break;
				}
			}
		}
	}
	return false;
}


/**
* @brief Executes players move
*
* 	This function gets the current state of the game field and the information about an execution of a turn.
* 	It behaves similar to the turn_valid function in that it looks for the opponent stones in neighbouring
* 	fields on lines that are terminated by the player's own stones. The loop is then run backwards to replace
* 	all the stones with player's ones. This updated game field could then be  read by any other function to
* 	play the game further.
*
*  @param field  The current state of the game field
*  @param player Player who makes the move, 1 for P1, 2 for P2
*  @param pos_x  The X coordinate the player has selected
*  @param pos_y  The Y coordinate the player has selected
*
*/
void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y)
{
	int opponent = 3 - player; // the same as: if player = 1 -> opponent = 2 else
    						   // if player = 2 -> opponent = 1

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (field[pos_y + j][pos_x + i] != opponent)
			{
				continue;
			}

			int curr_pos_y = pos_y + j; //Saving the current position on the field
			int curr_pos_x = pos_x + i;

			while (curr_pos_x >= 0 && curr_pos_x < SIZE_X //Making sure to stay in bounds
				&& curr_pos_y >= 0 && curr_pos_y < SIZE_Y)
			{
				if (field[curr_pos_y][curr_pos_x] == opponent) //Opponent's stone found
				{
					curr_pos_y += j; //Continue the line search in that direction
					curr_pos_x += i;
					continue;
				}
				else if (field[curr_pos_y][curr_pos_x] == player) //Player's terminating stone found
				{
					while (curr_pos_y != pos_y || curr_pos_x != pos_x) //Go back until coordinates are the original ones
					{
						curr_pos_y -= j;
						curr_pos_x -= i;
						field[curr_pos_y][curr_pos_x] = player; //replacing each stone with players stone
					}
					break;
				}
				else
				{
					// The coordinates are unnoccupied
					break;
				}
			}
		}
	}
}

/**
* @brief Counts the number of possible turns
*
* 	This function gets the current state of the game field and the player whose turn it is to make a move,
* 	then it calculates the total amount of possible moves that player could eventually make given the
* 	positions of the stones in the field.
*
*  @param field  The current state of the game field
*  @param player Player who is going to make the move, 1 for P1, 2 for P2
*
*/
int possible_turns(const int field[SIZE_Y][SIZE_X], const int player)
{
	int possible_turn_number = 0;

	for (int j = 0; j < SIZE_Y; ++j) //iterate over the whole field
	{
		for (int i = 0; i < SIZE_X; ++i)
		{
			if (turn_valid(field, player, i, j) == true) //check each cell for validity of a turn
			{
				possible_turn_number++;
			}
		}
	}
	return possible_turn_number;
}

bool human_turn(int field[SIZE_Y][SIZE_X], const int player)
{
	if (possible_turns(field, player) == 0)
	{
		return false;
	}

	char player_marker;
	int px;
	int py;
	//bool repeat=false;

	if (player == 1)
	{
		player_marker = 'X';
	}
	else
	{
		player_marker = 'O';
	}

	while (true)
	{
		std::string input;
		input.reserve(50);
		std::cout << std::endl << "Your move Mr."<<player_marker<<" (e.g. A1):" ;
		input.erase(input.begin(), input.end());
		std::cin >> input;
		px = ((int) input.at(0) ) - 65;
		py = ((int) input.at(1) ) - 49;

		if (turn_valid(field, player, px, py))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl
					<< "Invalid input: the coordinates you've selected aren't valid for a move\nPlease try again"
					<< std::endl;
		}
	}

	execute_turn(field, player, px, py);

	return true;
}

void game(const int player_type[2])
{


	bool turn_execute;
	int field[SIZE_Y][SIZE_X];


	initialize_field(field);
	show_field(field);


	int current_player = 1;
	int skip = 0; //Skip counter to check if two skips have occurred

	while (1)
	{
		/*
		 * Determining if a computer or a human turn is to be executed
		 */
		if (player_type[current_player - 1] == COMPUTER)
		{
			turn_execute = computer_turn(field, current_player);
		}
		else
		{
			turn_execute = human_turn(field, current_player);
		}

		if (turn_execute == true) // Checking the success of the execution of the turn
		{
			show_field(field);
			skip = 0; //resetting skip counter
		}
		else
		{
			std::cout
					<< "Unfortunately no valid possible turns are available for you."
					<< std::endl;
			skip++;

			if (skip > 1) // Skipping two turns in a row implies that no turns are available
			{
				break;
			}
		}
		current_player = 3 - current_player;
	}

	/*
	 * Deciding who won the game
	 */
	switch (winner(field))
	{
	case 0:
		std::cout << "It's a DRAW!" << std::endl;
		break;
	case 1:
		std::cout << "Congratulations PLAYER 1 you have WON!" << std::endl;
		break;
	case 2:
		std::cout << "Congratulations PLAYER 2, you have WON!" << std::endl;
		break;
	default:
		std::cout << "ERROR WINNER CODE NOT DETECTED" << std::endl;
		break;
	}
}

int main(void)
{

	if (TEST == 1)
	{
		bool result = run_full_test();
		if (result == true)
		{
			std::cout << "ALL TESTS PASSED!" << std::endl;
		}
		else
		{
			std::cout << "TEST FAILED!" << std::endl;
		}
	}

	int field[SIZE_Y][SIZE_X];

	initialize_field(field);
	show_field(field); //show initial conditions

	char player_type_input;
	bool inputInvalid = true;
	int player_type[2];

	for (int i = 0; i < 2; ++i)
	{
		do
		{
			std::cout << "Please choose: Player " << i + 1 << std::endl;
			std::cout << "Press C for Computer, H for Human " << std::endl;
			std::cin >> player_type_input;
			switch (player_type_input)
			{
			case 'C':
				player_type[i] = COMPUTER;
				inputInvalid = false;
				break;
			case 'H':
				player_type[i] = HUMAN;
				inputInvalid = false;
				break;
			}
		} while (inputInvalid == true);
	}

	game(player_type);
	return 0;
}
