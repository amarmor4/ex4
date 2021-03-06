//
// Created by yarden95c on 08/12/16.
//

#include "GameFlow.h"
#include "../both/Udp.h"

using namespace std;

/**
 * constractur of game flow.
 * @param map map of the city
 * @return nothing
 */
GameFlow::GameFlow(Map *map, int portNo1) {
    grid = map;
    taxiCenter = new TaxiCenter();
    comm = NULL;
    time = 0;
    portNo = portNo1;

}

/**
 * destractur
 */
GameFlow::~GameFlow() {
    delete (taxiCenter);
}

void GameFlow::establishCommunication() {
    comm = new Udp(true, portNo);
}

/**
 * menu optinos of program
 */
void GameFlow::startGame() {
    establishCommunication();
    comm->initialize();
    int choice;
    cin >> choice;
    while (choice != 7) {
        switch (choice) {
            case 1:
                this->recieveDrivers();
                break;
            case 2:
                this->insertARide();
                break;
            case 3:
                this->insertAVehicle();
                break;
            case 4:
                this->printDriverLocation();
                break;
            case 9:
                this->moveTheClock();
                this->sendClientNewLocation();
            default:
                break;
        }
        cin >> choice;
    }

    this->killTheClient();

}

void GameFlow::recieveDrivers() {
    int numOfDrivers;
    cin >> numOfDrivers;
    while (numOfDrivers > 0) {
        char buffer[9999];
        this->comm->reciveData(buffer, sizeof(buffer));
        Driver *d2;
        boost::iostreams::basic_array_source<char> device(buffer,
                                                          sizeof(buffer));
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s(
                device);
        boost::archive::binary_iarchive ia(s);
        ia >> d2;
        cout << *d2->getCurrentLocation() << endl;
        this->taxiCenter->addDriverInfo(d2);
        numOfDrivers--;

        Cab* cab = this->taxiCenter->getDriver()->getCab();
        string serial_str;
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std
        ::string> > stream(inserter);
        boost::archive::binary_oarchive oa(stream);
        oa << cab;
        stream.flush();
        comm->sendData(serial_str);
        cout << serial_str << endl;
    }
}

/**
 * insert a new trip to the trips in the taxi center
 * trip doesn't have a driver yet, only in choice 6 we add a driver to
 * each trip
 */
void GameFlow::insertARide() {
    int id, xStart, yStart, xEnd, yEnd, numOfPassengers, startTime;
    double tariff;
    char c;
    cin >> id >> c >> xStart >> c >> yStart >> c >> xEnd >> c >> yEnd >> c
        >> numOfPassengers >> c >> tariff >> c >> startTime;
    Point *start = new Point(xStart, yStart);
    Point *end = new Point(xEnd, yEnd);
    Trip *trip = new Trip(grid, id, start, end, numOfPassengers, tariff,
                          startTime);
    taxiCenter->addTrip(trip);
    start = NULL;
    end = NULL;
    trip = NULL;
    // set the pointers to point on null so when
    // the objects will delete those pointers will no longer point on them
}

/**
 * insert a new vehicle to the cabs in the taxi center
 */
void GameFlow::insertAVehicle() {
    int id, taxiType;
    char manufacturerLetter, colorLetter, c;
    enum Color color;
    enum CarType carType;
    cin >> id >> c >> taxiType >> c >> manufacturerLetter >> c >> colorLetter;
    color = Color(colorLetter);
    carType = CarType(manufacturerLetter);
    if (taxiType == 1) {
        StandardCab *cab = new StandardCab(id, carType, color, 1);
        taxiCenter->addCab(cab);
        cab = NULL;
        // set the pointer to point on null so when
        // the object will delete this pointer will no longer point on it
    } else {
        LuxuryCab *cab = new LuxuryCab(id, carType, color, 1);
        taxiCenter->addCab(cab);
        cab = NULL;
        // set the pointer to point on null so when
        // the object will delete this pointer will no longer point on it
    }
}

/**
 *printing the currrent location of a specific driver
 */
void GameFlow::printDriverLocation() {
    vector<Driver *> v = taxiCenter->getDriversInfo();
    int driverId;
    cin >> driverId;
    for (vector<Driver *>::iterator it = v.begin(); it != v.end(); it++) {
        if ((*it)->getDriverId() == driverId) {
            cout << *((*it)->getCurrentLocation()) << endl;
        }
    }
}

/**
 * move the clock + 1
 * check with all the trips, if it is their start time, connect them to a driver
 * if their time passed make them to move one step
 */
void GameFlow::moveTheClock() {
    time++;
    vector<Trip *> trips = taxiCenter->getTrips();
    vector<Driver *> drivers = taxiCenter->getDriversInfo();
    for (int i = 0; i < trips.size(); i++) {
        if (trips[i]->getStartTime() == time) {
            for (int j = 0; j < drivers.size(); j++) {
                if (drivers[j]->isAvailable() &&
                        drivers[j]->getCurrentLocation()->equals(
                        *trips[i]->getStartPoint())) {
                    trips[i]->setDriver(drivers[j]);
                }
            }
        }
        if (trips[i]->getStartTime() <= time) {

            trips[i]->moveOneStep();
        }
    }
}

void GameFlow::sendClientNewLocation() {
    Point *newLocation = this->taxiCenter->getDriver()->getCurrentLocation();
    string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(
            inserter);
    boost::archive::binary_oarchive oa(s);
    oa << newLocation;
    s.flush();
    comm->sendData(serial_str);
    cout << serial_str << endl;
    cout << *newLocation << endl;

}

void GameFlow::killTheClient() {
    Point *newLocation = NULL;
    string serial_str;
    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(
            inserter);
    boost::archive::binary_oarchive oa(s);
    oa << newLocation;
    s.flush();
    comm->sendData(serial_str);
    cout << serial_str << endl;
    //cout << *newLocation << endl;


}