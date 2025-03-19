#include<stdio.h>
#include<stdlib.h>
struct node{
    int data , expo;
    struct node * next , * prev;
};
void display(struct node * head){
    struct node * temp=head;
    while (temp!=NULL){
        printf("%dX^%d",temp->data ,temp->expo);
        if (temp->next!=0){
            printf(" + ");
        }
        temp=temp->next;
    }
}
struct node * create(struct node * head){
    int choice =1;
    while(choice){
    struct node * nextnode,*temp;
    nextnode=(struct node *)malloc(sizeof(struct node));
    nextnode->next=nextnode->prev=NULL;
    printf("Enter data and exponent repectively\n");
    scanf("%d",&nextnode->data);
    scanf("%d",&nextnode->expo);
    if(head==NULL){
        head=nextnode;
        temp=head;
    }
    else{
        temp->next=nextnode;
        nextnode->prev=temp;
        temp=temp->next;
    }
    printf("Press 1 to continue 0 to exit\n");
    scanf("%d",&choice);
    }
    return head;
}
struct node * polsum(struct node * head1,struct node * head2){
    struct node * temp1 = head1,* temp2 = head2;
    struct node * heado = NULL,* tempo ;
    while(temp1!=NULL && temp2!=NULL){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->next=temp->prev=NULL;
        if (temp1->expo==temp2->expo){
            temp->data=temp1->data+temp2->data;
            temp->expo=temp2->expo;
            temp1=temp1->next;
            temp2=temp2->next;
           // printf("\nworking = \n");
        }
        else if (temp1==NULL && temp2!=NULL){
            temp->data=temp2->data;
            temp->expo=temp2->expo;
            temp2=temp2->next;
        }
        else if (temp2==NULL && temp1!=NULL){
            temp->data=temp1->data;
            temp->expo=temp1->expo;
            temp1=temp1->next;
        }
        else if (temp1->expo<temp2->expo   ){
            temp->data=temp1->data;
            temp->expo=temp1->expo;
            temp1=temp1->next;
           // printf("\nworking < \n");
        }
        else if (temp1->expo>temp2->expo   ){
            temp->data=temp2->data;
            temp->expo=temp2->expo;
            temp2=temp2->next;
           // printf("\nworking > \n");
        }

        if(heado==NULL){
            heado=temp;
            tempo=heado;
        }
        else{
            tempo->next=temp;
            temp->prev=tempo;
            tempo=tempo->next;
        }
    }
   // printf("working exits \n");
    return heado;
}
int main(){
    struct node * pol1=NULL,* pol2=NULL,*pol3;
    pol1=create(pol1);
    pol2=create(pol2);
    printf("1st equation -> ");
    display(pol1);    
    printf("\n2nd equation -> ");
    display(pol2);
    pol3=polsum(pol1,pol2);
    printf("\nsum equation -> ");
    display(pol3);
    return 0;
}