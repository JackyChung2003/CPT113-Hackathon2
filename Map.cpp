#include "Map.h"
#include "Node.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

Map::Map() {
    head = nullptr;
    tail = nullptr;
}

Map::~Map() {
    Node *current =nullptr;
    current = head;
    while (current != nullptr) {
        Node *nodePtr = nullptr;
		nodePtr = current->next;
        delete current;
        current = nodePtr;
    }
}

void Map::generateRandomList(int level){
	int randomList = 0;
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
	randomList = (rand() % 11) + 20; // Generate the random number from 20-30
	// cout << "Random List: " << randomList << endl; // For checking only
	for (int i=1; i<=randomList; i++){
		append(i);
	}
	insertMonster(randomList,level);
}

void Map::append(int num) {
    Node *newNode, *nodePtr;
	
	newNode = new Node;
    newNode->value = num;
    newNode->next = nullptr;
    newNode->monsterType = '-';

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        // player = head;
    } else {
        nodePtr = tail;
        nodePtr->next = newNode;
        newNode->back = nodePtr;
        tail = newNode;
    }
}

void Map::deleteMap() {
    Node *current = head;

    while (current != nullptr) {
        Node *nodePtr = current->next;
        delete current;
        current = nodePtr;
    }

    head = nullptr;
    tail = nullptr;
    // player = nullptr;
}

void Map::insertMonster(int size, int level) {
    // Calculate the number of monsters
    int numMonsters = sqrt(size);

    // Create a dynamic array to store the monster positions
    int* monsterPositions = new int[numMonsters];

    srand(time(0));
    int tempMonsterLocation;
    bool validLocation;

    for(int i = 0; i < numMonsters; i++){
        validLocation = false;
        while(!validLocation) {
            tempMonsterLocation = (rand() % (size-2)) + 2; // Generate the random number from 2 - size-1 of the list, which will not start at starting point
            // Check if the generated location already exists in the array or is adjacent to any existing number
            bool exists = false;
            bool adjacent = false;
            for(int j = 0; j < i; j++) {
                if (monsterPositions[j] == tempMonsterLocation) {
                    exists = true;
                    break;
                }
                if (monsterPositions[j] == tempMonsterLocation - 1 || monsterPositions[j] == tempMonsterLocation + 1) {
                    adjacent = true;
                    break;
                }
            }
            // If the location is valid (does not exist and is not adjacent to any existing number), set validLocation to true
            if (!exists && !adjacent) {
                validLocation = true;
            }
        }
        // Store the valid monster location in the array
        monsterPositions[i] = tempMonsterLocation;
    }
    // insert the monster into the linkedlist
    Node *current = nullptr;
    for(int i = 0; i < numMonsters; i++){
        current = head;
        while (current != nullptr && current->value != monsterPositions[i]) {
            current = current->next;
        }
        current->monsterType = 'A';     
    }
    if(level>1){
        insertGoblin(size,monsterPositions);
    }
    delete [] monsterPositions;
}

void Map::insertGoblin(int size, int lvl1monsterNum []) {
    srand(time(0));
    int differenceNum = 1 - (rand() % 3); // randomNum will output 0/1/2, then 1-random will have "1,0,-1"

    int numMonstersbefore = sqrt(size);
    // Calculate the number of level 2 monsters, will have same, or more 1, or less 1
    int numMonsters = numMonstersbefore + differenceNum;
    // Create a dynamic array to store the monster positions
    int* monsterPositions = new int[numMonsters];

    int tempMonsterLocation;
    bool validLocation;

    for(int i = 0; i < numMonsters; i++){
        validLocation = false;
        while(!validLocation) {
            tempMonsterLocation = (rand() % (size-2)) + 2; // Generate the random number from 2 - size-1 of the list
            // Check if the generated location already exists in the array or is adjacent to any existing monster
            bool exists = false;
            bool nextGotMonster = false;
            for(int j = 0; j < numMonstersbefore; j++) {
                if (lvl1monsterNum[j] == tempMonsterLocation) {
                    exists = true;
                    break;
                }
                if (tempMonsterLocation + 1 == lvl1monsterNum[j]) {
                    nextGotMonster = true;
                    break;
                }
            }
            // If the location is valid(current location dont have monster or no lvl 1 monster on next step), set validLocation to true
            if (!exists && !nextGotMonster) {
                validLocation = true;
            }
        }
        // Store the valid monster location in the array
        monsterPositions[i] = tempMonsterLocation;
    }
    // insert the monster into the linkedlist
    Node *current = nullptr;
    for(int i = 0; i < numMonsters; i++){
        current = head;
        while (current != nullptr && current->value != monsterPositions[i]) {
            current = current->next;
        }
        current->monsterType = 'B';     
    }
    delete [] monsterPositions;
}

// for developer to view and debug
void Map::printList() {
    Node *current = head;
    while (current != nullptr) {
        cout << current->value << ":" << current->monsterType << endl;
        current = current->next;
    }
    cout << endl;
}

void Map::levelUp(){
    level++;
}

int Map::getlevel(){
    return level;
}

void Map::setlevel(int level){
    this->level = level;
}

Node *Map::getTail() const {
    return tail;
}

void Map::setTail(Node* tail){
    this->tail = tail;
}

Node *Map::getHead() const {
    return head;
}

void Map::setHead(Node* head){
    this->head = head;
}