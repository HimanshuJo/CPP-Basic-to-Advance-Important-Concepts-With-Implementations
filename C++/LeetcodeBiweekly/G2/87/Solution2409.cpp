// 2409. Count Days Spent Together
/*
Alice and Bob are traveling to Rome for separate business meetings.

You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. 
Alice will be in the city from the dates arriveAlice to leaveAlice (inclusive), while Bob 
will be in the city from the dates arriveBob to leaveBob (inclusive). 

Each will be a 5-character string in the format "MM-DD", corresponding to the month and day of the date.

Return the total number of days that Alice and Bob are in Rome together.

You can assume that all dates occur in the same calendar year, which is not a leap year. 
Note that the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

Example 1:

Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
Output: 3
Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 to August 19. 
They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

Example 2:

Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
Output: 0
Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.
 

Constraints:

All dates are provided in the format "MM-DD".
Alice and Bob's arrival dates are earlier than or equal to their leaving dates.
The given dates are valid dates of a non-leap year.
*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>mnth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string bobarrvmnth="";
        bobarrvmnth+=arriveBob[0], bobarrvmnth+=arriveBob[1];
        int bobArrv=stoi(bobarrvmnth);
        string boblvmnth="";
        boblvmnth+=leaveBob[0], boblvmnth+=leaveBob[1];
        int bobLv=stoi(boblvmnth);
        map<int, vector<int>>bobdays;
        string tempbgn__="";
        tempbgn__+=arriveBob[3], tempbgn__+=arriveBob[4];
        int bobbgndy=stoi(tempbgn__);
        string tempend__="";
        tempend__+=leaveBob[3], tempend__+=leaveBob[4];
        int boblvdy=stoi(tempend__);
        if(bobArrv==bobLv){
            vector<int>bobdy;
            for(int i=bobbgndy; i<=boblvdy; ++i){
                bobdy.push_back(i);
            }
            bobdays[bobArrv]=bobdy;
        } else{
            int bobbgnend=mnth[bobArrv-1];
            vector<int>bobdy;
            for(int i=bobbgndy; i<=bobbgnend; ++i){
                bobdy.push_back(i);
            }
            bobdays[bobArrv]=bobdy;
            int tempbgn___=bobArrv;
            tempbgn___++;
            while(tempbgn___!=bobLv){
                vector<int>bobdy__;
                int curmnthend=mnth[tempbgn___-1];
                for(int i=1; i<=curmnthend; ++i){
                    bobdy__.push_back(i);
                }
                bobdays[tempbgn___]=bobdy__;
                tempbgn___++;
            }
            int fnmnthend=mnth[bobLv-1];
            vector<int>bobdy____;
            for(int i=1; i<=boblvdy; ++i){
                bobdy____.push_back(i);
            }
            bobdays[bobLv]=bobdy____;
        }
        string alicearrvmnth="";
        alicearrvmnth+=arriveAlice[0], alicearrvmnth+=arriveAlice[1];
        int aliceArrv=stoi(alicearrvmnth);
        string alicelvmnth="";
        alicelvmnth+=leaveAlice[0], alicelvmnth+=leaveAlice[1];
        int aliceLv=stoi(alicelvmnth);
        map<int, vector<int>>alicedays;
        string tempbgn="";
        tempbgn+=arriveAlice[3], tempbgn+=arriveAlice[4];
        int alicebgndy=stoi(tempbgn);
        string tempend="";
        tempend+=leaveAlice[3], tempend+=leaveAlice[4];
        int alicelvdy=stoi(tempend);
        if(aliceArrv==aliceLv){
            vector<int>aldy;
            for(int i=alicebgndy; i<=alicelvdy; ++i){
                aldy.push_back(i);
            }
            alicedays[aliceArrv]=aldy;
        } else{
            int alicebgnend=mnth[aliceArrv-1];
            vector<int>aldy;
            for(int i=alicebgndy; i<=alicebgnend; ++i){
                aldy.push_back(i);
            }
            alicedays[aliceArrv]=aldy;
            int tempbgn_=aliceArrv;
            tempbgn_++;
            while(tempbgn_!=aliceLv){
                vector<int>aldy__;
                int curmnthend=mnth[tempbgn_-1];
                for(int i=1; i<=curmnthend; ++i){
                    aldy__.push_back(i);
                }
                alicedays[tempbgn_]=aldy__;
                tempbgn_++;
            }
            int fnmnthend=mnth[aliceLv-1];
            vector<int>aldy_;
            for(int i=1; i<=alicelvdy; ++i){
                aldy_.push_back(i);
            }
            alicedays[aliceLv]=aldy_;
        }
        int ans=0;
        for(auto &entries: bobdays){
            auto it=alicedays.find(entries.first);
            if(it!=alicedays.end()){
                vector<int>bobentr=entries.second;
                vector<int>aliceentr=alicedays[entries.first];
                for(auto &vals: bobentr){
                    auto itt=find(aliceentr.begin(), aliceentr.end(), vals);
                    if(itt!=aliceentr.end()){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};