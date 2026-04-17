/*
Problem: Detect Cycle in Linked List
Platform: LeetCode

Approach:

* Use Floyd’s Cycle Detection (Tortoise & Hare)
* Slow moves 1 step, fast moves 2 steps
* If they meet → cycle exists

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
bool hasCycle(ListNode *head) {
if(head == NULL) return false;

```
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}
```

};
