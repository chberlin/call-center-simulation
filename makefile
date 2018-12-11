assi4 : Main.o CallCenter.o Call.o PriorityQueue.o
	g++ Main.o CallCenter.o Call.o PriorityQueue.o -o run

CallCenter.o : CallCenter.cpp PriorityQueue.o
	g++ -c -std=c++11 CallCenter.cpp

Call.o : Call.cpp
	g++ -c -std=c++11 Call.cpp

PriorityQueue.o : PriorityQueue.cpp Call.o
	g++ -c -std=c++11 PriorityQueue.cpp

clean:
	rm*.o*.exe

