#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void bucketSort(int arr[], int n) {
    // Define the range of integers and the number of buckets
    const int range = 100; // Range of integers from 0 to 99
    const int num_buckets = range;

    // Create num_buckets empty stacks
    stack<int> b[num_buckets];

    // Put array elements in different stacks based on their value
    for (int i = 0; i < n; i++) {
        int bi = arr[i] * num_buckets / range; // Index of the bucket
        b[bi].push(arr[i]);
    }

    // Sort individual stacks
    for (int i = 0; i < num_buckets; i++) {
        stack<int>& bucket = b[i];
        stack<int> tempStack;

        while (!bucket.empty()) {
            int temp = bucket.top();
            bucket.pop();

            // Inserting elements in sorted order into tempStack
            while (!tempStack.empty() && tempStack.top() > temp) {
                bucket.push(tempStack.top());
                tempStack.pop();
            }
            tempStack.push(temp);
        }

        // Copy elements from tempStack back to original bucket
        while (!tempStack.empty()) {
            bucket.push(tempStack.top());
            tempStack.pop();
        }
    }

    // Concatenate all stacks into arr[]
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        stack<int>& bucket = b[i];
        while (!bucket.empty()) {
            arr[index++] = bucket.top();
            bucket.pop();
        }
    }
}

int main() {
    int arr[] = { 5, 1, 7, 10, 2, 3, 8, 9, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
