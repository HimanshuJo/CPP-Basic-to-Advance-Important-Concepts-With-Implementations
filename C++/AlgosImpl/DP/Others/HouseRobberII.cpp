// House Robber II
/*
Problem Statement:

Mr. X is a professional robber planning to rob houses along a street. 
Each house has a certain amount of money hidden. 

All houses along this street are arranged in a circle. 

That means the first house is the neighbor of the last one. 

Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. 
Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

Note:
It is possible for Mr. X to rob the same amount of money by looting two different sets of houses. 
Just print the maximum possible robbed amount, irrespective of sets of houses robbed.
*/

long long int hRUtil(vector<int>&values){
    int sz=values.size();
    long long int prev1=0, prev2=0;
    for(int i=0; i<sz; ++i){
        long long int pk=values[i], ntPk=0;
        if(i-2>=0){
            pk+=prev2;
        }
        ntPk+=prev1;
        long long int curr=max(pk, ntPk);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int sz=valueInHouse.size();
    if(sz==1) return valueInHouse[0];
    vector<int>temp1, temp2;
    for(int i=0; i<sz; ++i){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=sz-1) temp2.push_back(valueInHouse[i]);
    }
    long long int ans=max(hRUtil(temp1), hRUtil(temp2));
    return ans;
}