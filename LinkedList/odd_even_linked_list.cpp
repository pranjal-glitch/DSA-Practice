/*
Problem: Odd Even Linked List
Platform: LeetCode

Approach:

* Maintain two pointers:
  odd → nodes at odd positions
  even → nodes at even positions
* Link odd nodes together
* Link even nodes together
* Attach even list at end of odd list

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
ListNode* oddEvenList(ListNode* head) {

```
    if(!head || !head->next){
        return head;
    }

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}
```

};
