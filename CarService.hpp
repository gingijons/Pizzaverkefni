//
//  CarService.hpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#ifndef CarService_hpp
#define CarService_hpp

#include <stdio.h>

#include "car.hpp"
#include "CarRepository.hpp"
using namespace std;

class CarService{
public:
    CarService();
    void add_car(const Car& car);
    bool is_valid_car(const Car& car);
private:
    CarRepository car_repo;
    
};

#endif /* CarService_hpp */
