#include<bits/stdc++.h>
using namespace std;
int postIndex=0;

int search(int in[], int data, int n){
    for (int i=0; i<n; ++i){
        if (in[i]==data){
            return i;
        }
    }
    return 0;
}

void fillPre(int in[], int post[], int inStrt, int inEnd, stack<int>&s, int n){
    if (inStrt>inEnd){
        return;
    }
    int val=post[postIndex];
    int inIndex=search(in, val, n);
    postIndex--;
    fillPre(in, post, inIndex+1, inEnd, s, n);
    fillPre(in, post, inStrt, inIndex-1, s, n);
    s.push(val);
}

void prntPreMain(int in[], int post[], int n){
    int len=n;
    postIndex=len-1;
    stack<int>s;
    fillPre(in, post, 0, len-1, s, n);
    while (s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    int in[]={4, 2, 5, 1, 3, 6};
    int post[]={4, 5, 2, 6, 3, 1};
    int n=sizeof(in)/sizeof(int);
    prntPreMain(in, post, n);
}