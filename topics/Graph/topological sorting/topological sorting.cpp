/*
 * -> This is coded by Mina Demyan
 * - This code detects if there is a cycle in a directed graph or not.
 * - You can use it to check if a graph is a DAG (Directed Acyclic Graph).
 * - It also performs topological sorting if the graph is a DAG.
 */
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

const int N = 1e5;
bool vis[N];  // Array to keep track of visited nodes
bool inStack[N];  // Array to keep track of nodes in the current DFS path
vector<int> adj[N];  // Adjacency list to store the graph
int n, m;  // Number of nodes and edges
deque<int> dq;  // Deque to store the nodes in topological order

// Depth First Search function to detect cycles and perform topological sorting
bool dfs(int node) {
    vis[node] = true;  // Mark the current node as visited
    inStack[node] = true;  // Mark the current node as part of the current DFS path

    for (auto u : adj[node]) {  // Iterate through all adjacent nodes
        if (!vis[u]) {  // If the adjacent node is not visited
            if (dfs(u)) return true;  // Recursively visit the adjacent node; if a cycle is detected, return true
        } else if (inStack[u]) {  // If the adjacent node is in the current DFS path
            return true;  // Cycle detected, return true
        }
    }

    dq.emplace_front(node);  // Add the current node to the front of the deque for topological sorting
    inStack[node] = false;  // Remove the current node from the current DFS path
    return false;  // No cycle detected from this path, return false
}

// Function to check for cycles in the graph
bool isCycle() {
    for (int node = 1; node <= n; ++node) {  // Iterate through all nodes
        if (!vis[node]) {  // If the node is not visited
            if (dfs(node)) return true;  // Call DFS; if a cycle is detected, return true
        }
    }
    return false;  // No cycle detected in any component, return false
}

int main() {
    cin >> n >> m;  // Read the number of nodes and edges
    int a, b;
    for (int i = 0; i < m; ++i) {  // Read all edges
        cin >> a >> b;
        adj[a].emplace_back(b);  // Add an edge from a to b
    }

    // Check if there is a cycle in the graph
    if (isCycle()) {
        cout << "Cycle detected." << endl;
    } else {
        cout << "No cycle detected." << endl;
        cout << "The graph is a Directed Acyclic Graph (DAG)." << endl;
        // Perform topological sorting if the graph is a DAG
        for (auto t : dq) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}
