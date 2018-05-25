/**
 * @file test.cpp
 *
 * Provides a function for testing the program and some other functions in order to provide this.
 */

#include "test.h"
#include "config.h"

#include <iostream>


extern void show_field(const int field[SIZE_Y][SIZE_X]);
extern int winner(const int field[SIZE_Y][SIZE_X]);
extern bool turn_valid(const int field[SIZE_Y][SIZE_X],  const int player, const int pos_x, const int pos_y);
extern void execute_turn(int field[SIZE_Y][SIZE_X], const int player, const int pos_x, const int pos_y);
extern int possible_turns(const int field[SIZE_Y][SIZE_X], const int player);

/**
* @brief Tests the implemented winner function
*
* 	This function serves to test the winner function implemented in the main function. It takes
* 	a predefined playing field coupled with the predefined winner of the game of the given field as parameters.
* 	To complete the test, the winner function is called to compare its results to the already known results
* 	contained in this test function. The test counts as passed in the case if the predefined winner is the
* 	same as the calculated (suspected) winner gotten from the winner function.
*
*  @param field  	  The field to be checked in order to determine the winner
*  @param winner_code The predetermined correct winner return value
*  @return True if the test has been passed, else - False
*
*/
bool test_winner(const int field[SIZE_Y][SIZE_X], const int winner_code)
{
	std::cout << "Running test for 'winner'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking who wins" << std::endl;

	//Call winner-function
	int suspected_winner = winner(field);

	/* Check if result of winner function is correct and what you expected
	 *
	 * Return true for correct and false for wrong
	 *
	 * also print to the console if test was passed or not
	 */

	std::cout << "The expected winner code: " << winner_code << std::endl;
	std::cout << "The calculated winner code: " << suspected_winner
			<< std::endl;

	if (winner_code == suspected_winner)
	{
		std::cout << "The test was successful!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "\nTEST FAILED!" << std::endl;
		return false;
	}
}


/**
* @brief Tests the implemented turnvalid function
*
* 	This function serves to test the turnvalid function implemented in the main function. It takes
* 	a predefined state of a game field coupled with coordinates and the predefined validity of the turn as parameters.
* 	To complete the test, the turn valid function is called to compare its results to the already known results
* 	contained in this test function. The test counts as passed in the case if the predefined validity is the
* 	same as the calculated (suspected) validity gotten from the turnvalid function.
*
*  @param field  The state of the game field for the test
*  @param player Tested player whose turn it is to make a move, 1 for P1, 2 for P2
*  @param pos_x  The X coordinate to test
*  @param pos_y  The Y coordinate to test
*
*  @return True if the test has been passed, else - False
*
*/
bool test_turn_valid(const int field[SIZE_Y][SIZE_X], const int player, const int pos_x,
					 const int pos_y, const bool valid)
{
	std::cout << "Running test for 'turnvalid'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	show_field(field);
	std::cout << "Checking the validity of the turn" << std::endl;
	// check for a given field whether a turn is valid

	bool suspected_validity = turn_valid(field, player, pos_x, pos_y);

	std::cout << "The expected validity of the turn: "<< valid << std::endl;
	std::cout << "The calculated validity of the turn: " << suspected_validity << std::endl;

	if(suspected_validity == valid)
	{
		std::cout << "The test was successful!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "\nTEST FAILED!" << std::endl;
		return false;
	}
	return 0;
}

