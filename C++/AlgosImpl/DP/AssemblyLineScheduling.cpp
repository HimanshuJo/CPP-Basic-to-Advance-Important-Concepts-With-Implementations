// Assembly Line Scheduling
/*
A car factory has two assembly lines, each with n stations. 
A station is denoted by Si,j where i is either 1 or 2 and indicates the assembly line 
the station is on, and j indicates the number of the station. 

The time taken per station is denoted by ai,j. 

Each station is dedicated to some sort of work like engine fitting, body fitting, painting, and so on. 
So, a car chassis must pass through each of the n stations in order before exiting the factory. 

The parallel stations of the two assembly lines perform the same task. 
After it passes through station Si,j, it will continue to station Si,j+1 
unless it decides to transfer to the other line. 

Continuing on the same line incurs no extra cost, but transferring from line i at station j – 1 
to station j on the other line takes time ti,j. 

Each assembly line takes an entry time ei and exit time xi which may be different for the two lines. 
Give an algorithm for computing the minimum time it will take to build a car chassis

Breaking the problem into smaller sub-problems: 

We can easily find the ith factorial if (i-1)th factorial is known. 
Can we apply the similar funda here? 

If the minimum time taken by the chassis to leave station Si, j-1 is known, 
the minimum time taken to leave station Si, j can be calculated quickly by combining ai, j and ti, j.

T1(j) indicates the minimum time taken by the car chassis to leave station j on assembly line 1.
T2(j) indicates the minimum time taken by the car chassis to leave station j on assembly line 2.

Base cases: 
The entry time ei comes into picture only when the car chassis enters the car factory.
Time taken to leave the first station in line 1 is given by: 
T1(1) = Entry time in Line 1 + Time spent in station S1,1 
T1(1) = e1 + a1,1 

Similarly, time taken to leave the first station in line 2 is given by: 
T2(1) = e2 + a2,1

Recursive Relations: 
If we look at the problem statement, it quickly boils down to the below observations: 
The car chassis at station S1,j can come either from station S1, j-1 or station S2, j-1.

-------

Case #1: Its previous station is S1, j-1 
The minimum time to leave station S1,j is given by: 
T1(j) = Minimum time taken to leave station S1, j-1 + Time spent in station S1, j 
T1(j) = T1(j-1) + a1, j

Case #2: Its previous station is S2, j-1 
The minimum time to leave station S1, j is given by:

T1(j) = Minimum time taken to leave station S2, j-1 + 
        Extra cost incurred to change the assembly line + 
        Time spent in station S1, j 
T1(j) = T2(j-1) + t2, j + a1, j

The minimum time T1(j) is given by the minimum of the two obtained in cases #1 and #2. 
T1(j) = min((T1(j-1) + a1, j), (T2(j-1) + t2, j + a1, j))

Similarly, the minimum time to reach station S2, j is given by: 
T2(j) = min((T2(j-1) + a2, j), (T1(j-1) + t1, j + a2, j))

The total minimum time taken by the car chassis to come out of the factory is given by: 
Tmin = min(Time taken to leave station Si,n + Time taken to exit the car factory) 
Tmin = min(T1(n) + x1, T2(n) + x2) 
*/

#include<vector>
#include<iostream>
using namespace std;

int carAssembly(vector<vector<int>>&tTakenPerStat, vector<vector<int>>&extrCstIncur, int numStations, 
	            vector<int>&entryT, vector<int>&exitT){
	vector<int>tTakenToLeaveL1(numStations, 0), tTakenToLeaveL2(numStations, 0);
	int entryTL1=entryT[0], tSpntinStat1L1=tTakenPerStat[0][0];
	int entryTL2=entryT[1], tSpntinStat1L2=tTakenPerStat[1][0];
	int tTakenToLvFrstStatFrstL=entryTL1+tSpntinStat1L1;
	int tTakenToLvFrstStatSecL=entryTL2+tSpntinStat1L2;
	tTakenToLeaveL1[0]=tTakenToLvFrstStatFrstL, tTakenToLeaveL2[0]=tTakenToLvFrstStatSecL;
	for(int i=1; i<numStations; ++i){
		tTakenToLeaveL1[i]=min(tTakenToLeaveL1[i-1]+tTakenPerStat[0][i],
			                   tTakenToLeaveL2[i-1]+extrCstIncur[1][i]+tTakenPerStat[0][i]);
		tTakenToLeaveL2[i]=min(tTakenToLeaveL2[i-1]+tTakenPerStat[1][i],
	                           tTakenToLeaveL1[i-1]+extrCstIncur[0][i]+tTakenPerStat[1][i]);
	}
	return min(tTakenToLeaveL1[numStations-1]+exitT[0], tTakenToLeaveL2[numStations-1]+exitT[1]);
}

int main(){
	// 0->line, 1->station
	vector<vector<int>>tTakenPerStat{{4, 5, 3, 2}, {2, 10, 1, 4}};
	vector<vector<int>>extrCstIncur{{0, 7, 4, 5}, {0, 9, 2, 8}};
	vector<int>entryT{10, 12};
	vector<int>exitT{18, 7};
	int numStations=tTakenPerStat[0].size();
	int res=carAssembly(tTakenPerStat, extrCstIncur, numStations, entryT, exitT);
	cout<<res<<endl;
}