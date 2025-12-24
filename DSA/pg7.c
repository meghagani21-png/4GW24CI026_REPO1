#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char usn[50];
    char name[50];
    char program[50];
    int sem;
    char phno[50];
    struct student *next;
};

struct student *head = NULL;

struct student *createnode() {
    struct student *newnode = (struct student *)malloc(sizeof(struct student));

    printf("USN: ");
    scanf("%s", newnode->usn);

    printf("Name: ");
    scanf("%s", newnode->name);

    printf("Program: ");
    scanf("%s", newnode->program);

    printf("Semester: ");
    scanf("%d", &newnode->sem);

    printf("Phone: ");
    scanf("%s", newnode->phno);

    newnode->next = NULL;
    return newnode;
}

void createLlist(int n)
{
    for (int i = 0; i < n; i++)
    {
        struct student *newnode = createnode();

        /* Insert at front */
        newnode->next = head;
        head = newnode;
    }
}

void display() {
    struct student *temp = head;
    int count = 0;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("USN:%s Name:%s Program:%s Sem:%d Phone:%s\n",
               temp->usn, temp->name, temp->program, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total students: %d\n", count);
}

void insertend() {
    struct student *newnode = createnode();
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct student *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void deleteatend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct student *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteatfront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct student *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    int choice, n;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create list\n");
        printf("2. Display\n");
        printf("3. Insert at end\n");
        printf("4. Delete from end\n");
        printf("5. Delete from front\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of students: ");
                scanf("%d", &n);
                createLlist(n);
                break;
            case 2:
                display();
                break;
            case 3:
                insertend();
                break;
            case 4:
                deleteatend();
                break;
            case 5:
                deleteatfront();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

