# MISSING ILLUSION

## Description

 This game is about a boy who run away from home because of his problem faced in his life. And the game begin when he found a cave......
 
 This game is inspired by one of our groupmates. In this game, user will face some monsters and they need dodge or faced them. The map and monsters are randomly generated and spawn in the game.

## Features

The game incorporates several key features that enhance the gameplay experience. Here's an overview of these features:

- Start: The "Start" feature allows the user to begin a new game. When selected, the game initializes the map and create monster in the map, creates a node pointer represent player, and starts the game loop. This feature enables the user to embark on a new adventure and explore the game world.

- Save: The "Save" feature empowers the user to save their game progress for future sessions. The game provides three slots for saving, allowing the user to choose a slot to store their current game state. By selecting the "Save" option, the game saves the whole map with monsters' location, current player position, current level and more.

- Load: The "Load" feature enables the user to load a previously saved game and continue playing from where they left off. By selecting the "Load" function, the game presents the user with a list of available save slots. Upon choosing a specific slot, the game retrieves the saved data, restores the map and monsters, player location, player level, and other relevant game state. This feature allows players to revisit their saved games and pick up the gameplay seamlessly.

- Exit: The "Exit" feature provides users with the option to gracefully exit the game. Selecting the "Exit" option terminates the game and closes the program. This feature offers a convenient way for users to conclude their gaming session when desired.

These features contribute to the overall usability and enjoyment of the game, granting users control over their gameplay sessions. Whether starting a new game, saving progress, loading a saved game, or exiting the game, players have the flexibility to engage with the game at their own pace and convenience.

## How to Play

- Move forward: Press '1' and 'ENTER' to move your character forward.
- Move backward: Press '2' and 'ENTER' to move your character forward.
- Jump Across: Press the '3' and 'ENTER' to jump over monster or empty road.

## Object-Oriented Concepts
In the development of the game, several object-oriented concepts were utilized to structure the code and implement the desired functionality. Here's an overview of the concepts used:

#### Classes
Classes provide a blueprint for creating objects with shared attributes and behaviors. The following classes were defined:
- `Node`: Represents a node in the map, storing information about its value and neighboring nodes.
- `Script`: Manages the printing of random game-related messages and dialogues.
- `Map`: Represents the game map and provides methods for generating and manipulating the map, including generate the monster in the map.
- `Player`: Represents the player in the game, including their position and game-related actions.
- `FileHandling`: Handles file operations related to saving and loading game data.
- `GamePlay`: Controls the flow of the game, handling user choices and coordinating interactions between other classes.

#### Objects
Objects are instances of classes that encapsulate specific data and behaviour. In the game, objects were created from the defined classes to represent various entities such as the player, map, and file handler. For example:
- `player`: An object of the `Player` class represents the player and holds their position, mercy count, and other relevant information.
- `map`: An object of the `Map` class represents the game map and contains nodes with associated values.
- `Script`: An object of the `Script` which will call the script or dialogue.


#### Methods
Methods are functions defined within a class that encapsulate specific behaviour. They allow objects to perform actions and interact with each other. Examples of methods used in the code include:
- `saveToFile` and `loadFromFile`: Methods in the `FileHandling` class that handles saving and loading game data to/from files.
- `generateRandomList`, `insertMonster`,  `printList`and other methods: Methods in the `Map` class that generate the map, insert monsters and display the map's contents.
- `moveForward`, `moveBackward`,  `jumpOverNode` and others methods: Methods in the `Player` class that handle the player's movement actions within the map.
- `printGameIntro`, `printChap1`, and other methods in the `Script` class that print various game-related messages.
- `runGame`, `runLoadGame`, and other methods:  Methods in the `GamePlay` class that run the game and handle user input for further action.

  
#### Inheritance
Inheritance is a mechanism that allows a class to inherit properties and methods from another class. In the code, we can observe:
- The `Player` class inherits from the `Map` class. This relationship signifies that the player object has additional properties and methods while still possessing the characteristics of the map.

