/*
Problem: Sort Linked List (Merge Sort)
Platform: GFG / LeetCode

Approach:

1. Find middle of list (slow-fast pointer)
2. Divide into two halves
3. Recursively sort both halves
4. Merge sorted halves

Time Complexity: O(n log n)
Space Complexity: O(log n)
*/

node* findMid(node* head){
node* slow = head;
node* fast = head->next;

```
while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
return slow;
```

}

node* merge(node* left, node* right){
if(!left) return right;
if(!right) return left;

```
node* dummy = new node(-1);
node* temp = dummy;

while(left && right){
    if(left->data < right->data){
        temp->next = left;
        left = left->next;
    }
    else{
        temp->next = right;
        right = right->next;
    }
    temp = temp->next;
}

if(left) temp->next = left;
if(right) temp->next = right;

return dummy->next;
```

}

node* mergeSort(node *head) {

```
if(head == NULL || head->next == NULL){
    return head;
}

node* mid = findMid(head);

node* left = head;
node* right = mid->next;
mid->next = NULL;

left = mergeSort(left);
right = mergeSort(right);

return merge(left, right);
```

}
