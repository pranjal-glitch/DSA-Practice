/*
Problem: Minimum Cost to Make String Valid
Platform: GFG / Coding Ninjas

Approach:

* If length is odd → impossible
* Use stack to remove valid "{}" pairs
* Count remaining:
  a = number of '{'
  b = number of '}'
* Minimum reversals needed:
  (a + 1)/2 + (b + 1)/2

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {

```
// Odd length → not possible
if(str.length() % 2 == 1){
    return -1;
}

stack<char> s;

// Step 1: Remove valid pairs
for(char ch : str){
    if(ch == '{'){
        s.push(ch);
    } 
    else {
        if(!s.empty() && s.top() == '{'){
            s.pop();
        } else {
            s.push(ch);
        }
    }
}

// Step 2: Count remaining brackets
int a = 0, b = 0;

while(!s.empty()){
    if(s.top() == '{') a++;
    else b++;
    s.pop();
}

// Step 3: Calculate result
return (a + 1)/2 + (b + 1)/2;
```

}
