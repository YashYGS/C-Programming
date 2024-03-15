
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

//
// Initialize a linked list
//
void llist_init(LinkedList * list)
{
	list->head = NULL;
}

//
// It prints the elements in the list in the form:
// 4, 6, 2, 3, 8,7
//
void llist_print(LinkedList * list) {
	
	ListNode * e;

	if (list->head == NULL) {
		printf("{EMPTY}\n");
		return;
	}

	printf("{");

	e = list->head;
	while (e != NULL) {
		printf("%d", e->value);
		e = e->next;
		if (e!=NULL) {
			printf(", ");
		}
	}
	printf("}\n");
}

//
// Appends a new node with this value at the beginning of the list
//
//
void llist_add(LinkedList * list, int value) {
	// Create new node
	ListNode * n = (ListNode *) malloc(sizeof(ListNode));
	n->value = value;
	
	// Add at the beginning of the list
	n->next = list->head;
	list->head = n;
}

// Returns true if the value exists in the list.
//
int llist_exists(LinkedList * list, int value) {
      
        ListNode * e;
        if (list->head == NULL) {
               return 0;
        }
        e = list->head;
	//traversing list until null and comparing each node value with value 
        while (e != NULL) {
		if (e->value == value) {
			return 1;
		}
		e = e->next;

	}
	return 0;
}

//
// It removes the entry with that value in the list.
//
int llist_remove(LinkedList * list, int value) {

	//list is empty
	if (list->head == NULL) {
		return 0;
	}

	//curr is cuur node, prev is node before curr
	ListNode * curr;
	curr = list->head;
	ListNode * prev = NULL;
	
	//looping until value found
	while (curr != NULL) {
		if (curr->value == value) {break;}
		prev = curr;
		curr = curr->next;	
	}

	if (curr == NULL) {
		return;
	}

	//setting pointer from prev to element after curr, thus skipping 'value'
	if(prev != NULL) {
		prev->next = curr->next;
		free(curr);
	}else{
		curr = list->head;
		list->head = list->head->next;
		curr->next = NULL;
		free(curr);
	}
	
	return 1;
}

//
// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_get_ith(LinkedList * list, int ith, int * value) {

	ListNode * curr;
	curr = list->head;
	int counter = 0;

	//inc counter to get ith by pusing curr	
	while (curr != NULL) {
		if (counter == ith) {
			*value = curr->value;
			return 1;
		}
		curr = curr->next;
		counter++;
	}

	return 0;
}
//
// It removes the ith entry from the list.
// It returns 1 if success or 0 if there is no ith entry.
//
int llist_remove_ith(LinkedList * list, int ith) {

	 //list is empty
          if (list->head == NULL) {
                  return 0;
          }
 
          //curr is cuur node, prev is node before curr
          ListNode * curr;
          curr = list->head;
          ListNode * prev = NULL;
          int counter = 0;
 
          //looping until value found
          while (curr != NULL) {
                 if (counter == ith) {break;}
                  prev = curr;
                  curr = curr->next;
		  counter++;
          }

         if (curr == NULL) {
                 return;
         }

        //setting pointer from prev to element after curr, thus skipping 'value'
         if(prev != NULL) {
                 prev->next = curr->next;
                 free(curr);
         }else{
                 curr = list->head;
                 list->head = list->head->next;
                 curr->next = NULL;
                 free(curr);
         }

         return 1;
}

//
// It returns the number of elements in the list.
//
int llist_number_elements(LinkedList * list) {

	ListNode * curr;
	curr = list->head;
	int counter = 0;

	while (curr != NULL) {
		counter++;
		curr = curr->next;
	}

	return counter;
}


