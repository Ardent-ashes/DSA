#include<iostream> 
#include<climits> 
using namespace std; 

void swap(int *x, int *y); 
struct MaxHeap 
{ 
    int *harr; 
    int capacity;
    int heap_size; 

    MaxHeap(int cap){
        heap_size = 0; 
        capacity = cap; 
        harr = new int[cap]; 
    }


    void MaxHeapify(int i){
        int l = left(i); 
        int r = right(i); 
        int largest = i; 
        if (l < heap_size && harr[l] > harr[i]) 
            largest = l; 
        if (r < heap_size && harr[r] > harr[largest]) 
            largest = r; 
        if (largest != i) 
        { 
            swap(&harr[i], &harr[largest]); 
            MaxHeapify(largest); 
        } 
    }

    int parent(int i) { return (i-1)/2; } 


    int left(int i) { return (2*i + 1); } 


    int right(int i) { return (2*i + 2); } 


    int extractMax(){
        if (heap_size <= 0) 
            return INT_MIN; 
        if (heap_size == 1) 
        { 
            heap_size--; 
            return harr[0]; 
        } 

        int root = harr[0]; 
        harr[0] = harr[heap_size-1]; 
        heap_size--; 
        MaxHeapify(0); 

        return root; 
    }

    void deleteKey(int key) {
    int i;
    for (i = 0; i < heap_size; ++i) {
        if (harr[i] == key)
            break;
    }

    if (i == heap_size) {
        cout << "Key not found\n";
        return;
    }

    // Replace the key to be deleted with the last element
    harr[i] = harr[heap_size - 1];
    heap_size--;

    // Heapify the heap from the replaced position
    MaxHeapify(i);
}

    void increaseKey(int i, int new_val){
        harr[i] = new_val; 
        while (i != 0 && harr[parent(i)] < harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        } 
    }


    int getMax() { return harr[0]; } 

   

    void insertKey(int k){
        if (heap_size == capacity) 
        { 
            cout << "\nOverflow: Could not insertKey\n"; 
            return; 
        } 
        heap_size++; 
        int i = heap_size - 1; 
        harr[i] = k; 
        while (i != 0 && harr[parent(i)] < harr[i]) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        } 
    }
}; 

void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int main() 
{ 
    MaxHeap h(11); 
    h.insertKey(3); 
    h.insertKey(8);
    h.insertKey(1); 
    h.deleteKey(8); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
    while(h.heap_size!=0)  cout << h.extractMax() << " "; 
    
    //cout << h.getMax() << " "; 
    //h.decreaseKey(2, 1); 
    //cout << h.getMax(); 
    return 0; 
} 
