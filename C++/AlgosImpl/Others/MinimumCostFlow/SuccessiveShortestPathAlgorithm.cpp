#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
struct Edge{
	int from, to, cap, cost;
};

vector<vector<int>>adj, cost, capacity;
const int INF=1e9;

void shortest_paths(int N, int VBegn, vector<int>&d, vector<int>&p){
	d.assign(N, INF);
	p.assign(N, -1);
	d[VBegn]=0;
	vector<bool>inq(N, false);
	queue<int>q;
	q.push(VBegn);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(auto &v: adj[u]){
			if(capacity[u][v]>0&&d[v]>d[u]+cost[u][v]){
				d[v]=d[u]+cost[u][v];
				p[v]=u;
				if(!inq[v]){
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}
}

int min_cost_flow(int N, vector<Edge>&edges, int K, int S, int T){
	adj.assign(N, vector<int>());
	cost.assign(N, vector<int>(N, 0));
	capacity.assign(N, vector<int>(N, 0));
	for(auto &e: edges){
		adj[e.from].push_back(e.to);
		adj[e.to].push_back(e.from);
		cost[e.from][e.to]=e.cost;
		cost[e.to][e.from]=-e.cost;
		capacity[e.from][e.to]=e.cap;
	}
	int flow=0, cost=0;
	vector<int>d, p;
	while(flow<K){
		shortest_paths(N, S, d, p);
		if(d[T]==INF) break;
		int f=K-flow;
		int curr=T;
		while(curr!=S){
			f=min(f, capacity[p[curr]][curr]);
			curr=p[curr];
		}
		flow+=f;
		cost+=f*d[T];
		curr=T;
		while(curr!=S){
			capacity[p[curr]][curr]-=f;
			capacity[curr][p[curr]]+=f;
			curr=p[curr];
		}
	}
	if(flow<K) return -1;
	return cost;
}
*/

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}


int main(){
	int N=2;
	vector<Edge>in{{1, 2, 1, 1}};
	int K=1, S=1, T=2;
	int ans=min_cost_flow(N, in, K, S, T);
	cout<<ans<<endl;
}