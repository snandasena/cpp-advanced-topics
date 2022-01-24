//
// Created by sajith-csi on 1/18/2022.
//

#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int m_V;
    vector<vector<int>> m_adj;

    void DFS_Rec(int s, vector<bool> &visited)
    {
        visited[s] = true;
        cout << s << '\t';
        for (auto const &v: m_adj[s])
        {
            if (!visited[v])
            {
                DFS_Rec(v, visited);
            }
        }
    }

public:
    Graph(int v) : m_V(v), m_adj(v) {}

    void addEdge(int u, int v)
    {
        m_adj[u].push_back(v);
    }

    void BFS(int src)
    {
        queue<int> que;
        vector<bool> visited(m_V, false);
        que.push(src);
        visited[src] = true;
        while (!que.empty())
        {
            auto v = que.front();
            que.pop();
            cout << v << '\t';
            for (auto const &u : m_adj[v])
            {
                if (!visited[u])
                {
                    que.push(u);
                    visited[u] = true;
                }
            }
        }
        cout << endl;
    }

    void DFS(int s)
    {
        vector<bool> visited(m_V, false);
        DFS_Rec(s, visited);
        cout<<endl;
    }

    void DFSStack(int s)
    {
        vector<bool> visited(m_V, false);
        stack<int> stck;
        stck.push(s);
        visited[s] = true;
        int top;
        while (!stck.empty())
        {
            top = stck.top();
            stck.pop();
            cout << top << '\t';
            for (int const &ele: m_adj[top])
            {
                if (!visited[ele])
                {
                    stck.push(ele);
                    visited[ele] = true;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Graph G(5);
    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(1, 2);
    G.addEdge(3, 2);
    G.addEdge(3, 4);
//    G.BFS(0);
    G.DFS(0);
    G.DFSStack(0);


    return 0;
}