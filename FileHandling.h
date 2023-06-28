#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <fstream>
#include <string>
// #include "GamePlay.h"
// #include "Map.h"
// #include "Player.h"

using namespace std;

class Map;                  // Forward declaration of Map class
class Player;               // Forward declaration of Player class

class FileHandling{
    private:
        fstream dataFile;
    public:
        void saveToFile(const string& filename, Map &map, Player &player);          // save the game to the file
        void loadFromFile(const string& filename, Map &map, Player &player);        // read or load the game from the file

        void displaySavingChoice();                                                 // display saving choice
        void handleSavingChoice(Map &map, Player &player, int &userSavingChoice);   // handle user choice, and call others function to save file

        void displayLoadingChoice();                                                // display loading choice
        void handleLoadingChoice(Map &map, Player &player, bool &loadSuccess);      // handle user choice, and call others function to load file

        bool checkFileContain(const string &filename);                              // check file contain, if is not empty, then will proceed to read the file
};

#endif