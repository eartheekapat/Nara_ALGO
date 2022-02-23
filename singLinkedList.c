#include <stdio.h>

struct node
{
    int data;
    Node *next;
};
typedef struct node Node;

int listLength(Node *head);
Node *addEnd(Node *head, int data);
Node *nodeInit(int data);
Node *insertInLinkedList(Node *head, int data, int position);
Node *removeEnd(Node *head);
// remove node with data
Node *removeNode(Node *head, int data);
// remove node at the position from the linked list
Node *deleteNodeFromLinkedList(Node *head, int position);
// remove first/head node of the list
Node *removeFront(Node *head);

int main()
{
    Node *head = listInit(0);

    return 0;
}

void DeleteLinkedLIst(Node *head)
{
    if (head == NULL)
        return NULL;

    // if there's only one Node
    if (head->next == NULL)
        return removeFront(head);

    // there're more than one node
    Node *curr = head;
    Node *temp = curr;
    while (curr != NULL)
    {
        curr = curr->next;
        free(temp);
    }
}

Node *deleteNodeFromLinkedList(Node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 1) // delete first/head node
        return removeFront(head);

    // loop to find the position
    Node *curr = head;
    Node *prev = NULL;

    int i = 0;
    while (i < position)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    // at the position, we delete curr
    if (prev == NULL) // this means position is out of linkedlist
    {                 // so just do nothing and return head
        return head;
    }
    else if (prev != NULL && curr == NULL)
    { // this means there's no node at the position then do nothing
        return head;
    }
    else if (prev != NULL && curr != NULL && curr->next == NULL)
    { // the node to be deleted is the last node of the list
        prev->next = NULL;
        free(curr);
        return head;
    }
    else if (prev != NULL && curr != NULL && curr->next != NULL)
    { // the node to be deleted is neither first nor last node but
        // somewhere in the middle of the list
        prev->next = curr->next;
        free(curr);
        return head;
    }
}

Node *removeFront(Node *head)
{
    if (head == NULL)
        return NULL;
    // only one node which means free the linkedlist
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

Node *removeNode(Node *head, int data)
{
    if (head == NULL)
        return NULL;
    // case the node to remove is head
    if (head->data == data)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    // else we gotta find the node which contains data and remove it
    Node *curr = head;
    Node *prev = NULL;
    for (curr = head; curr->next != NULL; curr = curr->next)
    {
        if (curr->data == data) // found node to delete
        // which is not the first node for sure
        // means prev is assign
        {
            prev->next = curr->next;
            free(curr);
            return head;
        }
    }
    // out to this node to delete might be the last node
    // we may have to do sth different
    if (curr->data == data)
    {
        prev->next = NULL;
        free(curr);
        return head;
    }
}

Node *removeEnd(Node *head)
{
    Node *curr = head;
    for (curr = head; curr->next != NULL; curr = curr->next)
        ;
    // now that we get the last node, free it
    free(curr);
    return head;
}

Node *insertInLinkedList(Node *head, int data, int position)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    // loop to the position
    for (int i = 1; i < position; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) // 2 cases : position = 1 or prev+curr both NULL
    {
        if (position == 1)
        {
            Node *newNode = nodeInit(data);
            newNode->next = head;
            return newNode;
        }
        else
        { // do nothing and return head
            return head;
        }
    }
    else if (prev != NULL && curr == NULL)
    {
        // this mean at the position, there's no node
        // so we add node to prev
        Node *newNode = nodeInit(data);
        prev->next = newNode;
    }
    else if (prev != NULL && curr != NULL)
    {
        // so in this case node exists at both prev and curr
        // means we gotta add node to prev and link
        // the new node to curr
        Node *newNode = nodeInit(data);
        prev->next = newNode;
        prev->next->next = curr;
    }
}

Node *addFront(Node *head, int data)
{
    if (head == NULL)
        return NULL;
}

Node *addEnd(Node *head, int data)
{
    Node *curr = head;
    // loop to the last node
    for (curr = head; curr->next != NULL; curr = curr->next)
        ;
    // add a node to the end of the list
    Node *newNode = nodeInit(data);
    curr->next = newNode;
    return head;
}

int listLength(Node *head)
{
    int count = 0;
    // loop through the list
    for (Node *curr = head; curr != NULL; curr = curr->next)
        count++;
    return count;
}

Node *nodeInit(int data)
{
    Node *pn = malloc(sizeof(Node));

    if (pn = NULL)
        printf("out of mem");

    pn->data = data;
    pn->next = NULL;
    return pn;
}
