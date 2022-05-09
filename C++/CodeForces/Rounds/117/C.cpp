// C. Chat Ban
/*
You are a usual chat user on the most famous streaming platform. Of course, there are some moments when you just want to 
chill and spam something.

More precisely, you want to spam the emote triangle of size k. It consists of 2k−1 messages. 
The first message consists of one emote, the second one — of two emotes, ..., the k-th one — of k emotes, 
the k+1-th one — of k−1 emotes, ..., and the last one — of one emote.

For example, the emote triangle for k=3 consists of 5 messages:

Of course, most of the channels have auto moderation. Auto moderator of the current chat will ban you right after you 
spam at least x emotes in succession (you can assume you are the only user in the chat). Now you are interested — 
how many messages will you write before getting banned? Or maybe you will not get banned at all 
(i.e. will write all 2k−1 messages and complete your emote triangle successfully)? 
Note that if you get banned as a result of writing a message, this message is also counted.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤10^4) — the number of test cases. The next t lines describe test cases.

The only line of the test case contains integers k and x (1≤k≤10^9;1≤x≤10^18).

Output
For each test case, print the number of messages you will write before getting banned for the corresponding values k and x.

Example
input
7
4 6
4 7
1 2
3 7
2 5
100 1
1000000000 923456789987654321

output
3
4
1
4
3
1
1608737403

Note
Let's analyze the test cases of the example.

In the first test case, you write three messages containing 1, 2 and 3 emotes respectively, 
and since 1+2+3≥6, you get banned after that.

In the second test case, you write four messages containing 1, 2, 3 and 4 emotes respectively, 
and since 1+2+3+4≥7, you get banned after that.

In the third test case, you write one message containing exactly 1 emote. 

It doesn't get you banned, since 1<2, but you have already finished posting your emote triangle. S
o you wrote one message successfully.

In the fourth test case, you write four messages containing 1, 2, 3 and 2 emotes respectively, 
and since 1+2+3+2≥7, you get banned after that.

In the fifth test case, you write three messages containing 1, 2 and 1 emote respectively. 
It doesn't get you banned, since 1+2+1<5, but you have already finished posting your emote triangle. 
So you wrote three messages successfully.

In the sixth test case, since x=1, you get banned as soon as you send your first message.

The seventh test case is too large to analyze, so we'll skip it.
*/
/*
Solution:

This is a pretty obvious binary search problem. If we get banned after y messages, 
we also get banned after y+1, y+2 and so on messages (and vice versa, if we don't get banned after y messages, 
we also don't get banned after y−1, y−2 and so on messages).

For simplicity, let's split the problem into two parts: when we check if we're getting banned after y messages, 
let's handle cases y<k and y≥k separately.

Recall that the sum of the arithmetic progression consisting of integers 1, 2, ..., y is y*(y+1)/2. Let it be cnt(y).

The first case is pretty simple: the number of emotes we send with y messages when y<k is y*(y+1)/2 which is cnt(y). 
So we only need to check if cnt(y)≥x.

The second case is a bit harder but still can be done using arithmetic progression formulas. 
Firstly, we send all messages for y≤k (the number of such messages is cnt(k)).

Then, we need to add (k−1)+(k−2)+…+(y−k) messages. This number equals to cnt(k−1)−cnt(2k−1−y) 
(i.e. we send all messages from k−1 to 1 and subtract messages from 1 to 2k−1−y from this amount). 
The final condition is cnt(k)+cnt(k−1)−cnt(2k−1−y)≥x.

Time complexity: O(logk) per test case.
*/

#include<iostream>
#include<vector>
#include<cmath>
using ll=long long;
using namespace std;

ll sumDigs(ll num){
	return (num*(num+1)/2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		ll k, x;
		cin>>k>>x;
		ll ans=2*k-1;
		ll l=1, r=2*k-1;
		while(l<=r){
			ll mid=l+(r-l)/2;
			ll req=0;
			if(mid>=k){
				req=sumDigs(k)+sumDigs(k-1)-sumDigs(2*k-1-mid);
			} else{
				req=(mid*(mid+1))/2;
			}
			if(req>=x){
				ans=mid;
				r=mid-1;
			} else{
				l=mid+1;
			}
		}
		cout<<ans<<"\n";
	}
}

