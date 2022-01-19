/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
          ListNode *sl=head;
          ListNode *ft=head;
        
        while(ft!=NULL && ft->next!=NULL){
            sl=sl->next;
            ft=ft->next->next;
            
            if(sl==ft){
                sl=head;
                while(sl!=ft){
                    sl=sl->next;
                   ft=ft->next;
                }
                 return sl;
            }
        }
         return NULL;
    }
   
};
