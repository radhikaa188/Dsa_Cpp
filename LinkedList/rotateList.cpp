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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;

        ListNode*temp=head;
        ListNode*last=NULL;
        int cnt=1;
        while(temp->next){
            cnt++;
            temp=temp->next;
        }
        last=temp;
        int newK=k%cnt;
        last->next=head;
        long long mov=cnt-newK;
        ListNode*temp2=head;
        while(mov-1){
            mov--;
            if(temp2)temp2=temp2->next;
        }
        ListNode*newHead= temp2->next;
        temp2->next=NULL;
       
        return newHead;
    }
};