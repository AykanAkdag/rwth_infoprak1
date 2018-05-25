#include "map.h"
#include <QDebug>
#include <QString>
#include "math.h"

Map::Map()
{

}
Map::~Map()
{
    // Delte all cities
    CitiesVector::const_iterator iterCities;
    for(iterCities = citylist.begin(); iterCities != citylist.end(); iterCities++)
    {
        delete (*iterCities);
    }

    // Delete all streets
    StreetsVector::const_iterator iterStreets;
    for(iterStreets = streetlist.begin(); iterStreets != streetlist.end(); iterStreets++)
    {
        delete (*iterStreets);
    }
}
/**
 * @brief Adds Cities to the map
 *
 *      This map gets the city instance and initializes it in the map construct by adding it to the STL vector
 *      of all cities.
 *
 * @param cityToAdd City to be added
 */
void Map::addCity(City* cityToAdd)
{
    citylist.push_back(cityToAdd);

    //Output debug to console
    QString debugoutput = QString("Calling Map::addCity. A city with a name of '%1' has been added to the cities list.").arg(cityToAdd->getCityName());
    qDebug() << debugoutput;
}

bool Map::addStreet(Street* streetToAdd)
{
    if(std::find(citylist.begin(), citylist.end(), streetToAdd->getFirstCity()) != citylist.end()
    && std::find(citylist.begin(), citylist.end(), streetToAdd->getSecondCity()) != citylist.end())
    {
        streetlist.push_back(streetToAdd);
        //Output debug to console
        QString debugoutput = QString("Calling Map::addStreet. A street between '%1' and '%2' has been added").arg(streetToAdd->getFirstCity()->getCityName()).arg(streetToAdd->getSecondCity()->getCityName());
        qDebug() << debugoutput;
        return true;
    }
    //Output debug to console
    QString debugoutput = QString("Calling Map::addStreet. FAILED TO ADD THE STREET. THE REQUESTED CITY DOES NOT EXIST OR HAS NOT BEEN ADDED TO THE MAP YET.");
    qDebug() << debugoutput;
    return false;

}

void Map::draw(QGraphicsScene &scene)
{
    scene.clear();

    //Iterating over all the cities and printing them out on the map
    CitiesVector::const_iterator iterCities;
    for (iterCities = citylist.begin(); iterCities != citylist.end(); iterCities++)
    {
        (*iterCities)->draw(scene);
    }

    //Iterating over all the street and printing them out on the map
    StreetsVector::const_iterator iterStreets;
    for (iterStreets = streetlist.begin(); iterStreets != streetlist.end(); iterStreets++)
    {
        (*iterStreets)->draw(scene);
    }


}

City* Map::find_city(const QString city_name) const
{
    QString currcityname;
    CitiesVector::const_iterator iterCities;

    //Debug console outputs
    QString debugoutput1 = QString("Calling Map::find_city, looking for a city named: '%1' ").arg(city_name);
    qDebug() << debugoutput1;

    for (iterCities = citylist.begin(); iterCities != citylist.end(); iterCities++)
    {
        currcityname = (*iterCities)->getCityName();
        if(currcityname == city_name) //found?
        {
            //Debug console outputs
            QString debugoutput2 = QString("The city '%1' was successfuly found. Returning the pointer to the city... ").arg(city_name);
            qDebug() << debugoutput2;

            return (*iterCities);
        }
    }

    //Not found
    //Debug console outputs
    QString debugoutput3 = QString("THE CITY '%1' WAS NOT FOUND. EITHER DOES NOT EXIST OR THE NAME HAS A TYPO").arg(city_name);
    qDebug() << debugoutput3;
    return NULL;
}

AbstractMap::StreetsVector Map::get_street_list(const City* city) const
{
    StreetsVector connectedStreetsList;

    //Debug console outputs
    //QString debugoutput1 = QString("Calling Map::get_street_list, looking for all streets connected to: '%1' ").arg(city->getCityName());
    //qDebug() << debugoutput1;

    StreetsVector::const_iterator iterStreets;
    for(iterStreets = streetlist.begin(); iterStreets != streetlist.end(); iterStreets++)
    {
       City* firstcity = (*iterStreets)->getFirstCity();
       City* secondcity = (*iterStreets)->getSecondCity();
       //Only one of the cities must be connected
       if(firstcity == city || secondcity == city)
       {
          //if so, add the street to the list
          connectedStreetsList.push_back(*iterStreets);

          //Debug console outputs
          QString city1name = (*firstcity).getCityName();
          QString city2name = (*secondcity).getCityName();
          QString debugoutput2 = QString("Found a street connected to '%1'. The street connects '%2' to '%3'.").arg(city->getCityName()).arg(city1name).arg(city2name);
          qDebug() << debugoutput2;
       }
    }
    return connectedStreetsList;
}

City* Map::get_opposite_city(const Street* street, const City* city) const
{
    City* connectedCity1 = street->getFirstCity();
    City* connectedCity2 = street->getSecondCity();
    City* foundConnectedCity;

    //Debug console outputs
    QString debugoutput = QString("Calling Map::get_opposite_city, looking for the city connected to '%1' via the street '%2' to '%3'").arg(city->getCityName(), connectedCity1->getCityName(), connectedCity2->getCityName());
    qDebug() << debugoutput;

    if(connectedCity1 == city)
    {
        foundConnectedCity = street->getSecondCity();
    }
    else if(connectedCity2 == city)
    {
        foundConnectedCity = street->getFirstCity();
    }
    else
    {
        //Debug console outputs
        debugoutput = QString("'%1' IS NOT CONNECTED TO THIS STREET. RETURNING NULL.").arg(city->getCityName());
        qDebug() << debugoutput;
        return NULL;
    }

    //Debug console outputs
    debugoutput = QString("Opposite city to '%1' is: '%2'").arg(city->getCityName(), foundConnectedCity->getCityName());
    qDebug() << debugoutput;

    return foundConnectedCity;

}

double Map::get_length(const Street* street) const
{
    //Debug console outputs
    QString debugoutput = QString("Calling Map::get_lenght of street that connects '%1' and '%2'.").arg(street->getFirstCity()->getCityName(),street->getSecondCity()->getCityName());
    qDebug() << debugoutput;

    double res = sqrt(pow(street->getFirstCity()->getXcoor() - street->getSecondCity()->getXcoor(),2)
               +pow(street->getFirstCity()->getYcoor() - street->getSecondCity()->getYcoor(),2));

    //Debug console outputs
    QString resstring = QString::number(res,'f',2);
    debugoutput = QString("The lenght of this street is: %1").arg(resstring);
    qDebug() << debugoutput;
    return res;
}

std::vector<City*> Map::getCityList() const
{
    return citylist;
}

std::vector<Street*> Map::getStreetList() const
{
    return streetlist;
}

