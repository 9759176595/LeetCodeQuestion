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
    ListNode* swapPairs(ListNode* head) {
        vector<int> v;
        vector<int> v1;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        for(int i=1,j=0;i<n &&  j<n;i=i+2 , j=j+2){
            v1.push_back(v[i]);
            v1.push_back(v[j]);  
        }
        if(n%2!=0){
            v1.push_back(v[v.size()-1]);
        }
        ListNode* tp=NULL;
        ListNode* out=NULL;
        for(int i=0;i<v1.size();i++){
            if(out==NULL){
                out=new ListNode(v1[i]);
                tp=out;
            }
            else{
                tp->next=new ListNode(v1[i]);
                tp=tp->next;
            }
        }
        return out;
    }
};
