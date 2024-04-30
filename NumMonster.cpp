#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <string>
#include <fstream>
#include "NumMonster.h"
using namespace std;

void counting(string count){ //function for record which player win the game
    ofstream fout;
    fout.open("counting.txt", ios::app);
    if (fout.fail()) {
        cout << "Error in file opening!" << endl;
        exit(1);
        }
    fout << count << endl;
    fout.close();
}

void genmonster(int m, vector<int>& mlist) { //function for generating the random monster
    mlist.clear();
    random_device rd; //to make sure the random number generated is different every time
    mt19937 gen(rd()); 
    uniform_int_distribution<int> dis(1, 9);
    for (int i = 0; i < m; i++) {
        int mon = dis(gen);
        mlist.push_back(mon);
    }
    
}

int killmonster(int skillnum, vector<int> monlst, int m) { //function to check whether player can kill the monster
    int duplicate = 0;
    for (int i = 0; i < m; i++) {
        if (monlst[i] == skillnum) {
            duplicate++;
        }
    }
    cout << "You kill " << duplicate << " Monster." << endl;
    return duplicate;
}

void playersturn(int skillnum, string player, int &m, vector<int> mlist){ //function that let player input their skill number and report if the monster can be killed
    int duplicate = 0;
    while (true) {
            cout << player << "'s turn!" << endl;
            cout << "Number of monster left = " << m << endl;
            cout << player << ", Your Number: ";
            cin >> skillnum;
            if ((skillnum < 1)||(skillnum > 9)){
                cout << "Error: invalid input." << endl;
                continue;}
            else{
                break;
            }
        }
        genmonster(m, mlist);
        cout << "Monster are : " ;
        for (int i=0; i < mlist.size(); i++){
            cout << mlist[i] << "  ";
        }
        cout << endl;

        duplicate = killmonster(skillnum, mlist, m);
        m -= duplicate;

        cout << player << " still have " << m << " to eliminate!" <<endl;
        cout << endl;
}

void eliminate(string player1, string player2){// Mini game: Eliminate the numebr monster
    vector<int> m1list;
    vector<int> m2list;
    int skillnum = 0;
    int m1 = 3;
    int m2 = 3;
    bool p1turn = true;

    cout << "========================================================================================" << endl;
    cout << "𝓦𝓮𝓵𝓬𝓸𝓶𝓮 𝓽𝓸 𝓝𝓾𝓶𝓫𝓮𝓻 𝓜𝓸𝓷𝓼𝓽𝓮𝓻" << endl;
    cout << "𝓣𝓱𝓮 𝓜𝓸𝓷𝓼𝓽𝓮𝓻 𝔀𝓲𝓵𝓵 𝓫𝓮 𝓮𝓵𝓲𝓶𝓲𝓷𝓪𝓽𝓮𝓭, 𝔀𝓱𝓮𝓷 𝓶𝓪𝓬𝓽𝓬𝓱𝓲𝓷𝓰 𝓽𝓱𝓮 𝓼𝓪𝓶𝓮 𝓷𝓾𝓶𝓫𝓮𝓻" << endl;
    cout << "Caution!!! Input range 1-9 only!!!" << endl;
    cout << "========================================================================================" << endl;
    cout << "🄶 🄰 🄼 🄴  🄱 🄴 🄶 🄸 🄽 🅂  🄽 🄾 🅆 !" << endl;
    cout << "🄻 🄴 🅃 🅂  🄶 🄾 !" << endl;
    cout << endl;
   
    while (true) {
        if (p1turn) {
            playersturn(skillnum, player1, m1, m1list);
            p1turn = false;
            }
        else{
            playersturn(skillnum, player2, m2, m2list);
            p1turn = true;
        }
    if (m1 <= 0) {
        cout << "Congraduation!!! Winner is " << player1 << endl;
        string count = "Player 1";
        counting(count);
        break;
    }
    else if (m2 <= 0) {
        cout << "Congraduation!!! Winner is " << player2 << endl;
        string count = "Player 2";
        counting(count);
        break;
        }
    }
}


