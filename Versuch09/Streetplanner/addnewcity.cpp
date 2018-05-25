#include "addnewcity.h"
#include "ui_addnewcity.h"
#include <QDebug>
AddNewCity::AddNewCity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewCity)
{
    ui->setupUi(this);
}

AddNewCity::~AddNewCity()
{
    delete ui;
}

City* AddNewCity::getNewCity()
{
    //Getting the data for the new added city
    QString newCityName = ui->cityNameInput->text();
    int newCityX = ui->xCoorInput->value();
    int newCityY = ui->yCoorInput->value();

    //Debug Console outputs
    QString debugoutput = QString("A new city was input using AddNewCity Dialog with Name: '%1' and X:%2, Y:%3.").arg(newCityName).arg(newCityX).arg(newCityY);
    qDebug() << debugoutput;

    //return the newly created city
    return new  City(newCityName, newCityX, newCityY);
}

