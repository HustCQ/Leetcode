struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = nullptr;

        while (head) {
            ListNode *cur = head;
            head = head->next;
            cur->next = newHead;
            newHead = cur;
        }

        return newHead;
    }
};