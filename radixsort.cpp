#include <iostream>
#include <queue>
using namespace std;

int getmax(int ara[], int n)
{
    int m=ara[0];
    for(int i=0;i<n;i++)
    {
        if(ara[i]>m)
        {
            m=ara[i];
        }
    }
    return m;
}

void countsort(int ara[], int n, int ex)
{
    int output[n];
    int count[10]={0};
    int i=0;

    for(int i=0;i<n;i++)
    {
        count[(ara[i]/ex)%10]++;
    }

    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }

    for(i=n-1;i>=0;i--)
    {
        output[count[(ara[i]/ex)%10]-1]=ara[i];
        count[(ara[i]/ex)%10]--;
    }
    for (i = 0; i < n; i++)
        ara[i] = output[i];

}

void radixsort(int ara[],int n)
{
    int m=getmax(ara,n);
    for(int ex=1;m/ex>0;ex*=10)
    {
        countsort(ara,n,ex);
    }
}

int main() {
    int n;
    cin>>n;
    int ara[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    radixsort(ara,n);
    for (int i = 0; i < n; i++)
        cout << ara[i] << " ";
    return 0;
}
