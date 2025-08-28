class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;
        // Find the middle (slow will point to middle)
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr, *curr = slow->next;
        while (curr) {
            ListNode *next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }

        // Compare first half and reversed second half
        ListNode *left = head, *right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// prblm:https://leetcode.com/problems/palindrome-linked-list