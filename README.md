# Sokoban
A first-year project student, a Sokoban-like game in the terminal that uses a text file to generate a game map.

## USAGE
        ./my_sokoban map.txt

### DESCRIPTION
The 'map' file represents the warehouse map, containing '#' for walls, 'P' for the player, 'X' for boxes and 'O' for storage locations.

## Build on Linux (Ubuntu)

### 1. Install the dependencies:
        sudo apt-get update
        sudo apt-get install libncurses5-dev

### 2. build from my repo
        make
        ./my_sokoban map.txt


## Screenshots

![Alt text](screenshots/1.png?raw=true "1")
![Alt text](screenshots/2.png?raw=true "2")