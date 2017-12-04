//
//  SalesmanUI.cpp
//  Bílasala
//
//  Created by Sigurður Sigurðsson on 04/12/2017.
//  Copyright © 2017 Sigurður Sigurðsson. All rights reserved.
//

#include "SalesmanUI.hpp"

void SalesmanUI::main_menu(){
    
cout << "Hi staff person" << endl;
    
    while(true) {
        
        cout << "Pick the number for the corresponding option" << endl;
        cout << "*********************************" << endl;
        cout << "1. Add a car" << endl;
        cout << "2. View cars" << endl;
        cout << endl;
        char input;
        cin >> input;
        validate_user_input(input);
    }

}

void SalesmanUI::validate_user_input(char input){
    if(input == '1'){
        car_service.add_car(create_car());
    }
    else if (input == '2'){
        cout << "viewing a car" << endl;
        cout << endl;
    }
    
    else{
        cout << "invalid input!" << endl;
        cout << endl;
        
    }
}

Car SalesmanUI::create_car(){
    string manufacturer, type;
    int age;
    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Type: ";
    cin >> type;
    cout << "Age of car: ";
    cin >> age;
    Car car(manufacturer, type, age);
    return car;
    
}
