#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    // Compare first elements
    if (a.first != b.first) {
        return a.first < b.first;
    }
    // If first elements are equal, compare second elements
    return a.second < b.second;
}

int main() {
    int n;
    cout << "Enter the number of pairs: ";
    cin >> n;

    // Input pairs
    vector<pair<int, int>> pairs;
    cout << "Enter " << n << " pairs (each pair consists of two integers separated by space):" << endl;
    for (int i = 0; i < n; ++i) {
        int first, second;
        cin >> first >> second;
        pairs.push_back({first, second});
    }

    // Sorting pairs using the custom comparison function
    sort(pairs.begin(), pairs.end(), compare);

    // Printing sorted pairs
    cout << "Sorted pairs:" << endl;
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
