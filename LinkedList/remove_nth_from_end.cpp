/*
Problem: Remove Nth Node From End of List
Platform: LeetCode

Approach:

* Use two pointers (fast & slow)
* Move fast pointer n+1 steps ahead (from dummy)
* Move both until fast reaches NULL
* Delete the target node

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) {

```
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n+1 steps
    for(int i = 0; i <= n; i++){
        if(fast != NULL)
            fast = fast->next;
    }

    // Move both pointers
    while(fast != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    return dummy->next;
}
```

};
