#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "math.h"

typedef struct node {
	Vec2 val;
	struct node *nextNode;
} lnode_t;

typedef struct {
	lnode_t *nodes;
    int size;
} V2LinkedList;

V2LinkedList new_linked_list();

void push(V2LinkedList *list, Vec2 val);
#endif