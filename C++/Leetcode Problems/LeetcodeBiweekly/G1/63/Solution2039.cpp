// 2039. The Time When the Network Becomes Idle
/*
There is a network of n servers, labeled from 0 to n - 1.
You are given a 2D integer array edges, where edges[i] = [ui, vi] indicates there is a
message channel between servers ui and vi, and they can pass any number of messages to each other
directly in one second.

You are also given a 0-indexed integer array patience of length n.

All servers are connected, i.e., a message can be passed from one server to any other server(s)
directly or indirectly through the message channels.

The server labeled 0 is the master server. The rest are data servers. Each data server needs to
send its message to the master server for processing and wait for a reply.

Messages move between servers optimally, so every message takes the least amount of time to
arrive at the master server. The master server will process all newly arrived messages instantly and
send a reply to the originating server via the reversed path the message had gone through.

At the beginning of second 0, each data server sends its message to be processed.
Starting from second 1, at the beginning of every second, each data server will check if it
has received a reply to the message it sent (including any newly arrived replies) from the master server:

If it has not, it will resend the message periodically. The data server i will resend the
message every patience[i] second(s), i.e., the data server i will resend the message
if patience[i] second(s) have elapsed since the last time the message was sent from this server.

Otherwise, no more resending will occur from this server.

The network becomes idle when there are no messages passing between servers or arriving at servers.

Return the earliest second starting from which the network becomes idle.

Input: edges = [[0,1],[1,2]], patience = [0,2,1]
Output: 8
Explanation:
At (the beginning of) second 0,
- Data server 1 sends its message (denoted 1A) to the master server.
- Data server 2 sends its message (denoted 2A) to the master server.

At second 1,
- Message 1A arrives at the master server. Master server processes message 1A instantly and sends a reply 1A back.

- Server 1 has not received any reply. 1 second (1 < patience[1] = 2) elapsed since this server has sent the message,
therefore it does not resend the message.

- Server 2 has not received any reply. 1 second (1 == patience[2] = 1) elapsed since this server has sent the message,
therefore it resends the message (denoted 2B).

At second 2,
- The reply 1A arrives at server 1. No more resending will occur from server 1.
- Message 2A arrives at the master server. Master server processes message 2A instantly and sends a reply 2A back.
- Server 2 resends the message (denoted 2C).
...
At second 4,
- The reply 2A arrives at server 2. No more resending will occur from server 2.
...
At second 7, reply 2D arrives at server 2.

Starting from the beginning of the second 8, there are no messages passing between servers or arriving at servers.
This is the time when the network becomes idle.

Input: edges = [[0,1],[0,2],[1,2]], patience = [0,10,10]
Output: 3
Explanation: Data servers 1 and 2 receive a reply back at the beginning of second 2.
From the beginning of the second 3, the network becomes idle.

Constraints:

n == patience.length
2 <= n <= 10^5
patience[0] == 0
1 <= patience[i] <= 10^5 for 1 <= i < n
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= ui, vi < n
ui != vi
There are no duplicate edges.
Each server can directly or indirectly reach another server.
*/

#define INF 999999999

class Solution1 {
public:
    
    void djikstras(vector<vector<pair<int, int>>>&gr, vector<int>&dist, int cursource){
        dist[cursource]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0, cursource});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                pair<int, int>cur=pq.top();
                pq.pop();
                int curvert=cur.second, curwt=cur.first;
                if(curwt>dist[curvert]) continue;
                for(auto &nei: gr[curvert]){
                    pair<int, int>temp=nei;
                    int nwvert=temp.first, nwwt=temp.second;
                    if(dist[curvert]+nwwt<dist[nwvert]){
                        dist[nwvert]=dist[curvert]+nwwt;
                        pq.push({dist[nwvert], nwvert});
                    }
                }
            }
        }
    }
    
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int sz=edges.size();
        vector<vector<pair<int, int>>>gr(sz+1);
        for(auto &vals: edges){
            gr[vals[0]].push_back({vals[1], 1});
            gr[vals[1]].push_back({vals[0], 1});
        }
        int nodes=patience.size();
        vector<int>dist(nodes+1, INT_MAX);
        djikstras(gr, dist, 0);
        int ans=INT_MIN;
        for(int i=1; i<nodes; ++i){
            if(dist[i]*2<=patience[i]){
                ans=max(ans, dist[i]*2);
            }
            else{
                if((dist[i]*2)%patience[i]==0){
                    ans=max(ans, dist[i]*2+(dist[i]*2-patience[i]));
                } else{
                    ans=max(ans, dist[i]*2+(dist[i]*2-(dist[i]*2%patience[i])));
                }
            }
        }
        return ans+1;
    }
};

// -------*******-------

class Solution2 {
public:

    void djikstra(vector<vector<pair<int, int>>>&gr, vector<int>&dist, int curSource) {
        dist[curSource] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, curSource});
        while (!pq.empty()) {
            int sz = pq.size();
            while (sz--) {
                pair<int, int>cur = pq.top();
                pq.pop();
                int curVert = cur.second;
                int curWt = cur.first;
                if (curWt > dist[curVert]) continue;
                for (auto &nei : gr[curVert]) {
                    pair<int, int>curpair = nei;
                    int nwV = curpair.first, nwW = curpair.second;
                    if (dist[curVert] + nwW < dist[nwV]) {
                        dist[nwV] = dist[curVert] + nwW;
                        pq.push({dist[nwV], nwV});
                    }
                }
            }
        }
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int sz = edges.size();
        vector<vector<pair<int, int>>>gr(sz + 1);
        for (auto &entries : edges) {
            gr[entries[0]].push_back({entries[1], 1});
            gr[entries[1]].push_back({entries[0], 1});
        }
        int sz_ = patience.size();
        vector<int>dist(sz_ + 1, INF);
        djikstra(gr, dist, 0);
        int ans = INT_MIN;
        for (int i = 1; i < sz_; ++i) {
            /* (dist[i] * 2 - 1) / patience[i] => gives us no. of messages sent by server i by 
            the time 1st message is acknowledged.
            */
            int extraPayload = (dist[i] * 2 - 1) / patience[i];
            /*
            since, the gap between two messages sent by server i is patience[i], 
            multiply total messages that were passed with patience[i] to
            get time when the last message was sent.
            */
            /*
            Note - we shouldn't multiply with time because that gives the total time taken by all messages. 
            We only need time when last msg has been acknowledged.
            */
            int lastOut = extraPayload * patience[i]; // find the last time when a data server sends a message
            int lastIn = lastOut + dist[i] * 2; // this is the result for current data server
            ans = max(ans, lastIn);
        }
        return ans + 1;
    }
};