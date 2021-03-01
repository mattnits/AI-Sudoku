#include "llist.h"
#include <iostream>

NODE *create_node(int val, NODE *start = NULL) {
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->val = val;
    if (start == NULL) {
        node->start = NULL;
    }
    else {
        node->start = start;
    }
    node->next = NULL;

    return node;
}

void insert_sorted(NODE **startp, NODE **endp, int val) {
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->val = val;
    node->start = NULL;
    NODE *current = *startp;
    NODE *prev = NULL;
    int flag = 0;

    if (current == NULL) {
        node->next = NULL;
        *startp = node;
        *endp = node;
        
    }
    else {
        while (current != NULL) {
            //std::cout << "Vals: " << current->val << std::endl;
            if (current->val >= val) {
                if (prev == NULL) {
                    prev = node;
                    prev->next = current;
                    *startp = prev;
                    //std::cout << "test1" << std::endl;
                }
                else if (current->next != NULL) {
                    prev->next = node;
                    node->next = current;
                    //std::cout << "test2" << std::endl;
                }
                else if (current->next == NULL) {
                    prev->next = node;
                    node->next = current;
                    current->next = NULL;
                    //std::cout << "test3" << std::endl;
                }
                
                break;
            }
            else if (current->next == NULL) {
                node->next = NULL;
                current->next = node;
                *endp = node;
                //std::cout << "test3" << std::endl;
            }
            else {
                prev = current;
                current = current->next;
            }
            
        }
    }
}

void insert_unsorted(NODE **startp, NODE **endp, int val) {

}

int remove_index(NODE **startp, NODE **endp, int val) {
    NODE *current = *startp;
	NODE *prev = NULL;
    int flag = 0;

    if ((*startp)->start != NULL) {
        std::cout << "ERROR, PLEASE REMOVE NESTED LIST";
        return 1;
    }
	
	if (current != NULL) {
        while (current != NULL) {
            if (current->val == val) {
                flag = 1;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (flag == 1){
            if (prev == NULL && current->next == NULL) {
                *startp = NULL;
                free(current);
            }
            else if (prev == NULL) {
                *startp = current->next;
                free(current);
            }
            else if (current->next == NULL){
                prev->next = NULL;
                free(current);
            }
            else {
                prev->next = current->next;
                free(current);
            }

        }
    }
	return 0;
}

void display(NODE *start) {
    NODE *current = start;


    while (current != NULL) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

}

void make_start(NODE *first, NODE *second) {
    first->start = second;
}

NODE *search(NODE *start, int val) {
    NODE *current = start;

    while (current != NULL) {
        if (current->val == val) {
            return current;
        }
        current = current->next;
    }
    return NULL;
    
}