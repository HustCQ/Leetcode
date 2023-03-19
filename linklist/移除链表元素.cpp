struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if (!head) return head;

        ListNode *sentry = new ListNode();
        sentry->next = head;

        ListNode *p = sentry, *q = head;

        while (q) {
            if (q->val == val) {
                p->next = q->next;
                delete q;
                q = p->next;
                continue;
            }
            p = p->next;
            q = q->next;
        }

        head = sentry->next;
        delete sentry;

        return head;
    }
};