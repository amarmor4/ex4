//
// Created by moran on 03/12/16.
//

#ifndef TEST1_CAB_H
#define TEST1_CAB_H

#include <iostream>
#include <boost/serialization/access.hpp>
#include "Color.h"
#include "CarType.h"
#include "Point.h"
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
using namespace std;

/**
 * cab class.
 */
class Cab {
private:
    int cabId;
    double numOfKm;
    CarType carType;
    Color cabColor;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & cabId;
        ar & carType;
        ar & cabColor;

    }

public:
    Cab(int id = 0, CarType cabType = CarType(0) , Color color = Color(0));

    int getCabId();

    double getNumOfKm();

    CarType getCarType();

    Color getColor();

    virtual int getSpeed() = 0;

    //friend bool operator==(Cab cab1, Cab cab2);

    virtual ~Cab();

};

BOOST_SERIALIZATION_ASSUME_ABSTRACT(Cab)
#endif //TEST1_CAB_H
