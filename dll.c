#include <stdio.h>
#include <stdlib.h>


struct node {
    struct node* prev;
    int data;
    struct node* next;
};


struct node* getnode(int ele) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    ptr->data = ele;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}


void insertbeg(struct node** head, int ele) {
    struct node* p = getnode(ele);
    if (*head == NULL) {
        *head = p;
    } else {
        p->next = *head;
        (*head)->prev = p;
        *head = p;
    }
}


void insertmid(struct node** head, int ele, int pos) {
    struct node* p = getnode(ele);
    if (*head == NULL) {
        *head = p;
    } else {
        struct node* temp = *head;
        int i = 0;
        while (temp != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(p);
            return;
        }
        p->next = temp->next;
        p->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = p;
        }
        temp->next = p;
    }
}


void insertend(struct node** head, int ele) {
    struct node* p = getnode(ele);
    if (*head == NULL) {
        *head = p;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
        p->prev = temp;
    }
}


void delbeg(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}


void delend(struct node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = *head;
        if (temp->next == NULL) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
    }
}

// Function to delete a node from a specific position
void deletemid(struct node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty\n");
    } else {
        struct node* temp = *head;
        int i = 0;
        while (temp != NULL && i < pos) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

// Function to traverse and display the list
void traverse(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    printf("Menu\n");
    printf("1 to insert at beginning\n");
    printf("2 to insert at middle\n");
    printf("3 to insert at end\n");
    printf("4 to delete at beginning\n");
    printf("5 to delete at middle\n");
    printf("6 to delete at end\n");
    printf("7 to display\n");
    printf("8 to quit\n");

    struct node* head = NULL;
    int x = 0;
    while (x != 8) {
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch (x) {
            case 1: {
                int a;
                printf("Enter the element: ");
                scanf("%d", &a);
                insertbeg(&head, a);
                break;
            }
            case 2: {
                int c, pos;
                printf("Enter the element: ");
                scanf("%d", &c);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertmid(&head, c, pos);
                break;
            }
            case 3: {
                int b;
                printf("Enter the element: ");
                scanf("%d", &b);
                insertend(&head, b);
                break;
            }
            case 4:
                delbeg(&head);
                break;
            case 5: {
                int posi;
                printf("Enter the position: ");
                scanf("%d", &posi);
                deletemid(&head, posi);
                break;
            }
            case 6:
                delend(&head);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}