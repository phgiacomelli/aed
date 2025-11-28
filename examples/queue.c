#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
} Person;

typedef struct Node {
    Person* data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void Reset(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int isEmpty(Queue* queue) {
    return queue->head == NULL;
}

int Push(Queue* queue, Person* person) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error - malloc Node.\n");
        exit(1);
    }

    Person* newPerson = (Person*)malloc(sizeof(Person));
    if (newPerson == NULL) {
        printf("Error - malloc Person.\n");
        exit(1);
    }
    strcpy(newPerson->name, person->name);

    newNode->data = newPerson;
    newNode->next = NULL;

    if (isEmpty(queue))
        queue->head = newNode;
    else
        queue->tail->next = newNode;

    queue->tail = newNode;
    return 1;
}

Person Pop(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    Node* oldHead = queue->head;
    Person Person = *oldHead->data;

    queue->head = queue->head->next;

    free(oldHead->data);
    free(oldHead);

    return Person;
}

Person* Peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    return queue->head->data;
}

void Clear(Queue* queue) {
    Node* curr = queue->head;
    while (curr != NULL) {
        Node* next = curr->next;
        free(curr->data);
        free(curr);
        curr = next;
    }
    free(queue);
}

int main() {
    Person* p1 = (Person*)malloc(sizeof(Person));
    strcpy(p1->name, "Paulo");

    Person* p2 = (Person*)malloc(sizeof(Person));
    strcpy(p2->name, "Henrique");

    Queue* queue = (Queue*)malloc(sizeof(Queue));
    Reset(queue);

    // queue is empty
    Pop(queue);
    Peek(queue);

    Push(queue, p1);
    Push(queue, p2);

    Person p3 = Pop(queue);
    printf("name: %s\n", p3.name);
    Person* p4 = Peek(queue);
    printf("name: %s\n", p4->name);

    free(p1);
    free(p2);
    Clear(queue);

    return 0;
}