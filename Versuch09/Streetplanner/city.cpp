#include "city.h"
#include <QDebug>
#include <QGraphicsTextItem>
#define RADIUS 5

City::City(QString name, int x, int y)
{
    //init attributes
    cityname = name;
    xcoor = x;
    ycoor = y;

    //Debug console outputs
    QString debugoutput = QString("Calling City constructor. City with the name of '%1' and X:%2, Y:%3, was created").arg(name).arg(x).arg(y);
    qDebug() << debugoutput;
}

City::~City()
{

}

void City::draw(QGraphicsScene& scene) const
{
    //Add the red dot on the city coordinates
    scene.addEllipse(xcoor-RADIUS,ycoor-RADIUS,2*RADIUS,2*RADIUS,QPen(Qt::red),QBrush(Qt::red, Qt::SolidPattern));

    //Label the dot with the name of the city
    QGraphicsTextItem *citynamelabel = new QGraphicsTextItem;
    citynamelabel->setPos(xcoor-RADIUS, ycoor-RADIUS); //get the right position
    citynamelabel->setPlainText(cityname); //set the name of the city as the label
    scene.addItem(citynamelabel); //add the name label on the map

    //Debug messages
    QString debugoutput = QString("Calling City::draw. Added the city of '%1' on the map as a red dot with coordinates X:%2 Y:%3.").arg(this->cityname).arg(this->xcoor).arg(this->ycoor);
    qDebug() << debugoutput;
}

QString City::getCityName() const
{
    return cityname;
}

int City::getXcoor() const
{
    return xcoor;
}

int City::getYcoor() const
{
    return ycoor;
}
