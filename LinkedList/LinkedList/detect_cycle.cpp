/*Problem: Detect Cycle in Linked List
Platform: Leetcode

Approach:
Use Floyd's Cycle Detection
  Slow moves 1 step and fast moves 2 steps
  If they meet -> cycle exists.

  Time complexity: O(n)
  Space complexity: O(1)
  */

class Solution{
public:
bool hasCycle(ListNode *head){
  if(head == NULL){
    return false;
  }
  ListNode* slow = head;
  ListNode* fast = head;

  while(fast != NULL && fast -> next != NULL){
    slow = slow -> next;
    fast = fast -> next -> next;

    if(slow == fast){
    return true;
    }
  }
  return false;
}
};
