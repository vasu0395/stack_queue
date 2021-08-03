/**
 * Program to implement Dynamic circular queue in c.
 * Compilation : gcc queue_p.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 02/8/2021
 * Day_2_Coding_Assignment.
 *
 * Time Complexity :
 * 
 * enqueue -> O(1);
 * dequeue -> O(1);
 * is_empty_queue -> O(1);
 * peek -> O(1);
 * resize_queue -> O(size);
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Program for implement own queue
int size = 0; // inital size of queue
int capacity = 2; // inital capacity of queue
bool intialzie_done=false; // check intialzie done or not
int top = -1; // front marker on queue
int new_index = 0; // for checking next position 
int *queue; // create own queue using dynamic malloc function
// function to initialize_queue queue
void initialize_queue()
{
    // initialize_queue with inital capacity
    queue = (int*)malloc(capacity * sizeof(int));
}
// function to resize_queue array
void resize_queue()
{
    // first increase size of capacity by 2 times
    capacity = capacity * 2;
    int *new_queue; // create new_queue
    new_queue = (int*)malloc(capacity * sizeof(int));
    
    int count = 0;
    // first include element from top
    // (example :- if we have queue like _ _ 1 2 3 then first push (1 2 3) and then push (_ _) )
    for(int i = top ; count < size; i++)
    {
        new_queue[count] = queue[i]; 
        count++;
    }
    // pushing starting element
    for(int i=0;i<top;i++)
    {
        new_queue[count] = queue[i]; 
        count++;
    }
    // again put starting point 0.
    top = 0;
    // assign new_indexwith size
    new_index = size;
    // assign new_queue to queue
    queue = new_queue;
}
// function for enqueue operation
void enqueue(int x)
{
    // if no intialzie_done before
    if(!intialzie_done)
    {
        initialize_queue();
        intialzie_done=true;
    }
    // if capacity and size become equal we have to increase queue size
    if(size == capacity)
    {
        resize_queue();
    }
    
    printf("%d element added to queue\n",x);
    queue[new_index] = x;
    new_index++;
    // _ _ 1 2 3 then next time Element put over 4 _ 1 2 3 
    new_index = new_index % capacity;
    size++;
    // if we have 1 element at starting then 0 based index top 
    if(size == 1)
    {
        top = 0;
    }
    
}
// function for dequeue operation
int dequeue()
{
    if(top==-1)
    {
        printf("Invalid operation ");
        return -1;
    }
    
    if(size==-1)
    {
        printf("Invalid operation ");
        return -1;
    }
    
    printf("dequeue operation Successfully happens \n");
    int x = queue[top];
        
    top++;
    top = top % capacity;
    size--;
    
    // now the state of empty queue occur
    if(size == 0)
    {
        top = -1;
        new_index = 0;
    }
        
    return x;
}
// function for peek operation
int peek()
{
    if(top == -1)
    {
        printf("Invalid operation ");
        return -1;
    }
    else
    {
        // return top Element
        return queue[top];
    }
}
// function for is_empty_queue or not 
bool is_empty_queue()
{
    if(size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    printf("Peek Element %d\n",peek());
    printf("Element in queue \n");
    for(int i=top;i<size;i++)
	printf("%d ",queue[i]);
    for(int i=0;i<top;i++)
	printf("%d ",queue[i]);
    printf("\n");
	
    dequeue();
    dequeue();
	
    printf("Element in queue \n");
    for(int i=top;i<size;i++)
	printf("%d ",queue[i]);
    for(int i=0;i<top;i++)
	printf("%d ",queue[i]);
    printf("\n");
	
    printf("Is queue empty %s\n",is_empty_queue()?"True":"False");
	
    dequeue();
    dequeue();
	
    printf("Is queue empty %s\n",is_empty_queue()?"True":"False");
    return 0;
}
