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
    bool isPalindrome(ListNode* head) {
        int cnt=0;
        ListNode*temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        if(cnt==1) return true;
        ListNode*prev=NULL;
        ListNode*curr=head;
        ListNode*next=NULL;
        int c=cnt/2;
        while(c>0 && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            c--;
        }
        if(cnt%2==0){
            while(curr && prev){
                if(curr->val != prev->val) return false;
                curr=curr->next;
                prev=prev->next;
            }
        }else{
            curr=curr->next;
            while(curr && prev){
                if(curr->val != prev->val) return false;
                curr=curr->next;
                prev=prev->next;
            }
        }
        return true;
    }
};