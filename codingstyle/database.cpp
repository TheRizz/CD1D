#include "./headers/database.h"

//! Constructor for the database
Database::Database() : QSqlDatabase(addDatabase("QSQLITE"))
{
  //!Set database location
  setHostName("localhost");
  setDatabaseName("./assets/something_something.db");

  //!Open database and enable foreign keys if successful
  if(!open()) {
      qDebug() << "Failed to open database. Check if shadowbuid is off." << lastError();
  }
  else {    //! If the file opened successfully execute the following
      //!
      //! \brief query
      //! \param address of the invoking class
      //! \return void
      QSqlQuery query(*this);
      //! QDebug statement
      qDebug() << "foreign_key enabled:" << query.exec("PRAGMA foreign_keys = 1;");
      qDebug() << "\n\nThe database is open\n\n";
  }


}

//! Destructor for the database
Database::~Database() {
    QSqlDatabase::close();
}

void Database::readFromRestaurantFile(const QString& FILE) {

    QFile inFile(FILE); // Input file
    QSqlQuery query(*this);

    if(!inFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not read the input file" << endl << endl;
    }

    while(!inFile.atEnd()) {

        QString restaurantName = inFile.readLine().mid(30);

        restaurantName = restaurantName.mid(0, restaurantName.size() - 1);
//        qDebug() << restaurantName;

        QString tempRestaurantStr = restaurantName;
        tempRestaurantStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
        tempRestaurantStr = tempRestaurantStr.simplified();
        tempRestaurantStr.replace(" ", "");

        QString createDistances = "CREATE TABLE ?_Distances (RestaurantNum TEXT, Distance REAL);";
        createDistances.replace("?", tempRestaurantStr);

        query.prepare(createDistances);
//        qDebug() << "Create Distances: " << query.exec();
        query.exec();

        QString createMenu = "CREATE TABLE ?_Menu (itemName TEXT, price REAL);";
        createMenu.replace("?", tempRestaurantStr);

        query.prepare(createMenu);
//        qDebug() << "Create Menu: " << query.exec();
        query.exec();

        QString restaurantNumber = inFile.readLine().mid(28);
        restaurantNumber.replace(QRegExp("\\s"), "");

        query.prepare("INSERT INTO MASTER VALUES(?, ?);");
        query.bindValue(0, restaurantNumber);
        query.bindValue(1, restaurantName);
//        qDebug() << "Insert Into Master: " << query.exec();
        query.exec();


        QString distToRest = inFile.readLine().mid(50);
        distToRest.replace(QRegExp("\\s"), "");

        for(int i = 0; i < 10; i++) {
            QString inputDistance = inFile.readLine().mid(2);

            inputDistance.replace(QRegExp("\\s"), "");
            inputDistance = QString::number(inputDistance.toFloat(), 'f', 2);

            QString addDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
            addDistance.replace(":name", tempRestaurantStr);
            addDistance.replace(":num", QString::number(i + 1));
            addDistance.replace(":dist", inputDistance);

            query.prepare(addDistance);
//            qDebug() << "Add Distance: " << query.exec();
            query.exec();

        }

        QString distToSad = inFile.readLine();
        distToSad.replace(QRegExp("[A-Za-z\\s]"), "");
        distToSad = QString::number(distToSad.toFloat(), 'f', 2);

        query.prepare("INSERT INTO Saddleback_Distances VALUES(?, ?);");
        query.bindValue(0,restaurantNumber);
        query.bindValue(1, distToSad);
//        qDebug() << "Insert into Saddleback: " << query.exec();
        query.exec();

        QString numItems = inFile.readLine();
        numItems.replace(QRegExp("[A-Za-z\\s]"), "");

        for(int i = 0; i < numItems.toInt(); i++) {
            QString itemName = inFile.readLine();
            itemName = itemName.mid(0, itemName.size() - 1);

            QString itemPrice = QString(inFile.readLine()).replace(QRegExp("\\s"), "");

            QString addMenu = "INSERT INTO `:name_Menu` VALUES(':item', ':price');";
            addMenu.replace(":name", tempRestaurantStr);
            addMenu.replace(":item", itemName);
            addMenu.replace(":price", itemPrice);

            query.prepare(addMenu);
//            qDebug() << "Add Menu: " << query.exec();
            query.exec();
//            qDebug() << query.lastError().text();
        }

        inFile.readLine();

    }


}

