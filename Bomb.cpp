/*****************************************
** File:    Bomb.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Bomb.cpp file for Project 4.
** This program reads the Bomb.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/

#include "Bomb.h"


// Bomb-Default Constructor
// Creates a new bomb monkey
Bomb::Bomb():Monkey("Bomb",1,0){}

// Bomb(string type, int  damage, int location)
// Can create a new Bomb monkey
Bomb::Bomb(string type, int damage, int location):Monkey(type, damage, location){}

//~Bomb - Virtual Destructor
// Makes sure everything in child class is deallocated
Bomb::~Bomb(){

}

// Attack
// Iterates through all bloons. Hits all bloons in same location as bomb. Returns total bloon health or damage (whichever is less) for earnings (money)
int Bomb::Attack(vector<Bloon*> bloons){

  int bombEarnings = 0; // earnings received from the pops of bloons  

  // loops through the m_bloobs vector
  for(unsigned int i = 0; i < bloons.size(); i++){

    // determines if the bloon's location and monkey's location are the same and if the bloon's health is greater than 0
    if(bloons.at(i)->GetLocation() == GetLocation() && bloons.at(i)->GetHealth() > 0){

      cout << "The bomb shooter launches a bomb!" << endl;
      
      int bombDamage = bloons.at(i)->Pop(GetDamage()); // retrieves the damage done by a bomb monkey
      
      bombEarnings += bombDamage; // increments the bombEarnings by bombDamage
      
    }
    
  }
   return bombEarnings;
}
	  