#### Polymorphism
Polymorphism enables objects to exhibit different behaviors based on their specific context or type. In the code, we see examples of polymorphism through method overriding:
- The `display` method is overridden in the `MissingIllusionMenu` and `CreditsMenu` class, providing a different implementation compared to the same method in the `GameMenu` class.

#### Abstraction
Abstraction involves hiding implementation details and exposing only essential features to simplify the understanding and usage of classes and objects. In the code:
- The internal details of certain methods and classes are abstracted to a higher level. For example, the specific implementation of file handling in the `FileHandling` class is abstracted, exposing only the save and load functionality.

#### Encapsulation
Encapsulation refers to the bundling of data and methods within a class and controlling their access from outside. The code exhibits encapsulation in various ways:
- Private member variables, such as `head`, `tail` and `level` in the `Map` class, are only accessible through getter and setter methods.
- Certain methods and classes, such as the `Script` class, encapsulate specific functionalities and hide their implementation details.

By employing these object-oriented concepts, the code achieves better organization, modularity, and reusability. The separation of responsibilities among different classes allows for easier maintenance and extension of the game's functionality.

## Data Structures

In the development of the game, a linked list data structure was utilized to represent the game map. Here's an explanation of the data structure used and how it was implemented:

#### Linked List
A linked list is a linear data structure where elements are stored in separate objects called nodes. Each node contains data and a reference to the next node and previous node in the list. In our game, a linked list was used to represent the map, with each node representing a location on the map.

#### Implementation
The linked list data structure was implemented through the following components:

- `Node` class: The `Node` class represents a single node in the linked list. It contains attributes such as `value`, `monsterType`, `next`, and `back`. The `value` attribute holds the value of the node, and `monsterType` represents the type of monster associated with the node. The `next` attribute is a pointer to the next node in the list, and the `back` attribute is a pointer to the previous node.

- `Map` class: The `Map` class serves as the container for the linked list. It contains attributes such as `head`, `tail`, and `level`. The `head` attribute points to the first node in the list, and the `tail` attribute points to the last node. The `level` attribute stores the current level of the map.

The `Map` class also provides various methods to manipulate the linked list:
- `generateRandomList`: This method generates a random list of nodes with specified levels.
- `append`: This method adds a new node to the end of the list.
- `deleteMap`: This method deletes all the nodes in the map.
- `insertMonster`: This method inserts monsters at specific positions in the map.
- `insertGoblin`: This method inserts goblins at specific positions in the map.
  
- `Player` class: The `Player` class serves as the container for the linked list. It contains attributes such as `playerPosition`, and `mercy`. The `playerPosition` attribute points to the player location in the list. The `mercy` attribute stores the current mercy of the player.

The `Player` class also provides various methods to manipulate the linked list:
- `moveForward`: This method move forward the player 1 step.
- `moveBackward`: This method move backward the player 1 step.
- `jumpOverNode`: This method allow the player to jump over 1 node.

#### Usage
The linked list data structure is used to represent the game map, which serves as the main gameplay element. The map is generated randomly using the `generateRandomList` method. The `append` method is used to add new nodes to the end of the list, and the `deleteMap` method is used to clear the map when needed.

The `insertMonster` method is utilized to insert monsters at specific positions on the map, while the `insertGoblin` method is used to insert goblins at designated positions. These methods allow for the dynamic modification of the map during gameplay.

Overall, the linked list data structure plays a crucial role in representing and manipulating the game map, providing a dynamic and flexible gameplay experience.

## Screenshots

![Screenshot 1](https://github.com/jc2003-2003/CPT113-Hackathon2/blob/5b90054032b7e251469f05f9d730a6f675ff2246/Main%20Menu.jpeg)

![Screenshot 2](https://github.com/jc2003-2003/CPT113-Hackathon2/blob/5b90054032b7e251469f05f9d730a6f675ff2246/Chapter%201.jpeg)

## Demo Video
https://youtu.be/Ul61M6RdXeE


