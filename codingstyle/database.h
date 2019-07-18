#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <vector>
#include <queue>
#include <utility>

/**
 * @brief This connects the program to the database
 *
 * This class Allows the program to interact with the data to push and pull
 * necessary data
 */
class Database : public QSqlDatabase {

    private:
        //! Private Constructor
        Database();

        //! Static instance pointer used for singleton design pattern
        static Database *s_instance;

        QString cleanStr(QString in) const;

        bool hasBeenVisited(QString name, const std::queue<std::pair<QString, float> >& Q);

        bool isInRestaurants(const QString &name, const std::vector<QString> &restaurants);

        void removeFromVec(QString name, std::vector<QString>& vec);

    public:
        //! Destructor
        ~Database();

        /*!
         * \brief instance dynamically-allocates memory to s_instance pointer, and returns the same pointer (singleton design pattern)
         * \return static Database pointer
         */
        static Database* instance() {
            if(!s_instance) {
                s_instance = new Database;
                if(s_instance->isEmpty()) {
                   s_instance->readFromRestaurantFile("./assets/initial_restaurants.txt");
                }
            }

            return s_instance;
        }

        /**
         * @brief Reads in the restaurants
         *
         * Reads information from a file, including the restaurant names and restaurant information
         * and then stores the information in the database
         *
         * @param Input file for the restaurant information
         */
        void readFromRestaurantFile(const QString& FILE);

        /**
         * @brief Reads in the additional restaurants
         *
         * This reads in the additional 2 restaurants from the secondary input file
         */
        void ReadFromNewFile();

        /**
         * @brief Adds a new restaurant to the database
         * @param numRest Is the restaurant number
         * @param restaurantName Is the restaurant name
         */
        void AddNewRestaurant(std::vector<std::pair<QString, float> > numRest, QString restaurantName);

        /**
         * @brief Adds a new menu item to the database
         * @param restaurantName Is the restauant name
         * @param itemName Is the item name
         * @param itemPrice Is the price of the item
         */
        void AddMenuItem(QString restaurantName, QString itemName, QString itemPrice);

        /**
         * @brief Deletes a menu item from the database
         * @param restaurantName Is the restaurant name
         * @param itemName Is the menu item to be deleted
         */
        void DeleteMenuItem(QString restaurantName, QString itemName);

        /**
         * @brief A method that calculates the total number of restaurants and returns it
         * @return The total number of restaurants
         */
        unsigned short getNumRestaurants() const;

        /**
         * @brief Gathers all of the restaurant names and stores them in a vector of QStrings
         * @return The accumulated name of restaurants in a vector of QStrings
         */
        std::vector<QString> getRestaurantNames() const;

        /**
         * @brief Gathers all of the restaurant menu items and returns them in a vector that has name and price
         * @param RESTAURANT Is the name of the restaurant that is going to gather up the menu items
         * @return A vector of the menu items for a certain restaurant, both the item name and its price
         */
        std::vector<std::pair<QString, float> > getRestaurantMenu(const QString& RESTAURANT) const;

        /**
         * @brief Checks to see if the database has stored data or not
         * @return A bool that states whether or not the database contains data
         */
        bool isEmpty() const;       

        /**
         * @brief Creates a full trip out of the database that visits all of the restaurants and starts at Saddleback
         * @param restaurants is a vector of all of the restaurants that be visited on the trip
         * @return The menu items for each given restaurant
         */
        std::queue<std::pair<QString, float> > getFullTrip(std::vector<QString> restaurants);

        /**
         * @brief Creates a custom trip that visits only the selected restaurants
         * @param restaurants is a vector of all of the restaurants that be visited on the trip
         * @return The menu items for each given restaurant
         */
        std::queue<std::pair<QString, float> > getCustomTrip(std::vector<QString> restaurants);

        /**
         * @brief Creates a custom trip that will start at a certain point and then only visit a specified number of
         * other restaurants
         * @param startingPoint is the starting restaurant for the trip
         * @param restToVisit is the number of remaining restaurants to visit
         * @return The menu items for each given restaurant
         */
        std::queue<std::pair<QString, float> > getStartTrip(QString startingPoint, int restToVisit);
};

#endif // DATABASE_H
