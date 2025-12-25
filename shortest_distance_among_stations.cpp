#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<int>> edges, int source)
{

    vector<pair<int, int>> adj[n + 1];
    for (auto e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto edge : adj[node])
        {
            int next = edge.first;
            int weight = edge.second;

            if (dist[next] > d + weight)
            {
                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "\nShortest distances from Station " << source << ":\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == source)
            continue;
        if (dist[i] == INT_MAX)
            cout << "Station " << i << " : Not reachable\n";
        else
            cout << "Station " << i << " : " << dist[i] << "\n";
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 4, 1},
        {3, 4, 3}};

    int source;
    cout << "Enter your preferred starting station (1 to " << n << "): ";
    cin >> source;

    if (source < 1 || source > n)
    {
        cout << "Invalid station number!\n";
        return 0;
    }

    dijkstra(n, edges, source);
    return 0;
}
