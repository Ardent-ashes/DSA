#include<bits/stdc++.h>
using namespace std;

void combination(int n, int r, int ara[], int data[], int index, int start)
{
    if(index==r)
    {
        for(int i=0;i<r;i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=start;i<n;i++)
    {
        data[index]=ara[i];
        combination(n,r,ara,data,index+1,i+1);
    }

}

int main()
{
    int ara[]={5,6,7,8,9};
    int data[3]={};
    combination(5,3,ara,data,0,0);
}
