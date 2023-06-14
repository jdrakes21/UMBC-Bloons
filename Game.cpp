/*****************************************
** File:    Game.cpp
** Project: CMSC 202 Project 4, Spring 2023
** Author:  Jervon Drakes
** Date:    4/19/23
** Section: 44
** E-mail:  jdrakes1@umbc.edu
**
** This file contains the Game.cpp file for Project 4.
** This program reads the Game.h file and its functions and
** executes those functions to implement proj4.cpp
**
**
**
***********************************************/
#include "Game.h"

// Game(Default Constructor)
// Creates a new Game and populates money, round, and health
Game::Game(){

  m_curRound = START_ROUND;
  m_curMoney = START_MONEY;
  m_curLife = START_LIFE;

}

//~Game(Destructor)
// Deallocates anything dynamically allocated in memory
Game::~Game(){

  // loops through the m_bloons vector and deallacotes dynamically allocated memory
  for(unsigned int i = 0; i < m_bloons.size(); i++){
    delete m_bloons.at(i);
  }

  // loops through the m_monkeys vector and deallocates dynamically memory
  for(unsigned int i = 0; i < m_monkeys.size(); i++){
    delete m_monkeys.at(i);
  }

}

//PrintMap
//For each location on the map outputs the bloons and monkeys (or none)
void Game::PrintMap(){

 
  for(int i = 0; i < PATH_LENGTH; i++){

    // prints the specific location for monkeys and bloons
    cout <<  "**" << "Location" << " " << i + 1 << "**" << endl;
    int counter = 1;
 
    bool monkeyHere = false ; // variable initialized to determine if any monkeys exist
    
    cout << "--Monkeys--" << endl;

    
    for(unsigned int j = 0; j < m_monkeys.size(); j++){
      
      // conditional to determine if the location of the monkey matches a location in the map
      if(m_monkeys.at(j)->GetLocation() == i ){

	monkeyHere = true;  // once met monkeyHere is assigned a value of true
	
	cout << counter << ". ";

	// the monkeys at that location is printed
	cout << *m_monkeys.at(j);

	counter++;
      }
    }
    

    // conditional to determine if any monkeys exists
    if(!monkeyHere){

      cout << "None" << endl;
    }
    
    
    bool bloonHere = false; // variable initialized to determine if any bloons exist

    cout << "<<Bloons>>" << endl;
    
    for(unsigned int j = 0; j < m_bloons.size(); j++){

      // conditional to determine if the location of the bloon  matches a location in the map
      if(m_bloons.at(j)->GetLocation() == i){

	
	bloonHere = true; // once met bloonHere is assigned a value of true

	// bloons at that location are printed
	cout  << *m_bloons.at(j);
	
      }
    }

    // conditional to determine if any bloons exist
    if(!bloonHere){
      
      cout << "None" << endl;
    }
    cout << endl;
  }
}
  
// ImproveMonkey
// Asks the user which monkey they would like to improve and increases chose monkey's damage
void Game::ImproveMonkey(){


  // conditional to determine if the size of the monkey vector is 0
  if(m_monkeys.size() == 0){
    
    cout << "No monkeys to improve" << endl;
    return;
  }

  // conditional to determine if there is enough money to improve a monkey
  if(m_curMoney < COST_IMPROVE){    
    cout << "Not enough money to improve any monkey " << endl;
    return;
  }
  
  int userChoice;

  do{
    
    cout << "Which monkey would you like to improve" << "(1" << "-" << m_monkeys.size() << ")? " << endl;

    // loops through the m_monkeys vector and prints out the respective information for the monkeys available
    for(unsigned int i = 0; i < m_monkeys.size(); i++){
      
    cout << i + 1 << "." << " " << m_monkeys.at(i)->GetType() << " " << "Monkey" << " " << "Location" << " " << m_monkeys.at(i)->GetLocation() + 1 << " " << "Damage:" << " " << m_monkeys.at(i)->GetDamage() << endl;
    
    }
  cin >> userChoice;

  // the above is continuously printed if the user's choice meets these conditions
  }while( userChoice < 1 || userChoice > int (m_monkeys.size()));


  // the damage of the monkey chose is improved
  m_monkeys[userChoice - 1]->SetDamage(m_monkeys[userChoice - 1]->GetDamage() + IMPROVE_VALUE);
   
 
  m_curMoney -= COST_IMPROVE; // the money available to the user is decreased

  cout << m_monkeys[userChoice - 1]->GetType() << " "  << "in position" << " " << userChoice << " " << "improved!" << endl;

}

