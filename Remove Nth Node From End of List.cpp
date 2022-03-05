/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        //for(int i=0;i<v.size();i++){
        // int n=v.size();
        v.erase(v.end()-n);
        ListNode* h1=NULL;
        ListNode* h2=NULL;
        for(int i=0;i<v.size();i++){
            if(h1==NULL){
                h1=new ListNode(v[i]);
                h2=h1;
            }else{
                h2->next=new ListNode(v[i]);
                h2=h2->next;
            }
        }
        return h1;
    }
};
