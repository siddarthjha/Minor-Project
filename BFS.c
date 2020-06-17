/*
    ------------- BFS IMPLEMENTATION ---------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>                               // We have imported inttypes to lessen the memory usage as much as possible
#include <stdint.h> 

/*
@param search      -> The value to be searched.
@param insertnode  -> The values to be inserted.
@param select      -> The option to be selected.
@param dfs_found   -> Counter variable to increment when found the target.
@param queue       -> The array to insert the numbers(Size can vary accordng to your requirements).
@param front,queue -> These are conditions of queue to traverse the array.
*/

int queue[100];
int front=0,rear=-1;
static int8_t n=0;
size_t search;
static int temp=0;

// A linked list implementation
struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

// Function declarations

void printNode(struct node *root);                                   
void enqueue(struct node *root);
void dequeue();
void BFS(struct node *root);

 
 struct node *insert(struct node *root, int value)               // * Insertion of Nodes value and Construction of Tree *
 {
 	if(root==NULL)
 	{
 		root=(struct node*)malloc(sizeof(struct node));
 		root->left=root->right=NULL;
 		root->data=value;
 		return root;
	}
	else
	{
	 	if(value<=root->data)
	 	{
	 		root->left=insert(root->left,value);
		}
		else
		{
		 	if(value>root->data)
		 	{
		 		root->right=insert(root->right,value);
			}
		}
		return root;
	}	
 };
 
  void printNode(struct node *root)                // * Prints the values of node *
 {
 	static int bfs_found=0;
 	if(root!=NULL)
 	{
 		printf("%d ",root->data);
 		if(root->data==search)
 		{
 			printf("\nThe goal is found.....");
 			printf("\nThe program is being terminated.......");
 			exit(0);
		}
		bfs_found++;
	}
	if(bfs_found==temp)
	{
        printf("\nThe goal is not found.....");
	    printf("\nYou can try again:)");
	    bfs_found=0;
	}
 }
 // * Queue *
 void enqueue(struct node *root)                // * Adding the element into the Queue *
 {
 	
 	if(root!=NULL)
 	{
 		rear++;
 		queue[rear]=(uintptr_t)(root);
	}
 }
 
 void dequeue()                                 // * Removing Element from the Queue *
 {
 	if(rear>=front)
 	{
 		struct node *root=(struct node *)(intptr_t)queue[front];
 		printNode(root);
 		front++;
 	    enqueue(root->left);
        enqueue(root->right);	
	}
 }
 // * BFS Function *
 void BFS(struct node *root)
 {
 	if(root!=NULL)
 	{
 		enqueue(root);
 		do
		{
 			dequeue();
		}while(front<=rear);
	}
 }
 
 
 int main()
{
	struct node *root=NULL;
	int8_t select,limit;
	int i;
	size_t insertnode;
	
	printf("Enter your choice\n1.Enter values\n2.BFS SEARCH");
	while(1)
	{
		printf("\n\nPlease enter the option ");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				printf("Enter number of nodes in tree \n");
				scanf("%d",&n);
				temp=temp+n;
				for(i=0;i<n;i++)
				{
					printf("Enter value ");
					scanf("%d",&insertnode);
					root=insert(root, insertnode);
				}
				break;
			case 2:
				printf("Enter the value to be searched with BFS Algorithm....");
				scanf("%d",&search);
				BFS(root);
				break;
			default:
				printf("* ERROR CASE...... PLEASE TRY AGAIN AND USE YOUR BRAIN *");
				break;
		}
	}
	return 0;
}
