//01

#include <bits/stdc++.h>
using namespace std;
 
struct ll{
struct node{
node* next;
int val;
};
node* head=NULL;
node* tail=NULL;


void push(int x)
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



int pop()
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
int top()
{
    return tail->val;
}

int empty()
{
    if(head==NULL)
    {
        return 1;
    }
    else
    return 0;
}

};



int evaluatePostfix(string exp)
{
    
    ll* st=new ll;
 
   
    for (int i = 0; i < exp.size(); ++i) {
       
        if (isdigit(exp[i]))
            st->push(exp[i] - '0');
 
        else {
            int val1 = st->top();
            st->pop();
            int val2 = st->top();
            st->pop();
            switch (exp[i]) {
            case '+':
                st->push(val2 + val1);
                break;
            case '-':
                st->push(val2 - val1);
                break;
            case '*':
                st->push(val2 * val1);
                break;
            case '/':
                st->push(val2 / val1);
                break;
            }
        }
    }
    return st->top();
}
 
int main() {
    string exp;
    cin>>exp;
 
   
    int r=evaluatePostfix(exp);
    cout<<r<<endl;
 
    return 0;
}
