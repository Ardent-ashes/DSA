#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void bucketSort(double arr[], int n) {
    const int num_buckets = 101; // Number of buckets (0-100 inclusive for integers)
    stack<double> b[num_buckets]; // Array of stacks for buckets

    // Put array elements in different buckets based on their value
    for (int i = 0; i < n; i++) {
        int bi;
        if (arr[i] < 1) { // For floating-point numbers
            bi = static_cast<int>(arr[i] * num_buckets); // Index of the bucket
        } else { // For integers
            bi = static_cast<int>(arr[i]); // Index of the bucket
        }
        b[bi].push(arr[i]);
    }

    // Sort individual stacks
    for (int i = 0; i < num_buckets; i++) {
        stack<double>& bucket = b[i];
        stack<double> tempStack;

        while (!bucket.empty()) {
            double temp = bucket.top();
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
        stack<double>& bucket = b[i];
        while (!bucket.empty()) {
            arr[index++] = bucket.top();
            bucket.pop();
        }
    }
}

int main() {
    double arr[] = { 0.1234, 0.3434, 0.565, 0.897, 0.521 }; // Including integers and floating-point numbers
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