void Database::ReadFromNewFile() {

    QFile inFile("./assets/new_restaurants.txt"); // Input file
    QSqlQuery query(*this);

    if(!inFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not read the input file" << endl << endl;
    }
    int k = 0;
    while(!inFile.atEnd()) {

        QString restaurantName = inFile.readLine().mid(30);
        restaurantName = restaurantName.mid(0, restaurantName.size() - 1);
        qDebug() << restaurantName;

        QString tempRestaurantStr = restaurantName;
        tempRestaurantStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
        tempRestaurantStr = tempRestaurantStr.simplified();
        tempRestaurantStr.replace(" ", "");

        QString createDistances = "CREATE TABLE ?_Distances (RestaurantNum TEXT, Distance REAL);";
        createDistances.replace("?", tempRestaurantStr);
        query.prepare(createDistances);
        qDebug() << "Create Distances: " << query.exec();

        QString createMenu = "CREATE TABLE ?_Menu (itemName TEXT, price REAL);";
        createMenu.replace("?", tempRestaurantStr);
        query.prepare(createMenu);
        qDebug() << "Create Menu: " << query.exec();

        QString restaurantNumber = inFile.readLine().mid(28);
        restaurantNumber.replace(QRegExp("\\s"), "");

        query.prepare("INSERT INTO MASTER VALUES(?, ?);");
        query.bindValue(0, restaurantNumber);
        query.bindValue(1, restaurantName);
        qDebug() << "Insert Into Master: " << query.exec();

        QString distToRest = inFile.readLine().mid(50);
        distToRest.replace(QRegExp("\\s"), "");

        for(int i = 0; i < 12; i++) {
            QString inputDistance = inFile.readLine().mid(2);
            inputDistance.replace(QRegExp("\\s"), "");
            inputDistance = QString::number(inputDistance.toFloat(), 'f', 2);

            QString addDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
            addDistance.replace(":name", tempRestaurantStr);
            addDistance.replace(":num", QString::number(i + 1));
            addDistance.replace(":dist", inputDistance);
            query.prepare(addDistance);
            qDebug() << "Add Distance: " << query.exec();

            query.prepare("select restaurantName FROM Master where restaurantNum = ?;");
            query.bindValue(0, i + 1);
            qDebug() << query.exec();

            QString test;
            while (query.next()) {

                qDebug() << "Inside while";
                test = query.value(0).toString();

            }

            test.remove(QRegExp("[^a-zA-Z\\d\\s]"));
            test = test.simplified();
            test.replace(" ", "");
            qDebug() << endl << test << endl;

            if(k == 0) {

                QString addNewDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
                addNewDistance.replace(":name", test);
                addNewDistance.replace(":num", QString::number(11));
                addNewDistance.replace(":dist", inputDistance);
                qDebug() << "Add New Distance: " << addNewDistance;
                query.prepare(addNewDistance);
                qDebug() << "Add New Distance: " << query.exec();

            } else if(k == 1) {

                if(inputDistance != "3.70"){
                    QString addNewDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
                    addNewDistance.replace(":name", test);
                    addNewDistance.replace(":num", QString::number(12));
                    addNewDistance.replace(":dist", inputDistance);
                    qDebug() << "Add New Distance: " << addNewDistance;
                    query.prepare(addNewDistance);
                    qDebug() << "Add New Distance: " << query.exec();
                }

            }
        }

        QString distToSad = inFile.readLine();
        distToSad.replace(QRegExp("[A-Za-z\\s]"), "");
        distToSad = QString::number(distToSad.toFloat(), 'f', 2);
        query.prepare("INSERT INTO Saddleback_Distances VALUES(?, ?);");
        query.bindValue(0,restaurantNumber);
        query.bindValue(1, distToSad);
        qDebug() << "Insert into Saddleback: " << query.exec();

        QString numItems = inFile.readLine();
        numItems.replace(QRegExp("[A-Za-z\\s]"), "");

        for(int i = 0; i < numItems.toInt(); i++) {

            QString itemName = inFile.readLine();
            itemName = itemName.mid(0, itemName.size() - 1);
            QString itemPrice = QString(inFile.readLine()).replace(QRegExp("\\s"), "");
            QString addMenu = "INSERT INTO :name_Menu VALUES(':item', :price);";
            addMenu.replace(":name", tempRestaurantStr);
            addMenu.replace(":item", itemName);
            addMenu.replace(":price", itemPrice);
            query.prepare(addMenu);
            qDebug() << "Add Menu: " << query.exec();
            qDebug() << query.lastError().text();

        }

        k++;
        inFile.readLine();
    }
}

