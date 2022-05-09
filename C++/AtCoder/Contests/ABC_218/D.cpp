/* Problem Statement
We have N distinct points on a two-dimensional plane, numbered 1,2,…,N. 
Point i (1≤i≤N) has the coordinates (xi,yi).

How many rectangles are there whose vertices are among the given points and whose edges are 
parallel to the x- or y-axis?

Sample Input 1 

6
0 0
0 1
1 0
1 1
2 0
2 1

Sample Output 1 

3
There are three such rectangles:

the rectangle whose vertices are Points 1, 2, 3, 4,

the rectangle whose vertices are Points 1, 2, 5, 6,

and the rectangle whose vertices are Points 3, 4, 5, 6.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int answer=0;
    vector<pair<int, int>>points;
    for(int i=0; i<N; ++i){
        pair<int, int>tmp;
        int x, y;
        cin>>x>>y;
        tmp.first=x;
        tmp.second=y;
        points.push_back(tmp);
    }
    //sort(points.begin(), points.end());
    for(int i=0; i<points.size(); ++i)
    {
        for(auto j=i+1; j<points.size(); ++j)
        {
            pair<int, int> p1 = points[i];
            pair<int, int> p2 = points[j];

            if(p1.first == p2.first || p1.second == p2.second)
                continue;

            pair<int, int> p3 = make_pair(p1.first, p2.second);
            pair<int, int> p4 = make_pair(p2.first, p1.second);

            auto it1=find(points.begin(), points.end(), p3);
            auto it2=find(points.begin(), points.end(), p4);

            if(it1!=points.end()&&it2!=points.end()){
                answer++;
            }
        }
    }
    cout<<answer/2;
}