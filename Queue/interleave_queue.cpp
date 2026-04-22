/*
Problem: Interleave First Half of Queue with Second Half
Platform: GFG / Coding Ninjas

Approach:

* Split queue into two halves
* Store first half in another queue
* Push elements alternately

Note:

* Works only for even-sized queue

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q) {
int n = q.size();

```
// Edge case: odd size
if(n % 2 != 0) return;

queue<int> firstHalf;

// Step 1: Move first half to another queue
for(int i = 0; i < n/2; i++){
    firstHalf.push(q.front());
    q.pop();
}

// Step 2: Interleave
while(!firstHalf.empty()){
    q.push(firstHalf.front());
    firstHalf.pop();

    q.push(q.front());
    q.pop();
}
```

}
