// Check if it is possible to assign values such 
// that all the given relations are satisfied
/*
Given an array of strings arr[], where each arr[i] is of the form “i==j” or “i!=j”, 
where i and j are variables representing relationships among them, 
the task is to check if it is possible to assign values to the 
variables that satisfy all the relations. If found to be true, then print “Yes”. 
Otherwise, print “No”.

Examples:

Input: arr[] = {“i==j”, ” j!=i”}
Output: No
Explanation:
First relation holds true for values i = 1 and j = 1, but the 
second relation fails for the same set of values. Therefore, print No.

Input: arr[] = {“p==q”, “q==r”, “p==r”]
Output: Yes
Explanation:
The assignment of the value 1 in p, q and r satisfies all 3 relations. 
Therefore, print “Yes”.
*/
/*
Approach: The approach for solving the given problem is to use Union-Find Algorithm. 
The idea is to traverse the array of strings and go to every equality 
relation and perform union operation on the two variables. 
After the traversal, go to every non-equality relation in each string 
and check if the parent of the two variables is the same or not.

Follow the steps below to solve the problem:

Initialize an array, parent[] of size 26 with 0 and a variable answer as 
true to store the required result.
Traverse the array parent[] using the variable i, and set parent[i] as i.
Now, traverse each string S in the array of strings and 
if the value of S[i][1] is ‘=’, then perform union operation on S[i][0 – ‘a’] 
and S[i][3 – ‘a’].
Again, traverse each the string S in the array of string and do the following:
If the value of S[i][1] is equal to ‘!’, store the parent of S[i][0 – ‘a’] 
and S[i][3 – ‘a’] in X and Y respectively.
If the value of X is equal to Y, set the answer as false.
After the above steps, if the value of the answer is true then print 
“Yes” else print “No”.
*/

#include<bits/stdc++.h>
using namespace std;

// Finding parent of each node
int find(int v, vector<int>&parent){
    if (parent[v]!=v){
        return parent[v]=find(parent[v], parent);
    }
    return v;
}

// Finding union of two variables
void unions(int a, int b, vector<int>&parent){
    int x=find(a, parent);
    int y=find(b, parent);
    if (x!=y){
        parent[x]=parent[y];
    }
}

/*
    To check whether it is possible to assign values to variables
    to satisfy the relations
*/
bool equationsPossible(vector<string>&relations){
    vector<int>parent(26, 0);
    for (int i=0; i<26; ++i){
        parent[i]=i;
    }
    int n=relations.size();
    for (auto string: relations){
        if (string[1]=='='){
            unions(string[0]-'a', string[3]-'a', parent);
        }
    }
    for (auto string: relations){
        if (string[1]=='!'){
            int x=find(string[0]-'a', parent);
            int y=find(string[3]-'a', parent);
            if (x==y){
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<string>relations={"i==j", "j!=i"};
    vector<string>relations2={"p==q", "q==r", "p==r"};
    if (equationsPossible(relations)){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
    cout<<"-------"<<endl;
    if (equationsPossible(relations2)){
        cout<<"YES"<<endl;
    } else{
        cout<<"NO"<<endl;
    }
    return 0;
}
