#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Traverse
void traverse(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;

    *head = newNode;
}

// Insert at position
void insertAtPosition(struct Node** head, int value, int pos) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    // Insert at first position
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(struct Node** head) {

    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;

    *head = (*head)->next;

    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node** head) {

    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;

    // Only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete from position
void deleteFromPosition(struct Node** head, int pos) {

    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;

    // Delete first node
    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return;
    }

    struct Node* delNode = temp->next;

    temp->next = delNode->next;

    free(delNode);
}

// Main function
int main() {

    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("After inserting at end:\n");
    traverse(head);

    insertAtBeginning(&head, 5);

    printf("After inserting at beginning:\n");
    traverse(head);

    insertAtPosition(&head, 25, 3);

    printf("After inserting at position 3:\n");
    traverse(head);

    deleteFromBeginning(&head);

    printf("After deleting from beginning:\n");
    traverse(head);

    deleteFromEnd(&head);

    printf("After deleting from end:\n");
    traverse(head);

    deleteFromPosition(&head, 1);

    printf("After deleting from position 1:\n");
    traverse(head);

    return 0;
}
