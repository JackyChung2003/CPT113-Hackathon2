#include "Script.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Script::pressAnyKey(){
    // cin.ignore();
    getchar(); // Wait for a key press
}

void Script::printMonsPic(){
    cout << "                _,-}}-._" << endl;
    cout << "               /\\   }  /\\" << endl;
    cout << "              _|(O\\_ _/O)" << endl;
    cout << "            _|/  (__''__)" << endl;
    cout << "          _|\\/    WVVVVW" << endl;
    cout << "         \\ _\\     \\MMMM/_" << endl;
    cout << "       _|\\_\\     _ '---; \\_" << endl;
    cout << "  /\\   \\ _\\/      \\_   /   \\" << endl;
    cout << " / (    _\\/     \\   \\  |'VVV" << endl;
    cout << "(  '-,._\\_.(      'VVV /" << endl;
    cout << " \\         /   _) /   _)" << endl;
    cout << "  '....--''\\__vvv)\\__vvv)" << endl;
    cout << endl;
}

void Script::printGobPic(){
    cout << "    /," << endl;
    cout << "   / \\" << endl;
    cout << "__/___\\_\\V/" << endl;
    cout << " <(6_d)> Y" << endl;
    cout << "  /___\\__|" << endl;
    cout << " /) : (  |" << endl;
    cout << " /     \\ |" << endl;
    cout << "'--V-V--'|" << endl;
    cout << endl;
}

void Script::printScared(){
    cout << "   ( ( (                    ^^" << endl;
    cout << "    ) ) )                  v/oo" << endl;
    cout << "    ( ( (                v/',(~)" << endl;
    cout << "   '. ___ .'          _v-;,)=) " << endl;
    cout << "  '  (> <) '          \"\"\"\' \" \"" << endl;
    cout << "--ooO-(_)-Ooo--------------------" << endl;

    cout << endl;
}

void Script::printGameIntro() {
    cout<<"\n\n"
        << "*************************************************************************************************"<< endl
        << "Once upon a time, in a small town, there lived a young boy named Alex.\n"
        << "Press any key to continue the script...\n";
    pressAnyKey();
    cout<< "Alex's life was terrible.\n";
    pressAnyKey();
    cout<< "His parents were constantly scolding him and had unreasonably high expectations for his performance at school.\n";
    pressAnyKey();
    cout<< "No matter how hard he tried, it seemed like nothing he did was ever good enough for them.\n";
    pressAnyKey();
    cout<< "On top of that, he always been looked down upon by his teachers and faced \nrelentless bullying from his peers at school, leaving him feeling isolated and dejected.\n";
    pressAnyKey();
    cout<< "\nSo, one day, he ran away from the town...\n";
    pressAnyKey();
    cout<< "Lost in his thoughts and trying to figure out where to go, Alex stumbled upon a hidden cave on the outskirts of town.\n";
    pressAnyKey();
    cout<< "Intrigued and seeking solace, he cautiously stepped inside, hoping that the darkness would shield him from the world's cruelties,";
    pressAnyKey();
    cout<< "\n\n\nif only for a while......\n";
    pressAnyKey();
}

void Script::printChap1() {
    cout<<"\n\n"
        << "*************************************************************************************************"<< endl
        << "                                       C h a p t e r   1\n"
        << "*************************************************************************************************\n\n";
    pressAnyKey();
    cout<< "As Alex ventured deeper into the cave, a sense of foreboding crept over him.\n";
    pressAnyKey();
    cout<< "Shadows danced around him, playing tricks on his weary mind.\n";
    pressAnyKey();
    cout<< "The eerie silence was broken by a sudden, thunderous roar that reverberated through the cavern walls.\n";
    pressAnyKey();
    cout<< "Trembling with fear, he turned toward the source of the sound.\n";
    pressAnyKey();
    cout<< "The monster's eyes filled with anger and disappointment.\n\n";
    pressAnyKey();
    cout<< "-------------------------------------------------------------------------------------------------\n";
    cout<< "                                        Instruction\n";
    cout<< "-------------------------------------------------------------------------------------------------\n\n";
    cout<< "There will be monsters exist on your road. Jump over them when you meet them. You will hear a sound when its near you.\n";
    cout<< endl;
    printMonsPic();
}

