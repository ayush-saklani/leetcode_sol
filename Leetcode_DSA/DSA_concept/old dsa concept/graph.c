#include<stdio.h>
#include<stdlib.h>
struct graph{
    int vertices ;
    struct adjacency * array ;
};
struct adjacency_node{
    int data ;
    struct adjacency_node * next;
};
struct adjacency{
    struct adjacency_node * head;
    int * visited;
};
struct graph * create(int vertices){
    struct graph *graphi=(struct graph * )malloc(sizeof(struct graph));
    graphi->array  = (struct adjacency * )malloc(vertices*sizeof(struct adjacency));
    graphi->vertices=vertices;
    for (int i = 0; i < vertices; i++){
        graphi->array[i].head=NULL;
        graphi->array->visited=0;
    }
    return graphi;
}
void display(struct graph* graphi){
    for (int i = 0; i < graphi->vertices; i++){
        struct adjacency_node * temp= graphi->array[i].head;
        printf("\nAdjacent members of %d th vertex \n",i);
        while (temp){
            printf(" - %d" ,temp->data);
            temp=temp->next;
        }
    }
}
struct graph * addedge(struct graph * graphi,int source , int destination ){
    if(source==destination){
        struct adjacency_node * check=NULL;
        struct adjacency_node * newnode =(struct adjacency_node * )malloc(sizeof(struct adjacency_node));
        newnode->data = destination;
        newnode->next=NULL;
        if(graphi->array[source].head==NULL){
            newnode->next=graphi->array[source].head;
            graphi->array[source].head=newnode ;
        }
        else{
            check=graphi->array[source].head;
            while(check->next!=0){
                check=check->next;
            }
            check->next=newnode;
        }
    }
    else{
        struct adjacency_node * check=NULL;
        struct adjacency_node * newnode =(struct adjacency_node * )malloc(sizeof(struct adjacency_node));
        newnode->data = destination;
        newnode->next=NULL;
        if(graphi->array[source].head==NULL){
            graphi->array[source].head=newnode ;
        }
        else{
            check=graphi->array[source].head;
            while(check->next!=0){
                check=check->next;
            }
            check->next=newnode;
        }
        struct adjacency_node * newnode2 =(struct adjacency_node * )malloc(sizeof(struct adjacency_node));
        newnode2->data = source;
        newnode2->next=NULL;
        if(graphi->array[destination].head==NULL){
            graphi->array[destination].head=newnode2 ;
        }
        else{
            check=graphi->array[destination].head;
            while(check->next!=0){
                check=check->next;
            }
            check->next=newnode2;
        }
    }
    return graphi;
}
void DFS(struct graph* graphi, int vertex){
	struct adjacency * temp  = graphi->array[vertex].head;

	graphi->array[vertex].visited = 1;
	printf("Visited %d \n", graphi->array[vertex]);

	while (temp != NULL) {
		int connectedVertex = temp->head;

		if (graphi->array[connectedVertex].visited == 0){
    		DFS(graphi, connectedVertex);
		}
		temp->head = temp->head->next;
	}
}
int main(){
    int n,a,b,choice=1;
    printf("enter number of vertices\n");
    scanf("%d",&n);
    struct graph * graphi;
    graphi=create(n);
    while (choice){
        printf("Enter source and destination -> ");
        scanf("%d",&a);
        scanf("%d",&b);
        graphi=addedge(graphi,a,b);
        printf("press 0 to exit. press 1 to continue\n");
        scanf("%d",&choice);
    }
    display(graphi);
    DFS(graphi,0);
    return 0;
}