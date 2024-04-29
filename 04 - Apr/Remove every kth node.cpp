/* Link list Node 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

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
