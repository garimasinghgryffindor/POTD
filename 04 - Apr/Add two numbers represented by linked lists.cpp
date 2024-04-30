class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head) {
        while(head && head->data == 0) {
            head = head->next;
        }
        
        struct Node* prev = NULL, * curr = head, * next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        struct Node* dummy = NULL;
        struct Node* rev1 = reverse(num1);
        struct Node* rev2 = reverse(num2);
        struct Node * temp1 = rev1, * temp2 = rev2;
        
        if(rev1 == NULL && rev2 == NULL) return new Node(0);
        if(rev1 == NULL) return rev2;
        if(rev2 == NULL) return rev1;
        
        int carry = 0;
        while(carry || rev1 || rev2) {
            int res = 0;
            if(rev1) {
                res += rev1->data;
                rev1 = rev1->next;
            }
            if(rev2) {
                res += rev2->data;
                rev2 = rev2->next;
            }
            res += carry;
            
            carry = res/10;
            res = res%10;
            
            struct Node* node = new Node(res);
            node->next = dummy;
            dummy = node;
        }
        
        return dummy;
    }
};
