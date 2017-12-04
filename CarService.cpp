//
//  CarService.cpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#include "CarService.hpp"


CarService::CarService(){
    
    
}

void CarService::add_car(const Car& car){
    car_repo.add_car(car);
        cout << car << endl;
    }

//bool CarService::is_valid_car(const Car& car){
    
//}

