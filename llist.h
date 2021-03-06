#ifndef LLIST
#define LLIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
	struct node *next;
    struct node *start;
    struct node *end;

} NODE;

NODE *create_node(int, NODE *);

void insert_sorted(NODE **startp, NODE **endp, int val);

void insert_unsorted(NODE **startp, NODE **endp, int val);

int remove_index(NODE **startp, NODE **endp, int index);

void display(NODE *start);

void make_start(NODE *first, NODE *second);

NODE *search(NODE *start, int val);



#endif