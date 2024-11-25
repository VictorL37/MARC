# MARC Project: Optimal Pathfinding on Mars
## Overview 

MARC is a rover that has encountered a malfunction on Mars, leaving it unable to complete its mission. Despite the failure, it retains some key sensors: a radar and a gyroscope, which allow it to track its location and orientation on the planet. The challenge is for MARC to find its way back to a base station for repairs, using a limited number of movements (only 9 left). With a total of 5 movement decisions to be made, this project focuses on finding the best route based on MARC's current position and available moves.

Using a tree-based search algorithm, our program determines the most efficient path to guide MARC back to safety.

---

## How It Works
MARC's movement is guided by a series of nodes, each representing a position on the Mars map. The program builds a tree structure where each node contains relevant information, including:

+ Current position
+ Movement cost (the "value" of a move)
+ Soil type at the location
+ Direction of movement

The system uses a breadth-first search algorithm and a queue-based approach to explore all possible paths, and from that exploration, it picks the optimal path based on the minimum cost to get closer to the base.

---

## Features
The project consists of the following core functionalities:

1) **Tree Construction**:
The program builds an n-ary tree representing possible paths and movements, storing nodes containing both information and their child nodes.

2) **Queue Management**:
A custom queue structure is implemented to manage the nodes being evaluated. Nodes are added or removed based on their potential to move MARC closer to the goal.

3) **Pathfinding**:
The program identifies the optimal path by finding the node with the minimum movement cost. The shortest route is then chosen from a set of possible paths.

4) **Efficient Movement Selection**:
With only 5 moves left, MARC must make the best choices based on the available directions (North, South, East, West) to minimize travel time and reach the base.

---

## Getting Started
To get started with the project, follow these steps:

1) Clone the repository:
   + Ensure you have the latest version of the source code. To clone the repository, run the following command:

            git clone https://github.com/YourUsername/MARC-Project


2) Navigate to the project folder:
    + Once the repository is cloned, navigate to the project folder:

            cd MARC-Project


3) Compile the project:
    + The project is written in C. To compile the project, you can use the following command:

            gcc -o marc main.c


4) Run the project:
    + After compiling, run the program with:

            ./marc

(Note: If you're using a different system or compiler, the commands may vary slightly. Ensure you have a C compiler installed, such as gcc.)

---

## Code Structure
+ **tree.h**: Defines the tree and node structures, along with functions for node creation and tree traversal.
+ **queue_node.h**: Implements a custom queue to manage nodes efficiently during pathfinding.
+ **path.h**: Contains functions for calculating the optimal path based on the current state of the rover and available moves.

---

## Authors and Credits
This project was developed by:

**Victor LASSALLE** ([victor.lassalle@efrei.net]())

**Yrieix DE SALABERRY** ([yrieix.desalaberry@efrei.net]())

**Lina MIMOUNI** ([lina.mimouni@efrei.net]())

We'd like to thank Mr. Nicolas Flasque for the creation of this project and the opportunity to work on such an exciting challenge.
We'd also like to thank Ms. Lena TREBAUL for her guidance and feedback throughout the development of this project.

