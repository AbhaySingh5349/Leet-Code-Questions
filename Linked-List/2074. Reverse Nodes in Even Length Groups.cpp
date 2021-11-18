Question Link: https: //leetcode.com/problems/reverse-nodes-in-even-length-groups/

class Solution {
public:
    
    ListNode *rev(ListNode* head, int &len, int k){
        if(head==NULL) return head;
    
	    ListNode *nextHead; // head node of next group
		ListNode* prevNextHead; // last node of current group
	    nextHead=head, prevNextHead=nextHead;
		
	    for(int i=0;i<k;i++){
	        prevNextHead=nextHead;
	        nextHead=nextHead->next;
	    }
	    len-=k;
	    
	    ListNode *newHead=rev(nextHead,len,min(k+1,len)); // for edge cases like: [0,4,2,1,3] --> [0,2,4,3,1], we need to pass on length of next group accordingly
	    
	    ListNode *p, *q;
	    p=head, q=NULL;
	    if(k%2==0){ // if length is even, we need to reverse the links of current group
	        while(p!=nextHead){
	            ListNode* on=p->next;
	            p->next=q;
	            q=p;
	            p=on;
	        }
	    }
	    if(k%2==0){
	        head->next=newHead; // as we have reversed the links, initial head node is now last node for the group 
	    }else{
	        prevNextHead->next=newHead;
	    }
	    return (k%2==0 ? q:head);
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* p=head;
        int len=1;
        while(p->next!=NULL){
            p=p->next;
            len++;
        }
        
        return rev(head,len,1);
    }
};
