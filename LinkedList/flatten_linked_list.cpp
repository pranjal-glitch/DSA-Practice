/*
Problem: Flatten a Multilevel Linked List
Platform: GFG / Coding Ninjas

Approach:

* Recursively flatten right side
* Merge two sorted lists using child pointer
* Ignore next pointer after merge

Time Complexity: O(n*m)
Space Complexity: O(h)
*/

Node* merge(Node* a, Node* b) {
if(!a) return b;
if(!b) return a;

```
Node* result;

if(a->data < b->data){
    result = a;
    result->child = merge(a->child, b);
}
else{
    result = b;
    result->child = merge(a, b->child);
}

result->next = NULL; // important
return result;
```

}

Node* flattenLinkedList(Node* head) {

```
if(!head || !head->next){
    return head;
}

// Flatten right side first
head->next = flattenLinkedList(head->next);

// Merge current list with flattened next
head = merge(head, head->next);

return head;
```

}
