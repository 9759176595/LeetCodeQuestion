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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp=head;
        vector<int>v;
        if(head==NULL || head->next==NULL) return head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
       
        int t=v.size();
        int p=k%t;
        reverse(v.begin()+t-p,v.end());
        vector<int>v1;
         vector<int>v2;
        for(int i=t-1;i>=(t-p);i--){
            v1.push_back(v[i]);
          // cout<<v1.back()<<endl;
        }
        for(int i=0;i<(t-p);i++){
            v2.push_back(v[i]);
            // cout<<v2.back()<<endl;
        }
        
        for(int i=0;i<v2.size();i++){
            v1.push_back(v2[i]);
        }
      
        ListNode * h1=NULL;
        ListNode* h2=NULL;
        for(int i=0;i<t;i++){
            if(h1==NULL){
                h1=new ListNode(v1[i]);
                h2=h1;
            }
            else{
                h2->next=new ListNode(v1[i]);
                h2=h2->next;
            }
        }
        return h1;
    }
};
