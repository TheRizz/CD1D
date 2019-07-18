#include "./headers/restaurantdistancestablemodel.h"

// Constructs the item search table for the AdminControl UI
RestaurantDistancesTableModel::RestaurantDistancesTableModel(QObject *parent, Database *db, const QString& RESTAURANT_NAME) : QSqlTableModel(parent, *db) {
    QString viewName = RESTAURANT_NAME;
    viewName = viewName.simplified();
    viewName.replace(" ", "");
    viewName.replace("-", "");
    viewName.replace("\'", "");

    QString distancesTable = viewName + "_Distances";

    viewName += "_Dist";

    QString viewQuery = QString("CREATE VIEW %1 AS SELECT DISTINCT Master.restaurantName, %2.Distance FROM Master, %3 Where Master.restaurantNum = %4.restaurantNum AND %5.Distance != 0;").arg(viewName).arg(distancesTable).arg(distancesTable).arg(distancesTable).arg(distancesTable);

    QSqlQuery query(*db);

    query.prepare(viewQuery);

//    qDebug() << "View query: " << query.exec();
    query.exec();

//    qDebug() << query.executedQuery();


    Init(viewName);
}

// Initializes the table and sets up all the columns and rows
void RestaurantDistancesTableModel::Init(const QString& TABLE_NAME) {
    this->setTable(TABLE_NAME);
    this->select();
    this->setHeaderData(RESTAURANTS, Qt::Horizontal, tr("Restaurants"));
    this->setHeaderData(DISTANCES, Qt::Horizontal, tr("Distances"));
}

// Sets the filters for the table for the correct search
void RestaurantDistancesTableModel::SetFilter(QString filter) {
    this->setFilter(filter);
    this->select();
}
