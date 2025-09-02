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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        
        // Traverse both lists, switching head on reaching end
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        // Either both meet at intersection or both are NULL
        return a;
    }
};


// prblm:https://leetcode.com/problems/intersection-of-two-linked-lists