#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int v, int w) {
    adj[v].push_back(w);
}

void DFS(int v, vector<int> adj[], vector<bool>& visited) {
    stack<int> stack;
    stack.push(v);

    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex]) {
            cout << vertex << " ";
            visited[vertex] = true;
        }

        for (auto i = adj[vertex].rbegin(); i != adj[vertex].rend(); ++i) {
            if (!visited[*i]) {
                stack.push(*i);
            }
        }
    }
}

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V];
    
    // Create a graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2):\n";
    vector<bool> visited(V, false);
    DFS(2, adj, visited);

    return 0;
}
