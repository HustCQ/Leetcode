class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> array;
        ListNode *orderedHead = nullptr;
        ListNode *p = head;

        while (p) {
            array.push_back(p->val);
            p = p->next;
        }

        sort(array.begin(), array.end());
        p = head;

        for (auto it : array) {
            p->val = it;
            p = p->next;
        }

        return head;
    }
};
