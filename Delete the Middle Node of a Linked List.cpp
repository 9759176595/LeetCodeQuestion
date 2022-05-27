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
    ListNode* deleteMiddle(ListNode* head) {
         if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* fast=head,*slow=NULL;
        while(fast!=NULL&&fast->next!=NULL)
        {
            if(slow==NULL)
            {
                slow=fast;
                fast=fast->next->next;
            }
            else
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        ListNode* flag=slow;
        slow=slow->next;
        flag->next=slow->next;
        delete slow;
        return head;
    }
};
