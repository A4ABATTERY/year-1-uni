/**********************************************************
Filename: 		list.c
Author: 		Arunav Biswas
Date:			June 10th 2018
Description: 	This are functions to manipulate singly linked
				list data structure
Input:			Char, and ints.
Output: 		printfs to the screen showing list manipulation
***********************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*************************************************************
Function name:	length(struct node* head)
Description:	Determines the length to the end the list from
				a given point.
Parameters:		struct node
Precondition:	node doesnt point to NULL
Postcondition:	length of list.
*************************************************************/
int length(struct node* head){
	struct node* current = head;
	int i = 0;
	while(current != NULL){
		current = current->next;
		i++;
	}
	// printf("length: %d\n", i);
	return i++;
}
/*************************************************************
Function name:	print(struct node* head, int length)
Description:	prints values in list.
Parameters:		struct node, length of list
Precondition: 	length of list is not out of bounds
Postcondition:	NA, void
*************************************************************/
void print(struct node* head, int length){
	struct node* current = head;
	int i;
	printf("Your list: ");
	for(i = 0; (i < length)&&(current != NULL); i++){
		printf("%d ", current->val );
		current = current->next;
	}
	printf("\n");
}
/*************************************************************
Function name:	push(struct node * head, int value)
Description:	Appends a value to the head of the list
Parameters:		head of the list, and value of the new node.
Precondition:	node needs to be the head of the list
Postcondition:	node added to front
*************************************************************/
struct node * push(struct node*head, int value){
	// printf("\n\nValue: %d\n\n", value );
	struct node*temp = malloc(sizeof(struct node));
	temp->val = value;
	temp->next = head;
	return temp;
}
/*************************************************************
Function name:	append(struct node* head, int value)
Description:	Appends value to the end of the list.
Parameters:		struct node, value of new node
Precondition:	node doesnt point to NULL
Postcondition:	node added to back
*************************************************************/
struct node * append(struct node * head, int value){
	struct node * current = head;
	while(current->next != NULL){
		current = current->next;
	}
	struct node *temp = malloc(sizeof(struct node));
	temp->val = value;
	temp->next = NULL;
	current->next = temp;
	return head;
}
/*************************************************************
Function name:	clear(struct node* head)
Description:	Free heap memory occupied by list
Parameters:		list head
Precondition: 	list head
Postcondition:	basically return NULL
*************************************************************/
struct node * clear(struct node * head){
		struct node * current = head;
		struct node * NEXT;
		while(current != NULL){
			NEXT = current->next;
			free(current);
			current = NEXT;
		}
		head = NULL;
		printf("\n\n\nHave a great summer holiday :)\n");
		printf("*this is from the clear(struct node*) function*\n\n\n\n");


