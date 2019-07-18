#ifndef RESTAURANTMENUTABLEMODEL_H
#define RESTAURANTMENUTABLEMODEL_H

#include <QSqlTableModel>
#include "database.h"

/** @brief The RestaurantMenuTableModel class
*
*/

/*! \class RestaurantMenuTableModel
 * This class extends QSqlTableModel and serves as a way
 * to aggregate all the information of a Restaurant Menu table from
 * the database into a visual table on the ui. Allows for filters
 * to be set, and sorting elements of a column.
 */
class RestaurantMenuTableModel : public QSqlTableModel {
public:

    //! Constructor
    RestaurantMenuTableModel(QObject *parent, Database *db, const QString& RESTAURANT_NAME);
    void SetFilter(QString filter);

private:
    Q_OBJECT

    /*!
     * \brief Initialize the table
     */
    void Init(const QString& TABLE_NAME);

    /*! \enum Fields
     * This enum is used to help manipulate and output the datafields
     *  in the table.
     */
    enum Fields {
        MENU_ITEMS,
        ITEM_PRICES
    };
};

#endif // RESTAURANTMENUTABLEMODEL_H
