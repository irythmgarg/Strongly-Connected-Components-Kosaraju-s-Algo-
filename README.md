# Strongly-Connected-Components-Kosaraju-s-Algo-

# 🔁 Kosaraju's Algorithm – Strongly Connected Components (SCC) in Directed Graph

This repository implements **Kosaraju's Algorithm** in C++ to find the **number of Strongly Connected Components (SCCs)** in a directed graph using depth-first search (DFS) and graph reversal.

---

## 📌 Problem Statement

Given a **directed graph**, identify how many **strongly connected components (SCCs)** it contains. An SCC is a maximal group of vertices such that each vertex is reachable from every other vertex in the group.

---

## ⚙️ Algorithm Overview

Kosaraju’s Algorithm performs the following steps:

1. **DFS to compute finish times** of vertices and store in a stack.
2. **Reverse the graph** (transpose).
3. **DFS on the reversed graph** in the order of the stack to count SCCs.

---

## 🧾 Input Format

- `V`: Number of vertices in the graph.
- `adj`: Adjacency list of the directed graph.

---

## 📤 Output Format

- An integer: **number of strongly connected components (SCCs)** in the graph.

---
🧠 Concepts Used
Graph Traversal (DFS)
Graph Reversal (Transpose)
Stack usage for finish time tracking
Kosaraju’s Two-Pass Algorithm

---
📊 Time & Space Complexity
Time Complexity: O(V + E) for two DFS traversals

Space Complexity: O(V + E) for adjacency lists and stack

🔁 Why Kosaraju?
Kosaraju’s Algorithm is simple, intuitive, and based entirely on DFS. It is a reliable approach to determine SCCs in any directed graph, especially suitable when adjacency lists are used.
## ✅ Example Usage

```cpp
int V = 5;
vector<vector<int>> adj(V);

adj[0].push_back(2);
adj[2].push_back(1);
adj[1].push_back(0);
adj[0].push_back(3);
adj[3].push_back(4);

Solution sol;
int sccCount = sol.kosaraju(V, adj);
cout << "Number of SCCs: " << sccCount << endl;  // Output: 3
👨‍💻 Author
Your Name – @irythmgarg[Ridham Garg]

