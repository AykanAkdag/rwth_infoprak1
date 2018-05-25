#ifndef MAP_H
#define MAP_H
#include <vector>
#include "city.h"
#include "abstractmap.h"

class Map : public AbstractMap
{

public:
    /**
     * @brief Map Constructor
     */
    Map();
    ~Map();

    /**
     * @brief Adding the city to the vector of cities
     * @param cityToAdd City that is to be added
     */
    virtual void addCity(City* cityToAdd);

    /**
     * @brief Adding the street to the vector of streets
     * @param streetToAdd Street to be added
     * @return True if two cities are valid False otherwise
     */
    virtual bool addStreet(Street* streetToAdd);

    /**
     * @brief Draw function for streets
     * @param scene Graphics surface variable
     */
    virtual void draw(QGraphicsScene& scene);

    /**
     * @brief Find a city by its name
     * @param city_name The name of the city (QString)
     * @return A pointer to the found city
     */
    virtual City* find_city(const QString city_name) const;

    /**
     * @brief Get all streets connected to the given city
     * @param city City to which all streets must be output
     * @return std vector of all the streets connected
     */
    virtual std::vector<Street*> get_street_list(const City* city) const;

    /**
     * @brief Get opposite city to a given city
     * @param street Street connecting cities of which one end is searched for
     * @param city City to which an opposite one is searched via the given street
     * @return pointer to the opposite City
     */
    virtual City* get_opposite_city(const Street* street, const City* city) const;

    /**
     * @brief Get the lenght of a given street
     * @param street The street which is questioned for its lenght.
     * @return lenght of the street calculated with simple 2d coordinate geometry.
     */
    virtual double get_length(const Street* street) const;

    /**
     * @brief Getter method for all the cities saved on the map
     * @return A vector of all the cities added on the map
     */
    std::vector<City*>  getCityList() const;

    /**
     * @brief Getter method for all the streets on the map
     * @return A vector of all the streets added on the map
     */
    std::vector<Street*>  getStreetList() const;

private:
    CitiesVector citylist;
    StreetsVector streetlist;
};

#endif // MAP_H
