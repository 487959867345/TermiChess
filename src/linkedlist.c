#include "math.h"
#include "linkedlist.h"

#include <stdlib.h>
#include <stdio.h>
V2LinkedList new_linked_list() {
    V2LinkedList l;
    l.nodes = NULL;
    l.size = 0;
    return  l;
}

void push(V2LinkedList *list, Vec2 val) {
    lnode_t *cur = list->nodes;
    if (cur != NULL) {
        while (cur->nextNode != NULL) {
            cur = cur->nextNode;
        }
        cur->nextNode = (lnode_t*) malloc(sizeof(lnode_t));
        cur->nextNode->val = val;
        cur->nextNode->nextNode = NULL;
        list->size++;
    }else {
        lnode_t *head = (lnode_t*) malloc(sizeof(lnode_t));
        head->val = val;
        list->nodes = head;
        list->size++;
    }
}

void pop(V2LinkedList *list) {

    list->size--;
}