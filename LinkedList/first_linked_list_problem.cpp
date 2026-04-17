/*
Problem: Reverse Linked List (Medium)
Platform: LeetCode

Approach:

* Use iterative method
* Reverse pointers one by one

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
ListNode* reverseList(ListNode* head) {
ListNode* prev = NULL;
ListNode* curr = head;

```
    while(curr != NULL){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
```

};