		return head;
}
/*************************************************************
Function name:	remove_node(struct node* head, int index)
Description:	removes node at index
Parameters:		struct node head, and int index
Precondition:	node doesnt point to NULL
Postcondition:	node at index removed.
*************************************************************/
struct node * remove_node(struct node * head, int index){
	struct node * temp = head;
	struct node * nex = head;
	if(index == 0){
		temp = head->next;
		free(head);
		return temp;
	}else if(index > length(head)){
		printf("Error, removing index that doesnt exist :(\n");
		return head;
	}
	int i = 0;
	while(i < index){
		temp = nex;
		nex = nex->next;
		i++;
	}
	struct node * NEXT = temp;
	temp = temp->next;
	if(temp->next == NULL){
		free(temp);
		NEXT->next = NULL;
		temp = NULL;
		return head;
	}else{
		NEXT->next = temp->next;
		free(temp);
		temp = NULL;
		return head;
	}
}
/*************************************************************
Function name:	sort_ascending(struct node * head)
Description:	orders list from least to greatest
Parameters:		struct node head
Precondition:	node doesnt point to NULL
Postcondition:	sorted list
*************************************************************/
struct node * sort_ascending(struct node * head){
	struct node *A, *B, *temp;
    int swap = 1;
	temp = malloc(sizeof(struct node));
    temp->next = head;
    if(head != NULL && head->next != NULL){
        while(swap == 1){
            swap = 0;
            B = temp;
            A = temp->next;
            while(A->next != NULL){
                if(A->val > A->next->val){
					struct node * N1;
					struct node * N2;
					N1 = A;
					N2 = A->next;
					N1->next = N2->next;
					N2->next = N1;
					B->next = N2;
					swap = 1;
                }
                B = A;
                if(A->next != NULL)
                    A = A->next;
            }
        }
    }
    A = temp->next;
    free(temp);
    return A;
}
/*************************************************************
Function name:	sort_descending(struct node * head)
Description:	orders list from greatest to least
Parameters:		struct node head
Precondition:	node doesnt point to NULL
Postcondition:	sorted list
*************************************************************/
struct node * sort_descending(struct node * head){
	struct node *A, *B, *temp;
    int swap = 1;
	temp = malloc(sizeof(struct node));
    temp->next = head;
    if(head != NULL && head->next != NULL){
        while(swap == 1){
            swap = 0;
            B = temp;
            A = temp->next;
            while(A->next != NULL){
                if(A->val < A->next->val){
					struct node * N1;
					struct node * N2;
					N1 = A;
					N2 = A->next;
					N1->next = N2->next;
					N2->next = N1;
					B->next = N2;
					swap = 1;
                }
                B = A;
                if(A->next != NULL)
                    A = A->next;
            }
        }
    }
    A = temp->next;
    free(temp);
    return A;
}
/*************************************************************
Function name:	insert_middle(struct node* head, int value, int index)
Description:	inserts a node at index. the newly inserted node will
				be at the index that is passed in.
				list: 1, 2, 3, 4, 5
				head = insert_middle(head, 42, 3);
				list: 1, 2, 3, 42, 4, 5
Parameters:		struct node head, value of new node, index of where
				it should be placed
Precondition:	NA
Postcondition:	new node added at index.
*************************************************************/
struct node * insert_middle(struct node * head, int value, int index){
	if(index < 1){
		struct node* temp = malloc(sizeof(struct node));
		temp->val = value;
		temp->next = head;
		return temp;
	}
	int i = 0;

	if(index >= length(head)) {
		printf("Index not in scope of list, returning original list\n");
		printf("Please use Append or Push instead :(\n");
		return head;
	}
	struct node* cur = head;
	struct node* prv;
	while(i < index){
		// printf("run %d\n", i);
		prv = cur;
		cur = cur->next;
		i++;
	}
	// printf("index = %d, i = %d, len = %d\n", index, i, length(head));
	// printf("insert infront %d\n", prv->val);
	struct node* temp = malloc(sizeof(struct node));
	temp->val = value;
	temp->next = cur;
	prv->next = temp;


	return head;


}




//TESTING

/*int main (){
	char ans[2];
	int num;
	struct node *head = NULL;
	do {
		do {
			printf("Enter a number: ");
			scanf("%d", &num);
			head = push(head, num);//Can change to append
			printf("Do you want another num (y or n): ");
			scanf("%1s",ans);
		} while(ans[0] == 'y');
		printf("Sort ascending or descending (a or d)? ");
		scanf("%1s",ans);
		if(ans[0] == 'a')
			head=sort_ascending(head);
		else if(ans[0] == 'd')
			head=sort_descending(head);
		printf("Sorted ");
		print(head, length(head));
		printf("Appended value 6 to ");
		head = append(head, 6);
		print(head, length(head));
		printf("inserted value 23 at index 4 to ");
		head = insert_middle(head, 23, 4);
		print(head, length(head));
		printf("removed index 4 from ");
		head = remove_node(head, 4);
		print(head, length(head));
		printf("\nDo you want to do this again (y or n)? ");
		scanf("%1s",ans);
		head = clear(head);
	} while(ans[0] == 'y');
	return 0;
}
*/