unsigned short Database::getNumRestaurants() const {
    QSqlQuery query(*this);

    query.exec("SELECT COUNT(*) FROM `Master`;");

    query.first();

    return query.value(0).toInt();
}

std::vector<QString> Database::getRestaurantNames() const {
    QSqlQuery query(*this);

    std::vector<QString> names;

    query.exec("SELECT `restaurantName` FROM `Master`;");

    while(query.next())
        names.push_back(query.value(0).toString());

    return names;
}

std::vector<std::pair<QString, float> > Database::getRestaurantMenu(const QString& RESTAURANT) const {
    QSqlQuery query(*this);

    std::vector<std::pair<QString, float> > menu;

    query.exec(QString("SELECT `itemName`, `price` FROM `%1_Menu`;").arg(cleanStr(RESTAURANT)));

    while(query.next())
        menu.push_back(std::make_pair(query.value(0).toString(), query.value(1).toFloat()));

    return menu;
}

bool Database::isEmpty() const {
    return getNumRestaurants() == 0;
}

QString Database::cleanStr(QString in) const {
    in = in.simplified();
    in.replace(" ", "");
    in.replace("-", "");
    in.replace("\'", "");
    return in;
}

bool Database::hasBeenVisited(QString name, const std::queue<std::pair<QString, float> >& Q) {
    std::queue<std::pair<QString, float> > copy(Q);

    while(!copy.empty()) {
        if(std::get<0>(copy.front()) == name)
            return true;
        copy.pop();
    }

    return false;
}

bool Database::isInRestaurants(const QString &name, const std::vector<QString> &restaurants) {
    for(auto itr = restaurants.begin(); itr<restaurants.end(); ++itr) {
        if(cleanStr(*itr) == cleanStr(name)) {
            return true;
        }
    }
    return false;
}

void Database::removeFromVec(QString name, std::vector<QString>& vec) {
    for(auto itr = vec.begin(); itr < vec.end(); ++itr) {
        if(*itr == name) {
            vec.erase(itr);
            return;
        }
    }
}

std::queue<std::pair<QString, float> > Database::getFullTrip(std::vector<QString> restaurants) {
    //Return objects
    std::queue<std::pair<QString, float> > tripQueue;

    //Method objects
    QSqlQuery query(*this);

    //Starting from Saddleback Query
    QString executable = QString("SELECT `restaurantName`, `distance` FROM `Master`, `Saddleback_Distances` ") +
                         QString("WHERE `Master`.`restaurantNum` = `Saddleback_Distances`.`restaurantNum` ORDER BY `distance` ASC LIMIT 1;");

    if(query.exec(executable)) {
        query.first();
        QString restaurant = query.value(0).toString();

        std::pair<QString,float> restaurantPair;
        restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
        tripQueue.push(restaurantPair);

        removeFromVec(restaurant, restaurants);

        while(!restaurants.empty()) {

            executable = QString("SELECT `restaurantName`, `distance` FROM `Master`,`%1_Distances` WHERE `Master`.`restaurantNum` = `%1_Distances`.`restaurantNum` ORDER BY `distance`;").arg(cleanStr(restaurant));

            if(query.exec(executable)) {

                query.next();
                restaurant = query.value(0).toString();

                while(hasBeenVisited(restaurant, tripQueue)) {
                    query.next();
                    restaurant = query.value(0).toString();
                }

                restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
                tripQueue.push(restaurantPair);

                removeFromVec(restaurant, restaurants);
            }
        }
    }

    return tripQueue;
}

