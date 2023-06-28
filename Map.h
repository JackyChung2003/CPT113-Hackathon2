#ifndef MAP_H
#define MAP_H

#include "Node.h"

class Map{
    private:
        Node* head;
        Node* tail;
        int level = 1;
    public:

    Map();
    ~Map();
    void generateRandomList(int level);
    void append(int data);
    void deleteMap();
    void insertMonster(int size, int level);
    void insertGoblin(int position, int lvl1monsterNum[]);

    void printList();
    void levelUp();
    int getlevel();
    void setlevel(int level);

    Node *getTail() const;
    void setTail(Node* tail);

    Node *getHead() const;
    void setHead(Node* head);
};

#endif