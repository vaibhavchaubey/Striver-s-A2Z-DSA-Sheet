#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if (head==NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    
    node* temp = head;
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
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
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void display(node* head){
    node* temp = head;
    do                              //If we use while (temp!=head) we are not able to go inside the loop as in starting temp = head
    {                              //that is why we are using do while loop
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp!=head);
    
    cout<<endl;
}
void deleteAtHead(node* &head){
    node* temp = head;
    while (temp->next!=head)
    {
        temp = temp->next;
    }
    node* todelete = head;
    temp->next = head->next;
    head = head->next;

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
    while (count!=pos-1)         //To delete the given pos we should write pos-1 as we are changing temp->next
    {
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}
bool search(node* head, int key){
    node* temp = head;
    do
    {
        if (temp->data==key)
        {
            return true;
        }
        temp = temp->next;
    } while (temp!=head);
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
    deletion(head,5);          //Here 5 is pos
    display(head);
    cout<<search(head,3)<<endl;

    return 0;
}