#ifndef LIST_H_
#define LIST_H_

#include "types/NodeType.h"
typedef int(*ListCompareFunc)(NodeType*, NodeType*);

void LIST_InsertFunc(NodeType *list, NodeType *node);
void LIST_DeleteFunc(NodeType *node);
NodeType *LIST_GetFunc(NodeType *list);
NodeType* LIST_CompareFunc(NodeType* list, ListCompareFunc cmp);
int LIST_CountFunc(NodeType* list);
void LIST_AppendFunc(NodeType* list, NodeType* node);

#endif