#include<bits/stdc++.h>
using namespace std;

struct ll
{
    struct node
    {
        int val;
        node* next;
        node* prev;
    };
    node* head= NULL;
    node* tail=NULL;
    void insert_last(int x)
    {
        node* a= (node*)malloc(sizeof(node));
        a->next=NULL;
        a->prev=NULL;
        a->val=x;

        if(tail)
        {
            a->prev=tail;
            tail->next=a;
            tail=a;
        }
        else
        {
            tail=a;
            head=a;
        }
    }
    void insert_first(int x)
    {
        node* a= (node*)malloc(sizeof(node));
        a->next=NULL;
        a->val=x;
        
        if(head==NULL)
        {
            head=a;
            tail=a;
        }
        else
        {
            a->next=head;
            head->prev=a;
            head=a;
        }
    }
    int delete_first()
    {
        if(head==NULL)
        {
            return -1;
        }
        else if(head==tail)
        {
            int x=head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            
            int x;
            head=head->next;
            head->prev=NULL;
            //free(a);
            return x;
        }
    }
    int delete_last()
    {
        if(head==NULL)
        {
            return -1;
        }
        else if(head==tail)
        {
            int x=head->val;
            head=NULL;
            tail=NULL;
            return x;
        }
        else
        {
            int x=tail->val;
            tail=tail->prev;
            tail->next=NULL;
            tail=a;
            //free(a->next);
            
            return x;
        }
    }
    void circulate(int x)
    {
        node* p=head;
        x--;
        while(x--)
        {
           
            p=p->next;
            
        }
         
        cout<<p->val<<"\n";
    }
    void print()
    {
        node* p=head;
        while(p!=NULL)
        {
            cout<<p->val<<" ";
            p=p->next;
            
        }
        cout<<"\n";
    }
};





int main()
{
    int t;
    cin>>t;
    ll* h= new ll;
    while(t--)
    {
        int test;
        
        
        printf("for insert first press 1\nfor insert last press 2\nfor delete first press 3\nfor delete last press 4\n");
        cin>>test;
        if(test==1)
        {
            int x;
            cin>>x;
            h->insert_first(x);
           
        }
        if(test==2)
        {
            int x;
            cin>>x;
            h->insert_last(x);
           
        }
        if(test==3)
        {
            h->delete_first();
          
        }
        if(test==4)
        {
            h->delete_last();
           
        }
        
        if(test==5)
        {
            int x;
            cin>>x;
            h->circulate(x);
           
        }
        h->print();

    }
}
