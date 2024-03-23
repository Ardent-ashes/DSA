#include <bits/stdc++.h>
using namespace std;

int get_left(int ara[], int index) {
    return ara[2 * index + 1];
}

int get_right(int ara[], int index) {
    return ara[2 * index + 2]; 
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int ara[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> ara[i];
    }

   int t;
   cin>>t;
   while(t--)
   {
    char c;
    cin>>c;
    int x;
    cin>>x;
    if(ara[x]==-1) continue;
    if(c=='l') cout<<get_left(ara,x)<<endl;
    if(c=='r') cout<<get_right(ara,x)<<endl;
   }

    return 0;
}
