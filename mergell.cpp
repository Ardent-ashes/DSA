#include<bits/stdc++.h>
using namespace std;

struct ll {
    struct node {
        node* next;
        int val;
    };
    node* head = NULL;
    node* tail = NULL;

    void insert_last(int x) {
        node* a = new node();
        a->next = NULL;
        a->val = x;
        if (tail) {
            tail->next = a;
            tail = a;
        } else {
            tail = a;
            head = a;
        }
    }

     void sortList() {
        if (!head || !head->next)
            return;
        node* prev = NULL;
        node* curr = head;
        while (curr) {
            node* temp = curr->next;
            while (temp) {
                if (curr->val > temp->val) {
                    swap(curr->val, temp->val);
                }
                temp = temp->next;
            }
            prev = curr;
            curr = curr->next;
        }
    }

  void merge(node* p, node* q) {
    while (p != NULL && q != NULL) {
        if (p->val <= q->val) {
            insert_last(p->val);
            p = p->next;
        } else {
            insert_last(q->val);
            q = q->next;
        }
    }

    //Append remaining nodes from list p
    while (p != NULL) {
        insert_last(p->val);
        p = p->next;
    }

    // Append remaining nodes from list q
    while (q != NULL) {
        insert_last(q->val);
        q = q->next;
    }
}


    void print() {
        node* a = head;
        while (a != NULL) {
            cout << a->val << " ";
            a = a->next;
        }
        cout << "\n";
    }
};

int main() {
    int n, t1, t2;
    cin >> t1;
    ll* h1 = new ll;
    while (t1--) {
        cin >> n;
        h1->insert_last(n);
    }

    ll* h2 = new ll;
    cin >> t2;
    while (t2--) {
        cin >> n;
        h2->insert_last(n);
    }
    h1->sortList();
    h2->sortList();

    ll* h3 = new ll;
    h3->merge(h1->head, h2->head);
    h3->print();

    return 0;
}
