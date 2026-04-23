/*
Problem: Intersection of Two Linked Lists
Platform: LeetCode

Approach:

* Use two pointers
* Traverse both lists
* When pointer reaches end, switch to other list
* They will meet at intersection node (or NULL)

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

```
    if(headA == NULL || headB == NULL)
        return NULL;

    ListNode* a = headA;
    ListNode* b = headB;

    while(a != b){
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a;
}
```

};
