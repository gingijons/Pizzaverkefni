//
//  car.hpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#ifndef car_hpp
#define car_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Car {
    
public:
    Car(string manufacturer, string type, int age);
    string get_type();
    string get_manufacturer();
    int get_age();
    
    friend ostream& operator << (ostream& out, const Car& car);
    
private:
    string type;
    string manufacturer;
    int age;
    
};

#endif /* car_hpp */
