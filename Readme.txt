The game “A-MAZE”

GAME:
As the name of the game suggests, the game displays different levels of maze. A maze is a complex design of lines which are arranged in different ways in an area with some path between them. 
Our game consists of 3 levels of such a maze and a character which is continuously moving in the path between the maze. The start and end points are defined. The character has to reach the end point without touching the maze (the line arrangement). Each level has a different arrangement of maze and the maze gets difficult and more complex for the player to cross. 

LANGUAGE & PLATFORM:
The game currently runs on the console application and is written in C language.

ALGORITHM:
The player starts by entering his/her name. If different players are playing the game, high scores are also displayed in the end. The more path a player covers without touching the maze, the more points he gets. As soon as the character touches the maze, the game gets over.

WALL:
We have used two dimensional arrays for the walls of the maze. A two dimensional array representing all the (x, y) coordinates of console application is initialized by zero. Then we set all the coordinates that lie on the walls of the maze to 1, when the character touches any coordinate equal to 1, the game gets over.

GOTOXY FUNCTION
The other function we used is the gotoxy function in which we can move position the cursor directly to one point from where we need to start printing the maze. In this function, we supposed the console behaving as a grid and the cursor moves to the point where we want it to. Just the points of the coordinates are given.

PRINTING THE MAZE 
The maze was printed using for loops and nested for loops. Loops we made and different arrangement of asterisks was printed to create three different mazes and a first page. The gotoxy function was also used to print the maze from a point other than the starting point of a line.

CLEARING THE SCREEN
After each level, the console application screen was cleared and the cursor was sent back to the (0,0) coordinates to print the next maze.

CURSOR MOVEMENT:
For the cursor movement we used a while loop along with a switch. The switch statement determines the key pressed. In that switch we used if else statements to check If the cursor touches the points of the 2D array which are assigned value 1, the game gets over, otherwise the cursor continues moving.

END POINT
The two dimensional array values for the coordinates of end point are set to two. When the cursor reaches the end point, the loop breaks and player enters the next level.

HIGH SCORE:
File handling has been used to store high score. A structure with player’s name with the highest score is saved in the file. Every time a new player plays, his score is saved temporarily in another variable. At the end of his game, his score is compared by the highest score by reading the high score file. If his score is greater than the previous highest score, the file gets over written with the new high score along with the player’s name. 
