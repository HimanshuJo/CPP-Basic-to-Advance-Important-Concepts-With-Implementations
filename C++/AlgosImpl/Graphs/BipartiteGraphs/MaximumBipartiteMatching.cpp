// Maximum Bipartite Matching
/*
A matching in a Bipartite Graph is a set of the edges chosen in such a way that no two edges share an endpoint.

A maximum matching is a matching of maximum size (maximum number of edges). 
In a maximum matching, if any edge is added to it, it is no longer a matching. 
There can be more than one maximum matchings for a given Bipartite Graph. 

Why do we care? 

There are many real world problems that can be formed as Bipartite Matching. 
For example, consider the following problem:

“There are M job applicants and N jobs. Each applicant has a subset of jobs that he/she is interested in. 
Each job opening can only accept one applicant and a job applicant can be appointed for only one job. 

Find an assignment of jobs to applicants in such that as many applicants as possible get jobs.”
*/

#include<iostream>
#include<string.h>
using namespace std;

#define M 6
#define N 6

// Returns true if a matching for a vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[]){
	// Trying every job
	for(int v=0; v<N; ++v){
		/*
			If an applicant is interested in the job v and v is not visited
		*/
		if(bpGraph[u][v]&&!seen[v]){
			seen[v]=true;
			/*
				If job v is not assigned to an applicant OR previously assigned
				applicant for job v(which is matchR[v]) has an alternate job available

				Since v is marked as visited in the above line, matchR[v] in the following
				recursive calls will not get the job v again
			*/
			if(matchR[v]<0||bpm(bpGraph, matchR[v], seen, matchR)){
				matchR[v]=u;
				return true;
			}
		}
	}
	return false;
}

int maxBPM(bool bpGraph[M][N]){
	/*
		Keeping track of the applicants assigned to the jobs. The value of matchR[i]
		is the applicant number assigned to job i

		The value of -1 indicate nobody is assigned
	*/
	int matchR[N];
	memset(matchR, -1, sizeof(matchR));
	int res=0;
	for(int u=0; u<M; ++u){
		bool seen[N];
		memset(seen, 0, sizeof(seen));
		if(bpm(bpGraph, u, seen, matchR)){
			res++;
		}
	}
	return res;
}

int main()
{
    /*
    	Participant			Jobs
    		0               0  1  2  3  4  5
    	   ...				...
    */
    bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0},
                          {1, 0, 0, 1, 0, 0},
                          {0, 0, 1, 0, 0, 0},
                          {0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 1}};
 
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);
 
    return 0;
}