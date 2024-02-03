/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           long long mod = 1e9+7;
           long long ans = 0;
           Node * ptr = head;
           while(ptr != NULL) {
               ans = (ans*2 + ptr->data)%mod;
               ptr = ptr->next;
           }
           return ans;
        }
};

