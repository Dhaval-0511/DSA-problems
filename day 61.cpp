/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

   Node *removeDuplicates(Node *head) {
    if (!head) return nullptr; // Empty list
    
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            // Duplicate found; remove next node
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            if (toDelete->next)
                toDelete->next->prev = curr;
            delete toDelete; // free memory
        } else {
            curr = curr->next;
        }
    }
    return head;
}

};

// prblm:https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1