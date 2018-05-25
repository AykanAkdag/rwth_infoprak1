#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "city.h"
#include "map.h"
#include "addnewcity.h"
#include "mapio.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief Confirm button click slot
     *
     *      This method is the response fucntion to clicking confirm in the main ui.
     */
    void on_pushButton_confirm_Input_clicked();

    /**
     * @brief Exit button click slot
     *
     *      This method is the response function to clicking exit in the main ui.
     */
    void on_actionExit_triggered();

    /**
     * @brief Clear Scene button click slot
     *
     *      This method is the response function to clicking clear scene in the main ui.
     */
    void on_actionClear_Scene_triggered();

    /**
     * @brief About button click slot
     *
     *      This method is the response function to about in the main ui.
     */
    void on_actionAbout_triggered();

    /**
     * @brief Test method for the implemented City draw function
     */
    void on_testDrawCity_clicked();

    /**
     * @brief Test method for the implemented Map class
     */
    void on_testMap_clicked();

    /**
     * @brief Test method for Streets and Cities on the map
     */
    void on_testStreetDrawer_clicked();

    /**
     * @brief Button to hide/show the test buttons
     */
    void on_hideTestButtons_clicked();

    /**
     * @brief Button to open a dialog to add a new city
     */
    void on_addCity_clicked();

    /**
     * @brief Filling with a predefined map by selecting a txt files
     */
    void on_fillMap_clicked();

    /**
     * @brief Test method for the Abstract Map class
     */
    void on_testAbstractMap_clicked();

    /**
     * @brief Tests the implemented Dijkstra algorithm
     */
    void on_testDijkstra_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene graphscene; //new attribute of QGraphicsScene type
    Map map;
    MapIo* importmap;
};

#endif // MAINWINDOW_H
