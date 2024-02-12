#include<bits/stdc++.h>
using namespace std;

int countsort(int input[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        k=max(k,input[i]);

    }
    int count[k+1]={0};

    for(int i=0;i<n;i++)
    {
        count[input[i]]++;
    }
    for(int i=1;i<=k;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[count[input[i]]-1]=input[i];
        count[input[i]]--;
    }
    for(int i=0;i<n;i++)
        {
            cout<<output[i]<<" ";
        }
    return 0;
}


int main()
{
      
       int n;
       cin>>n;
       int input[n];
        for(int i=0;i<n;i++)
        {
            cin>>input[i];
        }
      
        
        countsort(input,n);
        
        




}
