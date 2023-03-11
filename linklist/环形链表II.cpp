class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        set<ListNode*> ns;

        while (head) {
            if (ns.find(head) != ns.end()) {
                return head;
            }
            ns.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};