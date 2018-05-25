#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include "city.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "mapiofileinput.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(&graphscene);                    //initialize the GraphicsScene attribute via GraphicsView

    importmap = new MapIoNrw;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Execute Dijkstra
void MainWindow::on_pushButton_confirm_Input_clicked()
{
    //Get the inputs from the user
    QString from = ui->fromInputBox->currentText();
    QString to = ui->toInputBox->currentText();

    //refresh the scene to delete previous red marked streets
    graphscene.clear();
    map.draw(graphscene);

    //Call Dijkstra
    std::vector<Street*> shortestPathList = Dijkstra::search(map, from, to);

    //Paint the streets in the shortest path to red
    std::vector<Street*>::const_iterator iterStreets;
    for(iterStreets = shortestPathList.begin(); iterStreets != shortestPathList.end(); iterStreets++)
    {
        (*iterStreets)->drawRed(graphscene);
    }

    //Output to the shortest path to the debug console
    QString debugoutput = QString("Shortest Path btw '%1' and '%2' is via:").arg(from,to);
    qDebug ()<< debugoutput;
    for(iterStreets = shortestPathList.begin(); iterStreets != shortestPathList.end(); iterStreets++)
    {
        City* city1 = (*iterStreets)->getFirstCity();
        City* city2 = (*iterStreets)->getSecondCity();

        qDebug() << QString("Driving on the street connecting '%1' and '%2'.").arg(city1->getCityName(),city2->getCityName());
    }
}


void MainWindow::on_actionExit_triggered()
{
    close();                                                    //exit menu bar press callback
}

void MainWindow::on_actionClear_Scene_triggered()
{
    graphscene.clear();                                         //clear scene menu bar press callback
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "Versuch 9", "RWTH Aachen Praktikum Informatik 1 Streetplanner with import from .txt ability.\nDeveloper: Can Oezmaden");
}


void MainWindow::on_testDrawCity_clicked()
{
    graphscene.clear();
    City aachen("Aachen", -100, 0);
    City berlin("Berlin", 0, 100);

    //Implementing directly city methods
    aachen.draw(graphscene);
    berlin.draw(graphscene);

    //Implementing map methods
    //map.addCity(&aachen);
    //map.addCity(&berlin);
    //map.draw(graphscene);
}

void MainWindow::on_testMap_clicked()
{
    Map map1;

    //copied from testfunktionen.txt
    City c1("city c1", 20,50);
    map1.addCity(&c1);
    map1.addCity(new City("city c2", 100, 52));
    map1.addCity(new City("city c3", -100, 20));
    map1.draw(graphscene);
}

void MainWindow::on_testStreetDrawer_clicked()
{
    Map map2;

    //creating the cities and showing them on the map
    City c1("Kings Landing", 30, -20);
    map2.addCity(&c1);
    City c2("Winterfell", -20, 100);
    map2.addCity(&c2);

    //drawing the connection
    Street s1(&c1, &c2);
    map2.addStreet(&s1);
    map2.draw(graphscene);
}

void MainWindow::on_hideTestButtons_clicked()
{
    //if clicked hide
    if (ui->hideTestButtons->isChecked() == true)
    {
        ui->testDrawCity->hide();
        ui->testMap->hide();
        ui->testStreetDrawer->hide();
        ui->testAbstractMap->hide();
        ui->testDijkstra->hide();
    }
    else //show
    {
        ui->testDrawCity->show();
        ui->testMap->show();
        ui->testStreetDrawer->show();
        ui->testAbstractMap->show();
        ui->testDijkstra->show();
    }
}

void MainWindow::on_addCity_clicked()
{
    //call addnewcity.ui
    AddNewCity addcitydialog;

    if(addcitydialog.exec() == QDialog::Accepted)
    {
        City* newCity = addcitydialog.getNewCity();

        //Debug Console outputs
        QString debugoutput = QString("Received callback from AddNewCity Dialog. Transferring the city onto the map. Name: '%1' X: %2, Y:%3").arg(newCity->getCityName()).arg(newCity->getXcoor()).arg(newCity->getYcoor());
        qDebug ()<< debugoutput;

        map.addCity(newCity);

        //insert to Combo boxes
        ui->fromInputBox->insertItem(ui->fromInputBox->currentIndex(),newCity->getCityName());
        ui->toInputBox->insertItem(ui->toInputBox->currentIndex(),newCity->getCityName());

        map.draw(graphscene);
    }
}

