/*
Problem: N Stacks in a Single Array
Platform: Coding Ninjas

Approach:

* Use 3 arrays:

  1. arr[] → stores actual values
  2. top[] → stores top index of each stack
  3. next[] → links free slots & stack elements

* freespot → keeps track of first free index

Push:

* Take index from freespot
* Update freespot
* Link new element to stack

Pop:

* Remove top index
* Update freespot
* Return element

Time Complexity:

* Push: O(1)
* Pop: O(1)

Space Complexity: O(S + N)
*/

#include <bits/stdc++.h>
using namespace std;

class NStack {
int *arr;
int *top;
int *next;

```
int n, s;
int freespot;
```

public:
NStack(int N, int S) {
n = N;
s = S;

```
    arr = new int[s];
    top = new int[n];
    next = new int[s];

    // Initialize all stacks as empty
    for(int i = 0; i < n; i++){
        top[i] = -1;
    }

    // Initialize free list
    for(int i = 0; i < s - 1; i++){
        next[i] = i + 1;
    }
    next[s - 1] = -1;

    freespot = 0;
}

bool push(int x, int m) {

    // Overflow
    if(freespot == -1){
        return false;
    }

    int index = freespot;
    freespot = next[index];

    arr[index] = x;

    next[index] = top[m - 1];
    top[m - 1] = index;

    return true;
}

int pop(int m) {

    // Underflow
    if(top[m - 1] == -1){
        return -1;
    }

    int index = top[m - 1];
    top[m - 1] = next[index];

    next[index] = freespot;
    freespot = index;

    return arr[index];
}
```

};
