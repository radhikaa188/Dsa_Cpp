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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode*l3= new ListNode();
        ListNode*curr=l3;
        
        while(l1||l2){
          int a= l1? l1->val: 0;
          int b= l2? l2->val: 0;
          int result= a+b+carry;
            
             carry=(result)/10;
             curr->val=result%10;

            if(l1) l1=l1->next;
            if(l2) l2=l2->next;

            if(l1||l2||carry){
            curr->next = new ListNode();
            curr=curr->next;
            }

        }
        if(carry)curr->val= carry;
        return l3;
    }
};