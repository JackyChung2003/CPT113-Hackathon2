#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Script.h"

class Map;              // Forward declaration of Map class
class Player;           // Forward declaration of Player class
class FileHandling;     // Forward declaration of FileHandling class

class GamePlay {
private:
    Script script;      // Composition of Script class
public:
    void printGameMenu();           // print game menu
    void handleUserChoice(Map &map, Player &player, FileHandling &file, int choice);        // take the user input and continue the action
    bool retryOrQuit();             // after die or finish the game, ask user whether want to continue or not                   
    int getUserChoice();            // take input from user

    void runGame(Map &map, Player &player, FileHandling &file);                     // run the new game
    void runLoadGame(Map &map, Player &player, FileHandling &file);                 // run the loaded game
};

#endif
