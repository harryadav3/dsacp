from typing import List
def ispalin(l: List[int]) -> bool:
    return l == l[::-1]


  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *t1 = l1 , *t2 = l2;
    int carry =0;
    ListNode *dmhead = new ListNode(-1);
    ListNode *curr = dmhead;
    while( t1 != nullptr || t2 != nullptr){

        int sum = carry;

        if(t1) sum += t1->val;
        if(t2) sum+= t2 ->val;

        ListNode* newnode = new ListNode(sum % 10);
        carry = sum/10;

        
        curr->next = newnode;
        curr = curr->next;

        if(t1) t1= t1->next;
        if(t2) t2 = t2->next;

    }

    if(carry){
        ListNode* newnode = new ListNode(carry);
        curr->next = newnode;
    }
 return dmhead->next;