// BuyMonkey
// Asks the user which monkey they wish to buy and decreases the money available and places the monkey in a location
void Game::BuyMonkey(){

  
  int monkeyChoice; // the monkey bought by the user
  int buyChoice = 4;
  
  do{
    cout << "What type of  monkey would you like to buy?" << endl;
    
    cout << "1. Dart Monkey" << endl;
    
    cout << "2. Boomerang Monkey" << endl;
    
    cout << "3. Bomb Monkey" << endl;
    
    cout << "4. Cancel" << endl;
    cin >> monkeyChoice;

    // the above is continuously printed once the choice of the user meets the conditions
  }while(monkeyChoice < 1 || monkeyChoice > buyChoice);


  
  switch(monkeyChoice){

  
  case 1:

    // conditional to determine if the money available can purchase a dart
  if(m_curMoney >= COST_DART){

    m_curMoney -= COST_DART; // once met the money available is decreased by the cost of a dart

    // a new dart is also placed within at a specific location
    PlaceMonkey(monkeyChoice);
  }else{

    // otherwise the user is alerted that they do not have enough money to buy a dart monkey
    cout << "You do not have enough money to purchase a Dart monkey" << endl;
  }
  break;
  
  case 2:

    // conditional to determine if the money available can purchase a boomerang
  if(m_curMoney >= COST_BOOMERANG){

    m_curMoney -= COST_BOOMERANG; // once met the money available is decreased by the cost of a boomerang

    // a new boomerang monkey is placed at a specific location
    PlaceMonkey(monkeyChoice);
  }else{

    // otherwise the user is alerted that they do not have enough money to buy a boomerang monkey
    cout << "You do not have enough money to purchase a Boomerang monkey" << endl;
  }
  
  break;
  
  case 3:

    // conditional to determine if the money available can purchase a bomb
  if(m_curMoney >= COST_BOMB){

    m_curMoney -= COST_BOMB; // once met the monkey available is decreased by the cost of a bomb

    // a new bomb monkey is placed at a specific location
    PlaceMonkey(monkeyChoice);
    
  }else{

    // otherwise the user is alerted that they do not have enough money to buy a bomb monkey
    cout << "You do not have enough money to purchase a Bomb monkey" << endl;

  }
  
  break;

  case 4:

    // conditional to determine if the user decides to not purchase a monkey
  if(monkeyChoice == 4){
    
    return;
  }
 
  }
}

// PlaceMonkey
// Based on the monkey purchased in BuyMonkey asks user where to place the monkey.Dynamically allocates new monkey and populates location and adds to m_monkey
void Game::PlaceMonkey(int choice){
  int monkeyLocation;

  do{
    
    cout << "Where would you like to place your new monkey" << " " << "(1-" << PATH_LENGTH << ")?" << endl;
    cin >> monkeyLocation;

    // the above is continuously outputted once the location entered meets the conditions
  }while(monkeyLocation < 1 || monkeyLocation > PATH_LENGTH);

  // a new Monkey object is created
  Monkey *userMonkey;
  

  // condtional to determine if the monkey bought is Dart
  if(choice == 1){

    userMonkey = new Dart("Dart", DAMAGE_DART, monkeyLocation - 1); // a new Dart monkey is created to be placed at a location
    
    cout << "New Dart monkey placed in location" << " " << monkeyLocation << endl;

    // conditional to determine if the monkey bought is Boomerang  
  }else if( choice == 2){

    userMonkey = new Boomerang("Boomerang", DAMAGE_BOOM, monkeyLocation - 1); // a new Boomerang monkey is created to be placed at a specific location
    
    cout << "New Boomerang monkey placed in location" << " " << monkeyLocation << endl;

    // contional to determine if the monkey bought is Bomb
  } else if( choice == 3){

    userMonkey = new Bomb("Bomb", DAMAGE_BOMB, monkeyLocation - 1); // a new Bomb monkey is created to be placed at a specific location
    
    cout << "New Bomb Monkey placed in location" << " " << monkeyLocation << endl;
  }

  // monkeys of any type is added to the m_monkeys vector
  m_monkeys.push_back(userMonkey);
}

