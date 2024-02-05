/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       if(!head) {
           Node * node = new Node(data);
           node->next = node;
           return node;
       }
       
       Node * ptr = head, *prev = NULL;
      if(ptr && data < ptr->data) {
          // try reaching the end of the list
          Node * temp = ptr;
          while(temp && temp->next != ptr) {
              temp = temp->next;
          }
          Node * node = new Node(data);
          temp->next = node;
          node->next = head;
          return node;
      }
       
      while(ptr) {
          if(ptr->data <= data) {
              prev = ptr;
              ptr = ptr->next;
          } else {
              prev->next = new Node(data);
              prev->next->next = ptr;
              return head;
          }
          if(ptr == head) {
              prev->next = new Node(data);
              prev->next->next = head;
              return head;
          }
      }
       
       return head;
    }
};
