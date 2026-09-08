#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

// Insert at the beginning
void insertAtBeginning() {
    int value;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("Node with data %d inserted at beginning.\n", value);
}

// Insert at the end
void insertAtEnd() {
    int value;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Node with data %d inserted at end.\n", value);
}

// Insert at a specific position (1-based indexing)
void insertAtPosition() {
    int value, position, count = 1;
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &value);
    printf("Enter position (1-based): ");
    scanf("%d", &position);

    newnode->data = value;

    if (position == 1) {
        newnode->next = head;
        head = newnode;
        printf("Node with data %d inserted at position %d.\n", value, position);
        return;
    }

    struct node* temp = head;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position! List has only %d nodes.\n", count);
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node with data %d inserted at position %d.\n", value, position);
}

// Delete from beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    printf("Node with data %d deleted from beginning.\n", temp->data);
    free(temp);
}

// Delete from end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Node with data %d deleted from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Node with data %d deleted from end.\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Delete from a specific position
void deleteAtPosition() {
    int position, count = 1;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter position (1-based): ");
    scanf("%d", &position);

    if (position == 1) {
        struct node* temp = head;
        head = head->next;
        printf("Node with data %d deleted from position 1.\n", temp->data);
        free(temp);
        return;
    }

    struct node* temp = head;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position! List has fewer nodes.\n");
        return;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    printf("Node with data %d deleted from position %d.\n", del->data, position);
    free(del);
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free all nodes before exit
void freeList() {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n----MENU----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteAtBeginning(); break;
            case 5: deleteAtEnd(); break;
            case 6: deleteAtPosition(); break;
            case 7: display(); break;
            case 8:
                freeList();
                printf("Exiting.\n");
                exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
