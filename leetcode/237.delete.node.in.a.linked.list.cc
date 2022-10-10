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
  void deleteNode(ListNode* node) {
    ListNode* behind = node;
    ListNode* ahead = node->next;
    while(ahead->next != NULL) {
      node->val = ahead->val;
      ahead = ahead->next;
      node = node->next;
    }
    node->val = ahead->val;
    node->next = NULL;
  }
};

/*

IDEA [O(n)]

1. We have two pointers
behind ->
   ahead ->
   
2. Both pointers moves 1 by 1
3. ahead pointer value is copied to behind value (even removing the node)
4. when ahead->next is NULL, we have to point behind->next to NULL

(This creates a memory leak, perhaps we can call a destructor like behind->~ListNode())

*/

