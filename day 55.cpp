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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Get the length of the list
        int length = 0;
        ListNode* node = head;
        while (node) {
            ++length;
            node = node->next;
        }

        ListNode dummy(0, head);
        for (int size = 1; size < length; size <<= 1) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;
            while (curr) {
                // Left part
                ListNode* left = curr;
                // Right part
                ListNode* right = split(left, size);
                // Next sublist
                curr = split(right, size);
                
                // Merge left and right parts
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }

private:
    // Split the list after n nodes and return the next part
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head && i < n; ++i)
            head = head->next;
        if (!head) return nullptr;
        ListNode* second =
         head->next;
        head->next = nullptr;
        return second;
    }

    // Merge two sorted lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* ptr = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = list1 ? list1 : list2;
        return dummy.next;
    }
};


// prblm:https://leetcode.com/problems/sort-list