std::queue<std::pair<QString, float> > Database::getCustomTrip(std::vector<QString> restaurants) {
    //Return objects
    std::queue<std::pair<QString, float> > tripQueue;

    //Method objects
    QSqlQuery query(*this);
    QString executable;

    //First Query
    executable = QString("SELECT `restaurantName`, `distance` FROM `Master`, `Saddleback_Distances` ") +
                 QString("WHERE `Master`.`restaurantNum` = `Saddleback_Distances`.`restaurantNum` ORDER BY `distance` ASC;");

    if(query.exec(executable)) {
        query.first();
        QString restaurant;
        std::pair<QString,float> restaurantPair;

        restaurant = query.value(0).toString();

        //While has been visited or isn't in restaurants
        if(!isInRestaurants(restaurant,restaurants)) {
            while(query.next()) {
                restaurant = query.value(0).toString();
                if(isInRestaurants(restaurant,restaurants))
                    break;
            }
        }

        restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
        tripQueue.push(restaurantPair);

        removeFromVec(restaurant, restaurants);

        while(!restaurants.empty()) {

            executable = QString("SELECT `restaurantName`, `distance` FROM `Master`,`%1_Distances` WHERE `Master`.`restaurantNum` = `%1_Distances`.`restaurantNum` ORDER BY `distance`;").arg(cleanStr(restaurant));

            if(query.exec(executable)) {

                query.first();
                restaurant = query.value(0).toString();

                //While has been visited and is in restaurants
                if(!isInRestaurants(restaurant,restaurants)) {
                    while(query.next()) {
                        restaurant = query.value(0).toString();
                        if(isInRestaurants(restaurant,restaurants))
                            break;
                    }
                }

                restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
                tripQueue.push(restaurantPair);

                removeFromVec(restaurant, restaurants);
            }
        }
    }

    return tripQueue;
}

std::queue<std::pair<QString, float> > Database::getStartTrip(QString startingPoint, int restToVisit){
    //Return objects
    std::queue<std::pair<QString, float> > tripQueue;
    std::vector<QString> restaurants = getRestaurantNames();

    //Method objects
    QSqlQuery query(*this);
    QString executable;

    //Query if has starting point
    executable = QString("SELECT `restaurantName`, `distance` FROM `Master`,`Saddleback_Distances` WHERE `Master`.`restaurantNum` = `Saddleback_Distances`.`restaurantNum` AND `Master`.`restaurantName` LIKE \"\%" + startingPoint + "\%\";");

    if(query.exec(executable)) {
        query.first();
        QString restaurant;
        std::pair<QString,float> restaurantPair;

        restaurant = query.value(0).toString();
        restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
        tripQueue.push(restaurantPair);

        removeFromVec(restaurant, restaurants);
        --restToVisit;

        while(!restaurants.empty() && restToVisit > 0) {

            executable = QString("SELECT `restaurantName`, `distance` FROM `Master`,`%1_Distances` WHERE `Master`.`restaurantNum` = `%1_Distances`.`restaurantNum` ORDER BY `distance`;").arg(cleanStr(restaurant));

            if(query.exec(executable)) {

                query.next();
                restaurant = query.value(0).toString();

                //While has been visited and is in restaurants
                while(hasBeenVisited(restaurant, tripQueue)) {
                    query.next();
                    restaurant = query.value(0).toString();
                }

                restaurantPair = std::make_pair(restaurant, query.value(1).toFloat());
                tripQueue.push(restaurantPair);

                removeFromVec(restaurant, restaurants);
                --restToVisit;
            }
        }
    }

    return tripQueue;
}







