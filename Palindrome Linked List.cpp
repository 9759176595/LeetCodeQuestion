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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int n=v.size();
        for(int i=0,j=n-1;i<j;){
            if(v[i]==v[j]){
                i++;
               j--;
            }
            else{
                return 0;
            }
                
        }
        return 1;
    }
};
