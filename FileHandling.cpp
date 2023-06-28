#include "FileHandling.h"
#include "Map.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;


void FileHandling::saveToFile(const string& filename, Map &map, Player &player) {
    dataFile.open(filename, ios::out);      // in output mode

    dataFile << map.getlevel() << endl;                     // save level first
    dataFile << player.getPlayerCoordinate() << endl;       // save player location
    if(map.getlevel()>2){
    	dataFile << player.getMercy() << endl;              // if level more than 2, save the current mercy value
	}

    Node* current = map.getHead();                      // point to head
    
    // save step and also monster
    while (current != nullptr) {
        dataFile << current->value << " ";
        dataFile << current->monsterType << endl;
        current = current->next;
    }
    cout << "Successful saved" << endl;
    dataFile.close();
}

void FileHandling::loadFromFile(const string& filename, Map &map, Player &player) {
    dataFile.open(filename, ios::in);      // in input mode
    
    // set everything to null first
    map.setHead(nullptr);
    map.setTail(nullptr);
    player.setPlayerPosition(nullptr);

    // load level and position of player
    int tempLevel;
    dataFile >> tempLevel;
    map.setlevel(tempLevel);
    dataFile.ignore();          // ignore newline character
    int position;
    dataFile >> position;
    dataFile.ignore();
    
    // load mercy
    if(map.getlevel()>2){
        int tempMercy;
    	dataFile >> tempMercy;
        player.setMercy(tempMercy);
    	dataFile.ignore();
	}

    int location;
    char monster;
    while (dataFile >> location) {
        Node *newNode = new Node;  // Create a new node for each location
        Node *nodePtr;
        newNode->value = location;
        newNode->next = nullptr;
        dataFile >> monster;
        newNode->monsterType = monster;
        dataFile.ignore();
        if (map.getHead() == nullptr) {
            map.setHead(newNode);
            map.setTail(newNode);
            }
            else {
                nodePtr = map.getTail();
                nodePtr->next = newNode;
                newNode->back = nodePtr;
                map.setTail(newNode);
            }
        //  Update the player's location if it matches the loaded location
        if(location == position){
            player.setPlayerPosition(newNode);
        }
    }
    dataFile.close();
}

void FileHandling::displaySavingChoice(){
    cout << endl;
    cout << "                                     Available Save Slots:             " << endl;
    cout << "                                         1. Slot 1                     " << endl;
    cout << "                                         2. Slot 2                     " << endl;
    cout << "                                         3. Slot 3                     " << endl;
    cout << "                                         4. Back to Main Menu          " << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "Your choice:";
}

void FileHandling::handleSavingChoice(Map &map, Player &player,int &userSavingChoice){
    displaySavingChoice();
    cin >> userSavingChoice;
    
    switch (userSavingChoice) {
        case 1:
            // Perform save operation for Slot 1
            cout << "Saving in Slot 1..." << endl;
            saveToFile("loadFile1.txt", map, player);
            break;
        case 2:
            // Perform save operation for Slot 2
            cout << "Saving in Slot 2..." << endl;
            saveToFile("loadFile2.txt", map, player);
            break;
        case 3:
            // Perform save operation for Slot 3
            cout << "Saving in Slot 3..." << endl;
            saveToFile("loadFile3.txt", map, player);
            break;
        case 4:
            // Go back to the game
            cout << "Going back to the game..." << endl;
            break;
    }
}

void FileHandling::displayLoadingChoice(){
    cout << endl;
    cout << "                                     Available Load Slots:             " << endl;
    cout << "                                         1. Slot 1                     " << endl;
    cout << "                                         2. Slot 2                     " << endl;
    cout << "                                         3. Slot 3                     " << endl;
    cout << "                                         4. Back to Main Menu          " << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
    cout << "Your choice:";
}

void FileHandling::handleLoadingChoice(Map &map, Player &player, bool &loadSuccess){
    
    int userLoadingChoice = 0;
    do{
        displayLoadingChoice();
        cin >> userLoadingChoice;
        
        switch (userLoadingChoice) {
            case 1:
                if(!checkFileContain("loadFile1.txt")){
                    // Perform load operation for Slot 1
                    cout << "Loading in Slot 1..." << endl;
                    loadFromFile("loadFile1.txt", map, player);
                    loadSuccess = true;      // to continue the game
                    break;
                }
                else{
                    cout << "It is a empty file. Please retry." << endl;
                    break;
                }
            case 2:
                if(!checkFileContain("loadFile2.txt")){
                    // Perform load operation for Slot 2
                    cout << "Loading in Slot 2..." << endl;
                    loadFromFile("loadFile2.txt", map, player);
                    loadSuccess = true;      // to continue the game
                    break;
                }
                else{
                    cout << "It is a empty file. Please retry." << endl;
                    break;
                }
            case 3:
                if(!checkFileContain("loadFile3.txt")){
                    // Perform load operation for Slot 3
                    cout << "Loading in Slot 3..." << endl;
                    loadFromFile("loadFile3.txt", map, player);
                    loadSuccess = true;      // to continue the game
                    break;
                }
                else{
                    cout << "It is a empty file. Please retry." << endl;
                    loadSuccess = false;
                    break;
                }
            case 4:
                // Go back to the game
                cout << "Going back to the main menu..." << endl;
                break;
            default:
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|                              Invalid choice. Please try again.                                 |"<< endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                loadSuccess = false;
                break;
        }
    }while(userLoadingChoice!=4 && loadSuccess!=true);
}

bool FileHandling::checkFileContain(const string &filename){
    fstream checkFile(filename);
    return checkFile.peek() == std::ifstream::traits_type::eof();
}


