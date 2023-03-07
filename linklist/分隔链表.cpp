class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *leh = nullptr, *let = nullptr;
        ListNode *leah = nullptr, *leat = nullptr;

        ListNode *p = head, *q = nullptr;

        while (p) {
            q = p;
            p = p->next;
            q->next = nullptr;
            if (q->val < x) {
                if (!leh) {
                    leh = let = q;
                } else {
                    let->next = q;
                    let = let->next;
                }
            } else {
                if (!leah) {
                    leah = leat = q;
                } else {
                    leat->next = q;
                    leat = leat->next;
                }
            }
        }

        if (leh) {
            head = leh;
            let->next = leah;
        } else {
            head = leah;
        }

        return head;
    }
};