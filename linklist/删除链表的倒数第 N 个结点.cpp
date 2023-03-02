class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode *sentry = new ListNode();
        sentry->next = head;

        ListNode *p = sentry, *q = head;

        while (n--) {
            q = q->next;
        }

        while (p && q) {
            p = p->next;
            q = q->next;
        }

        q = p->next;
        p->next = p->next->next;
        delete q;

        head = sentry->next;
        delete sentry;

        return head;
    }
};