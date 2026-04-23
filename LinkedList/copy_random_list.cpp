/*
Problem: Copy List with Random Pointer
Platform: LeetCode

Approach:

* Use HashMap to store mapping:
  original node → copied node
* First pass: create all nodes
* Second pass: assign next and random pointers

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
Node* copyRandomList(Node* head){
if(head == NULL){
return NULL;
}

```
    unordered_map<Node*, Node*> mp;
    Node* temp = head;

    // Step 1: Create new nodes
    while(temp != NULL){
        mp[temp] = new Node(temp->val);
        temp = temp->next;
    }

    // Step 2: Assign next and random
    temp = head;
    while(temp != NULL){
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}
```

};
