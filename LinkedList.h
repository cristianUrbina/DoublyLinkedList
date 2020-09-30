#ifndef LinkedList_H
#define LinkedList_H
#include "Node.h"
#include<iostream>
class LinkedList{
  private:
    Node * head;
    Node * feet;
    int size;
  public:
    LinkedList();
    void append(const int& datum);
    void create(const int& datum, int index);
    void del(int index);
    int getSize()const;
    void push(const int& datum);
    int read(int index);
    int readReverse(int index);
    void update(const int& datum, int index);
};

LinkedList::LinkedList():head(nullptr),feet(nullptr),size(0){}

void LinkedList::append(const int& datum){
  Node * pnewboy = new Node(datum);
  Node * pcurrentboy = feet;
  if(!feet){
    head=feet=pnewboy;
  }
  else {
    feet->nextboy = pnewboy;
	pnewboy->prevboy = feet;
	feet=pnewboy;
	}
  ++size;
}

void LinkedList::create(const int& datum, int index){
	Node * pnewboy = new Node(datum);
	Node * pauxboy = head;
	Node * pauxholder = nullptr;
	while(index--){
		pauxholder=pauxboy;
		if(!pauxboy->nextboy){
			if(index>0) this->append(0);
			else{
				this->append(datum);
				return;
			}
		}
		pauxboy=pauxboy->nextboy;
	}
	if(pauxboy == head){
		pnewboy->nextboy=head;
		head->prevboy=pnewboy;
		head=pnewboy;
	}
	else{
		pauxholder->nextboy=pnewboy;
		pnewboy->prevboy=pauxholder;
		pnewboy->nextboy=pauxboy;
		pauxboy->prevboy=pnewboy;
	}
	++size;
}

void LinkedList::del(int index){
	Node * pauxboy = head;
	Node * pauxholder = nullptr;
	while(index--){
		pauxholder=pauxboy;
		if(!pauxboy->nextboy) return;
		pauxboy=pauxboy->nextboy;
	}
	if(pauxboy == head) {
		head=head->nextboy;
		head->prevboy=nullptr;
	}
	else if(pauxboy == feet){
		feet=feet->prevboy;
		feet->nextboy=nullptr;
	}
	else {
		pauxholder->nextboy=pauxboy->nextboy;
		pauxboy->prevboy=pauxholder;
	}
	--size;
}

int LinkedList::getSize()const{
  return size;
}

void LinkedList::push(const int& datum){
  Node * pnewboy=new Node(datum);
  pnewboy->nextboy=head;
  if(head){
  	head->prevboy=pnewboy;
  	head=pnewboy;
  }
  else{
  	feet=head=pnewboy;
  }

  size++;
}

int LinkedList::read(int index){
	Node * pauxboy = head;
	while(index--){
		if(!pauxboy->nextboy) return 0;
		pauxboy=pauxboy->nextboy;
	}
	return pauxboy->content;
}

int LinkedList::readReverse(int index){
	Node * pauxboy = feet;
	while(index--){
		if(!pauxboy->prevboy) return 0;
		pauxboy=pauxboy->prevboy;
	}
	return pauxboy->content;
}

void LinkedList::update(const int& datum, int index){
	Node * pauxboy = head;
	while(index--) {
		if(!pauxboy->nextboy) return;
		pauxboy=pauxboy->nextboy;
	}
	pauxboy->content=datum;
}
#endif
