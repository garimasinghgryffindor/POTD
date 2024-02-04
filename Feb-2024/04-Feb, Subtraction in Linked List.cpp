//User function Template for C++

class Solution {
public:
    int findLen(Node* node) {
        int len = 0;
        while(node) {
            len++;
            node = node->next;
        }
        return len;
    }
    
    Node* reverse(Node* node) {
        Node * prev = NULL, *curr = node, *nextptr = NULL;
        
        while(curr) {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        
        return prev;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
       
       while(head1 && head1->data == 0) {
           head1 = head1->next;
       }
       
       while(head2 && head2->data == 0) {
           head2 = head2->next;
       }
       
       if(!head1 && !head2) return new Node(0);
       
       if(head1 == NULL) return head2;
       if(head2 == NULL) return head1;
       
       int len1 = findLen(head1);
       int len2 = findLen(head2);
       
       if(len1 < len2) {
           Node* temp = head1;
           head1 = head2;
           head2 = temp;
       }
       else if(len1 == len2) {
           Node * ptr = head1, *ptr2 = head2;
           
           while(ptr && ptr2) {
               if(ptr2->data > ptr->data) {
                   Node* temp = head1;
                   head1 = head2;
                   head2 = temp;
                   break;
               } else if(ptr->data > ptr2->data) {
                   break;
               }
               ptr = ptr->next;     ptr2 = ptr2->next;
           }
       }
       
       // now head1 is definitely greater than head2
       // subtract head2 from head1
       
        Node * rev1 = reverse(head1);
        Node * rev2 = reverse(head2);
        
        Node * ans = NULL;
        bool borrow = false;
        
        while(rev1 || rev2) {
            if(rev2) {
                if(borrow) {
                    if(rev1->data-1 - rev2->data < 0) {
                        Node * node = new Node(rev1->data+9 - rev2->data);
                        node->next = ans;
                        ans = node;
                        borrow = true;
                    } else {
                        Node * node = new Node(rev1->data-1 - rev2->data);
                        node->next = ans;
                        ans = node;
                        borrow = false;
                    }
                } else {
                    if(rev1->data - rev2->data < 0) {
                        Node * node = new Node(rev1->data+10 - rev2->data);
                        node->next = ans;
                        ans = node;
                        borrow = true;
                    } else {
                        Node * node = new Node(rev1->data - rev2->data);
                        node->next = ans;
                        ans = node;
                    }
                }
                rev1 = rev1->next;
                rev2 = rev2->next;
            } else {
                if(borrow) {
                    if(rev1->data-1 < 0) {
                        Node * node = new Node(rev1->data-1 + 10);
                        node->next = ans;
                        ans = node;
                        borrow = true;
                    } else {
                        Node * node = new Node(rev1->data-1);
                        node->next = ans;
                        ans = node;
                        borrow = false;
                    }
                } else {
                    Node * node = new Node(rev1->data);
                    node->next = ans;
                    ans = node;
                }
                rev1 = rev1->next;
            }
        }
       
       while(ans && ans->data == 0) {
           ans = ans->next;
       }
       
       if(!ans) return new Node(0);
       
        return ans;
    }
};
