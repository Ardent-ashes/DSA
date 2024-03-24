#include<bits/stdc++.h>

using namespace std;

void generatePermutations(string& str, int index, unordered_set<string>& uniquePermutations) {
    if (index == str.size()) {
        // If the current permutation is not already present, add it to the set
        uniquePermutations.insert(str);
        return;
    }

    // Loop through all characters starting from the current index
    for (int i = index; i < str.size(); ++i) {
        // Swap the current character with the character at index 'index'
        swap(str[i], str[index]);
        // Recur for the next index
        generatePermutations(str, index + 1, uniquePermutations);
        // Backtrack - restore the original string
        swap(str[i], str[index]);
    }
}

void generatePermutations(string& str) {
    unordered_set<string> uniquePermutations;
    generatePermutations(str, 0, uniquePermutations);
    // Print all unique permutations
    for (const string& perm : uniquePermutations) {
        cout << perm << endl;
    }
}

void permute(string str, int index, vector<string>& per) {
    if (index == str.size()) {
        int l = per.size();
        for (int i = 0; i < l; i++) {
            if (per[i] == str) return; // Using == operator for string comparison
        }
        cout << str << endl;
        per.push_back(str);

        return;
    }
    // Rest of your code...



    // Loop through all characters starting from the current index
    for (int i = index; i < str.size(); ++i) {
        // Swap the current character with the character at index 'index'
        swap(str[i], str[index]);
        // Recur for the next index
        permute(str, index + 1, per);
        // Backtrack - restore the original string
        swap(str[i], str[index]);
    }
}



int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    vector<string>per;
    permute(input,0,per);

   // generatePermutations(input);

    return 0;
}
