/*****************************************
** File:    Dart.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Dart.cpp file for Project 4.
** This program reads the Dart.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/

#include "Dart.h"


// Dart-Default Constructor
// Creates a new Dart Monkey
Dart::Dart():Monkey("Dart",5,0){}

// Dart(string type, int damage, int location)
// Creates a new Dart Monkey
Dart::Dart(string type, int damage, int location):Monkey(type, damage, location){}

//~Dart - Virtual Destructor
// Makes sure everything in child class is deallocated
Dart::~Dart(){


}

// Attack
// Iterates through all bloons. Hits first bloon in the same location as dart. Returns total bloon health or damage (whichever is less) for earnings (money)
int Dart::Attack(vector<Bloon*> bloons){

  int dartEarnings = 0;// the earnings received based on the damage done by a dart monkey

  // loops through the m_bloons vector
  for(unsigned int i = 0; i < bloons.size(); i++){

    // determines if the bloon's location is the same as the monkey's location and if the health of the bloon is greater than 0
    if(bloons.at(i)->GetLocation() == GetLocation() && bloons.at(i)->GetHealth() > 0){

      cout << "The Dart monkey throws a dart!" << endl;
      
      int dartDamage = bloons.at(i)->Pop(GetDamage());//retrieves the damage done by the Dart monkey
      
      dartEarnings += dartDamage; //increments the dartEarnings by dartDamage
    }
  }
  
  return dartEarnings;
}
