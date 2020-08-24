/*
    ------------- DFS IMPLEMENTATION ---------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>                               // We have imported inttypes to lessen the memory usage as much as possible
#include <stdint.h> 
/*

@param search      -> The value to be searched
@param insertnode  -> The values to be inserted
@param select      -> The option to be selected
@param dfs_found    -> Counter variable to increment when found the target

*/
size_t search;
static int8_t n=0,dfs_found=0;
static int temp=0;

// A Linked list implementation
struct node
{
	int data;
	struct node *left;
	struct node *right;	
 };
 
// * Function declarations *

void DFS(struct node *root);


struct node *insert(struct node *root, int value)                    // * Insertion of Nodes value to the Tree *
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
 
 void DFS(struct node *root)
 {
 	if(root!=NULL)
 	{
 		printf("%d ",root->data);
 		if(search==root->data)
 		{
 			printf("\nThe Goal node by DFS algo is found.....");
 			printf("\nThe program is being terminated......");
 			exit(0);
		}
		dfs_found++;
 		DFS(root->left);
 		DFS(root->right);
	}
 }
 
 int main()
{
	struct node *root=NULL;
	int8_t select;
	int i;
	size_t insertnode;
	
	printf("Enter your choice\n1.Enter values\n2.DFS SEARCH");
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
				printf("Enter the value to be searched with DFS Algorithm....");
				scanf("%d",&search);
				DFS(root);
				if(dfs_found==temp)
		        {
		        	printf("\nThe goal is not found by DFS Algorithm.....");
		        	printf("\nYou can try again:)");
		        	dfs_found=0;
		        }	
				break;
			default:
				printf("* ERROR CASE...... PLEASE TRY AGAIN AND USE YOUR BRAIN *");
				break;
		}
	}
	return 0;
}
