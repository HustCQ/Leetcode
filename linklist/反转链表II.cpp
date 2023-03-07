class Solution {
public:

    void swap(vector<ListNode*> &nodes, int i, int j) {
        int val = nodes[i]->val;
        nodes[i]->val = nodes[j]->val;
        nodes[j]->val = val;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) return head;

        vector<ListNode*> nodes;
        ListNode *p = head;

        while (p) {
            nodes.push_back(p);
            p = p->next;
        }

        while (left < right) {
            swap(nodes, left-1, right-1);
            ++left;
            --right;
        }

        for (int i = 0; i < nodes.size()-1; ++i) {
            nodes[i]->next = nodes[i+1];
        }

        nodes.back()->next = nullptr;

        return nodes.front();
    }
};