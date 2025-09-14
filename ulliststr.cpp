#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
  
  
 //This function returns the first item in the head_ ptr
  std::string const & ULListStr::front() const{
    return head_-> val[head_-> first];
  }


//This function returns the last item in the tail_ptr
 std::string const &ULListStr:: back() const{
    return tail_ ->val[tail_-> last -1];
  }


void ULListStr::pop_back(){

  if (tail_ == nullptr){ //First condition: The list is empty
    return;
  }

  else { //There must be at least one Item in the list, move the last index back by one
    tail_-> last = tail_-> last -1;
    size_--;
  }

  if (tail_-> last == tail_-> first){ //Condition: The Item's array is now empty
     Item* tmp = tail_;
      if (tail_ == head_){ //The Item removed was the only one in the list
        delete tmp;
        tail_ = nullptr;
        head_ = nullptr;

        return;
      }


     tail_ = tail_-> prev; //Move the tail_ pointer back one Item
     tail_-> next = nullptr;
     delete tmp;

  }
  return;
}


void ULListStr::pop_front(){ 
  if (head_ == nullptr){ /* If nothing in ULList*/
    return;
  }

 
  else { /*At least one value in ULList*/
    head_-> first = head_-> first + 1;
    size_--;
  }
  if (head_-> first > 9){ /* head_ Item's array is empty*/
    Item* tmp = head_;
    head_ = head_ -> next;
    delete tmp;
  }
  return;


}


void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){ //Case: list is already empty
    head_ = new Item();
    head_ -> next = nullptr;
    head_-> prev = nullptr;
    head_ -> val[5] = val;
    head_-> first = 5;
    head_-> last = 6;
    tail_ = head_;
    size_= 1;
    return;
  }
  //Case of at least one item in the list

  if (head_ -> first > 0){ //There is space in the head_ Item's array
    head_ -> val[head_-> first -1] = val;
    head_-> first = head_-> first-1;
    size_++;
    return;
  } else { //No space in the array, must create a new Item
    Item* newItem = new Item();
    newItem-> val[9] = val;
     size_ ++;
    newItem-> next = head_;
    head_-> prev = newItem;
    newItem-> prev = nullptr;
    newItem-> first = 9;
    newItem-> last = 10;
    head_ = newItem;
  }

}





void ULListStr::push_back(const std::string& val){
  /* Case 1: list is empty */
  if (head_ == NULL){
  
      head_ = new Item();
      head_-> val[0] = val;
      head_ -> first = 0;
      head_ -> last = 1;
      tail_ = head_;
      head_ -> next = NULL;
      head_ -> prev = NULL;
      size_ = 1;


      return;

  }

  /* Case 2: There is at least one item*/


  //Existing tail's array is not full
  if (!(tail_-> last >= 10)){
    tail_-> val[tail_->last] = val;
    tail_-> last = tail_-> last + 1;
    size_++;

  } else { //Arrays are full, must create a new item
    Item* newItem = new Item();
    newItem-> val[0] = val;
    tail_-> next = newItem;
    newItem-> prev = tail_;
    newItem -> last = 1;
    newItem-> first = 0;
    newItem -> next = nullptr;
    size_ ++;
    tail_ = newItem;


  }


}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}



  std::string* ULListStr::getValAtLoc(size_t loc) const {
    
    //Case: location is out of bounds
    if (loc > size_|| head_== nullptr){
      return NULL;
    }


    else { //Case: location is valid, evaluate index
      Item* tmp = head_;
      int count = 0;
      while (tmp != nullptr){



        if (tmp == head_){
          if (count + tmp-> last - tmp-> first -1 < loc){
            count += tmp -> last - tmp-> first-1;
            tmp = tmp-> next;
            continue;
          } else {
            int diff = loc-count;
            return tmp-> val + (tmp-> first + diff );
          }

        }


       else if (count + tmp-> last - tmp-> first < loc){
          count += tmp-> last - tmp-> first;
          tmp = tmp-> next;
          continue;
        } else {
          int diff = loc - count;
          return tmp->val + (tmp-> first+diff -1);
        }
      }
    }
    return NULL;

  

  }
  