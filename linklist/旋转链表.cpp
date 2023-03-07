class Solution {
public:
    static ListNode*  rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int len = 1;
        ListNode *p = head, *q = head, *t = head;

        while (q->next) { // q为最后一个节点
            len++;
            q = q->next;
        }

        k %= len;
        q = head;

        while (k--) {
            q = q->next;
        }

        while (q->next) {
            q = q->next;
            p = p->next;
        }

        q->next = head; // 链表循环

        head = p->next;
        p->next = nullptr;

        return head;
    }
};