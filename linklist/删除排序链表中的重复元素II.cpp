class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        map<int, int> kvs;

        ListNode *sentry = new ListNode();
        sentry->next = head;
        ListNode *p = head, *q = nullptr;

        while (p) {
            kvs[p->val]++;
            p = p->next;
        }

        p = sentry;
        while (p->next) {
            q = p->next;
            if (kvs[q->val] != 1) { // 下一个节点不保留
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }

        head = sentry->next;
        delete sentry;
        return head;
    }
};