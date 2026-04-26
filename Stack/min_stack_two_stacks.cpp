/*
Problem: Min Stack
Platform: LeetCode

Approach:

* Use two stacks:

  1. st → stores all values
  2. minSt → stores minimum values

* Push:
  if minSt empty or val <= min → push to minSt

* Pop:
  if popped element == min → pop from minSt

Time Complexity:

* Push: O(1)
* Pop: O(1)
* Top: O(1)
* GetMin: O(1)

Space Complexity: O(n)
*/

class MinStack {
public:
stack<int> st, minSt;

```
MinStack() {}

void push(int val) {
    st.push(val);
    if(minSt.empty() || val <= minSt.top()){
        minSt.push(val);
    }
}

void pop() {
    if(st.top() == minSt.top()){
        minSt.pop();
    }
    st.pop();
}

int top() {
    return st.top();
}

int getMin() {
    return minSt.top();
}
```

};
