#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void printlist(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatfront(int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
}

void insertatend(int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;

    node *last = head;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
}

void deletenode(int key)
{
    node *temp = head;
    node *prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;
        free(temp);
        return;
    } // if head node holds the value

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return; //key not found in list
    prev->next = temp->next;
    free(temp);
}

void reverse()
{
    node *curr = head;
    node *next = NULL;
    node *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main()
{
    insertatend(99);
    insertatfront(1);
    insertatfront(2);
    insertatfront(3);
    insertatend(5);
    insertatend(7);

    printlist(head);

    deletenode(99);
    printlist(head);
    reverse();
    printlist(head);
    return 0;
}