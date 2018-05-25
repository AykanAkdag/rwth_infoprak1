#ifndef ADDNEWCITY_H
#define ADDNEWCITY_H

#include <QDialog>
#include "city.h"

namespace Ui {
class AddNewCity;
}

class AddNewCity : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief AddNewCity Widget
     * @param parent Interface parent
     */
    explicit AddNewCity(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
    ~AddNewCity();

    /**
     * @brief Getter method for the input city
     *
     *      Gets the new city and returns it to the user.
     *
     * @return City*
     */
    City* getNewCity();

private:
    Ui::AddNewCity *ui;
};

#endif // ADDNEWCITY_H
