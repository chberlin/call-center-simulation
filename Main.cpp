
#include "Main.h"

int main(){
	bool legalDuration = false;
	bool legalProbablity = false;
	string stringDuration;
	string stringProb;
	int duration = 0;
	double callProbablity;

	while(legalDuration != true){
		cout << "How many minutes should the simulation accept new calls?  ";
		cin >> stringDuration;
		try{
			duration = std::stoi(stringDuration);
		}
		catch(...){
			cout << "invalid input" << endl;
			continue;
		}
		if(duration <= 0){
			cout << "invalid input" << endl;
		}
		else{
			legalDuration = true;
		}
	}
	cout << "Duration set to: " << duration << " minutes" << endl;

	while(legalProbablity != true){
		cout << "What is the probablity a call will arrive during a given minute (between 0.1 and 1.0)? ";
		cin >> stringProb;
		try{
			callProbablity = std::stod(stringProb);
		}
		catch (...){
			cout << "invalid input" << endl;
			continue;
		}
		if(callProbablity > 1 || callProbablity < .1){
			cout << "invalid input" << endl;
		}
		else{
			legalProbablity = true;
		}
	}
	cout << "Calls will arrive every " << int(duration/(duration * callProbablity)) << " minute[s] on average" << endl;


	runSimulation(duration, callProbablity);

	return 0;
}

void runSimulation(int duration, double callProbablity){
	CallCenter centerSimulation = CallCenter();
	//Incoming call dictates frequency of calls
	int incomingCall = (duration/(duration * callProbablity));
	int minute;
	srand(time (0));
	for (minute = 1; minute <= duration; minute++){		
		if( minute % incomingCall == 0){
			Call newCall = Call();
			newCall.setPriority(randomPriorityGenerator());
			newCall.setArrivalTime(minute);
			centerSimulation.addCallToQueue(newCall);
		}
		if(centerSimulation.getCallsWaiting()>0){
			centerSimulation.updateCallCenter(minute);
		}
	}
	while(centerSimulation.getCallsWaiting() > 0){
		minute++;
		centerSimulation.updateCallCenter(minute);
	}
	centerSimulation.displaySimResults(minute);
}

int randomPriorityGenerator(){
	int index = rand() % 10;
	vector<int> prioritySet;
	prioritySet.push_back(1);
	for(int i = 0; i <3; i++){
	prioritySet.push_back(2);
	}
	for(int i = 0; i < 6; i++){
		prioritySet.push_back(3);
	}
	return prioritySet.at(index);
}