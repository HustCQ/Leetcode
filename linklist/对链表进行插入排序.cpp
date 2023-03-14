class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *orderedHead = nullptr;
        ListNode *p = head;
        ListNode *sentry = new ListNode();

        while (p) {
            ListNode *cur = p;
            p = p->next;
            cur->next = nullptr;

            if (!sentry->next) {
                cur->next = sentry->next;
                sentry->next = cur;
            } else {
                ListNode *h = sentry;
                ListNode *q = sentry->next;

                while (q && q->val < cur->val) { // 保证cur位于q的前面
                    q = q->next;
                    h = h->next;
                }
                cur->next = q;
                h->next = cur;
            }
        }

        head = sentry->next;
        delete sentry;

        return head;
    }
};