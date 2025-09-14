/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>
#include "split.h"
int main(int argc, char* argv[])
{

  //Test 1:
  std::cout<< "odds: ";
  Node* headptr = new Node(4, nullptr);
  headptr -> next = new Node(7, nullptr);
  headptr-> next-> next = new Node (8, nullptr);
  Node* odds = nullptr;
  Node* evens= nullptr;
  split(headptr, odds, evens);
  while (odds != nullptr){
    std::cout<<odds-> value;
    Node* tmp = odds;
    odds = odds-> next;
    delete tmp;
  }
   std::cout<< " and now evens:";
    while (evens != nullptr){
    std::cout<<evens-> value;
    Node* tmp = evens;
    evens = evens-> next;
    delete tmp;
  }
std::cout<<std::endl;

  //Test 2:

  Node* newptr = new Node(1, nullptr);

  Node* odds2 = nullptr;
  Node* evens2 = nullptr;
  split (newptr, odds2, evens2);

  std::cout<<odds2-> value;
  std::cout<<std::endl;

  //Test 3:
  

  Node* one_ptr = new Node(1, nullptr);
  Node* three_ptr = new Node(3, nullptr);
  Node* five_ptr = new Node(5, nullptr);
  Node* seven_ptr = new Node(7, nullptr);
  Node* two_ptr = new Node(2, nullptr);
  Node* four_ptr = new Node(4, nullptr);
  Node* six_ptr = new Node(6, nullptr);
  Node* eight_ptr = new Node(8, nullptr);

  one_ptr -> next = three_ptr;
  three_ptr-> next = five_ptr;
  five_ptr-> next = seven_ptr;
  seven_ptr-> next = two_ptr;
  two_ptr-> next = four_ptr;
  four_ptr-> next= six_ptr;
  six_ptr-> next = eight_ptr;

  Node* odds3 = nullptr;
  Node* evens3 = nullptr;
  split(one_ptr, odds3, evens3);

  while (odds3 != nullptr){
    std::cout<< odds3-> value;
    Node* tmp = odds3;
    odds3 = odds3-> next;
    delete tmp;
  }
  while (evens3 != nullptr){
    std::cout<< evens3-> value;
    Node* tmp = evens3;
    evens3 = evens3-> next;
    delete tmp;
  }


}
