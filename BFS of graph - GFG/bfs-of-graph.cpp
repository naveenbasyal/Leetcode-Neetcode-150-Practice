//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    //void makeList(int V)
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int,bool> visited;
        unordered_map<int, vector<int>> adjList; 
        
        for(int i = 0; i < V; i++){
            
            for(auto j : adj[i]){
                adjList[i].push_back(j);    
            }
            
        }
        vector<int> bfsTraversal;
    queue<int> q;
    q.push(0); // Assuming the starting vertex is 0

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        if (!visited[vertex]) {
            visited[vertex] = true;
            bfsTraversal.push_back(vertex);

            for (int neighbor : adjList[vertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
    }

    return bfsTraversal;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends