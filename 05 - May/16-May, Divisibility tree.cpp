

class Solution {
public:
    int res = 0;
    
    int dfs(vector<vector<int> >&graph, vector<bool>&vis, int pos) {
        vis[pos] = true;
        int count = 0;
        for(auto x: graph[pos]) {
            if(vis[x]) continue;
            
            int temp = dfs(graph, vis, x);
            if(temp%2 == 0) {
                res++;
                // i.e; i can remove this edge
            } else {
                // i definitely cannot remove this edge
                // so the number of nodes in the componenets are increased by the sum of number of nodes in its children
                count += temp;
            }
        }
        
        return count + 1;
    }
    
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    vector<vector<int>>graph(n+1);
	    for(auto edge: edges) {
	        int u = edge[0], v = edge[1];
	        graph[u].push_back(v);
	        graph[v].push_back(u);
	    }
	    vector<bool>vis(n+1, false);
	    
	    dfs(graph, vis, 1);
	    
	    return res;
	    
	}
};
