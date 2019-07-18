#include "./headers/restaurantmenutablemodel.h"

// Constructs the item search table for the AdminControl UI
RestaurantMenuTableModel::RestaurantMenuTableModel(QObject *parent, Database *db, const QString& RESTAURANT_NAME) : QSqlTableModel(parent, *db) {
    QString tableName = RESTAURANT_NAME;
    tableName.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    tableName = tableName.simplified();
    tableName.replace(" ", "");
    tableName += "_Menu";
    Init(tableName);
}

// Initializes the table and sets up all the columns and rows
void RestaurantMenuTableModel::Init(const QString& TABLE_NAME) {
    this->setTable(TABLE_NAME);
    this->select();
    this->setHeaderData(MENU_ITEMS, Qt::Horizontal, tr("Menu Items"));
    this->setHeaderData(ITEM_PRICES, Qt::Horizontal, tr("Prices"));
}

// Sets the filters for the table for the correct search
void RestaurantMenuTableModel::SetFilter(QString filter) {
    this->setFilter(filter);
    this->select();
}
