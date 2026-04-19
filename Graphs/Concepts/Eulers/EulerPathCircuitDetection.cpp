// https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

class Solution {
  public:
    vector<bool> visited;
    vector<int> inDeg;
    void DFS(int node, vector<int> adj[]) {
        visited[node] = true;
        for(int curr : adj[node]) {
            if(!visited[curr]) {
                DFS(curr, adj);
            }
        }
    }
    bool isOneComponent(vector<int> adj[], int V) {
        visited.resize(V, false);
        int st = -1;
        for(int i = 0; i < V; i++) {
            if(adj[i].size() > 0) {
                st = i;
                break;
            }
        }
        DFS(st, adj);
        for(int i = 0; i < V; i++) {
            if(visited[i] == false && adj[i].size() != 0)
                return false;
        }
        return true;
    }
    void populateInDegree(vector<int> adj[], int V) {
        inDeg.resize(V, 0);
        for(int i = 0; i < V; i++) {
            for(int node : adj[i]) {
                inDeg[node]++;
            }
        }
    }
    int isEulerCircuit(int V, vector<int> adj[]) {
        if(!isOneComponent(adj, V)) {
            return 0; // None
        }
        populateInDegree(adj, V);
        int oddDeg = 0;
        for(int i = 0; i < V; i++) {
            for(int n : adj[i]) {
                if(inDeg[n] % 2 != 0) oddDeg++;
            }
        }
        if(oddDeg == 0)
            return 2; // Euler Circuit 
        if(oddDeg == 2)
            return 1; // only Euler Path
        return 0; // None
    }
};