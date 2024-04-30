#ifndef NUMMONSTER_H
#define NUMMONSTER_H

#include <vector>
#include <string>
using namespace std;

void counting(const string);
void genmonster(int, vector<int>&);
int killmonster(int, vector<int>, int);
void playersturn(int, string, int&, vector<int>);
void eliminate(string, string);

#endif
