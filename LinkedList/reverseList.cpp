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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            // Store the next node
            ListNode* temp = curr->next;  
            // Reverse the current node's pointer
            curr->next = prev;            
            // Move prev to current node and curr to prev
            prev = curr;                  
            curr = temp;                  
        }
        return prev;
    }
};