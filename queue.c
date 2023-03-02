/* 
 * Code for basic C skills diagnostic.
 * Developed by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 * 
 * @author Salma Mohammad
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"
#include "report.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));

    /* What if malloc returned NULL? */

    if (!q) 
    {
      return NULL;
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */

void q_free(queue_t *q)
{

if (q == NULL) 
{
  return;
}

    /* How about freeing the list elements and the strings? */

    list_ele_t *at = q->head;

    // While current is a valid value, create a struct for the next element and assign it the pointer to the next term, then free the current t
    while (at != NULL) {
    	list_ele_t *next = at->next;
    	free(at->value);
    	free(at);
    	at = next;
    }
    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (!q)
    {
	return false;
    }

    list_ele_t *newh;

    /* What should you do if the q is NULL? */

    newh = malloc(sizeof(list_ele_t));
    if (!newh)
    {
    	return false;
    }

    /* Don't forget to allocate space for the string and copy it */

    newh->value= malloc(strlen(s)+1);
    if (newh->value == NULL){
    	free(newh);
    	return false;
    }
    strcpy(newh->value, s);

    /* What if either call to malloc returns NULL? */
    
    
    newh->next = q->head;
    q->head = newh;
    
    if (!(q->tail)) {
    	q->tail = newh;
    }
    
    q->size += 1;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q) 
    {
      return false;
    }

    list_ele_t *newh;

    newh = malloc(sizeof(list_ele_t));

    if (!newh)
    {
    	return false;
    }

    newh->value = malloc(strlen(s)+1);
    if (!(newh->value)){
    	free(newh);
    	return false;
    }
    
    strcpy(newh->value, s);
    newh->next = NULL;
    if (q->tail != NULL) {
    	q->tail->next = newh;
    } 
    else
    {
    	q->head = newh;
    }
    q->tail = newh;
    
    q->size += 1;
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (q == NULL) return false;
    if (q->head == NULL) return false;
    
    list_ele_t *toBeRemoved = q->head;
    if (sp == NULL) return false;
    strncpy(sp,toBeRemoved->value,(bufsize-1));
    sp[bufsize-1] = '\0';
    
    q->head = toBeRemoved->next;
    free(toBeRemoved->value);
    free(toBeRemoved);
    //q->head = q->head->next;
    q->size -= 1;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
	
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) return 0;
    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q || q->size == 0 || q->size == 1) 
    {
      return;
    }
    /* You need to write the code for this function */

    list_ele_t *prev = NULL;
    list_ele_t *at = q->head;
    list_ele_t *next_part;

    q->tail = q->head;

    while (at) {
    	next_part = at->next;
    	at->next = prev;
    	prev = at;
    	at = next_part;
    }

        q->head = prev;
}


//correctlly edited code .c