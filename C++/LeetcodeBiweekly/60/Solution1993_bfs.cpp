#include<bits/stdc++.h>
using namespace std;

class LockingTree
{
public:
    vector<int> m;
    vector<vector<int>> children;
    vector<int> parent;

    LockingTree(vector<int> &parent)
    {
        m = vector<int>(parent.size());
        children = vector<vector<int>>(parent.size());
        this->parent = parent;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == -1)
                continue;
            children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user)
    {
        if (m[num] > 0)
            return false; //already locked
        m[num] = user;    //node is locked by user
        return true;
    }

    bool unlock(int num, int user)
    {
        if (m[num] != user)
            return false; //node is locked by some other user
        if (m[num] == 0)
            return false; //node is not locked at all
        m[num] = 0;       //unlock the lock and return true
        return true;
    }

    bool upgrade(int num, int user)
    {
        int k = num;
        while (k != -1)
        {
            if (m[k] > 0)
                return false; //atleast one of the ancestor is locked and hence return false
            k = parent[k];
        }

        //bfs
        queue<int> q;
        q.push(num);

        bool flag = false;
        while (!q.empty())
        {
            auto z = q.front();
            q.pop();
            for (auto i : children[z])
            {
                if (m[i] > 0)
                { //atleast one in descendants is locked, hence flag is true
                    m[num] = user;
                    m[i] = 0; //unlock it
                    flag = true;
                }
                q.push(i);
            }
        }

        if (flag)
            return true;
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */