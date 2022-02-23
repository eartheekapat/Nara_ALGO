#include <stdio.h>
#include <stdlib.h>

typedef struct CLLnode cNode;
struct CLLnode
{
    int data;
    cNode *next;
};

// initialize CLL
cNode *cNodeInit(int data);
// find length of CLL
int CLLlen(cNode *head);
// add to the end of the list
cNode *addEnd(cNode *head, int data);
// print the list
void printCLLdata(cNode *head);
// add to the front of the list
cNode *addFront(cNode *head, int data);
// delete the last node of the list
void delLast(cNode *head);
// delete the first node of the list
cNode *delHead(cNode *head);

int main()
{
    cNode *head = cNodeInit(0);
    head = addEnd(head, 1);
    head = addEnd(head, 2);
    head = addFront(head, -1);
    delLast(head);
    head = delHead(head);

    printf("There're %d nodes in CLL.\n", CLLlen(head));
    printCLLdata(head);

    return 0;
}

cNode *delHead(cNode *head)
{
    if (head == NULL)
        printf("Empty list");
    // find last node which links to head
    cNode *lastNode;
    for (lastNode = head; lastNode->next != head; lastNode = lastNode->next)
        ;
    lastNode->next = head->next;
    cNode *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void delLast(cNode *head)
{
    if (head == NULL)
        printf("Empty list");
    // find last node which links to head
    cNode *lastNode;
    cNode *lastNode_prev;
    for (lastNode = head; lastNode->next != head; lastNode = lastNode->next)
        lastNode_prev = lastNode;
    lastNode_prev->next = head;
    free(lastNode);
}

cNode *addFront(cNode *head, int data)
{
    if (head == NULL)
        return cNodeInit(data);
    // find last node
    cNode *lastNode;
    for (lastNode = head; lastNode->next != head; lastNode = lastNode->next)
        ;
    lastNode->next = cNodeInit(data);
    lastNode->next->next = head;
    head = lastNode->next;
    return head;
}

void printCLLdata(cNode *head)
{
    cNode *curr = head;
    do
    {
        printf("%d -> ", curr->data);
        curr = curr->next;

    } while (curr->next != head);
    printf("%d\n", curr->data);
}

cNode *addEnd(cNode *head, int data)
{
    if (head == NULL) // empty list
        return NULL;
    if (head->next == NULL) // having only one node in the list
    {
        head->next = cNodeInit(data);
        head->next->next = head;
        return head;
    }
    else // there're more than 2 nodes in the list
    {
        cNode *curr = head;
        // loop to the last node of the list
        for (int count = 0; curr->next != head; curr = curr->next)
            ;
        curr->next = cNodeInit(data);
        curr->next->next = head;
        return head;
    }
}

int CLLlen(cNode *head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    cNode *curr = head;
    do
    {
        curr = curr->next;
        count++;
    } while (curr != head);

    return count;
}

cNode *cNodeInit(int data)
{
    cNode *head = malloc(sizeof(cNode));
    if (head == NULL)
    {
        printf("mem err");
        return NULL;
    }
    head->data = data;
    head->next = NULL;

    return head;
}
