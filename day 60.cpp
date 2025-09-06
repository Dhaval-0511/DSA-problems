// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/
class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;
        if (!head) return ans;
        
        Node* left = head;
        Node* right = head;
        while (right->next) right = right->next; // Move to tail
        
        while (left && right && left != right && left->prev != right) {
            int currSum = left->data + right->data;
            if (currSum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if (currSum < target) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return ans;
    }
};



// prblm:https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1