#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};
struct node * create(struct node * head){
    int choice=1,data;
    while (choice){
        printf("enter data \n");
        scanf("%d",&data);
        struct node * temp;
        struct node * nextnode=(struct node *)malloc(sizeof(struct node ));
        nextnode->next=nextnode->prev=NULL;
        nextnode->data=data;
        if(head==NULL){
            head=nextnode;
            temp=nextnode;
        }
        else{
            temp->next=nextnode;
            nextnode->prev=temp;
            temp=temp->next;
        }
        printf("press 0 to exit");
        scanf("%d",&choice);
    }
    return head ;
}
void display(struct node * head){
    struct node * temp=head;
    while (temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    struct node * head=NULL;
    head=create(head);
    display(head);
    return 0;
}