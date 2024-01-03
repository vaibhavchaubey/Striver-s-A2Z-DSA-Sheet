/* Cycle Detection[IMP][without map]

Floyd’s cycle detection */
/* Also know as hare and tortoise method, and slow and fast pointer method.
Idea: Slow and fast pointers are initially at the start. Slow takes one step. Fast takes
two-step at a time. */

// #include<iostream>
// using namespace std;
// class node{                                              //Time Complexity: O(N)
//     public:
//     int data;
//     node* next;

//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };
// void insertAtTail(node* &head, int val){
//     node* n = new node(val);
//     if (head==NULL)
//     {
//         head = n;
//         return;
//     }
//     node* temp = head;
//     while (temp->next!=NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = n;
// }
// void display(node* head){
//     node* temp = head;
//     while (temp!=NULL)
//     {
//         cout<<temp->data<<"->";
//         temp = temp->next;
//     }
//     cout<<"NULL"<<endl;
// }
// void makeCycle(node* &head, int pos){      //pos => position
//     node* temp = head;
//     node* startNode;

//     int count = 1;
//     while (temp->next!=NULL)
//     {
//         if (count==pos)
//         {
//             startNode = temp;
//         }
//         temp = temp->next;
//         count++;
//     }
//     temp->next = startNode;
// }
// bool detectcycle(node* &head){
//     node* slow = head;
//     node* fast = head;

//     while (fast!=NULL && fast->next!=NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//         if (fast==slow)
//         {
//             return true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     node* head=NULL;
//     insertAtTail(head,1);
//     insertAtTail(head,2);
//     insertAtTail(head,3);
//     insertAtTail(head,4);
//     insertAtTail(head,5);
//     insertAtTail(head,6);
//     makeCycle(head,3);
//     // display(head);
//     cout<<detectcycle(head)<<endl;

//     return 0;
// }

/* Remove Cycle */
#include <iostream>
using namespace std;
class node
{ // Time Complexity: O(N)
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
bool detectcycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void removeCycle(node *&head)
{
    
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            slow->next = NULL;
            break;
        }
    }
}

/* OR */

// void removeCycle(node *&head)
// {
//     node *slow = head;
//     node *fast = head;

//     do
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     } while (slow != fast);

//     fast = head;
//     while (slow->next != fast->next)
//     {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     slow->next = NULL;
// }

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    makeCycle(head, 3);
    // display(head);
    cout << detectcycle(head) << endl;
    removeCycle(head);
    cout << detectcycle(head) << endl;
    display(head);

    return 0;
}