/**
* @brief Tests the implemented execute_turn function
*
* 	This function serves to test the execute turn function implemented in the main function. It takes
* 	a predefined state of a game field coupled with coordinates that the player has selected to make their move on.
* 	Moreover, it also gets an already pre-determined game field that should be expected to come out of the execute_turn
* 	function. To complete the test, the exectute turn function is called to compare its results to the already known results
* 	contained in this test function. The test counts as passed in the case if the predefined game field is the
* 	same as the calculated (suspected) game field gotten from the execute turn function.
*
*  @param input  The current state of the game field
*  @param output The expected state of the game field after the move
*  @param player Player who makes the move, 1 for P1, 2 for P2
*  @param pos_x  The X coordinate the player has selected
*  @param pos_y  The Y coordinate the player has selected
*
*/
bool test_execute_turn(int input[SIZE_Y][SIZE_X],
		const int output[SIZE_Y][SIZE_X], const int player, const int pos_x,
		const int pos_y)
{
	std::cout << "Running test for 'execute_turn'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "The input field is:" << std::endl;
	show_field (input);
	std::cout << "The expected outcome field is:" << std::endl;
	show_field (output);
	std::cout << "Checking the execution of the turn" << std::endl;

	execute_turn(input, player, pos_x, pos_y);

	std::cout << "The calculated execution of the turn: " << std::endl;
	show_field(input);

	for (int j = 0; j < SIZE_Y; ++j)
	{
		for (int i = 0; i < SIZE_X; ++i)
		{
			if (output[j][i] != input[j][i])
			{
				std::cout << "\nTEST FAILED!" << std::endl;
				return false;
			}
		}
	}
	std::cout << "\nThe test was successful!" << std::endl;
	return true;
}

/**
* @brief Tests the implemented possible_turns function
*
* 	This function is intented to test the possible_turns function implemented in the main function. It takes
* 	a predefined state of a game field, the player that is going to make the move, and lastly a predefined correct
* 	answer of number of possible turns calculated for the given field. To complete the test, the possible_turns
* 	function is called to compare its results to the already known results contained in this test function.
* 	The test counts as passed in the case number of possible turns is the same as the calculated (suspected)
* 	number of turns gotten from the possible_turns function.
*
*  @param field  The current state of the game field
*  @param player Player who makes the move, 1 for P1, 2 for P2
*  @param count_possible_turns  A precalculated number of possible turns for the field
*/
bool test_possible_turns(const int field[SIZE_Y][SIZE_X], const int player,
		const int count_possible_turns)
{
	std::cout << "Running test for 'possible_turns'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "The game field is:" << std::endl;
	show_field (field);
	std::cout << "The expected number of possible turns for Player " << player
			<< " is: " << count_possible_turns << std::endl;
	std::cout << "Checking the possible_turns result." << std::endl;

	int suspected_count_possible_turns = possible_turns(field, player);

	std::cout << "Calculated number of possible turns: "<< suspected_count_possible_turns << std::endl;
	if (suspected_count_possible_turns == count_possible_turns)
	{
		std::cout << "The test was successful!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "\nTEST FAILED!" << std::endl;
		return false;
	}

	return 0;
}

bool run_full_test(void)
{
	bool result = true;


// ---------- CHECK WINNER ---------- //

	int winner_matrix[5][8][8]= {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},//Just Player 1 stones
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},//Just Player 2 stones
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
				},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},//Draw between Player 1 and 2
				{0, 0, 1, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 2, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},//Null field
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},
			{   {1, 1, 1, 1, 1, 1, 1, 2},
				{1, 1, 2, 1, 1, 2, 1, 2},
				{1, 2, 2, 1, 2, 1, 1, 1},
				{1, 1, 1, 1, 1, 2, 1, 2},//Full field, player 1 wins
				{2, 1, 1, 1, 1, 1, 2, 1},
				{1, 2, 2, 2, 2, 2, 1, 1},
				{1, 2, 2, 1, 2, 2, 1, 1},
				{1, 1, 2, 2, 2, 2, 1, 1}
			}};


	int winner_code[5] = {1,2,0,0,1}; //The predefined winner codes for the matrices above

	int field_to_test1[8][8]; // Declaration of temp. variables used in the loop below
	int winner_code_to_test;

	for (int i = 0; i < 5; ++i)
	{
		winner_code_to_test = winner_code[i];

		/*
		* Copying the predefined field into the temp. array
		*/
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				field_to_test1[j][k] = winner_matrix[i][j][k];
			}
		}

		test_winner(field_to_test1, winner_code_to_test); //Testing the outcome for i-th combination
	}

