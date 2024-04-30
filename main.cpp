#include <iostream>
#include <string>
#include <fstream>
#include <thread> 
#include <chrono>

#include "NumMonster.h"
#include "Guess_Your_Luck.h"
#include "tictactoe.h"

using namespace std;

int main() {

    string con;
    string player1 = "Player 1", player2 = "Player 2";

    cout << "Welcome to Mini-Hub" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000)); 
    cout << "This is a game for two players." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "You will play three different games." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "In each game, the player who wins will gain a mark." << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "After three games, whoever has the highest mark will be the winner!!!" << endl;
    cout << "Press enter to start the game" << endl;
    getline(cin, con);
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "============= Game 1: Number Monsters =============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    eliminate(player1, player2);
    cout << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "============= Game 2: Guess Your Luck =============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    Guess_Your_Luck(player1, player2);
    cout << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
