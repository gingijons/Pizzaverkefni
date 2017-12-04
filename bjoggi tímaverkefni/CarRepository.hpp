//
//  CarRepository.hpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#ifndef CarRepository_hpp
#define CarRepository_hpp

#include "car.hpp"
#include <fstream>
using namespace std;

class CarRepository{
public:
    CarRepository();
    void add_car(const Car& car);
private:
    
};
#endif /* CarRepository_hpp */
