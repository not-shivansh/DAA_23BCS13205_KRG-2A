#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Structure to represent an edge
struct Edge {
    int from, to, weight;
};

// Function to run Dijkstra's algorithm
vector<int> dijkstra(int n, int start, vector<vector<pair<int,int>>> &adj) {
    vector<int> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Function to run Bellman-Ford algorithm
vector<int> bellmanFord(int n, int start, vector<Edge> &edges) {
    vector<int> dist(n, INF);
    dist[start] = 0;

    for(int i = 0; i < n-1; i++) {
        for(auto e : edges) {
            if(dist[e.from] < INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    // Check for negative cycles
    for(auto e : edges) {
        if(dist[e.from] < INF && dist[e.from] + e.weight < dist[e.to]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return {};
        }
    }

    return dist;
}

// Function to print distances along with city names
void printDistances(vector<int> &dist, vector<string> &cities) {
    cout << "\nShortest distances from source city:\n";
    for(int i = 0; i < dist.size(); i++) {
        cout << cities[i] << ": ";
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << " km" << endl;
    }
}

int main() {
    // Example: 6 Indian cities
    vector<string> cities = {"Delhi", "Mumbai", "Bangalore", "Kolkata", "Chennai", "Hyderabad"};
    int n = cities.size();

    // Graph edges with distances in km
    vector<Edge> edges = {
        {0, 1, 1400}, // Delhi -> Mumbai
        {0, 3, 1500}, // Delhi -> Kolkata
        {1, 2, 980},  // Mumbai -> Bangalore
        {1, 4, 1330}, // Mumbai -> Chennai
        {2, 4, 350},  // Bangalore -> Chennai
        {2, 5, 570},  // Bangalore -> Hyderabad
        {3, 4, 1650}, // Kolkata -> Chennai
        {3, 5, 1500}, // Kolkata -> Hyderabad
        {4, 5, 630}   // Chennai -> Hyderabad
    };

    vector<vector<pair<int,int>>> adj(n);
    for(auto e : edges) {
        adj[e.from].push_back({e.to, e.weight});
        // For undirected graph (two-way roads), uncomment next line
        // adj[e.to].push_back({e.from, e.weight});
    }

    int start;
    cout << "Select source city:\n";
    for(int i = 0; i < n; i++) {
        cout << i << ": " << cities[i] << endl;
    }
    cin >> start;

    // Dijkstra's Algorithm
    vector<int> dijkstraDist = dijkstra(n, start, adj);
    cout << "\nDijkstra's Algorithm Results:";
    printDistances(dijkstraDist, cities);

    // Bellman-Ford Algorithm
    vector<int> bfDist = bellmanFord(n, start, edges);
    if(!bfDist.empty()) {
        cout << "\nBellman-Ford Algorithm Results:";
        printDistances(bfDist, cities);
    }

    return 0;
}