// ---------- CHECK TURN VALID ---------- //

	int turnvalid_matrix[6][8][8] = {
			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 0, 0, 1},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {1, 0, 2, 0, 0, 1, 1, 1},
				{0, 0, 2, 0, 0, 1, 0, 0},
				{0, 0, 2, 0, 0, 2, 1, 1},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 2, 0},
				{0, 0, 0, 2, 1, 1, 0, 2},
				{1, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 0, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 1, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{2, 0, 1, 2, 0, 2, 0, 0},
				{0, 2, 0, 2, 2, 2, 2, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 0, 0, 2, 2, 2},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 1, 1, 1, 0, 0}
			},

			{   {2, 1, 0, 0, 2, 1, 1, 1},
				{0, 2, 0, 0, 0, 0, 0, 0},
				{1, 0, 0, 2, 0, 0, 0, 1},
				{0, 1, 1, 1, 0, 1, 0, 0},
				{1, 0, 0, 1, 1, 0, 0, 2},
				{0, 0, 0, 0, 0, 0, 0, 1},
				{1, 1, 0, 0, 0, 0, 2, 0},
				{1, 1, 2, 0, 0, 2, 2, 1}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int turnvalid_player[6] = {1, 2, 2, 1, 2, 1};
	int turnvalid_pos[6][2] = { {2, 3}, {0, 3}, {4, 3}, {3, 4}, {3, 5}, {3, 4} };
	bool turnvalid_valid[6] = {0, 0, 0, 1, 1, 0};

	int field_to_test2[8][8]; // Declaration of temp. variables used in the loop below
	int pos_x_to_test;
	int pos_y_to_test;
	int validity;
	int player;

	for (int i = 0; i < 6; ++i)
	{
		player = turnvalid_player[i];
		pos_x_to_test = turnvalid_pos[i][0];
		pos_y_to_test = turnvalid_pos[i][1];
		validity = turnvalid_valid[i];

		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				field_to_test2[j][k] = turnvalid_matrix[i][j][k];
			}
		}

		test_turn_valid(field_to_test2, player, pos_x_to_test, pos_y_to_test,
			validity);
	}

// ---------- CHECK EXECUTE TURN ---------- //

	int executeturn_matrix_in[9][8][8] = {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 2, 0, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 1, 2, 0, 2, 2, 1, 0},
				{0, 0, 0, 2, 2, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 1, 1, 1, 1, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 0, 1, 1, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_matrix_out[9][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 1, 2, 2},
				{2, 2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 1, 1},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 2, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 1, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 2, 0, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 1, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 1, 1, 1, 1, 1, 1, 0},
				{0, 0, 0, 1, 1, 0, 0, 0},
				{0, 0, 0, 1, 0, 1, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 2, 0, 0},
				{0, 0, 0, 0, 2, 0, 0, 0},
				{0, 0, 0, 2, 0, 0, 0, 0},
				{0, 0, 2, 1, 1, 1, 1, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 2, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 0, 0},
				{0, 1, 0, 0, 0, 0, 2, 1},
				{1, 2, 2, 2, 2, 0, 0, 0},
				{0, 0, 1, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int executeturn_player[9]={0,0,0,1,2,0,1,2,2};
	int executeturn_pos[9][2]={	{0,0},
					{0,0},
					{0,0},
					{3,4},
					{3,5},
					{0,0},
					{3,4},
					{2,4},
					{1,4}};

	for (int i = 0; i < 9; i++)
	{
		player = executeturn_player[i];
		pos_x_to_test = executeturn_pos[i][0];
		pos_y_to_test = executeturn_pos[i][1];
		int input[8][8];
		int output_to_test[8][8];

		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				input[j][k] = executeturn_matrix_in[i][j][k];
				output_to_test[j][k] = executeturn_matrix_out[i][j][k];
			}
		}
		test_execute_turn(input, output_to_test, player, pos_x_to_test, pos_y_to_test);
	}
// ---------- CHECK POSSIBLE TURNS ---------- //

	int possibleturns_matrix[2][8][8] {
			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 1, 2, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			},

			{   {0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 2, 1, 1, 0, 0},
				{0, 0, 0, 2, 1, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0}
			}
		};

	int possibleturns_player[2] =
	{ 1, 1 };
	int possibleturns_count[2] =
	{ 4, 5 };

	int field_to_test3[8][8];
	int player_to_test = 0;
	int predet_count = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				field_to_test3[j][k] = possibleturns_matrix[i][j][k];
			}
		}

		player_to_test = possibleturns_player[i];
		predet_count = possibleturns_count[i];
		test_possible_turns(field_to_test3, player_to_test, predet_count);
	}

return result;
}
