#include <iostream>
using namespace std;

struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
    int capacity;
};

CircularQueue* createCircularQueue(int capacity) {
    CircularQueue* cq = new CircularQueue;
    cq->capacity = capacity;
    cq->arr = new int[capacity];
    cq->size = 0;
    cq->front = 0;
    cq->rear = -1;
    return cq;
}

void enqueue(CircularQueue* cq, int value) {
    if (cq->size == cq->capacity) {
        cout << "Queue is full. Cannot enqueue." << endl;
        return;
    }
    cq->rear = (cq->rear + 1) % cq->capacity;
    cq->arr[cq->rear] = value;
    cq->size++;
}

void dequeue(CircularQueue* cq) {
    if (cq->size == 0) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    cq->front = (cq->front + 1) % cq->capacity;
    cq->size--;
}

int peek(CircularQueue* cq) {
    if (cq->size == 0) {
        cout << "Queue is empty. No elements to peek." << endl;
        return -1;
    }
    return cq->arr[cq->front];
}

bool isEmpty(CircularQueue* cq) {
    return cq->size == 0;
}

bool isFull(CircularQueue* cq) {
    return cq->size == cq->capacity;
}

int main() {

    int x;
    cin>>x;
    CircularQueue* cq = createCircularQueue(x);


    enqueue(cq, 10);
    enqueue(cq, 20);
    enqueue(cq, 30);
    enqueue(cq, 40);
    enqueue(cq, 50);
    enqueue(cq, 60); // This will print a message indicating the queue is full.

    while (!isEmpty(cq)) {
        cout << peek(cq) << " ";
        dequeue(cq);
    }
    cout << endl;

    delete[] cq->arr;
    delete cq;

    return 0;
}
