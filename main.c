/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[50];
    struct node* next;
} person_t;

void printList(person_t*);
void removeDuplicated();

int main() {
    
    person_t *head;
    person_t p1 = {"Daniel", NULL};
    person_t p2 = {"Ana", NULL};
    person_t p3 = {"Daniel", NULL};
    person_t p4 = {"NoName", NULL};
    
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    head = &p1;
    
    printf("Initial data:\n");
    printList(head);
    
    printf("\nRemoving duplicated:\n\n");
    removeDuplicated(&head);

    printf("Clean list:\n");
    printList(head);
    
    exit(0);
}

void printList(person_t *list){
    
    //skipping the null stuff part
    
    while (list != NULL) {
        printf("Person's name: %s\n", list->name);
        list = list->next;
    }
}

void removeDuplicated(person_t **head) {

    //skipping the null stuff part
    
    person_t *current = *head;
    person_t *compNode;
    
    while (current!=NULL) {
        compNode = current;
        while(compNode->next!=NULL) {
            if (strcmp(current->name, compNode->next->name) == 0) {
                compNode->next = compNode->next->next;
            }
            compNode = compNode->next;
        }
        current = current->next;
    }
    
}
