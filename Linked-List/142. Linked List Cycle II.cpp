Quesion Link: https://leetcode.com/problems/linked-list-cycle-ii/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        
        ListNode *fast, *slow;
        fast=slow=head;
        
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }while(slow!=fast && fast!=NULL && slow!=fast);
        
        if(fast==NULL) return NULL;
        
        int len=1;
        while(slow->next!=fast){
            len++;
            slow=slow->next;
        }
        
        slow=fast=head;
        for(int i=0;i<len;i++) fast=fast->next;
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
