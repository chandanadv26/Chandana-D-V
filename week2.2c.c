#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int value;

    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &value);

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    printf("%d inserted into the queue.\n", value);
}

void delete() {
    int value;

    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    value = queue[front];
    printf("%d deleted from the queue.\n", value);

    if (front == rear) {

        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}


void display() {
    int i;

    if (front == -1) {
        printf("Queue Empty!\n");
        return;
    }

    printf("Circular Queue: ");

    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
