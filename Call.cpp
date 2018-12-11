#include "Call.h"     

Call::Call(){
	arrivalTime = 0;
	priority = -1;
	answerTime = rand()% 6 + 3;
}

int Call::getAnswerTime(){
	return answerTime;
}
int Call::getPriority(){
	return priority;
}
int Call::getArrivalTime(){
	return arrivalTime;
}
void Call::setArrivalTime(int minute){
	arrivalTime = minute;
}
void Call::setPriority(int num){
	priority = num;
}
bool Call::operator!=(const Call &callObj){
	Call firstCall;
	if(callObj.answerTime != firstCall.answerTime ||
		callObj.priority != firstCall.priority ||
		callObj.arrivalTime != firstCall.arrivalTime){
		return true;
	}
	else{
		return false;
	}
}


bool Call::operator==(const Call &callObj){
	Call firstCall;
	if(callObj.answerTime == firstCall.answerTime &&
		callObj.priority == firstCall.priority &&
		callObj.arrivalTime == firstCall.arrivalTime){
		return true;
	}
	else{
		return  false;
	}
}

bool Call::operator>(const Call &callObj){
	Call firstCall;
	if(firstCall.priority > callObj.priority){
		return true;
	}
	else{
		return false;
	}
}

bool Call::operator<(const Call &callObj){
	Call firstCall;
	if(firstCall.priority < callObj.priority){
		return true;
	}
	else{
		return false;
	}
}