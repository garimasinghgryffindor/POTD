//User function template for C++

// s : given string to search
// dictionary : vector of available strings

struct Trie {
    Trie * links[26];
    bool flag = false;
};

class Solution
{
public:
    Trie * root = new Trie();
    
    void insert(string s) {
        Trie * node = root;
        
        if(s.empty()) {
            return;
        }
        for(int i = 0; i < s.length(); i++) {
            if(!node->links[s[i]-'a']) {
                node->links[s[i]-'a'] = new Trie();
            }
            node = node->links[s[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Trie *node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            
            if(!node->links[ch-'a']) {
                return false;
            }
            
            node = node->links[ch-'a'];
        }
        return node->flag;
    }
    
    bool isPrefix(string prefix) {
        Trie *node = root;
        for(int i=0 ; i<prefix.length() ; i++) {
            char ch = prefix[i];
            
            if(!node->links[ch-'a']) {
                return false;
            }
            
            node = node->links[ch-'a'];
        }
        return true;
    }

    bool recur(string s, int idx) {
        if(idx == s.length()) return true;
        
        for(int j = idx; j < s.length(); j++) {
            string temp = s.substr(idx, j-idx+1);
            if(search(temp)) {
                if(recur(s, j+1)) return true;
            }
            else if(!isPrefix(temp)) return false;
        }
        return false;
    }

    int wordBreak(int n, string s, vector<string> &dictionary) {
        for(auto x: dictionary) {
            insert(x);
        }
        
        return recur(s, 0) == true;
    }
};
