#include <iostream>
#include <queue>
using namespace std;

struct Stack {
    queue<int> q1;
    queue<int> q2;
};

// Constructor function
Stack createStack() {
    Stack s;
    return s;
}

// Push element x onto stack.
void push(Stack &s, int x) {
    // Push the new element to q2
    s.q2.push(x);
    
    // Move all elements from q1 to q2
    while (!s.q1.empty()) {
        s.q2.push(s.q1.front());
        s.q1.pop();
    }
    
    // Swap q1 and q2
    swap(s.q1, s.q2);
}

// Removes the element on top of the stack.
void pop(Stack &s) {
    if (!s.q1.empty())
        s.q1.pop();
}

// Get the top element.
int top(Stack &s) {
    if (!s.q1.empty())
        return s.q1.front();
    return -1; // If stack is empty
}

// Return whether the stack is empty.
bool isEmpty(Stack &s) {
    return s.q1.empty();
}

int main() {
    Stack s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);

    cout << "Top element: " << top(s) << endl;
    pop(s);
    cout << "Top element after pop: " << top(s) << endl;

    return 0;
}
