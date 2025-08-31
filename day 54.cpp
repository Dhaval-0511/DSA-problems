class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: only one node
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move fast pointer two steps and slow one step
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // Delete the middle node
        prev->next = slow->next;
        return head;
    }
};


// prblm:https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list