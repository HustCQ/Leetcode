class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        map<Node*, Node*> m;
        Node *p = head;

        while (p) {
            m[p] = new Node(p->val);
            p = p->next;
        }

        p = head;
        while (p) {
            Node *newNode = m[p];
            newNode->next = p->next ? m[p->next] : nullptr;
            newNode->random = p->random ? m[p->random] : nullptr;
            p = p->next;
        }

        return m[head];
    }
};