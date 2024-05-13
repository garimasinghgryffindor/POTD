
class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int res = 0;
        vector<vector<int>>graph(v+1);
        vector<int>visited(v+1, 0);
        for(int i = 0; i < e; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 1; i <= v; i++) {
            if(visited[i] == 0) {
                int edges_c = 0, vertices = 0;
                stack<int>st;
                st.push(i);
                visited[i] = 1;
                
                while(!st.empty()) {
                    int tp = st.top();  st.pop();
                    edges_c += graph[tp].size();
                    vertices++;
                    
                    for(int node: graph[tp]) {
                        if(!visited[node]) {
                            visited[node] = 1;
                            st.push(node);
                        }
                    }
                }
                
                
                edges_c /= 2;
                int c = vertices * (vertices - 1)/2;
                if(edges_c == c) {
                    res++;
                }
            }
        }
        
        return res;
        
    }
};
