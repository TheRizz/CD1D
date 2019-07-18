#include <QFile>
#include <vector>
#include <QString>
using namespace std;

void database::fileparser() {

    //rest = restaurant
    QFile infile;      // Input file stream
    QString restName;  // Restaurant name
    int restNum;       // Restaurant number
    int totOtherRest;  // Total other restaurants
    vector distToRest; // Distance to other restaurants
    int distToSad;     // Distance to Saddleback
    vector menuItem;   // Menu Item names
    vector menuPrice;  // Menu Item Prices


    infile.open("initial_restaurants");
    while(infile) {

        // Loop to read in the menu items and prices
        menuItem.reserve(10);
        menuPrice.reserver(10);
        while(infile != '\n') {

            getline(infile, )

        }


    }


    qDebug

};
