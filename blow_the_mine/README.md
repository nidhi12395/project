This is an Arduino based 2 player game. In the middle there is a cluster of 7 LEDs and the play station of both the players on either side. Each LED in a cluster represent a mine. There are 4 more green LEDs. 2 green LEDs on each player side. These green LEDs represent blast1 and blast2. A winning buzzer is there which will blow if any one of the player wins the game. A joystick is used by both the players to play this game.

Rules of the Game:

1. Player 1 will select any two LEDs of his/her choice. Player 2 will not see which LEDs player 1 has selected. The selected LEDs by player 1 will be his/her 2 mines. After the selection player 1 will press a push button from his/her play station side and will allow player 2 to do the selection.

2. Player 2 will select any two LEDs of his/her choice. Player 1 will not see which LEDs player 2 has selected. The selected LEDs by player 2 will be his/her 2 mines. After the selection player 2 will press a push button from his/her play station side and now the game will start.

3. Player 1 and Player 2 will play this game in alternate turns.

4. The target of player 1 will be to identify both the mines of player 2 and vice versa.

5. If I say, player1 has identified any one of the mine of player2 then one green LED (blast1) from player1's play station will glow. Same goes for player 2.

6. If I say, player1 has also identified second mine of player2 blast2 will glow from player1 side and buzzer will blow representing the win of player1. Same goes for player 2.

7. Since both the players are playing in alternate turns it becomes difficult to remember which LED player 1 has glown in the previous turns when the next turn of player1 arrives and same problem is with player2. Hence when the next turn of any of the player arrives the previous glown LEDs by that player will glow automatically so that the player already knows that yes I have glown these LEDs before so I have to glow some other LEDs from this cluster.