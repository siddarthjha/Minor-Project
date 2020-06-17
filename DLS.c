/*
    ------------- DLS IMPLEMENTATION ---------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>                                          // We have imported inttypes to lessen the memory usage as much as possible
#include <stdint.h> 
/*
@param limit    -> It is the limit of the tree, increments accordingly

*/

size_t search;
static int8_t n=0,dls_found=0;
static int temp=0;

struct node
{
	int data;
	struct node *left;
	struct node *right;	
 };

// * Function declarations * 
 void DLS(struct node *root,int i,int8_t limit);

 
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
 
  void DLS(struct node *root,int i,int8_t limit)
 {
 	if(root!=NULL)
 	{
 		while(i<limit)
 		{
 			printf("%d ",root->data);
 			if(search==root->data)
			{
				printf("The Goal node by DLS algo is found.....");
 			    printf("\nThe program is being terminated......");
 			    //idfs_limit=limit;
 			    dls_found=1;
 			    exit(0);
 		    }	
			DLS(root->left,i,limit-1);
 			DLS(root->right,i,limit-1);	
 			break;
		}		
	}		
 }
 
 
 int main()
{
	struct node *root=NULL;
	int8_t select,limit;
	int i;
	size_t insertnode;
	
	printf("Enter your choice\n1.Enter values\n2.DlS SEARCH");
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
				printf("Enter the value to be searched by DLS Algorithm.....");
				scanf("%d",&search);
				printf("Enter the limit for the implementation of DLS Algorithm....");
				scanf("%d",&limit);
				DLS(root,0,limit);
				if(dls_found==0)
		        {
		        	printf("The goal is not found by DLS Algorithm.....");
		        	printf("\nYou can try again:)");
		        	dls_found=0;
		        }	
				break;
			default:
				printf("* ERROR CASE...... PLEASE TRY AGAIN AND USE YOUR BRAIN *");
				break;
		}
	}
	return 0;
}
