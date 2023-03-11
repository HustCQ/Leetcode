class Solution {
public:
    void preorderTraversal(TreeNode* root, vector<TreeNode*> &array) {
        if (!root) return;
        array.push_back(root);
        preorderTraversal(root->left, array);
        preorderTraversal(root->right, array);
    }

    void flatten(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;
        vector<TreeNode*> array;
        preorderTraversal(root, array);

        for (int i = 0; i < array.size(); ++i) {
            if (i == array.size()-1) {
                array[i]->left = array[i]->right = nullptr;
                break;
            }

            array[i]->left = nullptr;
            array[i]->right = array[i+1];
        }
    }
};