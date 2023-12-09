#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int value;
};

Node* list_create_node(int data)
{
    Node* somnod;
    somnod = (Node*)malloc(sizeof(Node));
    somnod->prev = NULL;
    somnod->next = NULL;
    somnod->value = data;
    return somnod;
}

void list_out(Node* head)
{
    while (head != NULL)
    {
        printf("%d\n", head->value);
        head = head->next;
    }
}

void list_delete(Node* head)
{
    Node* next = NULL;

    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

void list_delete_node(Node* node)
{
    Node* next = node->next;
    Node* prev = node->prev;

    free(node);

    if (prev)
        prev->next = next;

    if (next)
        next->prev = prev;
}

Node* list_prepend(Node* head, int data)
{
    Node* l;
    l = (Node*)malloc(sizeof(Node*));
    l = head->prev;
    l->next = head;
    l->prev = NULL;
    l->value = data;
    return l;
}

Node* list_append(Node* head, int data)
{
    Node* tail = head;
    Node* node;

    if (head == NULL)
        return NULL;

    /* Ищем конец списка */
    while (tail->next)
        tail = tail->next;

    node = list_create_node(data);

    list_insert(tail, node);

    return node;
}

void list_insert(Node* insnode, Node* newnode)
{
    newnode->next = insnode->next;
    newnode->prev = insnode;

    insnode->next = newnode;

    if (newnode->next != NULL)
        newnode->next->prev = newnode;
}