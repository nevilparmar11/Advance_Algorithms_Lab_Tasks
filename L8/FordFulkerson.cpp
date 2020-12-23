/*
* @Author: nevil
* @Date:   2020-09-23 18:46:30
* @Last Modified by:   nevil
* @Last Modified time: 2020-09-23 18:57:36
*/

#include <bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{

    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return (visited[t] == true);
}

bool dfsutil(int rGraph[V][V], int s, int t, int parent[], bool visited[]) {
    visited[s] = true;
    for (int i = 0; i < V; i++) {
        if (visited[i] == false && rGraph[s][i] > 0 ) {
            parent[i] = s;
            dfsutil(rGraph, i, t, parent, visited);
        }
    }
    return (visited[t] == true);
}


void  fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;

    bool visited[V];
    memset(visited, 0, sizeof(visited));
    parent[s] = -1;


    while (dfsutil(rGraph, s, t, parent, visited))
    {
        int path_flow = INT_MAX;
        cout << t << " ";
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            cout << u << " ";
            path_flow = min(path_flow, rGraph[u][v]);

        }
        cout << "=>" << path_flow << " ";
        cout << "\n ";

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;

        memset(visited, 0, sizeof(visited));
        parent[s] = -1;

    }

    cout << "\nmax flow : " << max_flow << "\n";
}


int fordFulkerson2(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];

    int max_flow = 0;

    bool visited[V];
    memset(visited, 0, sizeof(visited));
    parent[s] = -1;


    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = INT_MAX;
        cout << t << " ";
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            cout << u << " ";
            path_flow = min(path_flow, rGraph[u][v]);

        }
        cout << "=>" << path_flow << " ";
        cout << "\n ";

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;

        memset(visited, 0, sizeof(visited));
        parent[s] = -1;

    }

    cout << "\nmax flow : ";
    return max_flow;
}


int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "possible path and max flow using dfs \n" << "\n" ;
    fordFulkerson(graph, 0, 5);


    cout << endl << endl;
    cout << "possible path and max flow using bfs \n" ;
    cout << fordFulkerson2(graph, 0, 5) << endl;
    return 0;
}
