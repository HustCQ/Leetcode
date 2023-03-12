class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next);

        ListNode *p = head;
        vector<ListNode*> array;
        vector<ListNode*> list;

        while (p) {
            array.push_back(p);
            p = p->next;
        }

        int i = 0, j = array.size()-1;

        while (i <= j) {
            list.push_back(array[i++]);
            list.push_back(array[j--]);
        }

        for (int i = 0; i < list.size()-1; i++) {
            list[i]->next = list[i+1];
        }

        list.back()->next = nullptr;
    }
};