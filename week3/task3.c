#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node* previous;
    struct node* next;
};

struct linkedlist{
    struct node* start;
};

void print_list(struct linkedlist ll){
    struct node* nd = ll.start;
    while (nd != NULL){
        printf("%d ", nd->value);
        nd = nd->next;
    }
    printf("\n");
}

int insert_element(struct node* base, struct node* insert){
    if (base == NULL || insert == NULL){
        return 1;
    }
    if (base->next == NULL){
        base->next = insert;
        insert->previous = base;
        return 0;
    }
    else{
        struct node* nextnext = base->next;
        base->next = insert;
        nextnext->previous = insert;
        insert->next = nextnext;
        insert->previous = base;
        return 0;
    }
}

int delete_element(struct node* base){
    if (base == NULL){
        return 1;
    }
    if (base->next != NULL){
        base->next->previous = base->previous;
    }
    if (base->previous != NULL){
        base->previous->next = base->next;
    }

    // free(base);
}
void main(){
    struct node fake  = {0, NULL, NULL};
    struct node one   = {1, NULL, NULL};
    struct node two   = {2, NULL, NULL};
    struct node three = {3, NULL, NULL};
    struct linkedlist ll = {&fake};
    print_list(ll);
    insert_element(ll.start, &one);
    insert_element(ll.start, &two);
    insert_element(ll.start, &three);
    print_list(ll);
    delete_element(&two);
    print_list(ll);
}