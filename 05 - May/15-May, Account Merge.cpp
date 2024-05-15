// User function Template for C++

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int n = accounts.size();
        UnionFind uf(n);

        // Map emails to indices and names
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                emailToIndex[email] = i;
                emailToName[email] = accounts[i][0];
            }
        }

        // Union emails with the same owner
        for (auto& acc : accounts) {
            int root = emailToIndex[acc[1]];
            for (int j = 2; j < acc.size(); ++j) {
                uf.unite(root, emailToIndex[acc[j]]);
            }
        }

        // Group emails by owner
        unordered_map<int, set<string>> mergedAccounts;
        for (auto& acc : accounts) {
            int root = uf.find(emailToIndex[acc[1]]);
            for (int j = 1; j < acc.size(); ++j) {
                mergedAccounts[root].insert(acc[j]);
            }
        }

        // Build the result
        vector<vector<string>> result;
        for (auto it = mergedAccounts.begin(); it != mergedAccounts.end(); ++it) {
            vector<string> account;
            account.push_back(emailToName[*(it->second.begin())]);
            for (auto& email : it->second) {
                account.push_back(email);
            }
            result.push_back(account);
        }

        return result;
    }
};
