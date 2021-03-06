Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

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
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        for(int i=0;i<n;i++)
            fast=fast->next;
        
        if(!fast)
            return head->next;
        
        while(fast->next!=NULL)
        {
            
            fast=fast->next;
            slow=slow->next;
        } 
        
        slow->next = slow->next->next;
        
        return head;
        
        
    }
};
