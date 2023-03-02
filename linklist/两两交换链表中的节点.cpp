class Solution {
public:

    void swap(vector<ListNode*> &array, int i, int j) {
        ListNode *tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        vector<ListNode*> array;

        ListNode *p = head;

        while (p) {
            array.push_back(p);
            p = p->next;
        }

        for (int i = 0; i < array.size()-1; i += 2) {
            swap(array, i, i + 1);
        }

        array.back()->next = nullptr;

        for (int i = 0; i < array.size()-1; ++i) {
            array[i]->next = array[i+1];
        }

        return array.front();
    }
};