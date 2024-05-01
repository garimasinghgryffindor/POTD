
class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
        // Code here
        struct Node* vowel = new Node(0);
        struct Node* cons = new Node(0);
        struct Node* vow = vowel, *con = cons;
        struct Node* curr = head;
        while(curr) {
            char c = curr->data;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vow->next = curr;
                vow = vow->next;
            } else {
                con->next = curr;
                con = con->next;
            }
            curr = curr->next;
        }
        
        vowel = vowel->next;
        cons = cons->next;
        con->next = NULL;
        
        if(vowel) {
            vow->next = cons;
            return vowel;
        }
        
        return cons;

    }
};
