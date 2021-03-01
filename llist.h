#ifndef LLIST
#define LLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
	struct node *next;
    struct node *start;

} NODE;

NODE *create_node(int val);

void display(NODE *start);

NODE *search(NODE *start, int val);

void insert(NODE **startp, int val);

int remove_index(NODE **startp, int index);




#endif