void MainWindow::on_fillMap_clicked()
{
    //clear the screen from the previous maps
    graphscene.clear();
    MapIoFileinput userSelectedMap("","");
    importmap = &userSelectedMap;

    //Selecting cities and streets txt files
    QString citiesFile = QFileDialog::getOpenFileName(this,
                                                      tr("Open Cities.txt"), "C:/", tr("Text files (*.txt)"));

    QString streetsFile = QFileDialog::getOpenFileName(this,
                                                       tr("Open Streets.txt"), "C:/", tr("Text files (*.txt)"));

    //init the map from the selected txt files
    userSelectedMap.map_init_from_file(map, citiesFile, streetsFile);

    //Add the cities to the combo box lists
    std::vector<City*> cities = map.getCityList();
    std::vector<City*>::const_iterator iterCities;
    for(iterCities = cities.begin(); iterCities != cities.end(); iterCities++)
    {
        ui->fromInputBox->insertItem(ui->fromInputBox->currentIndex(),(*iterCities)->getCityName());
        ui->toInputBox->insertItem(ui->toInputBox->currentIndex(),(*iterCities)->getCityName());
    }

    //output the filled map
    map.draw(graphscene);
}

void MainWindow::on_testAbstractMap_clicked()
{
    Map map3;

    //COPIED FROM TESTFUNKTIONEN.TXT
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = map3.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not be added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        map3.addCity(a);
        map3.addCity(b);
        bool t1 = map3.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: find city";
        City* city = map3.find_city("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = map3.find_city("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = map3.find_city("c");
        if (city != NULL)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    map3.addCity(c);
    map3.addStreet(s2);

    {
        qDebug() << "MapTest: get_street_list";
        AbstractMap::StreetsVector streetList1 = map3.get_street_list(a);
        AbstractMap::StreetsVector streetList2 = map3.get_street_list(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    {
        qDebug() << "MapTest: street_length";
        double l = map3.get_length(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: get_opposite_city";
        const City *city = map3.get_opposite_city(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map3.get_opposite_city(s, c);
        if (city != 0)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }


    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_testDijkstra_clicked()
{
    Map map4;

    //Debug Console outputs
    QString debugoutput = "MapTest: DIJKSTRA";
    qDebug ()<< debugoutput;

    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 200);
    City *d = new City("d", -100, -50);
    map4.addCity(a);
    map4.addCity(b);
    map4.addCity(c);
    map4.addCity(d);
    Street* s1 = new Street(a,b);
    Street* s2 = new Street(a,d);
    Street* s4 = new Street(a,c);
    Street* s5 = new Street(b,c);
    map4.addStreet(s1);
    map4.addStreet(s2);
    map4.addStreet(s4);
    map4.addStreet(s5);

    map4.draw(graphscene);

    std::vector<Street*> shortestPathList = Dijkstra::search(map4, "d", "c");

    //Repaint the streets in the shortest path to red
    std::vector<Street*>::const_iterator iterStreets;
    for(iterStreets = shortestPathList.begin(); iterStreets != shortestPathList.end(); iterStreets++)
    {
        (*iterStreets)->drawRed(graphscene);
    }
    //map.draw(graphscene);

    //Output to the shortest path to the debug console
    debugoutput = QString("Shortest Path btw '%1' and '%2' is via:").arg(d->getCityName(),c->getCityName());
    qDebug ()<< debugoutput;
    for(iterStreets = shortestPathList.begin(); iterStreets != shortestPathList.end(); iterStreets++)
    {
        City* city1 = (*iterStreets)->getFirstCity();
        City* city2 = (*iterStreets)->getSecondCity();

        qDebug() << QString("Drive on the '%1' to '%2' street shown red on the map").arg(city1->getCityName(),city2->getCityName());
    }
}
