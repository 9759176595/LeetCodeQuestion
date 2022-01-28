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
    ListNode* reverseList(ListNode* head) {
     vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        reverse(v.begin(),v.end());
        ListNode* out=NULL, *temp=NULL;
        for(int i=0;i<v.size();i++){
            if(out==NULL){
                out=new ListNode(v[i]);
                temp=out;
            }
            else{
                temp->next=new ListNode(v[i]);
                temp=temp->next;
            }
        }
        return out;
    }
};
