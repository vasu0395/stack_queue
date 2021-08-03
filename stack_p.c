/*
 * Program to implement stack in c.
 * Compilation : gcc stack_p.c
 * Execution : ./a.out 
 *
 * @vasu ( 1910990395 )  , 02/8/2021
 * Day_2_Coding_Assignment.
 *
 * Time complexity :
 * push() -> O(1)
 * pop()  -> O(1)
 * peek() -> O(1)
 * is_empty() -> O(1)
 * resize_stack() ->O(size)
*/
 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Program for creating own stack 
int top=-1; // initalize marker of stack
bool initalize=false; // for checking stack initalize or not
int capacity=3; // by default making capacity 3
int *stack; // creating dynamic stack
// function to initalize stack with intial capacity
void initalize_stack() 
{
    // using malloc function for Dynamic Memory Allocation
    stack=(int*)malloc(capacity * sizeof(int)); // create stack of size capacity
}
// function to resize stack
void resize_stack()
{
    // first double the capacity
    capacity = capacity * 2;
    // create new stack of double size as of previous 
    int *new_stack;
    // using malloc function for Dynamic Memory Allocation
    new_stack=(int*)malloc(capacity * sizeof(int));
    // first simply push all element of stack into new_stack
    for(int i=0;i<capacity/2;i++)
    new_stack[i]=stack[i];
    // assign stack to new stack
    stack=new_stack;
}
// function to perform push operation
void push(int x)
{
    // if initalize not done before
    if(!initalize)
    {
        initalize_stack();
        initalize=true;
    }
    // first increase top count
    top++;
    // if we reached at end then increase size of stack by calling resize_stack().
    if(top==capacity-1)
    {
        resize_stack();
    }
    // push element at index top
    printf("Element %d push into stack\n",x);
    stack[top]=x;
}
// function to return top element of stack
int peek()
{
    // return top element of stack
    return stack[top];
}
// function to return pop element and remove it from stack
int pop()
{
    // since stack is empty then no pop operation perform
    if(top==-1)
    {
        printf("under_flow_condition");
        return -1;
    }
    // store pop element
    int x=stack[top];
    // remove it from stack
    top--;
    // return it's value
    return x;
}
// function to check weather stack is empty or not
bool is_empty()
{
    // if we have empty stack then top always point to -1.
    if(top==-1)
    return true;
    
    return false;
}
int main()
{
    push(1);
    push(2);
    push(3);
    printf("Element at Peek %d\n",peek());
    printf("Element pop %d\n",pop());
    push(3);
    printf("Is stack Empty ? %s",is_empty()?"True":"False");
    
    return 0;
}
