#ifndef NODETYPE_H_
#define NODETYPE_H_

typedef struct NodeType_s
{
    struct NodeType_s* prev;
    struct NodeType_s* next;
} NodeType;

#endif