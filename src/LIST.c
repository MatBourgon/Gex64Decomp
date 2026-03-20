#include "common.h"

#include "LIST.h"

void LIST_InsertFunc(NodeType *list, NodeType *node)
{
    node->prev = list;

    node->next = list->next;

    if (list->next != NULL)
    {
        list->next->prev = node;
    }

    list->next = node;
}

void LIST_DeleteFunc(NodeType *node)
{
    if (node->prev != NULL)
    {
        if (node->next != NULL)
        {
            node->prev->next = node->next;

            node->next->prev = node->prev;

            node->next = NULL;

            node->prev = NULL;

            return;
        }
    }
    else if (node->next != NULL)
    {
        node->next->prev = NULL;

        node->next = NULL;

        node->prev = NULL;

        return;
    }

    if (node->prev != NULL)
    {
        node->prev->next = NULL;

        node->next = NULL;
    }
    else
    {
        node->next = NULL;
    }

    node->prev = NULL;
}

NodeType *LIST_GetFunc(NodeType *list)
{
    NodeType *temp; // not from decls.h

    temp = list->next;

    if (temp != NULL)
    {
        LIST_DeleteFunc(temp);

        return temp;
    }

    return NULL;
}

// Find last "best" node
NodeType* LIST_CompareFunc(NodeType* list, ListCompareFunc cmp) {
    NodeType* node = NULL;
    
    for (list = list->next; list != NULL; list = list->next) {
        if ((node == NULL) || (cmp(node, list) > 0)) {
            node = list;
        }
    }
    return node;
}

int LIST_CountFunc(NodeType* list) {
    int count = 0;
    while ((list = list->next) != NULL) {
        ++count;
    }
    return count;
}

void LIST_AppendFunc(NodeType* list, NodeType* node) {
    while (node->next != 0) {
        NodeType* temp = node->next;
        LIST_DeleteFunc(temp);
        LIST_InsertFunc(list, temp);
    }
}
