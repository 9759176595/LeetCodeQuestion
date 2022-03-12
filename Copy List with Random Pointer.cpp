/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //----------METHOD 1
//         Node* curr=head;
//         unordered_map<Node*,Node*> mp;
//         while(curr){
//             mp[curr]=new Node(curr->val);
//             curr=curr->next;
//         }
//         curr=head;
//         while(curr){
//             mp[curr]->next=mp[curr->next];
            
//             mp[curr]->random=mp[curr->random];
            
//             curr=curr->next;
//         }
//         return mp[head];
        
        //--------METHOD 2
        Node* curr=head;
        while(curr){
            Node* temp=new Node(curr->val);
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;    
        }
        curr=head;
        while(curr){
            if(curr->random)
                curr->next->random=curr->random->next;
            curr=curr->next->next;
        }
        
        Node* dummy=new Node(-1);
        
        Node* curr1=head;
        Node* curr2=dummy;
        while(curr1){
            curr2->next=curr1->next;
            curr2=curr2->next;
            curr1->next=curr1->next->next;    
            curr1=curr1->next;
        }
        return dummy->next;
    }
};
