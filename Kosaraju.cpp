#include <vector>
#include <stack>
using namespace std;

/**
 * Class to compute the number of Strongly Connected Components (SCCs)
 * in a directed graph using Kosaraju's Algorithm.
 */
class Solution {
public:

    /**
     * First DFS to fill stack based on finishing times of nodes.
     * Nodes are pushed to stack after exploring all descendants.
     */
    void dfsFill(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
        visited[u] = true;

        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }

        st.push(u);  // Push after visiting all reachable nodes
    }

    /**
     * Second DFS on the reversed graph to explore all nodes in a component.
     */
    void dfsTraverse(int u, vector<vector<int>>& adjReversed, vector<bool> &visited) {
        visited[u] = true;

        for (int &v : adjReversed[u]) {
            if (!visited[v]) {
                dfsTraverse(v, adjReversed, visited);
            }
        }
    }

    /**
     * Main function implementing Kosaraju’s Algorithm.
     *
     * @param V    Number of vertices
     * @param adj  Adjacency list of the original directed graph
     * @return     Count of Strongly Connected Components
     */
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);

        // Step 1: Fill stack with nodes ordered by finish time using DFS
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> adjReversed(V);
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                adjReversed[v].push_back(u); // Reverse the edge
            }
        }

        // Step 3: Perform DFS on reversed graph in stack order
        visited.assign(V, false);
        int count = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++; // Each DFS marks one SCC
            }
        }

        return count;
    }
};
