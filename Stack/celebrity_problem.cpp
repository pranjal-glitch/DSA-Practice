/*
Problem: Celebrity Problem
Platform: GFG / Coding Ninjas

Definition:

* A celebrity is known by everyone
* A celebrity knows no one

Approach:

1. Push all people into stack
2. Compare two people:

   * If A knows B → A can't be celebrity
   * Else → B can't be celebrity
3. One candidate remains
4. Verify candidate:

   * Should not know anyone
   * Everyone should know candidate

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// knows(A, B) is predefined

int findCelebrity(int n) {

```
stack<int> s;

// Step 1: push all people
for(int i = 0; i < n; i++){
    s.push(i);
}

// Step 2: eliminate
while(s.size() > 1){
    int a = s.top(); s.pop();
    int b = s.top(); s.pop();

    if(knows(a, b)){
        s.push(b);
    } else {
        s.push(a);
    }
}

int candidate = s.top();

// Step 3: verify candidate

// Candidate should not know anyone
for(int i = 0; i < n; i++){
    if(i != candidate && knows(candidate, i)){
        return -1;
    }
}

// Everyone should know candidate
for(int i = 0; i < n; i++){
    if(i != candidate && !knows(i, candidate)){
        return -1;
    }
}

return candidate;
```

}
