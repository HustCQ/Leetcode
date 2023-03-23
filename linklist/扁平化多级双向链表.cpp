class Solution {
public:
    Node* flatten(Node* head) {
        if (!head || (!head->next && !head->child)) return head;

        vector<Node*> array;
        stack<Node*> st;

        st.push(head);

        while (!st.empty()) {
            Node *cur = st.top();
            st.pop();
            if (cur->next) {
                st.push(cur->next);
            }
            if (cur->child) {
                st.push(cur->child);
            }
            cur->child = nullptr;
            cur->next = nullptr;
            array.push_back(cur);
        }

        for (int i = 0; i < array.size()-1; ++i) {
            array[i]->next = array[i+1];
            array[i+1]->prev = array[i];
        }

        return array.front();
    }
};