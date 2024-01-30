//01
//01
//01
//01
#include<bits/stdc++.h>
using namespace std;
struct ll{
struct node{
node* next;
int val;
};
node* head=NULL;
node* tail=NULL;


void insert_last(int x)
{
    node* a=(node*)malloc(sizeof(node));
    a->next=NULL;
    a->val=x;
    if(tail){
        tail->next=a;
        tail=a;
    }
    else{
        tail=a;
        head=a;
    }
}






void print()
{
    node* a = head;
    while(a!=NULL)
    {
        cout<<a->val<<"\n";
        a=a->next;
    }
    //cout<<"\n";
}

};

int main()
{
    int n,t,y;
    cin>>t;
    ll* h = new ll;
    while(t--)
    {
       
             cin>>n;
             h->insert_last(n);
        
        
        
    }
    h->print();
    delete h;
    return 0;
    
}