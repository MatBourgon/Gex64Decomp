#ifndef TNODETYPE_H_
#define TNODETYPE_H_

typedef struct NodeType_s
{
    struct NodeType_s* prev;
    struct NodeType_s* next;
} NodeType;

#endif