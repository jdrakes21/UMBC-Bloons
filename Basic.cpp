/*****************************************
** File:    Basic.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Basic.cpp file for Project 4.
** This program reads the Basic.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/

#include "Basic.h"

// Basic-Default Constructor
// Can create a new basic bloon
Basic::Basic(): Bloon() {

  // sets health to 1
  SetHealth(1);

  // sets the bloon's location to 0
  SetLocation(0);

  // sets the color of the bloon to red
  m_color = "red";

}

// Basic(int health, int location)
// Creates a new basic bloon with health at a specific location. If health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
Basic::Basic(int health, int location) : Bloon(health, location){

  // sets the health for a specific bloon
  SetHealth(health);

  // sets the location for a specific bloon
  SetLocation(location);

  
  switch(health){

  case 1:
    m_color = "red"; // color is red once the health is 1
    break;
    
  case 2:
    m_color = "blue"; // color is blue once the health is 2
    break;
    
  case 3:
    m_color = "green"; // color is green once the health is 3
    break;
    
  case 4:
    
    m_color = "yellow"; // color is yellow once the health is 4
    break;
    
  case 5:
    m_color = "pink"; // color is pink once the health is 5
    break;
    
  default:
    m_color = "black"; // color is black once the health is greater than or equal to 6
  }
}

//~Basic - Virtual Destructor
// Makes sure everything in child class is deallocated
Basic::~Basic(){


}

// Pop
// Changes the color of the bloon based on how many health it has left. red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
int Basic::Pop(int damage){
  

  int myPops = 0; // the number of pops 
  
  int remHealth = GetHealth() - damage; // the remaining health of the bloon once damage is done

  // determines if the health of the bloon is greater than or equal to the damage
  if(GetHealth() >= damage){
    
    myPops += damage; // myPops is incremented by the damage

  }else{
    
    myPops += GetHealth(); // myPops is incremented by the health
    
  }

  // the remHealth is set
  SetHealth(remHealth);

  // determines if the remaining health is less than or equal to 0
  if(remHealth <= 0){

    // the user is alerted that a specific bloon pops
    cout << "The " << m_color << " bloon pops!" << endl;

    // the user is informed that the bloon is now gone
    cout << "The bloon is now gone!" << endl;
    
    return myPops;

  }else{

    // the user is informated that a specific bloon pops
    cout << "The " << m_color << " bloon pops!" << endl;

    // determines if the remaining health is 1
    if(remHealth == 1){
      
      m_color = "red"; // the color is therefore red
                 
    }

    // determines if the remaining health is 2
    else if(remHealth == 2){
      
      m_color = "blue"; // the color is therefore then blue

      // deteermines if the remaining health is 3
    }else if(remHealth == 3){
      
      m_color = "green"; // the color is therefore then green

      // determines if the remaining health is 4
    }else if(remHealth == 4){
      
      m_color = "yellow"; // the color is then yellow

      // determines if the remaining health is 5
    }else if(remHealth == 5){
      
      m_color = "pink"; // the color is therefore then pink

      // determines if the remaining health is greater than or equal to 6
    }else if(remHealth >= 6){
      
      m_color = "black"; // the color is therefore then black
      
    }

    // the user is informed what color the bloon is now
    cout << "The bloon is now " << m_color << "." << endl;
     
  }
  
  return myPops;
}


// GetColor
// returns the current color of the bloon
string Basic::GetColor(){

  return m_color;
}


