struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        int index = 1;
        ListNode *oddH = nullptr, *oddT = nullptr;
        ListNode *evenH = nullptr, *evenT = nullptr;
        ListNode * p = head;

        while (p) {
            ListNode *cur = p;
            p = p->next;
            cur->next = nullptr;
            if (index++ % 2) { // 奇索引
                if (!oddH) {
                    oddH = oddT = cur;
                } else {
                    oddT->next = cur;
                    oddT = oddT->next;
                }
            } else { // 偶索引
                if (!evenH) {
                    evenH = evenT = cur;
                } else {
                    evenT->next = cur;
                    evenT = evenT->next;
                }
            }
        }

        oddT->next = evenH;

        return oddH;
    }
};