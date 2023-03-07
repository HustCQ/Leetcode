class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *sentry = new ListNode();
        sentry->next = head;
        ListNode *p = sentry, *q = nullptr;
        set<int> vals;

        while (p->next) {
            q = p->next;
            if (vals.find(q->val) != vals.end()) { // 重复
                p->next = q->next;
                delete q;
            } else {
                vals.insert(q->val);
                p = p->next;
            }
        }

        head = sentry->next;
        delete sentry;

        return head;
    }
};