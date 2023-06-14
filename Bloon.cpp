/*****************************************
** File:    Bloon.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Bloon.cpp file for Project 43.
** This program reads the Bloon.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/


#include "Bloon.h"

// Bloon-Default Constructor
// Abstract class - cannot directly instantiate this class
Bloon::Bloon(){
  
  m_health = 0;
  m_location = 0;
}

// Bloon(int health, int location) - Overloaded Constructor
// Abstract class - cannot directly instantiate this class
Bloon::Bloon(int health, int location){

  m_health = health;
  m_location = location;

}

// virtual ~Bloon - Virtual Destructor
// Makes sure everything in child class is deallocated
Bloon::~Bloon(){

}

// GetHealth
// returns health of bloon
int Bloon::GetHealth(){

  return m_health;
}

// SetHealth
// sets health of bloon
void Bloon::SetHealth(int health){

  m_health = health;

}

// GetLocation
// returns location of bloon
int Bloon::GetLocation(){

  return m_location;

}

// SetLocation
// sets location of bloon
void Bloon::SetLocation(int location){
  m_location = location;
}

// Overloaded <<
// prints the details of the bloon
ostream& operator<<(ostream& output, Bloon& B){

  // outputs the bloon's color and health.
  output << "Bloon:" << " " << B.GetColor() << " " << "Health:" << " " << B.GetHealth() << endl;

  return output;
}
