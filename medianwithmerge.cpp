// Merge sort in C++

#include <bits/stdc++.h>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int ara[],int ar1[], int ar2[], int n1, int n2) {

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = 0;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (ar1[i] <= ar2[j]) {
      ara[k] = ar1[i];
      i++;
    } else {
      ara[k] = ar2[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    ara[k] = ar1[i];
    i++;
    k++;
  }

  while (j < n2) {
    ara[k] = ar2[j];
    j++;
    k++;
  }
}


// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  int n1,n2;
  cin>>n1;
  cin>>n2;
  int ar1[n1];
  int ar2[n2];
  for(int i=0;i<n1;i++)
  {
    cin>>ar1[i];
  }
  sort(ar1,ar1+n1);
  for(int i=0;i<n2;i++)
  {
    cin>>ar2[i];
  }
    sort(ar2,ar2+n2);
  int ara[n1+n2];
  merge(ara,ar1,ar2,n1,n2);
//   for(int i=0;i<n1+n2;i++)
//   {
//     cout<<ara[i]<<" ";
//   }
 int l=n1+n2;
 cout<<l<<endl;
 float r;
 if(l%2!=0)
 {
    r=ara[(l+1)/2];
    cout<<"hi"<<endl;
 }
 else
 {
    printf("elements %d %d\n",ara[l/2],ara[(l/2)+1]);
    r= ((float)(ara[l/2-1]+ara[(l/2)]))/2;
 }
 cout<<r<<endl;
  return 0;
}
