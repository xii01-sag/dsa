#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
    char usn[20], name[30], prog[10], phno[15];
    int sem;
    struct student *next;
};
typedef struct student* NODE;
NODE createNode() {
    NODE temp = (NODE)malloc(sizeof(struct student));
    if (!temp) {
        printf("Memory not allocated!\n");
        exit(0);
    }
    printf("\nEnter USN: ");
    scanf("%s", temp->usn);
    printf("Enter Name: ");
    scanf("%s", temp->name);
    printf("Enter Programme: ");
    scanf("%s", temp->prog);
    printf("Enter Semester: ");
    scanf("%d", &temp->sem);
    printf("Enter Phone Number: ");
    scanf("%s", temp->phno);
    temp->next = NULL;
    return temp;
}
NODE insertFront(NODE head) {
    NODE newnode = createNode();
    newnode->next = head;
    return newnode;
}
NODE insertEnd(NODE head) {
    NODE newnode = createNode();
    if (head == NULL) {
        return newnode;
    }
    NODE temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}
NODE deleteFront(NODE head) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return head;
    }
    NODE temp = head;
    printf("\nDeleted Student USN: %s\n", temp->usn);
    head = head->next;
    free(temp);
    return head;
}
NODE deleteEnd(NODE head) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return NULL;
    }
    if (head->next == NULL) {
        printf("\nDeleted Student USN: %s\n", head->usn);
        free(head);
        return NULL;
    }
    NODE temp = head, prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("\nDeleted Student USN: %s\n", temp->usn);
    free(temp);
    prev->next = NULL;
    return head;
}
void display(NODE head) {
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    int count = 0;
    NODE temp = head;
    printf("\n--- STUDENT LIST ---\n");
    while (temp != NULL) {
        printf("USN: %s | Name: %s | Programme: %s | Sem: %d | Phone: %s\n",
               temp->usn, temp->name, temp->prog, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("\nTotal Nodes = %d\n", count);
}
int main() {
    NODE head = NULL;
    int choice, n, i;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create SLL using front insertion\n");
        printf("2. Display & Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Stack Push)\n");
        printf("6. Delete at Front (Stack Pop)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter number of students: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    head = insertFront(head);
                }
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insertEnd(head);
                break;
            case 4:
                head = deleteEnd(head);
                break;
            case 5:
                head = insertFront(head);
                break;
            case 6:
                head = deleteFront(head);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
