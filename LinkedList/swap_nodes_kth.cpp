/*
Problem: Swapping Nodes in a Linked List
Platform: LeetCode

Approach:

* Find length of list
* Locate kth node from start
* Locate kth node from end
* Swap their values

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
ListNode* swapNodes(ListNode* head, int k) {
ListNode* first = head;
ListNode* second = head;
ListNode* temp = head;

```
    int length = 0;

    // Step 1: Calculate length
    while(temp){
        length++;
        temp = temp->next;
    }

    // Step 2: Find kth node from start
    for(int i = 1; i < k; i++){
        first = first->next;
    }

    // Step 3: Find kth node from end
    for(int i = 1; i < length - k + 1; i++){
        second = second->next;
    }

    // Step 4: Swap values
    swap(first->val, second->val);

    return head;
}
```

};
