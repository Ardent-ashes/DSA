#include <bits/stdc++.h>
using namespace std;

struct Heap{
    vector<int> ara;
    int size = 0;

    void maxheapify(int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && ara[l] > ara[largest])
            largest = l;
        if (r < size && ara[r] > ara[largest])
            largest = r;

        if (largest != i) {
            swap(ara[i], ara[largest]);
            maxheapify(largest);
        }
    }

     void minheapify(int i) {
        int min = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && ara[l] < ara[min])
            min = l;
        if (r < size && ara[r] < ara[min])
            min = r;

        if (min != i) {
            swap(ara[i], ara[min]);
            minheapify(min);
        }
    }

    void insert(int v) {
        ara.push_back(v);
        size++;
        for (int i = size / 2 - 1; i >= 0; i--) {
            minheapify(i);
        }
    }

    int extract_max() {
        if (size == 0) return INT_MIN;
        int ret = ara[0];
        ara[0] = ara[size - 1];
        size--;
        int current = 0;
        while (current < size / 2) {
            int left = current * 2 + 1;
            int right = current * 2 + 2;
            int largest = left;
            if (right < size && ara[right] > ara[left]) largest = right;
            if (ara[largest] <= ara[current]) break;
            swap(ara[current], ara[largest]);
            current = largest;
        }
        return ret;
    }

   int extract_min() {
    if (size == 0) return INT_MAX;
    int ret = ara[0];
    ara[0] = ara[size - 1];
    size--;
    int current = 0;
    while (current < size / 2) {
        int left = current * 2 + 1;
        int right = current * 2 + 2;
        int smallest = left;
        if (right < size && ara[right] < ara[left]) smallest = right;
        if (ara[smallest] >= ara[current]) break;
        swap(ara[current], ara[smallest]);
        current = smallest;
    }
    return ret;
}
    // Now, ara[i] has been moved to its correct position in the heap
    // The max heap property has been restored


};



int main() {
    Heap* heap = new Heap();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        heap->insert(v);
    }

    cout << "[";
    cout << heap->extract_min();
    for (int i = 1; i < n; i++) {
        cout << "," << heap->extract_min();
    }

    cout << "]";
    delete heap;
    return 0;
}
