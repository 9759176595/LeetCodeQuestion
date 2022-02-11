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
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        vector<int>v1;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        if(v.size()==1)
            return;
        
        int n=v.size();
        int i=0; int j=n-1;
        for(;i<j;i++,j--){
                v1.push_back(v[i]);
                v1.push_back(v[j]);
            
        }
         if(n%2!=0){
                v1.push_back(v[n/2]);
            }
        
        //cout<<v1[1];
        ListNode* tp=NULL;
        ListNode* out=NULL;
        for(int i=0;i<n;i++)
        {
            if(tp==NULL){
                tp=new ListNode(v1[i]);
                out=tp;
            }
            else{
                out->next=new ListNode(v1[i]);
                out=out->next;
            }
        }
        // head = NULL;
        *head = *tp;
    }
};
