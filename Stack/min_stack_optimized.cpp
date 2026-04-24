/*
Problem: Special Stack / Min Stack (Optimized)
Platform: GFG / Coding Ninjas

Approach:

* Use single stack with encoding technique
* Maintain current minimum (mini)

Push:

* If new value < mini:
  store encoded value: 2*data - mini
  update mini

Pop:

* If popped value < mini:
  restore previous minimum

Top:

* If top < mini → return mini
* Else return top

Time Complexity:

* Push: O(1)
* Pop: O(1)
* Top: O(1)
* GetMin: O(1)

Space Complexity: O(1)
*/

#include <stack>
using namespace std;

class SpecialStack {
stack<int> s;
int mini;

public:

```
void push(int data) {
    if (s.empty()) {
        s.push(data);
        mini = data;
    } 
    else if (data < mini) {
        s.push(2 * data - mini);
        mini = data;
    } 
    else {
        s.push(data);
    }
}

void pop() {
    if (s.empty()) return;

    int curr = s.top();
    s.pop();

    if (curr < mini) {
        mini = 2 * mini - curr;
    }
}

int top() {
    if (s.empty()) return -1;

    int curr = s.top();

    if (curr < mini) return mini;
    return curr;
}

bool isEmpty() {
    return s.empty();
}

int getMin() {
    if (s.empty()) return -1;
    return mini;
}
```

};
