/*
    * IMPLEMENTATION OF DFS BFS DLS and IDFS ALGORITHMS *    
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>                                 // We have imported inttypes to lessen the memory usage as much as possible
#include <stdint.h>                                   // This is imported to type cast the integer to pointer conversion which vary in 32 bit and 64 bit

// * Variable Declarations *

int queue[10];
int8_t front=0,rear=-1;
int search;
static int8_t n=0,dfs_found=0,dls_found=0,ids_found=0;
static int8_t temp=0;

// * Structure Declaration *

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;	
 }searchtree;
 
 // * Function Prototype *
 
void printNode(searchtree *root);     // We have named the structure with name "searchtree" and will be using this in place of "struct node"                              
void enqueue(searchtree *root);
void dequeue();
void BFS(searchtree *root);
void DFS(searchtree *root);
void DLS(searchtree *root,int8_t i,int8_t limit);
void IDDS(searchtree *root,int8_t limit);
void height(searchtree *root);
 
 // * Construction of tree *
 
 searchtree *insert(searchtree *root, int value)                    // * Insertion of Nodes value to the Tree *
 {
 	if(root==NULL)
 	{
 		root=(searchtree*)malloc(sizeof(searchtree));
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
 
 // * Prining of Nodes for BFS search *
 
  void printNode(searchtree *root)                                    // * Prints the values of node *
 {
 	static int bfs_found=0;
 	if(root!=NULL)
 	{
 		printf("%d ",root->data);
 		if(root->data==search)
 		{
 			printf("\nThe goal node(%d) is found.....",search);
 			printf("\nThe program is being terminated.......");
 			exit(0);
		}
		bfs_found++;
	}
	if(bfs_found==temp)
	{
        printf("\nThe goal node(%d) is NOT found by BFS Algorithm.....",search);
	    printf("\nYou can try again:)");
	    bfs_found=0;
	}
 }
 // * Queue *
 
 void enqueue(searchtree *root)                    // * Adding the element into the Queue *
 {
 	
 	if(root!=NULL)
 	{
 		rear++;
 		queue[rear]=(uintptr_t)(root);
	}
 }
 
 void dequeue()                                      // * Removing Element from the Queue *
 {
 	if(rear>=front)
 	{
 		searchtree *root=(searchtree *)(intptr_t)queue[front];
 		printNode(root);
 		front++;
 	    enqueue(root->left);
        enqueue(root->right);	
	}
 }
 // * BFS Function *
 
 void BFS(searchtree *root)
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
 // * DFS Function *
 
 void DFS(searchtree *root)
 {
 	if(root!=NULL)
 	{
 		printf("%d ",root->data);
 		if(search==root->data)
 		{
 			printf("\nThe Goal node(%d) by DFS algo is found.....",search);
 			printf("\nThe program is being terminated......");
 			exit(0);
		}
		dfs_found++;
 		DFS(root->left);
 		DFS(root->right);
	}
 }
 // * DLS Function *
 
 void DLS(searchtree *root,int8_t i,int8_t limit)
 {
 	if(root!=NULL)
 	{
 		while(i<limit)
 		{
 			printf("%d ",root->data);
 			if(search==root->data)
			{
				printf("The Goal node(%d) by DLS algo is found.....",search);
 			    printf("\nThe program is being terminated......");
 			    dls_found=1;
 			    exit(0);
 		    }	
			DLS(root->left,i,limit-1);
 			DLS(root->right,i,limit-1);	
 			break;
		}		
	}			
 }
 
 
 // * Retrieval of height of tree for IDDFS Algorithm *
 
  int level(searchtree *root)
 {
 	if(root==NULL)
 	{
 		return 0;
	}
	else
	{
		int lh=level(root->left);
		int rh=level(root->right);
		if(lh>rh)
		return (lh+1);
		else
		return (rh+1);
	}
 	
 }
 
 // * IDDFS Function *
 
 void IDDFS(searchtree *root,int8_t limit)
 {
 	if(root!=NULL)
 	{
 		if(limit==1)
 		{
 			printf("%d ",root->data);
 	    }
 		if(search==root->data)
 		{
 			printf("\nThe Goal node(%d) is found by IDDFS Algorithm..... ",search);
 			printf("\nThe program is being terminated.....");
 			ids_found=1;
 			exit(0);
		}
		else if(limit>1)
		{
			IDDFS(root->left,limit-1);
			IDDFS(root->right,limit-1);
			
		}		
	}
 } 
 
 // * Main function *
 
int main()
{
	searchtree *root=NULL;
	int8_t select,limit,height;
	int i;
	int insertnode;

	printf("Enter your choice\n1.Enter values\n2.BFS SEARCH\n3.DFS SEARCH\n4.DLS SEARCH\n5.IDDFS SEARCH\n6.Exit");
	printf("\n-------------------------------------");
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
			case 3:
				printf("Enter the value to be searched with DFS Algorithm....");
				scanf("%d",&search);
				DFS(root);
				if(dfs_found==temp)
		        {
		        	printf("\nThe goal node(%d) is NOT found by DFS Algorithm.....",search);
		        	printf("\nYou can try again:)");
		        	dfs_found=0;
		        }	
				break;
			case 4:
				printf("\nEnter the value to be searched by DLS Algorithm.....");
				scanf("%d",&search);
				printf("Enter the limit for the implementation of DLS Algorithm....");
				scanf("%d",&limit);
				DLS(root,0,limit);
				if(dls_found==0)
		        {
		        	printf("\nThe goal node(%d) is NOT found by DLS Algorithm.....",search);
		        	printf("\nYou can try again:)");
		        	dls_found=0;
		        }	
				break;
			case 5:
				printf("Enter the value to be searched by IDFS Algorithm.......");
				scanf("%d",&search);
				height=level(root);                                                    // * Height is been retrieved through this function 
				for(i=1;i<=height;i++)
				{
					IDDFS(root,i);
				}
				
				if(ids_found==0)
		        {
		        	printf("\nThe goal node(%d) is NOT found by IDDFS Algorithm.....",search);
		        	printf("\nYou can try again:)");
		        	ids_found=0;
		        }
				break;
			case 6:
				printf("Ending the program ********* :)");
				exit(0);
			default:
				printf("* ERROR CASE...... PLEASE TRY AGAIN.....*");
				break;
		}
	}
	return 0;
}
