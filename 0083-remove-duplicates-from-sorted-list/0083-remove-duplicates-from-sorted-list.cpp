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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr ) return head;
        ListNode* front = head->next; 
        ListNode* back = head; 

        while(front != nullptr){
            
            if(front->val == back->val){
                back->next  = front->next;
                front = front->next;
            }
            else{
                front = front->next;
                back = back->next;
            }
            
        }
        return head;
    }
};