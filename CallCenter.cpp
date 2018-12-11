#include "CallCenter.h"

CallCenter::CallCenter(){
	PriorityQueue waitList = PriorityQueue();
	callsEntered = 0;
	callsAnswered = 0;
}

bool CallCenter::addCallToQueue(Call newCall){
	int numCall = waitList.getLength();
	if(numCall< 1){
		currentCall = newCall;
		answerTime = currentCall.getAnswerTime();
	}
	waitList.Push(newCall);
	callsEntered++;
	if(waitList.getLength() == (numCall + 1)){
		return true;
	}
	else{
		return false;
	}
}
int CallCenter::getCallsWaiting(){
	return waitList.getLength();
}

bool CallCenter::setCurrentCall(){
	if(currentCall != waitList.Peek() && answerTime == 0){
		currentCall = waitList.Peek();
		answerTime = currentCall.getAnswerTime();
		return true;
	}
	else{
		return false;
	}
}

void CallCenter::updateCallCenter(int minute){

	if(answerTime <= 0){
		double waitTime = minute - waitList.Peek().getArrivalTime();
		allWaitTimes.push_back(waitTime);
		if(waitList.Peek().getPriority() == 1){
			p1WaitTime.push_back(waitTime);
		}
		else if(waitList.Peek().getPriority() == 2){
			p2WaitTime.push_back(waitTime);
		}
		else if(waitList.Peek().getPriority() == 3){
			p3WaitTime.push_back(waitTime);
		}
		if(!waitList.isEmpty()){
			waitList.Pop();
		}
		callsAnswered++;
		if(!waitList.isEmpty()){
			setCurrentCall();
		}				
	}
	else{
		answerTime--;
	}
	displayCurrentStatus(minute);
}

void CallCenter::displaySimResults(int minute){

	cout << "-----------------------------------" << endl;
	cout << "Total Number of calls entered: " << callsEntered << endl;
	cout << "Total Number of calls Answered " << callsAnswered << endl;
	cout << "Total Simulation time: " << minute << " minutes" << endl;
	cout << "Total Average Wait Time: " << getAverageWaitTime(allWaitTimes) << endl;
	cout << "Priority 1 Wait Time: " << getAverageWaitTime(p1WaitTime) << " minutes" << endl;
	cout << "Priority 2 Wait Time: " << getAverageWaitTime(p2WaitTime) << " minutes" << endl;
	cout << "Priority 3 Wait Time: " << getAverageWaitTime(p3WaitTime) << " minutes" << endl;
	cout << "###############################" << endl;
	cout << "End Simulation" << endl;

}

double CallCenter::getAverageWaitTime(vector<int> waitTime){
	double sum = 0;
	for(int i = 0; i < waitTime.size(); i++){
		sum = waitTime.at(i) + sum;
	}
	double average = sum / waitTime.size();
	return average;
}

void CallCenter::displayCurrentStatus(int minute){
	if( minute % 5 == 0){
			cout << "-------------------------------" << endl;
			cout << "Current Time Elapsed: " << minute << " minutes" << endl;
			cout << "Calls completed: " << callsAnswered << endl;
			cout << "Number of calls in the waiting list: " <<  waitList.getLength() << endl;
		}
}