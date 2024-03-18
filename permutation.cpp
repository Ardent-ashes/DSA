#include<bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r)
{
    char temp;
   if(l==r)
   {
    cout<<s<<"\n";
   }
   
   else
   {
    for(int i=l;i<=r;i++)
    {
        temp=s[l];
        s[l]=s[i];
        s[i]=temp;
        permute(s,l+1,r);
        temp=s[l];
        s[l]=s[i];
        s[i]=temp;

    }
   }

}

int main()
{
    string s="abcd";
    permute(s,0,3);
}