//
// It saves the list in a file called file_name. The format of the
// file is as follows:
//
// value1\n
// value2\n
// ...
//
int llist_save(LinkedList * list, char * file_name) {

	FILE *f = fopen(file_name, "w");
	
	if (f == NULL) {
        	fprintf(stderr, "\nError opened file\n");
       	 	//exit (1);
		return 0;
   	 } 
	
	ListNode * curr;
	curr = list->head;
	
	//saving curr val n pushing pointer	
	while (curr != NULL)	{
		fprintf(f , "%d\n", curr->value);
		curr = curr->next;
	}

	fclose(f);
	return 0;

}

//
// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
//
int llist_read(LinkedList * list, char * file_name) {

	
	llist_clear(list);
 
	FILE *f;
	f  = fopen(file_name, "r");
	int num = 0; 

	if(f == NULL) {
        	//printf("Error opening file\n");
   	 	return 0;
         }

	while (fscanf(f, "%d", &num) != EOF){
		llist_add(list, num);

	}
	if (f != NULL) {
		fclose(f);
	}
	return 1;
}


//
// It sorts the list. The parameter ascending determines if the
// order si ascending (1) or descending(0).
//
void llist_sort(LinkedList * list, int ascending) {

	ListNode *lCounter;
	ListNode *e;
	ListNode *tempLink;
	tempLink = list->head;
	lCounter = list->head;

	int l = 0;

	//finding length of llist
	while (lCounter != NULL){
		l++;
		lCounter = lCounter->next;
	}

		e = list->head;
	int temp = 0;
	

	if (ascending == 1) {
 		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l - i - 1; j++) {
				if (e->value > e->next->value) {
					temp = e->value;
					e->value = e->next->value;
					e->next->value = temp;
				}
				e = e->next;
			}
			//tempLink = tempLink->next;
			e = tempLink;	 
		}
	} else {
		for (int i = 0; i < l; i++) {
                         for (int j = 0; j < l - i - 1; j++) {
                                 if (e->value < e->next->value) {
                                         temp = e->value;
                                         e->value = e->next->value;
                                         e->next->value = temp;
                                 }
                                 e = e->next;
                         }
                         //tempLink = tempLink->next;
                         e = tempLink;
                 }

	}
	

}

//
// It removes the first entry in the list and puts value in *value.
// It also frees memory allocated for the node
//
int llist_remove_first(LinkedList * list, int * value) {

	if (list->head == NULL) {
                   return 0;
        }

	*value = list->head->value;
	ListNode *e = list->head;
	list->head = list->head->next;
	free(e);
	

	return 1;

}

//
// It removes the last entry in the list and puts value in *value/
// It also frees memory allocated for node.
//
int llist_remove_last(LinkedList * list, int *value) {
 	

	 ListNode *curr = list->head;
	 ListNode *prev = NULL;

	//pushing temp curr till last val to remove
	while (curr != NULL) {
		if (curr->next == NULL) {
			*value = curr->value; 
			prev->next = NULL;
			free(curr);
			return 1;
		}
		prev = curr;
		curr = curr->next;
	}	

	 if (curr == NULL) {
                  return;
         }


	 return 1;

}

//
// Insert a value at the beginning of the list.
// There is no check if the value exists. The entry is added
// at the beginning of the list.
//
void llist_insert_first(LinkedList * list, int value) {

	if (list->head == NULL) {
		list->head->value = value;
	}

	ListNode *front = (ListNode*)malloc(sizeof(ListNode));
	front->value = value;
	front->next = list->head;
	list->head = front;
}

//
// Insert a value at the end of the list.
// There is no check if the name already exists. The entry is added
// at the end of the list.
//
void llist_insert_last(LinkedList * list, int value) {

	if (list->head == NULL) {
                 list->head->value = value;
         }

	ListNode *back= (ListNode*)malloc(sizeof(ListNode));
	back->value = value;

	ListNode *e = list->head;
	while(e != NULL && e->next != NULL){
		e = e->next;
	}
	e->next = back;

}

//
// Clear all elements in the list and free the nodes
//
void llist_clear(LinkedList *list) {

	while (list->head != NULL) {
		list->head = list->head->next;	
	}

}
