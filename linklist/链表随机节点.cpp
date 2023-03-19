struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:


    Solution(ListNode* head) {
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        return vals[rand()%vals.size()];
    }

private:
    vector<int> vals;
};