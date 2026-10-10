/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        if(k == 0) return head;
        int n = 0;
        ListNode* temp = head;
        ListNode* tail = temp;
        while(temp->next){
            n++;
            temp = temp->next;
            if(temp) tail = temp;
        }
        n++;
        temp->next = head;
        k %= n;
        
        int p = n - k - 1;
        temp = head;
        while(p--){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};