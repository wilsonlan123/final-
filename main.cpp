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

    cout << "============= Game 3: Tic Tac Toe =============" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    playGame();
    cout << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "Let's see the final result!!!" << endl;
    
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Loading" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Loading." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Loading.." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Loading..." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    // Reading results from the file
    ifstream fin("counting.txt");
    if (!fin) {
        cerr << "Error in file opening!" << endl;
        exit(1);
    }

    int count1 = 0, count2 = 0;
    string line;
    while (getline(fin, line)) {
        if (line.find("Player 1") != string::npos) {
            count1++;
        } else if (line.find("Player 2") != string::npos) {
            count2++;
        }
    }

    if (count1 > count2) {
        cout << " ██████╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗  █████╗ ████████╗██╗   ██╗██╗      █████╗ ████████╗██╗ ██████╗ ███╗   ██╗\n██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██║     ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║\n██║     ██║   ██║██╔██╗ ██║██║  ███╗██████╔╝███████║   ██║   ██║   ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║\n██║     ██║   ██║██║╚██╗██║██║   ██║██╔══██╗██╔══██║   ██║   ██║   ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║\n╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║██║  ██║   ██║   ╚██████╔╝███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║\n ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝" << endl; 
        cout << player1 << " wins!!!" << endl;
    } else if (count2 > count1) {
        cout << " ██████╗ ██████╗ ███╗   ██╗ ██████╗ ██████╗  █████╗ ████████╗██╗   ██╗██╗      █████╗ ████████╗██╗ ██████╗ ███╗   ██╗\n██╔════╝██╔═══██╗████╗  ██║██╔════╝ ██╔══██╗██╔══██╗╚══██╔══╝██║   ██║██║     ██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║\n██║     ██║   ██║██╔██╗ ██║██║  ███╗██████╔╝███████║   ██║   ██║   ██║██║     ███████║   ██║   ██║██║   ██║██╔██╗ ██║\n██║     ██║   ██║██║╚██╗██║██║   ██║██╔══██╗██╔══██║   ██║   ██║   ██║██║     ██╔══██║   ██║   ██║██║   ██║██║╚██╗██║\n╚██████╗╚██████╔╝██║ ╚████║╚██████╔╝██║  ██║██║  ██║   ██║   ╚██████╔╝███████╗██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║\n ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝" << endl; 
        cout << player2 << " wins!!!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
