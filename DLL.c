#include <stdio.h>
#include <stdlib.h>

typedef struct CLLnode cNode;
struct CLLnode
{
    int data;
    cNode *next;
};

// initialize CLL
cNode *CLLinit(int data);
// find length of CLL
int CLLlen(cNode *head);

int main()
{
    cNode *head = CLLinit(0);

    printf("%d", CLLlen(head));
}

int CLLlen(cNode *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    for (cNode *curr = head; curr != NULL; curr = curr->next)
    {
        count++;
    }
    return count;
}

cNode *CLLinit(int data)
{
    cNode *head = malloc(sizeof(cNode));
    if (head == NULL)
        printf("mem err");
    return;
    head->data = data;
    head->next = NULL;

    return head;
}
