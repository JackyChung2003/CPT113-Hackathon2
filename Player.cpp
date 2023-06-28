#include "Player.h"
#include "Node.h"
#include "Map.h"

#include <iostream>

using namespace std;

Player::Player() {
    playerPosition = nullptr;
    mercy = 3;
}

Node *Player::getPlayerPosition() const {
    return playerPosition;
}

void Player::setPlayerPosition(Node* newPosition) {
    playerPosition = newPosition;
}

int Player::getPlayerCoordinate() const {
    return playerPosition->value;
}

void Player::moveForward(Map &map) {
    Node* current = playerPosition;
    if(current->next){
        playerPosition = current->next;
        cout << "--You have moved forward.--" << endl;
    }

    else{
        cout << "No more road in front" << endl;    // wont face this issue
    }
    checkStatus(map);
}

void Player::setForgetDie(){
    playerPosition->monsterType = '-';      // to forget he been die cause by any monster
}

void Player::moveBackward(Map &map) {
    Node* current = playerPosition;
    
    if(current->back){
        playerPosition = current->back;
        cout << "--You have moved backward.--" << endl;         // dialog
        // when level 3 will recover the mercy
        if (map.getlevel()==3){
        	Mercy();
		}
    }
    else{
        script.printBackHit();                              // dialog
    }
    checkStatus(map);
}

void Player::jumpOverNode(Map &map) {
    Node* current = playerPosition;

    if (playerPosition && playerPosition->next) {
        // Jump over the node
        playerPosition = playerPosition->next->next;
        cout << "--You have successfully jumped over a step.--" << endl;
    }
    else {
        cout << "There is no step ahead to jump over." << endl;
    }

    if(current->next->monsterType == 'A'){
        script.printJumpMons();  // dialog
    }
    else{
        script.printJumpAir();   // dialog
    }
    checkStatus(map);
}

bool Player::isPlayerAlive() {
    if (playerPosition != nullptr && playerPosition->monsterType == 'A') { // indicate meet monster
        return false;
    }
    if (playerPosition == nullptr){
        script.printFell();            // dialog
        return false;
    }
    return true;
}

bool Player::finish(Map &map){
	if (playerPosition == map.getTail()){ // if head point to nullptr, the program broken.
		return true;
	}
	return false;
}

// Mercy Function
void Player::Mercy(){
	Node *nodePtr = nullptr;
    nodePtr = playerPosition;
    
	if (nodePtr->next != nullptr && nodePtr->next->monsterType == 'A'){
		cout << "Your mental bacomes weaker..." << endl;
		mercy--;
		if (mercy == 0){
			cout << "Due to the depressed condition, you totally go crazy. " << endl;
			cout << "You rush towards the doors in front of you, one by one without sensing whether there are anything ahead." << endl;
			cout << "When you stop at one of the room, you discover that there is a monster standing in front of you." << endl;
			cout << "You accept your destiny by letting the monster bitting every part of your body..." << endl;
			playerPosition->monsterType = 'A';
		}
	}
	else{
        cout << "You have calmed down yourself." << endl;
        mercy++;
        if (mercy>=3){
        	mercy = 3;
        	cout << "You are fully calm down." << endl;
		}
    }
}

int Player::getMercy() const {
    return mercy;
}

void Player::setMercy(int newMercy) {
    mercy = newMercy;
}

void Player::checkStatus(Map &map){
	Node *nodePtr = nullptr;
    nodePtr = playerPosition;

    // if jump over the exit and die
    if (playerPosition != map.getHead() && !nodePtr){      
        script.printJumpAcrossExit();                            // dialog
    }
    // if the next node is a monster
	else if (nodePtr->next != nullptr && nodePtr->next->monsterType == 'A'){
		script.printMons();                                       // dialog
        // level 3 will have damage when monster next node
        if(map.getlevel()==3){
			Mercy();
		}
	}
    // die if current node containing monster
	else if (nodePtr->monsterType == 'A'){
		script.printEat();                                        // dialog
	}
    // answer question if current node containing goblin
    else if (nodePtr->monsterType == 'B'){
        GoblinQuestion(map);
    }
    // if the next node is exit
	else if (nodePtr->next == map.getTail()){
		script.printAlmost();       // dialog
	}
    // if current node is exit
	else if (nodePtr == map.getTail()){
		script.printExitFound();                     // dialog
	}
    // normal walking scene
	else{
		script.printWalk();
	}
}

void Player::GoblinQuestion(Map &map){
	Node *nodePtr = nullptr;
	nodePtr = playerPosition;
	
	cout << "But before you can reach another door, there is a strange creature appears in front of you." << endl;
    cout << "Goblin Question: How many nodes have you passed?" << endl;
    int answer;
    cin >> answer;

    if (answer == nodePtr->value) {
        cout << "Goblin Witch : \"Correct answer! You can pass the road.\"" << endl;
        cout << "The goblin witch disappears in front of you, leaving an evil laugh echo..." << endl;
        cout << "You carefully open the door and move to the next location carefully." << endl;
        moveForward(map);
    } else {
        cout << "Goblin Witch : \"WRONG ANSWER! YOU SHOULD NOT PAASS!!!\"" << endl;
        cout << "Yield the goblin witch." << endl;
        cout << "Then, it summons a monster in front of you." << endl;
        cout << "Without any sounds of shouting for help, ";
        nodePtr->monsterType = 'A'; // forward to checkStatus, mentioning player eaten by a monster, else can form one more status like
        // attacked by a group of goblin or any other situasion.
        // will also forward to isPlayerAlive(), to mention the game is over (Lose).
    }
}
