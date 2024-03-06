// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            TrieNode *node = root;
            
            if(key.empty()) {
                node->children[26] = new TrieNode();
                return;
            }
            
            for(char x: key) {
                if(!node->children[x-'a']) {
                    node->children[x-'a'] = new TrieNode();
                }
                node = node->children[x-'a'];
            }
            node->isLeaf = true;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
            TrieNode * node = root;
            if(key.empty()) {
                return true;
            }
            
            for(char x: key) {
                if(!node->children[x-'a']) {
                    return false;
                }
                node = node->children[x-'a'];
            }
            return node->isLeaf;
        }
};
