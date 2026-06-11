class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while (t1) {
            lenA++;
            t1 = t1->next;
        }

        while (t2) {
            lenB++;
            t2 = t2->next;
        }

        t1 = headA;
        t2 = headB;

        int diff = abs(lenA - lenB);

        if (lenA > lenB) {
            while (diff--) t1 = t1->next;
        } else {
            while (diff--) t2 = t2->next;
        }

        while (t1 && t2) {
            if (t1 == t2) return t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        return NULL;
    }
};