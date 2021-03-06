//
// Created by yarden95c on 08/12/16.
//

#ifndef EX3_MENU_H
#define EX3_MENU_H

#include <iostream>
#include <list>
#include "../both/Status.h"
#include "Map.h"
#include "TaxiCenter.h"
#include "../both/Color.h"
#include "../both/CarType.h"
#include "../both/LuxuryCab.h"
#include "../both/StandardCab.h"
#include "UdpServer.h"


class GameFlow {
private:
    Map *grid;
    TaxiCenter *taxiCenter;
    Socket *comm;
    int time;
    int portNo;

public:
    GameFlow(Map *map, int portNo);

    void establishCommunication();

    void startGame();

    void recieveDrivers();

    void insertARide();

    void insertAVehicle();

    void printDriverLocation();

    void moveTheClock();
    ~GameFlow();

};


#endif //EX3_MENU_H
