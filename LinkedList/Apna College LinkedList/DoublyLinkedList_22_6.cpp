#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    if (head!=NULL)                //As is case of no element there is no prev of head
    {
        head->prev = n;
    }
    head = n;
}
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node* head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void deleteAtHead(node* &head){
    if (head == NULL) {
        return;
    }
    node* todelete = head;
    head = head->next;
    if (head!=NULL)                //As is case of no element there is no prev of head
    {
        head->prev = NULL;
    }

    delete todelete;
}
void deletion(node* &head, int pos){
    if (pos==1)
    {
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    int count = 1;
    while (temp->next!=NULL && count!=pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next!=NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;    
}
bool search(node* head, int key){
    node* temp = head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            return true;
        }
        temp = temp->next;       
    }
    return false;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    // deleteAtHead(head);
    deletion(head,5);              //Here 5 is pos
    display(head);
    cout<<search(head,3)<<endl;


    

    return 0;
}