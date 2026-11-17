

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int n, i, t, swapped;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    do {
        swapped = 0;
        temp = head;

        while(temp != NULL && temp->next != NULL) {
            if(temp->data > temp->next->data) {
                t = temp->data;
                temp->data = temp->next->data;
                temp->next->data = t;
                swapped = 1;
            }
            temp = temp->next;
        }
    } while(swapped);

    printf("Sorted list: ");
    temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
    return 0;
}
