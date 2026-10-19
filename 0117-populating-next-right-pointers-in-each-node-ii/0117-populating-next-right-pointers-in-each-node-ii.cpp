class Solution {
public:
    Node* connect(Node *root) {
        Node *head = nullptr; // Head of the next level
        Node *prev = nullptr; // Last connected child
        Node *cur = root;     // Current node

        while (cur != nullptr) {
            while (cur != nullptr) {

                // Connect the left child
                if (cur->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }

                // Connect the right child
                if (cur->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }

                // Move to the next node at the current level
                cur = cur->next;
            }

            // Move to the next level
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }
};