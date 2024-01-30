#include<bits/stdc++.h>
using namespace std;
struct ll{
struct node{
node* next;
int val;
};
node* head=NULL;
node* tail=NULL;

void insert_first(int x)
{
    node* a=(node*)malloc(sizeof(node));
    a->next=NULL;
    a->val=x;
    if(head==NULL){
        head=a;
        tail=a;
    }
    else{
        a->next=head;
        head=a;
    }
}

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

int delet_first()
{
    if(head==NULL)
    {
        return -1;
    }
    if(head==tail)
    {
        int x=head->val;
        head=NULL;
        tail=NULL;
        return x;
    }
    else
    {
        int x=head->val;
        head=head->next;
        return x;
    }
}

int delet_last()
{
    if(head==NULL)
    {
        return -1;
    }
    if(head==tail)
    {
        int x=head->val;
        head=NULL;
        tail=NULL;
        return x;
    }
    else
    {
        int x=tail->val;
        node* a=head;
        while(a->next!=tail)
        {
            a=a->next;
        }
        a->next=NULL;
        tail=a;
        return x;
    }
}


void print()
{
    node* a = head;
    while(a!=NULL)
    {
        cout<<a->val<<" ";
        a=a->next;
    }
    cout<<"\n";
}

};

int main()
{

    int n,t,y;
    cin>>t;
   ll* h = new ll;
    while(t--)
    {
        cin>>y;
        if(y==1)
        {
             cin>>n;
             h->insert_last(n);;
        }
        
       // h->insert_first(n);
       if(y==2)
       {
            
            h->delet_last();
       }
        
        h->print();
        
    }
    delete h;
    return 0;
    
}
