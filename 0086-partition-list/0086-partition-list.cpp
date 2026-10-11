class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head) {
            ListNode* nextNode = head->next; // Save next
            head->next = nullptr;            // Break old links

            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }

            head = nextNode;
        }

        less->next = greaterHead->next;
        return lessHead->next;
    }
};
