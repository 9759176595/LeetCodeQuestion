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
    ListNode* removeElements(ListNode* head, int val) {
        vector<int> v;
        int n=0;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
            n++;
        }
        for(int i=0;i<n;i++){
            auto x=find(v.begin(),v.end(),val);
            if(x!=v.end()){
                v.erase(x);
            }
        }
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
