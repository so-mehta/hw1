/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
Node*& findTail(Node*& curr);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

/* The following is the base case: 
    if the head pointer is null, terminate */
  if (in == nullptr){
    return;
  }
  else { /*Now either adding value to evens or odds list */
    if (in-> value %2 != 0){ /*odd value*/
      if (odds == nullptr){
        odds = in;
        in = in-> next;
        odds-> next = nullptr;
      } else {
        Node* tail = findTail (odds);
        tail-> next = in;
        in = in-> next; /*update the in pointer*/
        tail-> next -> next = nullptr;
        
      }
    } else{ /*even value*/
      if (evens == nullptr){
        evens = in;
        in = in-> next;
        evens-> next = nullptr;
      } else {
        Node* tail = findTail (evens);
        tail-> next = in;
        in = in-> next; /*update the in pointer*/
        tail-> next -> next = nullptr;
        
      }
    }
    /*Now, the recursive case with an updated in pointer*/
    split (in, odds, evens);
  }
}

/* If you needed a helper function, write it here */

/*This function takes in the head pointer of a non-empty list
  and returns a pointer to the last Node in the list*/
Node*& findTail(Node*& curr){

  if (curr-> next == nullptr){
    return curr;
  } else {
    return findTail(curr-> next);
  }
}