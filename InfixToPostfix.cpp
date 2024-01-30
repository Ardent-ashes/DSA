//01
//01
#include <bits/stdc++.h>
using namespace std;
 
struct ll{
struct node{
node* next;
char val;
};
node* head=NULL;
node* tail=NULL;

void insert_first(char x)
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

void push(char x)
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
        char x=head->val;
        head=NULL;
        tail=NULL;
        return x;
    }
    else
    {
        char x=tail->val;
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
char top()
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

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 

char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; 
}
 

void inToPost(string s) {
    ll *st= new ll;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        else if (c == '(')
            st->push('(');
 
       
        else if (c == ')') {
            while (st->top() != '(') {
                result += st->top();
                st->pop();
            }
            st->pop(); 
        }
 
       
        else {
            while (!st->empty() && precedence(s[i]) < precedence(st->top()) ||
                   !st->empty() && precedence(s[i]) == precedence(st->top()) &&
                   associativity(s[i]) == 'L') {
                result += st->top();
                st->pop();
            }
            st->push(c);
        }
    }
 
    while (!st->empty()) {
        result += st->top();
        st->pop();
    }
 
    cout << result << endl;
}
 
int main() {
    string ex;
    cin>>ex;
    int i=0;
    ll* h = new ll;
    while(ex[i]!='\0')
    {
        h->push(ex[i]);
        i++;
    }
 
   
    inToPost(ex);
 
    return 0;
}
