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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp=head;
        vector<int>v1;
        while(temp){
            v1.push_back(temp->val);
            temp=temp->next;
        }
        int temp1=0;
        for(int i=0;i<v1.size();i++){
            for(int j=i+1;j<v1.size();j++){
                if(v1[i]>v1[j]){
                    temp1=v1[j];
                    v1[j]=v1[i];
                    v1[i]=temp1;
                }
            }
        }
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
