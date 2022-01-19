Question Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        struct ListNode *slow, *fast;
        slow=fast=head;
        
        while(slow!=NULL && fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
        }
        return slow;
    }
};
