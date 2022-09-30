#include<stdio.h>
#include<stdlib.h>

//linked list contains data field and a pointer to the next node in the linked list

struct node
{
	int row;
	int col;
	int val;
	struct node *next; //pointer to a node structure
};
struct node* insert_begin(int row, int col, int val, struct node *head);
void display(struct node *head);


void main()
{
	int row, col, i, j;
	printf("Enter the number of rows in the Sparse Matrix: ");
	scanf("%d",&row);
	printf("Enter the number of columns in the Sparse Matrix: ");
	scanf("%d",&col);
	int a[row][col];
	for (i = 0; i < row; i++)
	for (j = 0; j < col; j++)
	{
		printf("\na[%d][%d] = ",i,j);
		scanf("%d",&a[i][j]);
	}
	struct node *head; //head points to the first node in the LL. If LL is empty head will be NULL
	head = NULL;
	
	for (i = 0; i < row; i++)
	for (j = 0; j < col; j++)
	{
		if (a[i][j] != 0)
		head = insert_begin(i, j, a[i][j], head);
	}
	display(head);
}



struct node* insert_begin(int row, int col, int val, struct node *head)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->row = row;
	newnode->col = col;
	newnode->val = val;
	newnode->next = head; //newnode's next pointer points to previous first node
	head = newnode;//head points to new node
	return(head);
}

void display(struct node *head)
{
	struct node *temp;
	for (temp = head;temp->next != NULL;temp = temp->next)
	{
		printf("|%d|%d|%d|-->",temp->row,temp->col,temp->val);
	}
	printf("|%d|%d|%d|",temp->row,temp->col,temp->val);
}
