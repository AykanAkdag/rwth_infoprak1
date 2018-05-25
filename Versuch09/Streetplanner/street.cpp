#include "street.h"
#include <QDebug>

/**
 * @brief Street::Street
 *
 *      Constructor for the Street Class.
 *
 * @param city1 The city to be connected with city2
 * @param city2 The city to be connected with city1
 */
Street::Street(City* city1, City* city2)
{
    firstcity = city1;
    secondcity = city2;
}

Street::~Street()
{
}

City* Street::getFirstCity() const
{
    return this->firstcity;
}

City* Street::getSecondCity() const
{
    return this->secondcity;
}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(firstcity->getXcoor(), firstcity->getYcoor(), secondcity->getXcoor(), secondcity->getYcoor(), QPen(Qt::black));

    //Debug console outputs
    QString debugoutput = QString("Calling Street::draw. Drawing the street between '%1' and '%2'").arg(firstcity->getCityName()).arg(secondcity->getCityName());
    qDebug() << debugoutput;
}

void Street::drawRed(QGraphicsScene &scene)
{
    scene.addLine(firstcity->getXcoor(), firstcity->getYcoor(), secondcity->getXcoor(), secondcity->getYcoor(), QPen(Qt::red, 3));

    //Debug console outputs
    QString debugoutput = QString("Calling Street::drawRed. Drawing the street between '%1' and '%2' IN RED").arg(firstcity->getCityName()).arg(secondcity->getCityName());
    qDebug() << debugoutput;
}
