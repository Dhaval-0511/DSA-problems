/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;       // move by 1
            fast = fast->next->next; // move by 2

            if (slow == fast)        // cycle detected
                return true;
        }
        return false;                // no cycle
    }
};

// prblm: