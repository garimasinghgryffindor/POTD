class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(K == 1) return NULL;
        
        Node * node = head, * prev = NULL;
        int i = 0;
        while(node) {
            i++;
            if(i == K) {
                prev->next = prev->next->next;
                i = 0;
                prev = NULL;
            } else {
                prev = node;
            }
            node = node->next;
        }
        
        return head;
    }
};
