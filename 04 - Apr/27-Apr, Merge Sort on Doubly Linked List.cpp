
/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    
    struct Node* getMid(struct Node* head) {
        struct Node* slow = head, *fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    struct Node* merge(struct Node* left, struct Node* right) {
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        
        struct Node* newList = new Node(0);
        struct Node* l = left, *r = right;
        struct Node* curr = newList;
        
        while(l && r) {
            if(l->data <= r->data) {
                curr->next = l;
                l->prev = curr;
                l = l->next;
            } else {
                curr->next = r;
                r->prev = curr;
                r = r->next;
            }
            curr = curr->next;
        }
        
        if(l) {
            curr->next = l;
            l->prev = curr;
        }
        
        if(r) {
            curr->next = r;
            r->prev = curr;
        }
        
        struct Node* res = newList->next;
        res->prev = NULL;
        return res;
    }
    
    struct Node* mergeSort(struct Node* head) {
        if(!head || !head->next) return head;
        
        struct Node* mid = getMid(head);
        struct Node* midNext = mid->next;
        
        mid->next = NULL;
        midNext->prev = NULL;
        Node * left = mergeSort(head);
        Node * right = mergeSort(midNext);
        merge(left, right);
    }
    
    struct Node *sortDoubly(struct Node *head) {
        return mergeSort(head);
    }
};