// StartGame
// Welcomes the player to the game. Continually calls MainMenu until user quits
void Game::StartGame(){

  MainMenu();

}

// MainMenu
// Checks to see if player still has life. If m_curLife <= 0, game ends with loss. Display menu (View Map, Buy New Monkey, Improve Existing Monkey. Progress Round, Check Stats, or Quit).Calls function related to user choice.
int Game::MainMenu(){

  int choice = 0;
  int exitChoice = 6;

  cout << "Welcome to UMBC Bloons!" << endl;

  // once the user's choice is not 6 which signals to quit the program continues running
  while(choice != 6){
    do{

      // conditional to the determine if user has no life remaining
      if(m_curLife <= 0 ){

	// once met the user is alerted that the game has finished
	cout << "Sorry, you have lost the game." << endl;
	choice = exitChoice;
      }

      // conditional to determine if the user's choice is the exitChoice
      if(choice != exitChoice){

	// once  met the menu is printed where the user is asked what they wish to do
	cout << "What would you like to do?" << endl;
	
	cout << "1. View Map" << endl;
	
	cout << "2. Buy New Monkey" << endl;
	
	cout << "3. Improve Existing Monkey" << endl;
	
	cout << "4. Progress Round" << endl;
	
	cout << "5. Check Stats" << endl;
	
	cout << "6. Quit" << endl;
	cin >> choice;
      }

      // the above is continuously printed once the user's choice meets these conditions
    }while(choice > exitChoice || choice < 1);

    switch(choice){
    case 1:

      // once the choice is 1 the map is printed
      PrintMap();
      break;
      
    case 2:

      // once the choice is 2 the user can buy a monkey
      BuyMonkey();
      break;
      
    case 3:

      // once the choice is 3 the user can improve a monkey
      ImproveMonkey();
      break;
      
    case 4:

      // once the choice is 4 the user can play a round 
      PlayRound();
      break;
      
    case 5:

      // once the choice is 5 the stats for the game is shows
      Stats();
      break;
      
    case 6:

      // once the choice is 6 the game is finished and the user is thanked for playing
      cout << "Thanks for playing!" << endl;
      break;
    }
  }
  return choice;
}

// Stats
// Displays the information about the game (current round, number of monkeys, money, and lives left)
void Game::Stats(){

  cout << "**" << "CURRENT STATS" << "**" << endl;
  cout << "Current Round: " << m_curRound << endl;
  cout << "Monkeys Working: " << m_monkeys.size() << endl;
  cout << "Current Money: " << m_curMoney << endl;
  cout << "Current Life: " << m_curLife << endl;
}


// PlayRound
// Announces beginning and end of round. Calls PopulateBloons once then ResolveBattle once. Calls RemovePopped (5 times due to erase function). Calls MoveBloons once then calls CheckPath (5 times due to erase call)
void Game::PlayRound(){
  
  cout << "Starting Round" << " " << m_curRound << endl;

  // bloons are populated within a specific location
  PopulateBloons();

  // monkeys attack and cause damage to the bloons at a specific location
  ResolveBattle();

  for(int i = 0; i < 5; i++){

    // bloons popped are removed from the m_bloons vector
    RemovePopped();
  }

  // blooons that are still alive are moved one location down the path
  MoveBloons();

  for(int i = 0; i < 5; i++){

    CheckPath();
  }
  
  cout << "Round" << " " << m_curRound << " " << "completed" << endl;
  m_curRound++;
}


