struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *p = headA, *q= headB;

        while (p) {
            len1++;
            p = p->next;
        }

        while (q) {
            len2++;
            q = q->next;
        }

        int diff = len1 > len2 ? len1 - len2 : len2 - len1;
        p = len1 > len2 ? headA : headB;
        q = len1 > len2 ? headB : headA;

        while (diff > 0) {
            diff--;
            p = p->next;
        }

        while (p && q) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }

        return nullptr;
    }
};