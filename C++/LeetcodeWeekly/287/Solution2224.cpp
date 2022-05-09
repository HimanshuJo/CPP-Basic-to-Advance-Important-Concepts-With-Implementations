// 2224. Minimum Number of Operations to Convert Time
/*
You are given two strings current and correct representing two 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is 
between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes. 
You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.

Example 1:

Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.
Example 2:

Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.
 

Constraints:

current and correct are in the format "HH:MM"
current <= correct
*/

class Solution {
public:
    int convertTime(string current, string correct) {
        int bgnH=stoi(current.substr(0, 2)), bgnM=stoi(current.substr(3, 2));
        int endH=stoi(correct.substr(0, 2)), endM=stoi(correct.substr(3, 2));
        int totBgnMin=bgnH*60+bgnM, totEndMin=endH*60+endM;
        int temp1=totBgnMin, temp2=totEndMin;
        int res=0;
        while(temp1+60<=temp2){
            temp1+=60;
            res++;
        }
        if(temp1!=temp2){
            while(temp1+15<=temp2){
                temp1+=15;
                res++;
            }
        }
        if(temp1!=temp2){
            while(temp1+5<=temp2){
                temp1+=5;
                res++;
            }
        }
        if(temp1!=temp2){
            while(temp1+1<=temp2){
                temp1+=1;
                res++;
            }
        }
        return res;
    }
};