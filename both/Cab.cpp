//
// Created by moran on 03/12/16.
//

#include "Cab.h"

/**
 * constractor.
 * @param id cab id.
 * @param km number of km.
 * @param cabType cab type.
 * @param color color of cab.
 * @return
 */
Cab::Cab(int id, enum CarType cabType, enum Color color){
    cabId=id;
    carType=cabType;
    cabColor=color;
}

/**
 * get cab id.
 * @return cab id.
 */
int Cab::getCabId(){
    return this->cabId;
}

/**
 * get number of km of cab.
 * @return number of km of cab.
 */
double Cab::getNumOfKm(){
    return this->numOfKm;
}

/**
 * get car type.
 * @return car type.
 */
CarType Cab::getCarType(){
    return this->carType;
}

/**
 * get color of cab.
 * @return color of cab.
 */
Color Cab::getColor(){
    return this->cabColor;
}

/**
 * destructor.
 */
Cab::~Cab(){

}
//bool operator==(Cab cab1, Cab cab2){
//    return cab1.getCabId() == cab2.getCabId()&&
//            cab1.getNumOfKm() == cab2.getNumOfKm()&&
//           cab1.getCarType()==cab2.getCarType() &&
//           cab1.getColor() == cab2.getColor();
//
//}