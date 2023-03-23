class Solution {
public:
    ListNode* reverse(ListNode *head) {
        ListNode *newHead = nullptr;

        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = newHead;
            newHead = cur;
        }

        return newHead;
    }

    ListNode* addTwoList(ListNode* l1, ListNode* l2) {
        ListNode *nh = nullptr, *nt = nullptr;
        int sum = 0, up = 0;

        while (l1 && l2) {
            sum = l1->val + l2->val + up;
            up = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            if (!nh) {
                nh = nt = node;
            } else {
                nt->next = node;
                nt = nt->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            sum = l1->val + up;
            up = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            if (!nh) {
                nh = nt = node;
            } else {
                nt->next = node;
                nt = nt->next;
            }
            l1 = l1->next;
        }

        while (l2) {
            sum = l2->val + up;
            up = sum / 10;
            sum %= 10;
            ListNode *node = new ListNode(sum);
            if (!nh) {
                nh = nt = node;
            } else {
                nt->next = node;
                nt = nt->next;
            }
            l2 = l2->next;
        }

        if (up) {
            nt->next = new ListNode(up);
        }

        return nh;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }

        ListNode *nl1 = reverse(l1);
        ListNode *nl2 = reverse(l2);


        return reverse(addTwoList(nl1, nl2));
    }
};