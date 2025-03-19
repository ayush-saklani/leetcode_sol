#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * right,*left;
};
struct node * create(struct node * head,int data){
    if(head==NULL){
        struct node * temp ;
        temp=(struct node *)malloc(sizeof(struct node ));
        temp->right=temp->left=NULL;
        temp->data=data;
        return temp;
    }
    else if(head->data>data){
        head->left=create(head->left,data);
    }
    else if(head->data<data){
        head->right=create(head->right,data);
    }
    return head;
}
void display(struct node * head){
    if(head!=NULL){
        display(head->left);
        printf("%d ",head->data);
        display(head->right);
    }
}
int main(){
    struct node *head=NULL;
    int choice =1,data;
    while (choice)
    {
        printf("enter data");
        scanf("%d",&data);
        head = create(head,data);
        printf("press 1 to continue 0 to exit");
        scanf("%d",&choice);
    }
    display(head);
    return 0;
}