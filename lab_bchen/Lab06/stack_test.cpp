#include <iostream>
//#include "llist_sol.h"
#include "llist.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
  Stack<int> mylist;
  mylist.push(5);
  mylist.push(6);
  mylist.push(7);
  cout << "Front item is: " << mylist.top() << endl;
  //cout << "Item at location 1 is " << mylist[1] << endl;
  //mylist.remove(6);
  //mylist.insert(0,4);
  //mylist.insert(3,8);
  cout << "List contents (and removal)" << endl;
  cout << "Size: " << mylist.size() << endl;
  while(!mylist.empty()){
   mylist.pop();
   try{cout << mylist.top() << endl;}
   catch(invalid_argument e){};
  }
  mylist.pop();
  return 0;
}
