struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        stack<int> st;

        ListNode *p = head;

        while (p) {
            st.push(p->val);
            p = p->next;
        }

        p = head;

        while (p && !st.empty()) {
            if (p->val != st.top()) return false;
            p = p->next;
            st.pop();
        }

        return p == nullptr && st.empty();
    }
};