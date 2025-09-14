#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  //Test Case 1:
ULListStr list1;
list1.push_back("8");
list1.push_back("9");
list1.pop_front();
list1.pop_front();
list1.push_front("7");
std::cout<<list1.get(0)<<" "<<list1.back()<<" "<<list1.front();
std::cout<<std::endl;

//Test Case 2:
ULListStr list2;
list2.push_front("9");
list2.push_front("10");
list2.push_front("11");
list2.push_front("12");
list2.push_front("13");
list2.push_front("14");
list2.push_front("15");
list2.push_front("16");
list2.push_front("17");
list2.push_front("18");
list2.push_front("19");
list2.pop_back();

for (int i = 0; i< 10; i++){
  std::cout<< list2.get(i)<<" ";
}
std::cout<<std::endl;

//Test Case 3:

ULListStr list3;
list3.push_back("1");
list3.push_back("2");
list3.push_back("3");
list3.push_back("4");
list3.push_back("5");
list3.push_back("6");
list3.push_back("7");
list3.push_back("8");
list3.push_back("9");
list3.push_back("10");
list3.push_back("11");
list3.push_back("12");
list3.push_back("13");
list3.pop_front();
list3.pop_front();
list3.pop_front();
list3.push_front("0");
for (int i = 0; i<11; i++ ){
  std::cout<<list3.get(i)<<" ";
}




return 0;


}
