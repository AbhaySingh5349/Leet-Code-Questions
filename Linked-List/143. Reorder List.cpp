Question Link: https://leetcode.com/problems/reorder-list/

// Approach 1:

class Solution {
public:
    
    void zip(ListNode * &left, ListNode *right, int len, int k){
	if(right==NULL) return;
	
	zip(left,right->next,len,k+1);
	if(k>len/2){
		ListNode* on=left->next;
		left->next=right;
		right->next=on;
		left=on;
	} 
    } 
    
    void reorderList(ListNode* head) {
        ListNode *left, *right;
        left=right=head;
        
        int len=1;
        while(head->next!=NULL){
            head=head->next;
            len++;
        }
        if(len%2==0) len--;
	zip(left,right,len,0);
	left->next=NULL; 
    }
};

// Approach 2:

class Solution {
public:
    
    ListNode* getMid(ListNode* head){
        ListNode *slow, *fast;
        slow=head;
        fast=head->next;
        
        do{
            slow=slow->next;
            fast=fast->next;
            if(fast) fast=fast->next;
        }while(fast!=NULL && fast->next!=NULL);
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode *p, *q;
        q=NULL ,p=head;
        while(p!=NULL){
            ListNode* on=p->next;
            p->next=q;
            q=p;
            p=on;
        }
        return q;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return ;
        
        ListNode* mid=getMid(head);
        
        ListNode *p ,*q;
        p=head, q=mid->next;
        mid->next=NULL;
        q=reverse(q);
        
        while(p!=NULL && q!=NULL){
            ListNode *op=p->next, *oq=q->next;
            
            p->next=q;
            q->next=op;
            
            p=op;
            q=oq;
        }
    }
};