void Script::printChap2() {
    cout << "\n\n"
        << "*************************************************************************************************\n"
        << "                                        C h a p t e r   2\n"
        << "*************************************************************************************************\n\n";
    pressAnyKey();
    cout<< "Leaving the cavern of the roaring monster behind, Alex continued his journey deeper into the cave.\n";
    pressAnyKey();
    cout<< "The air grew heavy, and he felt a piercing gaze upon him.\n";
    pressAnyKey();
    cout<< "Suddenly, instead of monster appear, a goblin with sharp claws and a wicked grin appeared before him.\n";
    pressAnyKey();
    cout<< "The goblin's eyes sparkled with full of contempt, bombarded Alex with relentless questions.\n\n";
    pressAnyKey();
    cout<< "-------------------------------------------------------------------------------------------------\n";
    cout<< "                                        Instruction\n";
    cout<< "-------------------------------------------------------------------------------------------------\n\n";
    cout<< "Instead of monsters exist, a creature call goblin will also exist on your road.\n";
    cout<< "It will ask you a question about what is your current position, make sure to answer CORRECTLY.\n"
        << endl;
    printGobPic();
}

void Script::printChap3() {
    cout << "\n\n"
        << "*************************************************************************************************\n"
        << "                                        C h a p t e r   3\n"
        << "*************************************************************************************************\n\n";
    pressAnyKey();
    cout<< "As Alex delved deeper into the cave, he encountered a menacing sight.\n";
    pressAnyKey();
    cout<< "The roaring monster and inquisitive goblin stood side by side, their eyes filled with malice.\n";
    pressAnyKey();
    cout<< "The shadows around them twisted and contorted, forming a sinister army against him.\n\n";
    pressAnyKey();
    cout<< "-------------------------------------------------------------------------------------------------\n"
        << "                                        Instruction\n"
        << "-------------------------------------------------------------------------------------------------\n\n"
        << "Now when player heard the sound from the monsters, \n"
        << "It will decrease player's mental health by 1/3, to restore the mental health, player can move backward.\n"
        << "Once the mental health become 0, the game will end.\n"
        << "Remember you need to stay at a safety or the place you dont feel fear from monster.\n"
        << "OR else your mental health will keep decrease every load game.\n"
        << endl;
    printScared();
}

void Script::printEnd() {
	cout << endl;
	cout << "*************************************************************************************************" << endl;
	cout << "                                       E n d i n g" << endl;
	cout << "*************************************************************************************************\n\n";
    pressAnyKey();
    cout<<"After what felt like an eternity, Alex finally stumbled upon an exit-a ray of sunlight illuminating the path ahead. He burst out of the cave.\n";
    pressAnyKey();
    cout<< "He saw a man waiting outside the cave, his eyes filled with concern. The man's gentle smile and warm presence instantly put Alex at ease.\n";
    pressAnyKey();
    cout<< "The man said he would bring Alex to a place, somewhere better.\n";
    pressAnyKey();
    cout<< "He turned to look back at the cave, witnessing his parents sitting on the ground, tear-stained faces etched with a profound longing, silently weeping...\n"
        << endl;
}

