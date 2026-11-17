

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head=NULL,*newnode,*temp;
    struct node *prev=NULL,*current,*next;
    int n,i;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
            head=newnode;
        else {
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }

    current=head;

    while(current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    head=prev;

    printf("Reversed list: ");
    temp=head;

    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }

return 0;
}
