#ifndef PLAYER_H
#define PLAYER_H

#include "Node.h"
#include "Map.h"
#include "Script.h"

class Player : public Map{
    private:
        Node *playerPosition;
        int mercy = 3;
        Script script; // Composition of Script class
    public:
        Player();

        Node* getPlayerPosition() const;            // not sure how to use
        void setPlayerPosition(Node* newPosition);  // not sure how to use
        int getPlayerCoordinate() const;            // not sure how to use

        void setForgetDie();
        
        void moveForward(Map &map);
        void moveBackward(Map &map);
        void jumpOverNode(Map &map);

        bool isPlayerAlive();
        bool finish(Map &map);

        void Mercy();
        int getMercy() const;                       // not sure how to use
        void setMercy(int newMercy);                // not sure how to use

        void checkStatus(Map &map);                         // The status of the player
        void GoblinQuestion(Map &map);                      // to ask question
};  

#endif