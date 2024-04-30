==================================================================================  
**Team member:**
1. Ho Kin Sang, UID = 3036080006
2. So Ching Hong, UID = 3036068022
3. Lan Lik Wai, UID = 3036068931
----------------------------------------------------------------------------------
**Description of the game**  
  
This is a 2-player mini-game party, where you and your friend can compete in 3 games, including NumberMonster, Guess_Your_Luck, and TicTacToe. Whoever wins the most, wins!
1. **Number Monster**  
--> In this game, Two players are rival in eliminating their **Number Monster** by guess the corresponding numberv of the monster. The fastest player to eliminate all monsters win!
  
2. **Guess_Your_Luck**  
--> In this game, you and your friend will compete in guess the correct **Golden Number**. The dynamic range is initialize between [0,100] inclusive at the beginning of the game. It will modify and be more precise according to your guesses. The first player guess the **Golden Number** wins!
  
3. **TicTacToe**  
--> This is the classic TicTacToe game, where 2 players strike to line up their symbol 3 in a row in any directions!
----------------------------------------------------------------------------------
**Code Requirement**
  
1. Generation of random game sets or events  
--> In the game [NumberMonster] and [Guess_Your_Luck], random target are genereated at the beginning of the game, i.e. The random number monsters in [NumberMonster] and the golden number in [Guess_Your_Luck].

2. Data structure for storing games status.  
--> In all three games, array is used to store the games status. Inlucding but not limited to the number of dices left in [NumberMonster], the dynamic range in [Guess_Your_Luck], and the intermeddiate game status of [TicTacToe].

3. File Input/Output  
--> In each game, after playing the game, the file "counting.txt" will record who will the game. For example, if player 1 win in game one, which is "Eliminate Monsters", a record "Player 1" will be stored in the file. After playing three games, the code will read from the file "counting.txt" and a final result will be generated according to previous results.

4. Program codes in multiple files  
--> Each game program is in different files. It will only be compiled when it is called.

5. Proper indentation and naming styles  
--> Indentation is well constructed for easier understanding, e.g. indent once in every while/for loop. The vriable or function names are also very intuitive, e.g. update_range, target.
----------------------------------------------------------------------------------
**A list of non-standard C/C++ libraries**  
1. Including "Vector", "Random", "string", "fstream" etc.
They are used to store game status, generate random goals, or read input files etc.
----------------------------------------------------------------------------------
**Compilation and execution instructions**
1. Run "make clean" to clean the old file first.
2. Run "make main" to compile the file.
3. Run "./main" to start the game.
4. When the text "Press enter to start the game" shows up, what you need to do is press the "enter button", so that the game will be started.

**Guideline of Mini Games** 
1. Number Monster: in this game there will be three monsters, which are number based, generated and you can only type number 1 - 9 only, once you match the monster's number, the monster will be elinminated. Caution!!! The number of those monster will be changed in different times. 
For example, player 1 at first will input a number let say "3", and a set of monster "3, 4, 5" are generated, then the monster that matchs with 3 will be elinmiated, and player 1 just needs two monsters in the next round (after player 2 input). In other case, monsters "3, 3, 4" are generated, then two monters will be elinminated at the same time. 
The fastest player to eliminate all monsters win!

2. Guess_Your_Luck: In this game, you and your friend will compete in guess the correct **Golden Number**. The dynamic range is initialize between [0,100] inclusive at the beginning of the game. It will modify and be more precise according to your guesses. The first player guess the **Golden Number** wins!

3. TicTacToe: Caution!!! Player 1 is in the role of **"X"** and Player 2 is in the role of **"O"** in the game. At first, player 1 will take the move first.
For the input of the game, please fill in the row and column with space to sperate them. For example, 1 2, which means row(1) and column (2).
One of the player strike to line up their symbol 3 in a row in any directions win.
==================================================================================
