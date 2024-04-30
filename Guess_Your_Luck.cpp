#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <list>
#include <vector>
#include <random>
#include <map>
#include <string>
#include <fstream>
#include "Guess_Your_Luck.h"
using namespace std;

bool update_range(int target, int guess, int range[]) {
    if (guess > target) {
        range[1] = guess;
        cout << "Please guess a number between " << range[0] << " to " << range[1] << endl;
        return true;
    } else if (guess < target) {
        range[0] = guess;
        cout << "Please guess a number between " << range[0] << " to " << range[1] << endl;
        return true;
    } else {
        cout << "GOLDEN NUMBER " << target << " IS FOUND!!!" << endl;
        return false;
    }
}

void Guess_Your_Luck(string player1, string player2) {
    int turn = 0;
    bool p1turn = true;
    int guess = 0;
    string players[] = {player1, player2};
    srand(time(0));
    int target = rand() % 100;
    int* range = new int[2];
    range[0] = 0;
    range[1] = 100;
    cout << "========================================================================================" << endl;
    cout << "Welcome to the game of <Guess_Your_Luck>." << endl;
    cout << "In this game, Players are taking turns to guess the <Golden Number>." << endl;
    cout << "The range of the number is initialized between [0,100], and it will be updated according to your guesses." << endl;
    cout << "WISH YOU LUCK!" << endl;
    cout << "========================================================================================" << endl;
    cout << "Guess a number between " << range[0] << " to " << range[1] << endl;

    while (true) {
        if (p1turn) {
            while (true) { //make sure valid input
                    cout << player1 << ", choose a number: ";
                    cin >> guess;
                if ((guess < range[0]) || (guess > range[1])) {
                    cout << "Error: invalid input" << endl;
                    continue;
                } 
                else{
                    break; //break the inside while loop
                }
            }
            update_range(target, guess,range); //update the range
            turn++;
            p1turn = false; //change player

        } else {
            while (true) {
                    cout << player2 << ", choose a number: ";
                    cin >> guess;
                if ((guess < range[0]) || (guess > range[1])) {
                    cout << "Error: invalid input" << endl;
                    continue;
                } else {
                    break;
                }
            }
            update_range(target, guess,range); //update the range
            turn++;
            p1turn = true; //change player
            }
        if (guess == target)  //correct guess
            break; //exit the guessing period
        }

    cout << "========================================================================================" << endl;
    cout << "Winner is ..." << players[(turn + 1) % 2] << endl;
    delete[] range;
    cout << "Congratulations! " << players[(turn+1) % 2] << " Has better luck than " << players[(turn%2)] << endl;
    cout << "========================================================================================" << endl;
    string count = players[(turn + 1) % 2];
    ofstream fout;
    fout.open("counting.txt", ios::app);
    if (fout.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
        }
    fout << count << endl;
    fout.close();
}
