#include "GamePlay.h"
#include "Player.h"
#include "FileHandling.h"
#include "Map.h"
#include "Node.h"

#include <iostream>

using namespace std;

// print game menu
void GamePlay::printGameMenu() {
    cout << "Choose an action:" << endl;
    cout << "1. Move forward" << endl;
    cout << "2. Move backward" << endl;
    cout << "3. Jump over a step" << endl;
    cout << "4. Quit and save the game" << endl;
    cout << endl;
}

// Handle user choice and perform action accordingly
void GamePlay::handleUserChoice(Map &map, Player &player, FileHandling &file, int choice) {
    switch (choice) {
        case 1:
            player.moveForward(map);
            break;
        case 2:
            player.moveBackward(map);
            break;
        case 3:
            player.jumpOverNode(map);
            break;
        case 4:
            file.handleSavingChoice(map, player,choice);
            break;
        default:
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "|                              Invalid choice. Please try again.                                 |"<< endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
    }

    cout << endl;
}

// Ask user whether want to continue or exit, then return as boolean in main
bool GamePlay::retryOrQuit() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;

    while (choice != 1 && choice != 2) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "|                              Invalid choice. Please try again.                                 |"<< endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    }

    if (choice == 1) {
        return true;
    } else if (choice == 2) {
        return false;
    }

    // Default return statement (not reached if the input is valid)
    return false;
}

// take input from user
int GamePlay::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}

// run the normal new gameplay
void GamePlay::runGame(Map &map,Player &player, FileHandling &file) {
    player.setMercy(3);                     // reset the mercy back to original value
    if(map.getlevel() == 1){
        script.printGameIntro();
    }
    while(map.getlevel()!=4){
        switch (map.getlevel())
        {
            case 1:
                script.printChap1();
                break;
            case 2:
                script.printChap2();
                break;
            case 3:
                script.printChap3();
                break;
            default:
                break;
        }
        map.generateRandomList(map.getlevel());
        // map.printList();        // for developer check only
        player.setPlayerPosition(map.getHead());        // set player position to the first node
        player.checkStatus(map);                        // check for the map situation
        int choice;
        do {
            printGameMenu();
            choice = getUserChoice();
            handleUserChoice(map, player, file, choice);
            if (!player.isPlayerAlive()) {                  // when die, need to print retry 
                script.printRetry();
            }
            else if (player.finish(map)) {
                map.levelUp();
                if(map.getlevel() < 4){
                    script.printVictory(); 
                }
                else{                       // Only output if after the lvl3
                    script.printEnd();
                    cout << "DO you want to see the truth?" << endl;
                    cout << "Enter Y for yes, or any character to ignore the truth" << endl;
                    char pick;
                    cin >> pick;
                    if(pick == 'Y' || pick == 'y'){
                        script.printTruth();
                    }
                }
            }
        }while (choice != 4 && !player.finish(map) && player.isPlayerAlive() && map.getlevel()!=4);

        map.deleteMap();        // deleted whole map

        // if in game already want quit, can direct quit, or the level already complete, quit also
        if(choice == 4 || map.getlevel() == 4){
            break;
        }

        // to handle if win or lose, want continue or not
        if(!retryOrQuit()){
            // file.handleSavingChoice(map, player,choice);
            cout << "Your game will not be saved" << endl;
            cout << "back to main menu" << endl;
            break;
        }
        else{
            player.setForgetDie();          // remove the monster label on player, reset player status to nothing
            player.setMercy(3);             // reset mercy to initial value
        }
    }
}

void GamePlay::runLoadGame(Map &map,Player &player, FileHandling &file) {
    bool firstLoad = true;
    while(map.getlevel()!=4){
        switch (map.getlevel())
        {
            case 1:
                script.printChap1();
                break;
            case 2:
                script.printChap2();
                break;
            case 3:
                script.printChap3();
                break;
            default:
                break;
        }
        // if is the first time load back to this data, then need to print back last time saved position
        if(firstLoad){
            cout << "*************************************************************************************************"<< endl;
            cout << "                             The player's last saved position : " << player.getPlayerCoordinate() << endl;
            cout << "*************************************************************************************************"<< endl << endl;;
            firstLoad = false;
            // if is level 3, need to display mercy also
            if(map.getlevel()==3){
                cout << "*************************************************************************************************"<< endl;
                cout << "                             The player's last saved mercy : " << player.getMercy() << endl;
                cout << "*************************************************************************************************"<< endl << endl;;
            }
        }
        else{   // is not using the data from file, need regenerate the map
            map.generateRandomList(map.getlevel());
            player.setPlayerPosition(map.getHead());
        }
        // map.printList();         // developer mode
        player.checkStatus(map);
        int choice;
        
        do {
            printGameMenu();
            choice = getUserChoice();
            handleUserChoice(map, player, file, choice);        // perform the action based on user choice

            if (!player.isPlayerAlive()) {
                script.printRetry();
            } 
            else if (player.finish(map)) {
                map.levelUp();
                if(map.getlevel() < 4){
                    script.printVictory(); 
                }
                else{
                    script.printEnd();
                    cout << "DO you want to see the truth?" << endl;
                    cout << "Enter Y for yes, or any character to ignore the truth" << endl;
                    char pick;
                    cin >> pick;
                    if(pick == 'Y' || pick == 'y'){
                        script.printTruth();
                    }
                }
            }
        } while (choice != 4 && !player.finish(map) && player.isPlayerAlive());

        map.deleteMap();

        // if in game already want quit, can direct quit, or the level already complete, quit also
        if(choice == 4 || map.getlevel() == 4){
            break;
        }

        // to handle if win or lose, want continue or not
        if(!retryOrQuit()){
            cout << "Your game will not be saved" << endl;
            cout << "back to main menu" << endl;
            break;
        }
        else{
            player.setForgetDie();          // remove the monster label on player, reset player status to nothing
            player.setMercy(3);             // reset mercy to initial value
        }
    }
}