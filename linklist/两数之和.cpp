class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int up = 0;

        ListNode *head = nullptr, *tail = nullptr;

        while (l1 && l2) {
            sum = l1->val + l2->val + up;
            up = sum / 10;
            sum %= 10;

            if (!head) {
                head = tail = new ListNode(sum);
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            if (!head) {
                head = l1;
                break;
            } else {
                sum = l1->val + up;
                up = sum / 10;
                sum %= 10;
                tail->next = new ListNode(sum);
            }
            l1 = l1->next;
            tail = tail->next;
        }

        while (l2) {
            if (!head) {
                head = l2;
                break;
            } else {
                sum = l2->val + up;
                up = sum / 10;
                sum %= 10;
                tail->next = new ListNode(sum);
            }
            l2 = l2->next;
            tail = tail->next;
        }

        if (up > 0) {
            tail->next = new ListNode(up);
        }

        return head;
    }
};