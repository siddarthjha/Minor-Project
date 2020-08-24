/*
    ------------- IDDFS IMPLEMENTATION ---------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>                                  // We have imported inttypes to lessen the memory usage as much as possible
#include <stdint.h> 

/*
@param search      -> The value to be searched
@param insertnode  -> The values to be inserted
@param select      -> The option to be selected
@param ids_found    -> Counter variable to increment when found the target
*/

size_t search;
static int8_t n=0,ids_found=0;
static int temp=0;

// A linked list implementation
struct node
{
	int data;
	struct node *left;
	struct node *right;	
 };

// Funnction declaration
void IDDFS(struct node *root,int8_t i);


struct node *insert(struct node *root, int value)               // * Insertion of Nodes value to the Tree *
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
 
 
 // * IDDFS Function *
 
 int height(struct node *root)
 {
 	if(root==NULL)
 	{
 		return 0;
	}
	else
	{
		int lh=height(root->left);
		int rh=height(root->right);
		if(lh>rh)
		return (lh+1);
		else
		return (rh+1);
	}
 	
 }
 void ids(struct node *root, int limit)
 {
 	if(root!=NULL)
 	{
 		if(limit==1)
 		printf("%d ",root->data);
 		if(search==root->data)
 		{
 			printf("The goal node(%d) is found by IDS Algorithm......",search);
 			printf("\nThe program is being terminated");
 			ids_found=1;
 			exit(0);
		}
 		else if(limit>1)
 		{
 			ids(root->left,limit-1);
 			ids(root->right,limit-1);
		}
	}
 	
 }
 
int main()
{
	struct node *root=NULL;
	int8_t select,limit;
	int i,s,s1;
	size_t insertnode;
	
	printf("Enter your choice\n1.Enter values\n2.IDDFS SEARCH");
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
				printf("Enter the value to be searched by IDFS Algorithm.......");
				scanf("%d",&search);
				s=height(root);
				//printf("\n%d\n",s);
				//IDDFS(root,0);
				for(s1=1;s1<=s;s1++)
				{
					ids(root,s1);
				}
				if(ids_found==0)
		        {
		        	printf("The goal is not(%d) found by IDDFS Algorithm.....",search);
		        	printf("\nYou can try again:)");
		        	ids_found=0;
		        }	
				break;
			default:
				printf("ERROR CASE...... PLEASE TRY AGAIN AND USE YOUR BRAIN");
				break;
		}
	}
	return 0;
}