void Database::AddNewRestaurant(std::vector<std::pair<QString, float> > restInfo, QString restaurantName){
    int restCount = restInfo.size();
    QSqlQuery query(*this);
    std::vector<std::pair<QString, float> >::iterator it = restInfo.begin();


    // Simplifys the restaurant name
    QString tempRestaurantStr = restaurantName;
    tempRestaurantStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    tempRestaurantStr = tempRestaurantStr.simplified();
    tempRestaurantStr.replace(" ", "");

    // Creates a new distances table
    QString createDistances = "CREATE TABLE ?_Distances (RestaurantNum TEXT, Distance REAL);";
    createDistances.replace("?", tempRestaurantStr);
    query.prepare(createDistances);
    qDebug() << "Create new distances table table: " << query.exec();

    // Creates a new menu table
    QString createMenu = "CREATE TABLE ?_Menu (itemName TEXT, price REAL);";
    createMenu.replace("?", tempRestaurantStr);
    query.prepare(createMenu);
    qDebug() << "Create new menu table table: " << query.exec();

    // Adds the restaurant to the master table
    QString restaurantNumber = QString::number(restInfo.size() + 1);
    restaurantNumber.replace(QRegExp("\\s"), "");
    query.prepare("INSERT INTO MASTER VALUES(?, ?);");
    query.bindValue(0, restaurantNumber);
    query.bindValue(1, restaurantName);
    qDebug() << "Add to master table: " << query.exec();

    // Places the values inside of the distances table for the new restaurant
    int i = 0;
    for(it = restInfo.begin(); it < restInfo.end(); it++) {
        QString inputDistance = QString::number(it->second);

        QString addDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
        addDistance.replace(":name", tempRestaurantStr);
        addDistance.replace(":num", QString::number(i + 1));
        addDistance.replace(":dist", inputDistance);
        query.prepare(addDistance);
        qDebug() << "Add Distance: " << query.exec();

        i++;
    }

    // Inserts the distance from saddleback into the saddleback distances table
    query.prepare("INSERT INTO Saddleback_Distances VALUES(?, ?);");
    query.bindValue(0,restaurantNumber);
    query.bindValue(1, restInfo.front().second);
    qDebug() << "Insert into Saddleback: " << query.exec();


    int j = 0;
    for(it = restInfo.begin(); it < restInfo.end(); it++){
        QString inputDistance = QString::number(it->second);

        // Get the restaurantName from the master table
        query.prepare("SELECT restaurantName FROM Master where restaurantNum = ?;");
        query.bindValue(0, j + 1);
        qDebug() << "Select restaurantName: " << query.exec();
        QString test;
        while (query.next()) {

            qDebug() << "Inside while";
            test = query.value(0).toString();

        }
        test.remove(QRegExp("[^a-zA-Z\\d\\s]"));
        test = test.simplified();
        test.replace(" ", "");
        qDebug() << endl << test << endl;


        // Add the new distances to all of the restaurants
        QString addNewDistance = "INSERT INTO :name_Distances VALUES(:num, :dist);";
        addNewDistance.replace(":name", test);
        addNewDistance.replace(":num", restaurantNumber);
        addNewDistance.replace(":dist", QString::number(it->second));
        qDebug() << "Add New Distance: " << addNewDistance;
        query.prepare(addNewDistance);
        qDebug() << "Add New Distance: " << query.exec();

    }

}





void Database::AddMenuItem(QString restaurantName, QString itemName, QString itemPrice){
    QSqlQuery query(*this);
    // Simplifys the restaurant name
    QString tempRestaurantStr = restaurantName;
    tempRestaurantStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    tempRestaurantStr = tempRestaurantStr.simplified();
    tempRestaurantStr.replace(" ", "");

    QString addMenu = "INSERT INTO :name_Menu VALUES(':item', :price);";
    addMenu.replace(":name", tempRestaurantStr);
    addMenu.replace(":item", itemName);
    addMenu.replace(":price", itemPrice);
    query.prepare(addMenu);
    qDebug() << "Add Menu: " << query.exec();

}

void Database::DeleteMenuItem(QString restaurantName, QString itemName){
    QSqlQuery query(*this);
    // Simplifys the restaurant name
    QString tempRestaurantStr = restaurantName;
    tempRestaurantStr.remove(QRegExp("[^a-zA-Z\\d\\s]"));
    tempRestaurantStr = tempRestaurantStr.simplified();
    tempRestaurantStr.replace(" ", "");

    QString addMenu = "DELETE FROM :name_Menu WHERE itemName = :item;";
    addMenu.replace(":name", tempRestaurantStr);
    addMenu.replace(":item", itemName);
    query.prepare(addMenu);
    qDebug() << "Add Menu: " << query.exec();
}


















