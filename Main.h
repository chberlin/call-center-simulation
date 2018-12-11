#include "CallCenter.h"
#include "Call.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include<random>
#include <ctime>
using namespace std;

int main();
//side effect: prompts user for duration and call probability information
//side effect: calls runSimulation

void runSimulation(int duration, double callProbablity);
//input: duration, call probablity
//side effect: Creates Call center object, creates call objects, runs simulation loop

int randomPriorityGenerator();
//Output: Random priority from wegighted random averages