void Script::printTruth() {
    cout << endl
        << "-------------------------------------------------------------------------------------------------\n"
        << "                                          Truth\n"
        << "-------------------------------------------------------------------------------------------------\n\n"
        << "After getting lost in the cave for a few days, Alex faints because of hunger and thirst.\n";
    pressAnyKey();
    cout<< "Before death, his mind imagines some aspects of his life.\n";
    pressAnyKey();
    cout<< "The parents who expect a lot from him are the monster called 'tnerap'.\n";
    pressAnyKey();
    cout<< "The teachers who always despise him are the goblin called 'rehcaet'.\n";
    pressAnyKey();
    cout<< "The army called 'yllub' represents the plight he faced in school when he was bullied by his peers.\n\n";
    pressAnyKey();
    cout<< "-------------------------------------------------------------------------------------------------\n"
        << "                                        The lesson:\n"
        << "-------------------------------------------------------------------------------------------------\n\n";
    pressAnyKey();
    cout<< "Forgive the child as they are still improving themselves...\n";
    pressAnyKey();
    cout<< "Don't look down on students as they are still growing...\n";
    pressAnyKey();
    cout<< "Stop bullying your friends as they are humans who deserve kindness and respect, just like you...\n"
        << endl;
}

void Script::printWalk() {
    string sentences[] = {
        "As Alex cautiously stepped into the cave, the air grew heavy with anticipation.\n",
        "His footsteps echoed through the dimly lit passages, creating an eerie symphony of sound.\n",
        "Each step he took seemed to amplify the weight of his troubled thoughts, echoing in his mind.\n",
        "The cool, damp air wrapped around him like a cloak, sending a shiver down his spine.\n",
        "Whispers seemed to emanate from the cave's depths, teasing his ears and leaving him on edge.\n",
        "The faint drips of water echoed like distant whispers, as if the cave itself held secrets waiting to be discovered.\n",
        "The silence enveloped him, punctuated only by the sound of his own breathing, a steady rhythm in the darkness.\n",
        "Every step forward felt like a leap of faith into the unknown, unsure of what lay ahead.\n",
        "As he ventured deeper, the cave seemed to take on a life of its own, its mysteries unfolding before his eyes.\n",
        "The walls of the cave bore the scars of time, etched with ancient stories waiting to be unraveled.\n",
        "Echoes of forgotten footsteps resonated through the narrow corridors, as if the cave held the memories of those who had treaded its path before.\n",
        "The distant sound of dripping water created a rhythmic symphony, soothing and haunting all at once.\n",
        "Occasional gusts of wind whispered through hidden crevices, carrying with them a hint of mystery and adventure.\n",
        "Stalactites and stalagmites reached towards each other, forming intricate sculptures that seemed to guard the secrets of the cave.\n",
        "Shafts of light, penetrating through cracks in the cave ceiling, painted surreal patterns on the rough, rocky surfaces.\n",
        "Every twist and turn revealed a new chamber, unveiling the wonders and enigmas hidden within the heart of the cave.\n",
        "A gentle breeze whispered ancient secrets, as if the cave itself whispered its history to those who dared to listen.\n",
        "Silent pools of water mirrored the cave's ethereal beauty, reflecting a distorted reality that mesmerized Alex's gaze.\n",
        "The earthy scent of damp soil mingled with the faint fragrance of moss, immersing him in the natural essence of the cave.\n",
        "As Alex stood before the monstrous figure, his heart raced with fear, but he refused to let it consume him.\n"
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printMons() {
    string sentences[] = {
        "As Alex ventured deeper into the cave, a thunderous growl reverberated through the air, sending shivers down his spine.\n",
        "The piercing sound of the monster's roar echoed through the darkness, causing Alex's heart to race with fear.\n",
        "A deafening roar emanated from the looming figure before Alex, its reverberations filling the cave and instilling a sense of dread within him.\n",
        "The monstrous creature unleashed a mighty roar that echoed off the walls, its sheer power overwhelming Alex's senses.\n",
        "The cave trembled with the force of the monster's roar, its ferocity striking fear into Alex's very core.\n",
        "The resounding roar of the monster pierced the silence, its intensity enveloping Alex in a wave of terror.\n",
        "The monstrous howl of the monster echoed through the cavern, a chilling sound that froze Alex in his tracks.\n",
        "The reverberating bellow of the creature resonated through the cave, causing Alex's heart to skip a beat.\n",
        "The cave was filled with the menacing sound of the monster's roar, its deep timbre shaking Alex to his very core.\n",
        "The earth shook beneath Alex's feet as the monster let out a bone-chilling roar, the sound echoing ominously in the cave.\n"
    };


    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printGoblin() {
    string sentences[] = {
        "Just as Alex thought he was safe, a peculiar creature materialized before him, blocking his path to the next chamber.\n",
        "Before Alex could proceed further, an enigmatic being manifested right in front of him, impeding his progress.\n",
        "As Alex moved forward, a mysterious entity suddenly materialized, standing in his way and challenging his advance.\n",
        "In the midst of his exploration, Alex encountered a peculiar being that appeared out of nowhere, obstructing his passage.\n",
        "A strange creature materialized before Alex, its presence surprising him and forcing him to reassess his next move.\n",
        "Just as Alex thought he could continue his journey uninterrupted, a curious entity emerged, halting his progress.\n",
        "The path ahead was blocked by an unfamiliar creature that materialized in front of Alex, demanding his attention.\n",
        "Before Alex could proceed any further, a peculiar being manifested itself, creating an unexpected obstacle in his path.\n",
        "As Alex cautiously moved forward, a mysterious figure suddenly appeared, challenging him to confront the unknown.\n",
        "With a sudden appearance, a strange entity stood before Alex, its presence demanding his immediate attention.\n"
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printJumpMons() {
    string sentences[] = {
        "With a surge of adrenaline, Alex summoned all his courage and leaped across the monstrous creature, narrowly avoiding its grasp.\n",
        "In a daring display of agility, Alex propelled himself into the air, gracefully vaulting over the intimidating monster beneath him.\n",
        "Determined to escape the clutches of the beast, Alex mustered his strength and executed a daring jump, soaring over the menacing creature with precision.\n",
        "The monster lunged forward, but Alex's quick reflexes allowed him to spring into action, vaulting over its massive form with a single powerful leap.\n",
        "With a fearless leap, Alex defied the monster's reach, soaring through the air and landing safely on the other side.\n",
        "Summoning his inner acrobat, Alex performed a daring leap, effortlessly clearing the monster's path and landing securely beyond its menacing presence.\n",
        "Alex's heart raced as he propelled himself into the air, defying the monster's pursuit with a magnificent jump that carried him to safety.\n",
        "With a burst of determination, Alex propelled himself skyward, soaring over the towering monster and leaving it in awe of his audacious feat.\n",
        "As the monster lunged forward, Alex propelled himself upward, his body sailing over the creature's menacing form with a breathtaking leap.\n",
        "Alex mustered every ounce of strength and agility, launching himself over the monster with a gravity-defying jump, escaping its clutches in a thrilling display of bravery.\n"
    };


    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printJumpAir() {
    string sentences[] = {
        "Alex summoned his bravery and leaped into the air, expecting an obstacle, but to his surprise, there was nothing there to challenge his jump.\n",
        "With determination, Alex propelled himself forward, preparing to jump across an obstacle, only to find empty space before him.\n",
        "As Alex leaped forward, his anticipation turned to confusion as he realized there was no obstacle to overcome, leaving him momentarily puzzled mid-air.\n",
        "Bracing himself for a daring jump, Alex soared through the air, only to realize there was no physical barrier to conquer, causing a mix of relief and bewilderment.\n",
        "Fueled by adrenaline, Alex mustered his strength and executed a powerful jump, momentarily perplexed by the absence of any obstacle in his path.\n",
        "With unwavering determination, Alex launched himself into the air, expecting to encounter an obstacle, only to find nothing but open space before him.\n",
        "Alex's heart raced as he leaped forward, prepared to overcome an obstacle, but as he soared through the air, he discovered there was nothing impeding his path.\n",
        "Summoning his courage, Alex propelled himself into the air, anticipating a challenge, only to find an empty void waiting for him on the other side of his jump.\n",
        "With a surge of energy, Alex took a daring leap, fully expecting an obstacle to conquer, only to find himself soaring through the air with nothing to impede his progress.\n",
        "Alex's muscles tensed as he jumped forward, ready to overcome an obstacle, but his leap led him into emptiness, leaving him momentarily suspended in mid-air.\n"
    };


    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
    cout  << endl;
}

void Script::printAlmost() {
    string sentences[] = {
        "Alex was on the verge of finding the exit, just a few steps away from reaching his destination.",
        "The exit was within sight, and Alex could almost taste the victory of nearing his escape.",
        "With determination, Alex approached the exit, feeling a sense of relief as he drew closer.",
        "The exit was just within grasp, and Alex could sense the freedom awaiting him.",
        "Alex's heart raced with anticipation as he neared the exit, knowing that his journey was almost over.",
        "The exit loomed before him, and Alex could practically feel the warmth of success emanating from it.",
        "With each step, Alex inched closer to the exit, feeling a surge of excitement building within him.",
        "The sight of the exit ahead fueled Alex's determination as he pushed forward, knowing he was on the brink of escape.",
        "Alex's hopes soared as he approached the exit, knowing that his perseverance was about to pay off.",
        "The exit was tantalizingly close, and Alex's excitement grew as he prepared to cross the threshold to freedom."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printExitFound() {
    string sentences[] = {
        "Alex's eyes widened in relief as he discovered the exit right before him.",
        "With a sigh of relief, Alex finally stumbled upon the exit, ending his quest.",
        "The long search came to an end as Alex stumbled upon the exit, feeling a surge of accomplishment.",
        "A smile of triumph spread across Alex's face as he uncovered the exit, signaling the end of his journey.",
        "After a grueling journey, Alex's perseverance paid off as he uncovered the exit, elated with his discovery.",
        "Alex's heart swelled with joy as he stumbled upon the exit, knowing that freedom awaited him.",
        "The sight of the exit filled Alex with a renewed sense of hope and excitement as he realized his journey was nearing its end.",
        "With a sense of fulfillment, Alex stood before the exit, knowing he had reached his ultimate goal.",
        "A wave of satisfaction washed over Alex as he found the exit, knowing that his efforts had not been in vain.",
        "Alex's determination led him to the exit, where he stood with a mix of relief and accomplishment, ready to move forward."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printEat() {
    string sentences[] = {
        "The monster seized Alex and devoured him in one swift motion.",
        "Alex found himself in the clutches of the monster, which proceeded to consume him.",
        "Helplessly, Alex was engulfed by the monster, disappearing into its voracious mouth.",
        "The jaws of the monster closed around Alex, swallowing him whole.",
        "In a horrifying turn of events, the monster feasted on Alex, leaving no trace behind.",
        "Alex's fate was sealed as the monster captured him and made him its meal.",
        "The ravenous monster pounced on Alex, tearing into him and consuming him entirely.",
        "Despite his efforts, Alex couldn't escape the monster's grasp as it consumed him entirely.",
        "The monstrous creature overpowered Alex, consuming him in a single bite.",
        "Alex met his unfortunate end as the monster devoured him, leaving nothing but emptiness in its wake."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printBackHit() {
    string sentences[] = {
        "Alex noticed a wall blocking his path backward, preventing him from moving in that direction.",
        "He realized there was a wall behind him, making it impossible for him to go backward.",
        "Alex came to the realization that he couldn't move backward anymore due to the wall.",
        "Seeing the wall behind him, Alex understood he couldn't go back any further.",
        "The presence of the wall meant Alex couldn't retreat or go backward.",
        "Alex discovered he was trapped with a wall behind him, unable to move backward.",
        "Realizing he had hit a wall, Alex understood he couldn't go backward anymore.",
        "The wall behind Alex prevented him from moving backward, leaving him with no choice but to continue forward.",
        "Alex's progress was halted by the wall behind him, making it impossible to go backward.",
        "With the wall blocking his path, Alex couldn't retreat or go backward anymore."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printJumpAcrossExit() {
    string sentences[] = {
        "Alex jumped across the exit but went too far.",
        "He leaped across the exit but realized he overshot it.",
        "Alex cleared the exit with a jump but landed awkwardly.",
        "He propelled himself forward, clearing the exit, but stumbled upon landing.",
        "With determination, Alex jumped across the exit but misjudged the distance.",
        "He jumped across the exit but lost balance upon landing.",
        "Alex successfully cleared the exit with a jump but couldn't maintain stability.",
        "He gathered his strength and leaped across the exit but jumped too high.",
        "With agility, Alex cleared the exit but had an awkward landing.",
        "He took a leap of faith across the exit but stumbled upon landing."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printFell() {
    string sentences[] = {
        "Alex slipped and fell off the world, disappearing into the void.",
        "As Alex took a step, he lost his footing and plummeted off the edge of the world.",
        "He accidentally stumbled and tumbled over the world's edge, vanishing into the unknown.",
        "In a sudden misstep, Alex lost his balance and plunged into the abyss beyond the world's edge.",
        "Without warning, Alex slipped and fell, descending into the endless expanse beyond the world.",
        "With a momentary lapse, Alex lost his grip and descended into the void outside the world's boundaries.",
        "In a harrowing twist of fate, Alex lost control and tumbled off the world's edge, vanishing from sight.",
        "As he ventured too close to the edge, Alex lost his balance and dropped into the vast nothingness below.",
        "In an unfortunate accident, Alex slipped off the world, leaving nothing but emptiness in his wake.",
        "With a sudden jolt, Alex's footing gave way, sending him spiraling into the unknown beyond the world's edge."
    };

    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));

    cout << sentences[index] << endl;
}

void Script::printTheEnd(){
	cout << " _____  _                 _               __                  _ __  _        _  _  _        __ _ " << endl;
    cout << "|_   _|| |_   __ _  _ _  | |__ ___       / _| ___  _ _       | '_ \\| | __ _ | || || | _ _  / _` |" << endl;
    cout << "  | |  |   \\ / _` || ' \\ | / /(_-)      |  _|/ _ \\| '_|      | .__/| |/ _` | \\_. || || ' \\ \\__. |" << endl;
    cout << "  |_|  |_||_|\\__/_||_||_||_\\_\\/__/      |_|  \\___/|_|        |_|   |_|\\__/_|\\___/ |_||_||_||___/ " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                      _____  _  _  ___        ___  _  _  ___  " << endl;
    cout << "                     |_   _|| || || __|      | __|| \\| ||   \\" << endl;
    cout << "                       | |  | __ || _|       | _| | .  || |) |" << endl;
    cout << "                       |_|  |_||_||___|      |___||_|\\_||___/ " << endl;
    cout << endl;
}

void Script::printVictory(){
    cout << "    __ __ _____ __ __    __ __ _____ __ __ _____    _____ _____ _____ _____ _____ _____ ____  " << endl;
    cout << "   |  |  |     |  |  |  |  |  |  _  |  |  |   __|  |   __|   __|     |  _  |  _  |   __|    \\ " << endl;
    cout << "   |_   _|  |  |  |  |  |     |     |  |  |   __|  |   __|__   |   --|     |   __|   __|  |  |" << endl;
    cout << "     |_| |_____|_____|  |__|__|__|__|\\___/|_____|  |_____|_____|_____|__|__|__|  |_____|____/ " << endl << endl;;
    cout << "                                   1. Continue the next level         " << endl;
    cout << "                                   2. Back to main menu               " << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
}

void Script::printRetry(){
    cout << "                     ___  ___  __  __  ___         ___  __   __ ___  ___ " << endl;
    cout << "                    / __|/   \\|  \\/  || __|       / _ \\ \\ \\ / /| __|| _ \\" << endl;
    cout << "                   | (_ || - || |\\/| || _|       | (_) | \\   / | _| |   /" << endl;
    cout << "                    \\___||_|_||_|  |_||___|       \\___/   \\_/  |___||_|_\\" << endl << endl;
    cout << "                                   1. Retry this level               " << endl;
    cout << "                                   2. Back to main menu               " << endl;
    cout << endl;
    cout << "*************************************************************************************************" << endl;
}



