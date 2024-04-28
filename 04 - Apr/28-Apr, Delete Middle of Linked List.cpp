/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node * getMid(Node * head) {
        Node *slow = head, *fast = head, *prev = NULL;
        while(fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next != NULL) return slow;
        return prev;
    }
    
    Node* deleteMid(Node* head)
    {
        if(!head || !head->next) return NULL;
        Node * mid = getMid(head);
        mid->next = mid->next->next;
        return head;
    }
};
