
#include "PriorityQueue.h"
#include <vector>
#include <iostream>

class CallCenter
{
public:
	CallCenter();

	bool addCallToQueue(Call newCall);
	//input: Call Object
	//output: True if added. False if not added.
	//side effect: Increments callsEntered
	//side effect: adds call to priority queue
	//side effect: calls setCurrentCaller

	int getCallsWaiting();
	//output: size of wait list

	void updateCallCenter(int minute);
	//input: current iteration of simulation (minute)
	//side effect: Answers calls (Pops calls of priority queue)
	//side effect: calculates waitTime. Appends to allWaitTimes
	//in addition to either p1WaitTime, p2WaitTime, or p3WaitTime

	void displayCurrentStatus(int minute);
	//input: current iteration of simulation (minute)
	//side effect: prints the current simulation time
	//prints number of calls in the waiting list
	//prints number of calls completed


	void displaySimResults(int minute);
	//input: current iteration of simulation (minute)
	// side effect: Prints to terminal total calls entered/answerd
	// prints total time to answer all calls
	// total average wait time for calls to be answered
	// average wait time for priority 1, priority 2, and priority 3

private:
	PriorityQueue waitList;
	Call currentCall;
	//Inializes from caller at front of queue
	int answerTime;
	//Initalized from the current caller and decremented each minute
	int callsEntered;
	//tracks how many calls are received
	int callsAnswered;
	//tracks how many calls are answered
	vector<int> p1WaitTime;
	//Vector to track to average wait time for priority1 calls
	vector<int> p2WaitTime;
	//Vector to track to average wait time for priority2 calls
	vector<int> p3WaitTime;
	//Vector to track to average wait time for priority3 calls
	vector<int> allWaitTimes;
	//Vector to track to average wait time for priority3 calls

	bool setCurrentCall();
	//output: True if currentCall was changed. False if not
	//side effect: initalizes currentCaller
	//side ffect: initalizes answerTime

	double getAverageWaitTime(vector<int> waitTime);
	//input: vector holding wait times
	//output: average of values inside vector
	
};