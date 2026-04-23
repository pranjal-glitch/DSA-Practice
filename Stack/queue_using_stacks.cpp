/*
Problem: Implement Queue using Stacks
Platform: LeetCode

Approach:

* Use two stacks:

  1. in  → for push operations
  2. out → for pop/peek operations

* Transfer elements from 'in' to 'out' only when 'out' is empty

Time Complexity:

* Push: O(1)
* Pop: Amortized O(1)
* Peek: Amortized O(1)

Space Complexity: O(n)
*/

class MyQueue {
public:
stack<int> in, out;

```
MyQueue() {}

void push(int x) {
    in.push(x);
}

void transfer() {
    if(out.empty()){
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
}

int pop() {
    transfer();
    int val = out.top();
    out.pop();
    return val;
}

int peek() {
    transfer();
    return out.top();
}

bool empty() {
    return in.empty() && out.empty();
}
```

};
