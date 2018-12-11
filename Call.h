#ifndef call_
#define call_
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;




class Call{              
public:

   Call();
   //Default Constructor

   int getAnswerTime();
   //output: answerTime
   
   int getPriority();
   //output: priority

   int getArrivalTime();
   //output: arrivalTime;

   void setArrivalTime(int minute);
   //input: current iteration of simulation
   //side effect: sets arrival time
   void setPriority(int num);
   //input: a number 1-3
   //side effect: sets the priority

   bool operator!=(const Call &callObj);

   bool operator==(const Call &callObj);
   //input: Call object to be compared
   //output: true if equal. False if not equal

   bool operator>(const Call &callObj);
   //Overload > operator for Call class

   bool operator<(const Call &callObj);
   //Overload < operator for Call class

private:
      int arrivalTime;
      //time during the simulation at which the call arrived at the call center
      int priority;
      //randomly computed
      //10% have 1
      //30% have 2
      //60% have 3
      int answerTime;
      //time it takes to answer call
      //randomly computed between 3-8 minutes
};
#endif