// PopulateBloons
// Each round, dynamically allocated bloons added to path in position START_BLOON. Bloons have a minimum of 1 health. For each round, the number of new bloons increases matching the round number. For example: Round 1 = 1 red bloon (health 1). Round 2 = 1 red bloon (health 1) and 1 blue bloon (health 2). Round 3 = 1 red (health 1) and 1 blue (health 2) and 1 green (health 3).Round 4 = 1 red, 1 blue, 1 green, and 1 yellow (health 4) and so forth. Notifies user that a new bloon (with color) has appeared.
void Game::PopulateBloons(){

  
  int bloonNumber = m_curRound; // assigns the number of bloons as the current round
  
  for(int i = 0; i < bloonNumber; i++){
    
    Bloon* gameBloon; // creates a new bloon
    
    gameBloon = new Basic(i + 1, START_BLOON);// creates a new basic bloon which will be placed at a location

    // the bloon is added the m_bloons vector
    m_bloons.push_back(gameBloon);
    
    cout << "A new" << " " << gameBloon->GetColor() << " " << "bloon appears!" << endl;
  }
}

// ResolveBattle
// Each monkey attacks the whole bloon vector. For each pop, curMoney is increased.
void Game::ResolveBattle(){

  // loops through the m_monkeys vector and attacks the bloons 
  for(unsigned int i = 0; i < m_monkeys.size(); i++){
    
    m_curMoney += m_monkeys[i]->Attack(m_bloons) * EARN_POP; // the amount of money is increased as bloons are popped
  }
}

// RemovedPopped
// Iterates through m_bloons and if health is <= 0, bloon is deallocated and removed from m_bloons
void Game::RemovePopped(){

  // loops through the m_bloons vector 
  for(unsigned int i = 0 ; i < m_bloons.size(); i++){

    // condtional to determinethe health of the bloon
    if(m_bloons.at(i)->GetHealth() <= 0){

      // bloon is deallocated and removed
      delete m_bloons[i];

      // bloon is erased at specific location
      m_bloons.erase(m_bloons.begin() + i);
      
      i = 0;
      
    }
  }
    
}

// MoveBloons
// For each bloon that still lives, it moves one location down the path
void Game::MoveBloons(){

  // loops through the m_bloons vector
  for(unsigned int i = 0; i < m_bloons.size(); i++){

    // determines the health of the bloon
    if(m_bloons.at(i)->GetHealth() > 0 ){

      int bloonLocation = m_bloons.at(i)->GetLocation(); // retrieved the location of a bloon

      // increments the bloon's location and essentially moves
      m_bloons.at(i)->SetLocation(bloonLocation + 1);
    }  
    
  }
  cout << "The bloons move along a path" << endl;

}

// CheckPath
// Iterates over m_bloons to see if location is equal to (or greater than)PATH_LENGTH. If location is equal to PATH_LENGTH, causes damage to player.Damage to player is one per health of bloon.If 10 green bloons (health 3) hit player, player takes 30 damage. Bloons that hurt player are deallocated and erased from m_bloons
void Game::CheckPath(){

  int genDamage = 0;

  // loops through the m_bloons vector
  for(unsigned int i = 0; i < m_bloons.size(); i++){

    // determines if the location of the bloon is greater than or equal to the PATH_LENGTH
    if(m_bloons.at(i)->GetLocation() >= PATH_LENGTH){
      
      genDamage += m_bloons.at(i)->GetHealth(); // the damage is incremented

      // user is alerted that a bloon made it to the end of the path and it took a specific damage
      cout << "A bloon made it the end of the path and you took" << " " << m_bloons.at(i)->GetHealth() << " damage" << endl;

      // bloon is deallocated
      delete m_bloons[i];

      // bloon is erased at specific location
      m_bloons.erase(m_bloons.begin() + i);
      i = 0;
    }
  }
  m_curLife -= genDamage; // the life availanle is decremented by the damage done

}

