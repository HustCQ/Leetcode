class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        set<ListNode*> ns;

        while (head) {
            if (ns.find(head) != ns.end()) {
                return true;
            }
            ns.insert(head);
            head = head->next;
        }
        return false;
    }
};