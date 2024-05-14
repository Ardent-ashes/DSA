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
           // tail=a;
            //free(a->next);
            
            return x;
        }
    }

    void insert_after(int val, int x)
    {
        node* p = head;
        while(p != NULL && p->val != val)
        {
            p = p->next;
        }
        if(p == NULL)
        {
            cout << "Value not found in the list.\n";
            return;
        }
        
        node* new_node = new node;
        new_node->val = x;
        new_node->prev = p;
        new_node->next = p->next;
        
        if(p->next != NULL)
        {
            p->next->prev = new_node;
        }
        p->next = new_node;
        
        if(p == tail)
        {
            tail = new_node;
        }
    }

     void delete_after(int val)
    {
        node* p = head;
        while(p != NULL && p->val != val)
        {
            p = p->next;
        }
        if(p == NULL || p->next == NULL)
        {
            cout << "Value not found or there is no node after the specified value.\n";
            return;
        }
        
        node* to_delete = p->next;
        p->next = to_delete->next;
        if(to_delete->next != NULL)
        {
            to_delete->next->prev = p;
        }
        delete to_delete;
        
        if(p->next == NULL)
        {
            tail = p;
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

         if(test==6)
        {
            int x,y;
            cin>>x;
            h->delete_after(x);
           
        }
        h->print();

    }
}
