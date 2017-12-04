//
//  car.cpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#include "car.hpp"

Car::Car(string manufacturer, string type, int age){
    
    this->type = type;
    this->manufacturer = manufacturer;
    this->age = age;
    
}

string Car::get_type(){
    return this->type;
}
string Car::get_manufacturer(){
    return this->manufacturer;
}

int Car::get_age(){
    return this->age;
}

ostream& operator << (ostream& out, const Car& car){
    out << car.type << ", " << car.manufacturer << ", " << car.age << endl;
    return out;
}

