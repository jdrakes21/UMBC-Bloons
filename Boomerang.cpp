/*****************************************
** File:    Boomerang.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Boomerang.cpp file for Project 4.
** This program reads the Boomerang.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/

#include "Boomerang.h"


// Boomerang-Default Constructor
// Creates a new Boomerang Monkey
Boomerang::Boomerang():Monkey("Boomerang",1,0){}


// Boomerang(string type, int damage, int location)
// Creates a new Boomerang Monkey
Boomerang::Boomerang(string type, int damage, int location):Monkey(type,damage,location){}


//~Boomerang - Virtual Destructor
// Makes sure everything in child class is deallocated
Boomerang::~Boomerang(){


}

// Attack
// Iterates through all bloons. For each bloon in the same location as boomerang, hits each bloon twice (once out and once back). Returns total bloon health or damage (whichever is less) for earnings (money)
int Boomerang::Attack(vector<Bloon*> bloons){

  
  int boomerangEarnings = 0; // earnings recived based on the damage done by a boomerang monkey
 
  // loops through the m_bloons vector
  for(unsigned int i = 0; i < bloons.size(); i++){

    // determines if the bloon's location is in the same location as the monkey and if the bloons health is greater than 0
    if(bloons.at(i)->GetLocation() == GetLocation() && bloons.at(i)->GetHealth() > 0){
      
      cout << "The boomerang monkey throws a boomerang!" << endl;

      int boomerangDamage = bloons.at(i)->Pop(GetDamage()); // variable determine the the damage the boomerang monkey does 
      
      boomerangEarnings += boomerangDamage; // increments boomerangEarnings by boomerangDamage
	
    }
  }
  
  for(unsigned int i = 0; i < bloons.size(); i++){

    if(bloons.at(i)->GetLocation() == GetLocation() && bloons.at(i)->GetHealth() > 0){

      int boomerangDamage = bloons.at(i)->Pop(GetDamage());
      boomerangEarnings += boomerangDamage;
      
    }
  }
  
  return boomerangEarnings;
}
