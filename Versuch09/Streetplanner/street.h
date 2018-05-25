#ifndef STREET_H
#define STREET_H
#include "city.h"

class Street
{
public:

    /**
     * @brief Street Consturctor
     * @param city1 From
     * @param city2 To
     */
    Street(City* city1, City* city2);
    ~Street();

    /**
     * @brief Draw function for the Street Class
     * @param scene Graphics Surface variable
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Draws the given street with a red QPen.
     *
     *      Used for the Dijkstra shortest path outputs.
     *
     * @param scene Graphics Surface variable
     */
    void drawRed(QGraphicsScene& scene);

    /**
     * @brief Getter method for the first city (from city)
     * @return A pointer to the first city
     */
    City* getFirstCity() const;

    /**
     * @brief Getter method for the second city (to city)
     * @return A pointer to the second city
     */
    City* getSecondCity() const;

private:
    City* firstcity;
    City* secondcity;
};

#endif // STREET_H
