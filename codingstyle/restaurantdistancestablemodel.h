#ifndef RESTAURANTDISTANCESTABLEMODEL_H
#define RESTAURANTDISTANCESTABLEMODEL_H

#include <QSqlTableModel>
#include "database.h"
/** @brief The RestaurantDistancesTableModel class
*
*/

/*! \class RestaurantDistancesTableModel
 * This class extends QSqlTableModel and serves as a way
 * to aggregate all the information of a Restaurant Menu table from
 * the database into a visual table on the ui. Allows for filters
 * to be set, and sorting elements of a column.
 */
class RestaurantDistancesTableModel : public QSqlTableModel {
public:

    //! Constructor
    RestaurantDistancesTableModel(QObject *parent, Database *db, const QString& RESTAURANT_NAME);
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
        RESTAURANTS,
        DISTANCES
    };
};

#endif // RESTAURANTDISTANCESTABLEMODEL_H
