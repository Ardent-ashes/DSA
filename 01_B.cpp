//01
//01
//01
#include <iostream>
using namespace std;

struct ll
{

    struct student
    {
        student *next;
        string name;
        int roll;
    };
    student *head=NULL;
    student *tail=NULL;

    void insert_first(string name, int roll)
    {
        //Your code starts here #001
        student* a=(student*)malloc(sizeof(student));
        a->next=NULL;
        a->name=name;
        a->roll=roll;
        if(head==NULL){
        head=a;
        tail=a;
    }
    else{
        a->next=head;
        head=a;
    }
        
        //Your code ends here #001
        
    }

    
    void print()
    {
        //prints elements from head to tail
        //Your code starts here #002
        student* a = head;
        while(a!=NULL)
        {
        cout<<a->name<<" "<<a->roll<<"\n";
        a=a->next;
        }

        //Your code ends here #002
    }
};


int main()
{
    //Your code starts here #003
    
    int t;
    string s;
    int n;
    cin>>t;
   ll* h = new ll;
    while(t--)
    {
        
        {
             cin>>s;
             cin>>n;
             h->insert_first(s,n);
        }
        
       
       
       
        
    }
     h->print();
    delete h;
    return 0;

    
    //Your code ends here #003


}