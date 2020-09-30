#include<iostream>
#include "LinkedList.h"
using namespace std;

int main(){
  LinkedList myList = LinkedList();
  myList.push(18);
  myList.append(15);
  myList.append(16);
  myList.append(17);
  myList.push(19);
  myList.create(20,5);
  cout<<"Final List: ";
  for(int i = 0; i<myList.getSize();++i){
  	cout<<myList.read(i)<<" ";
  }

  return 0;
}
