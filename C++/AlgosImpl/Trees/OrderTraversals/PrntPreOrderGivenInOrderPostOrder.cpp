#include<bits/stdc++.h>
using namespace std;

int postIndex=0;

int search(int in[], int data, int n){
    for(int i=0; i<n; ++i){
        if(in[i]==data){
            return i;
        }
    }
    return 0;
}

void dfsPreOrder(int in[], int post[], int inStrt, int inEnd, stack<int>&stk, int n){
    if(inStrt>inEnd){
        return;
    }
    int val=post[postIndex];
    int inIndex=search(in, val, n);
    postIndex--;
    dfsPreOrder(in, post, inIndex+1, inEnd, stk, n);
    dfsPreOrder(in, post, inStrt, inIndex-1, stk, n);
    stk.push(val);
}

void prntPre(int in[], int post[], int n){
    int len=n;
    postIndex=len-1;
    stack<int>stk;
    dfsPreOrder(in, post, 0, len-1, stk, n);
    while(stk.size()>0){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main(){

            /*
                     1
                   /   \
                  2     3
                 / \     \
                4   5     6  

            */

    int in[]{4, 2, 5, 1, 3, 6};
    int post[]{4, 5, 2, 6, 3, 1};
    int n=sizeof(in)/sizeof(int);
    prntPre(in, post, n);
    return 0;
}

// 1 2 4 5 3 6 