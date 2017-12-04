//
//  CarRepository.cpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#include "CarRepository.hpp"

CarRepository::CarRepository(){
    
}

void CarRepository::add_car(const Car& car){
    
    ofstream fout;
    fout.open("cars.txt", ios::app);
    if(fout.is_open()){
        fout << car;
        fout.close();
    }
    else{
        /// throw error
    }
    
}

