#include "Node.h"
#include "Player.h"
#include "Map.h"
#include "FileHandling.h"
#include "GamePlay.h"
#include "Script.h"

#include <iostream> 

using namespace std;

class GameMenu {
public:
    void display() {
        cout << "*************************************************************************************************"<< endl;
        cout << "   __  __  ___  ___  ___  ___  _  _   ___        ___  _     _     _   _  ___  ___   ___   _  _ \n";
        cout << "  |  \\/  ||_ _|/ __|/ __||_ _|| \\| | / __|      |_ _|| |   | |   | | | |/ __||_ _| / _ \\ | \\| |\n";
        cout << "  | |\\/| | | | \\__ \\\\__ \\ | | | .  || (_ |       | | | |__ | |__ | |_| |\\__ \\ | | | (_) || .  |\n";
        cout << "  |_|  |_||___||___/|___/|___||_|\\_| \\___|      |___||____||____| \\___/ |___/|___| \\___/ |_|\\_|"<< endl << endl;
        cout << "*************************************************************************************************"<< endl;
        cout << endl;
    }
};

class MissingIllusionMenu : public GameMenu {
public:
    void display() {
        GameMenu::display();
        cout << endl;
        cout << "                                   1. Start a New Game          " << endl;
        cout << "                                   2. Continue the Game         " << endl;
        cout << "                                   3. Credits                   " << endl;
        cout << "                                   4. Exit Game                 " << endl << endl;
        cout << "*************************************************************************************************"<< endl;
    }
};

class CreditsMenu : public GameMenu {
public:
    void display() {
        GameMenu::display();
        cout << endl;
        cout << "                   Developed by: Jacky Chung, Yeo Din Song, Lim Jia Liang            " << endl;
        cout << "                                       Version: 1.0                    " << endl;
        cout << "                               Release Date: 28/06/2023          " << endl;
        cout << "                                  Website: Unavailable now       " << endl;
        cout << "                                   Email: Unavailable now     " << endl;
        cout << "                      +--------------+\n"
             << "                      |.------------.|\n"
             << "                      ||            ||\n"
             << "                      ||   CPT113   ||\n"
             << "                      || Hackathon 2||\n"
             << "                      ||            ||\n"
             << "                      |+------------+|\n"
             << "                      +-..--------..-+\n"
             << "                      .--------------.\n"
             << "                     / /============\\ \\\n"
             << "                    / /==============\\ \\\n"
             << "                   /____________________\\\n"
             << "                   \\____________________/\n";
        cout << endl;
        cout << "*************************************************************************************************"<< endl;
    }
};

int main() {
    FileHandling file;
    Player player;
    Map map;
    GamePlay game;
    MissingIllusionMenu mainMenu;
    CreditsMenu creditsMenu;
    Script script;

    int select = -1;
    bool loadSuccess = false;        // to check whether load success or not

    while(select != 4){
        mainMenu.display();

        cout << "Enter your choice: ";
        cin >> select;

        switch (select) {
            case 1:     //start new game
                game.runGame(map,player,file);
                break;

            case 2:     //load the game
                file.handleLoadingChoice(map,player,loadSuccess);
                if(loadSuccess){
                    game.runLoadGame(map,player,file);
                    break;
                }
                break;
            case 3:     // Credits
                creditsMenu.display();
                break;
            case 4:     // Exit Game
                script.printTheEnd();
                break;
            default:
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << "|                              Invalid choice. Please try again.                                 |"<< endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
        }
        if(map.getlevel() == 4){
            script.printTheEnd();
            select = 4;
        }
    }
    return 0;
}
