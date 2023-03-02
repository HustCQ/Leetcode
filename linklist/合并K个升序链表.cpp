class Solution {
public:

    ListNode* mergeList(ListNode *list1, ListNode *list2) {
        if (!list1 || !list2) {
            return list1 ? list1 : list2;
        }

        ListNode *head = nullptr, *tail = nullptr;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (!head) {
                    head = tail = list1;
                } else {
                    tail->next = list1;
                    tail = tail->next;
                }
                list1 = list1->next;
            } else {
                if (!head) {
                    head = tail = list2;
                } else {
                    tail->next = list2;
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }

        if (list1) {
            tail->next = list1;
        }

        if (list2) {
            tail->next = list2;
        }

        return head;
    }

    ListNode* mergeKListsProcess(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        int mid = start + ((end - start) >> 1);

        return mergeList(
                mergeKListsProcess(lists, start, mid),
                mergeKListsProcess(lists, mid+1, end)
                );
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return *lists.begin();
        return mergeKListsProcess(lists, 0, lists.size()-1);
    }
};