#ifndef CITY_H
#define CITY_H
#include <QString>
#include <QGraphicsScene>

/**
 * @brief The City class
 *
 *      This is the class representing a city with it's coordinates.
 */
class City
{
public:
    /**
     * @brief City Constructor
     * @param name The name of the city (QString)
     * @param x X coordinate
     * @param y Y coordinate
     */
    City(QString name, int x, int y);

    /**
     * @brief City Destructor
     */
    ~City();

    /**
     * @brief Draw method for city class
     *
     *      This method outputs the city with its name as a red dot on a map.
     *
     * @param scene Graphics surface
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Getter for the City Name
     * @return City name
     */
    QString getCityName() const;

    /**
     * @brief Getter for the X coordinate
     * @return X coordinate of the city
     */
    int getXcoor() const;

    /**
     * @brief Getter for the Y coordinate
     * @return Y coordinate of the city
     */
    int getYcoor() const;
private:
    QString cityname;
    int xcoor;
    int ycoor;
};

#endif // CITY_H
