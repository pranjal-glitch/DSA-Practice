/*
Problem: Circular Queue Implementation
Concept: Data Structure (Queue)

Approach:

* Use array to implement circular queue
* Maintain front and rear pointers
* Use modulo arithmetic for circular movement

Time Complexity:

* Enqueue: O(1)
* Dequeue: O(1)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:
int *arr;
int front;
int rear;
int size;

```
CircularQueue(int n){
    size = n;
    arr = new int[size];
    front = rear = -1;
}

bool enqueue(int value){

    // Queue full
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1 + size) % size)) {
        return false;
    }

    // First element
    if(front == -1){
        front = rear = 0;
    }
    // Circular case
    else if(rear == size - 1 && front != 0){
        rear = 0;
    }
    else{
        rear++;
    }

    arr[rear] = value;
    return true;
}

int dequeue(){

    // Queue empty
    if(front == -1){
        return -1;
    }

    int ans = arr[front];

    // Single element
    if(front == rear){
        front = rear = -1;
    }
    // Circular move
    else if(front == size - 1){
        front = 0;
    }
    else{
        front++;
    }

    return ans;
}
```

};
