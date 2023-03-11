class Solution {
public:

    TreeNode* createTree(vector<int> &array, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + ((end - start) >> 1);
        TreeNode * root = new TreeNode(array[mid]);
        root->left = createTree(array, start, mid - 1);
        root->right = createTree(array, mid + 1, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head || !head->next) return head ? new TreeNode(head->val) : nullptr;

        vector<int> array;

        ListNode *p = head;
        while (p) {
            array.push_back(p->val);
            p = p->next;
        }

        return createTree(array, 0, array.size()-1);
    }
};