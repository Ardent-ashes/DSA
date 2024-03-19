#include<bits/stdc++.h>
using namespace std;
void printStack(stack<char> s) {
    int count_a = 0;
    stack<char> cp = s;

    // Count occurrences of 'a' in the stack
    while (!cp.empty()) {
        if (cp.top() == 'a')
            count_a++;
        cp.pop();
    }

    // Print the stack if 'a' appears exactly 4 times
    if (count_a >= 4) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
stack<char> copyStack(const stack<char>& original) {
    stack<char> copiedStack;
    stack<char> tempStack;

    tempStack = original;
    while (!tempStack.empty()) {
        copiedStack.push(tempStack.top());
        tempStack.pop();
    }
  // Return the copied stack
    return copiedStack;
}

void generate(stack<char>s, string word, int k)
{

    stack<char>cp;
    if(s.size()==k)
    {
        printStack(s);
        return;
    }
    cp=copyStack(s);
    for(int i=0;i<word.length();i++)
    {
        cp.push(word[i]);
        generate(cp,word, k);
        cp.pop();
    }
}

int main()
{
    string s="abcdef";
    stack<char>e;
    int k=5;
    generate(e,s,k);
}
