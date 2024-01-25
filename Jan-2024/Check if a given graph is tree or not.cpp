class Solution {
  public:
    
    void dfs(vector<vector<int>>&graph, int node, vector<bool>&visited) {
        visited[node] = true;
        
        for(auto x: graph[node]) {
            if(!visited[x]) dfs(graph, x, visited);
        }
    }
    
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        
        if((n-m) != 1) return 0;
        
        vector<vector<int>> graph(n);
        
        for(auto edge: adj) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        dfs(graph, 0, visited);
        
        for(int i = 0; i < n; i++) {
            if(!visited[i]) return 0;
        }
        
        return 1;
    }
};
