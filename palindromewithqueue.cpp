#include<bits/stdc++.h>
using namespace std;

void ispalindrome(string s)
{
    int n=s.length();
    stack<char>last;
    queue<char>first;
    for(int i=0;i<n/2;i++)
    {
        first.push(s[i]);
    }
    if(n%2==0)
    {
       for(int i=n/2;i<n;i++)
        {
            last.push(s[i]);
        }
    }
    else
    {
            for(int i=(n+1)/2;i<n;i++)
            {
               last.push(s[i]);
            }
    }
    for(int i=0;i<n/2;i++)
    {

        if(first.front()!=last.top())
        {
            cout<<"not palindrome\n";
            return;
        }
        else
        {
            first.pop();
            last.pop();
        }

        
    }
    cout<<"palindrom yes\n";
    return;
    
}


int main()
{
      
       string s;
       cin>>s;
      
        
        ispalindrome(s);
        
        




}
