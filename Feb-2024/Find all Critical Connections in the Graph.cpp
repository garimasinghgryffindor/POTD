//User function Template for C++

class Solution {
public:
    int dfs(int i, int p, vector<int>& rank, int k,
        vector<int> adj[], vector<vector<int> >& ans,
        vector<int>& vis)
{
 
    // Set rank of the ith node to k
    // which is depth
    rank[i] = k;
 
    // Mark ith node as visited
    vis[i] = 1;
 
    int minDepth = INT_MAX;
 
    // Exploring all the neighbour
    // node of node i
    for (auto ch : adj[i]) {
 
        // This if condition is to make
        // sure we do not call parent
        // from where it is called to
        // avoid child parent loop
        if (ch != p) {
 
            // If neighbour is already
            // visited then we take
            // minimum with rank of ch,
            // means a cycle is found
            if (vis[ch]) {
                minDepth = min(minDepth, rank[ch]);
            }
 
            // If neighbour is not
            // visited then we go in
            // depth to check cycle
            // is present or not
            else {
                int minRank = dfs(ch, i, rank, k + 1, adj,
                                  ans, vis);
 
                // If dfs returns smaller
                // depth value than current
                // depth it means current
                // edge is in a cycle
                // else there is no cycle
                // so we have pushed the
                // edge in our answer
                if (rank[i] < minRank) {
                    ans.push_back({ i, ch });
                }
                minDepth = min(minRank, minDepth);
            }
        }
    }
    return minDepth;
}
    
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector<vector<int> > ans;
        vector<int> rank(V, -1), vis(V, 0);
        dfs(0, -1, rank, 0, adj, ans, vis);
        for (int i = 0; i < ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        return ans;
	     
	}
};
