class Solution {
public:
    Node* connect(Node* root) {
        if (!root || (!root->left && !root->right)) return root;

        queue<Node*> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node *curLevel = nullptr;
            for (int i = 0; i < size; ++i) {
                Node *cur = que.front();
                que.pop();
                if (curLevel == nullptr) {
                    curLevel = cur;
                } else {
                    curLevel->next = cur;
                    curLevel = curLevel->next;
                }

                if (cur->left) {
                    que.push(cur->left);
                }

                if (cur->right) {
                    que.push(cur->right);
                }
            }
        }
        return root;
    }
};