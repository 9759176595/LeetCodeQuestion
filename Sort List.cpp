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
    ListNode* sortList(ListNode* head) {
        vector<int>v1;
        ListNode* temp=head;
        while(temp){
            v1.push_back(temp->val);
            temp=temp->next;
        }
        sort(v1.begin(),v1.end());
        ListNode* t1=NULL;
        ListNode* t2=NULL;
        
        for(int i=0;i<v1.size();i++){
            if(t1==NULL){
                t1=new ListNode(v1[i]);
                t2=t1;
            }
            else{
                t2->next=new ListNode(v1[i]);
                t2=t2->next;
            }
        }
        return t1;
        
    }
};
