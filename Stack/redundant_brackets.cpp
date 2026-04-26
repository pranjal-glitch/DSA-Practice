/*
Problem: Redundant Brackets
Platform: GFG / Coding Ninjas

Approach:

* Use stack to track brackets and operators
* On encountering ')':

  * Check if any operator exists inside brackets
  * If not → redundant

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
stack<char> st;

```
for(char ch : s){

    // Push opening bracket and operators
    if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        st.push(ch);
    }
    else if(ch == ')'){
        
        bool isRedundant = true;

        // 🔥 IMPORTANT FIX: check stack safety
        while(!st.empty() && st.top() != '('){
            char top = st.top();

            if(top == '+' || top == '-' || top == '*' || top == '/'){
                isRedundant = false;
            }

            st.pop();
        }

        if(isRedundant) return true;

        if(!st.empty()) st.pop(); // remove '(' safely
    }
}

return false;
```

}

