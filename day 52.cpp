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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* odd = head;                  // First odd node
        ListNode* even = head->next;           // First even node
        ListNode* even_head = even;            // Head of even list
        
        while (even && even->next) {
            odd->next = even->next;            // Link odd to next odd
            odd = odd->next;
            even->next = odd->next;            // Link even to next even
            even = even->next;
        }
        
        odd->next = even_head;                 // Attach even list to tail of odd list
        return head;
    }
};

// prblm:https://leetcode.com/problems/odd-even-linked-list