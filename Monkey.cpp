/*****************************************
** File:    Monkey.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Monkey.cpp file for Project 4.
** This program reads the Monkey.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/

#include "Monkey.h"

// Monkey-Default Constructor
// Abstract class - cannot directly instantiate this class
Monkey::Monkey(){
  
  m_damage = 0;
  
  m_type = " ";
  
  m_location = 0;
}

// Monkey-Overloaded Constructor
// Abstract class - cannot directly instantiate this class
Monkey::Monkey(string type, int damage, int location){

  m_type = type;
  
  m_damage = damage;
  
  m_location = location;
}

// virtual ~Monkey - Virtual Destructor
// Makes sure everything in child class is deallocated
Monkey::~Monkey(){

}

// GetDamage
// returns the damage of a monkey
int Monkey::GetDamage(){

  return m_damage;
}

// GetType
// returns the type of monkey
string Monkey::GetType(){

  return m_type;
}

// GetLocation
// returns the location of a monkey
int Monkey::GetLocation(){

  return m_location;

}

// SetDamage
// Sets the damage of monkey
void Monkey::SetDamage(int damage){

  m_damage = damage;
}


// SetType
// Sets type of monkey (dart, bomb, or boomerang)
void Monkey::SetType(string type){

  m_type = type;
  
}

// SetLocation
// Sets location of monkey on track
void Monkey::SetLocation(int location){
  m_location = location;

}

// Overloaded <<
// Prints the details of a monkey
ostream& operator<<(ostream& output, Monkey& monkey){

  // the monkey's type =, location and damage is prnted 
  output << monkey.GetType() << " "  << "Monkey"<< ":" << " "  << "Location" << " " << monkey.GetLocation() + 1 << " " << "Damage: " <<  monkey.GetDamage() << endl; 

  return output;
}
  
