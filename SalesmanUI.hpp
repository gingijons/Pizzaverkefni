//
//  SalesmanUI.hpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#ifndef SalesmanUI_hpp
#define SalesmanUI_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "car.hpp"
#include "CarService.hpp"
using namespace std;

class SalesmanUI{
    
public:
    void main_menu();
    Car car(string type, string manufacturer, int age);
    
private:
    void validate_user_input(char input);
    CarService car_service;
    Car create_car();
};

#endif /* SalesmanUI_hpp */
