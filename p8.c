#include <stdio.h>
#include <stdlib.h>
struct Employee {
    char SSN[15], Name[30], Dept[20], Designation[30];
    float Sal;
    long long PhNo;
    struct Employee *next, *prev;
};
struct Employee* createNode() {
    struct Employee* n = malloc(sizeof(struct Employee));
    printf("Enter SSN Name Dept Designation Salary Phone:\n");
    scanf("%s %s %s %s %f %lld", n->SSN, n->Name, n->Dept, n->Designation, &n->Sal, &n->PhNo);
    n->next = n->prev = NULL;
    return n;
}
void insertEnd(struct Employee** head, struct Employee** tail) {
    struct Employee* n = createNode();
    if (!*head) {
        *head = *tail = n;
    } else {
        n->prev = *tail;
        (*tail)->next = n;
        *tail = n;
    }
    printf("Inserted at end.\n");
}
void insertFront(struct Employee** head, struct Employee** tail) {
    struct Employee* n = createNode();
    if (!*head) {
        *head = *tail = n;
    } else {
        n->next = *head;
        (*head)->prev = n;
        *head = n;
    }
    printf("Inserted at front.\n");
}
void deleteEnd(struct Employee** head, struct Employee** tail) {
    if (!*head) {
        printf("Empty list.\n");
        return;
    }
    if (!(*head)->next) {
        free(*head);
        *head = *tail = NULL;
    } else {
        struct Employee* t = *tail;
        *tail = t->prev;
        (*tail)->next = NULL;
        free(t);
    }
    printf("Deleted from end.\n");
}
void deleteFront(struct Employee** head, struct Employee** tail) {
    if (!*head) {
        printf("Empty list.\n");
        return;
    }
    if (!(*head)->next) {
        free(*head);
        *head = *tail = NULL;
    } else {
        struct Employee* t = *head;
        *head = t->next;
        (*head)->prev = NULL;
        free(t);
    }
    printf("Deleted from front.\n");
}
void display(struct Employee* head) {
    if (!head) {
        printf("Empty list.\n");
        return;
    }
    int c = 0;
    while (head) {
        printf("%s %s %s %s %.2f %lld\n", head->SSN, head->Name, head->Dept, head->Designation, head->Sal, head->PhNo);
        head = head->next;
        c++;
    }
    printf("Total nodes: %d\n", c);
}
void freeList(struct Employee** head, struct Employee** tail) {
    struct Employee* cur = *head;
    while (cur) {
        struct Employee* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    *head = *tail = NULL;
}
int main() {
    struct Employee *head = NULL, *tail = NULL;
    int ch;
    do {
        printf("\nMenu:\n1.Insert End\n2.Display\n3.Insert Front\n4.Delete End\n5.Delete Front\n6.Double Ended Queue Demo\n7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insertEnd(&head,&tail); break;
            case 2: display(head); break;
            case 3: insertFront(&head,&tail); break;
            case 4: deleteEnd(&head,&tail); break;
            case 5: deleteFront(&head,&tail); break;
            case 6: insertFront(&head,&tail); deleteEnd(&head,&tail); break;
            case 7: freeList(&head,&tail); printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (ch != 7);
    return 0;
}
