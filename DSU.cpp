#include <bits/stdc++.h> 
#include <cstdlib>
using namespace std;

int parent[100];
int ranks[100];

void make_set(int v) {
    parent[v] = v;
    ranks[v] = 0;
}

/*void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}*/

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

int main() { 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        make_set(y);
    }

    int u;
    cin >> u;
    for (int i = 0; i < u; i++) {
        int x, y;
        cin >> x >> y;
        union_sets(x, y);
    }
    
    int f;
    cin >> f;
    for (int i = 0; i < f; i++) {
        int x;
        cin >> x;
        cout << find_set(x) << "\n";
    }
  
    return 0; 
}
