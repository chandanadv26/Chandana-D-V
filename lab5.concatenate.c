
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head1=NULL,*head2=NULL;
    struct node *newnode,*temp;
    int n,i;

    printf("Enter nodes in first list: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head1==NULL)
            head1=newnode;
        else {
            temp=head1;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }

    printf("Enter nodes in second list: ");
    scanf("%d",&n);

    for(i=0;i<n;i++) {
        newnode=malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head2==NULL)
            head2=newnode;
        else {
            temp=head2;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }

    temp=head1;

    if(head1==NULL)
        head1=head2;
    else {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=head2;
    }

    printf("Concatenated list: ");

    temp=head1;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
