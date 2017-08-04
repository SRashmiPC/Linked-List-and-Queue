#include <iostream>
#include <string>

using namespace std;

typedef int E;
class Node{
private:
	E value;
	Node *next;
	Node *tail;

public:
	E Node::getValue();
	void Node::setValue(E val);
	Node* Node::getNext();
	void Node::setNext(Node *newNode);
};

E Node::getValue(){
	return value;
}

void Node::setValue(E val){
	value = val;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node *newNode){
	next = newNode;
}

class LinkedList {
private:
	Node *head;
	Node *tail;
	int length;

public:
	void LinkedList::init_list();
	bool LinkedList::is_list_empty();
	Node* LinkedList::search(E value);
	Node* LinkedList::deleteNode(E value);
	int LinkedList::deleteat(int i);
	bool LinkedList::insert(E value);
	bool LinkedList::insertat(E value, int i);
	int LinkedList::list_length();
	void LinkedList::printList();
};

void LinkedList::init_list(){
	head = NULL;
	tail = NULL;
	length = 0;
}

bool LinkedList::is_list_empty(){
	if (length == 0){
		return true;
	}
	return false;
}

Node* LinkedList::search(E value){
	Node *finder = head;
	while (finder){
		if (finder->getValue() == value){
			return finder;
		}
		finder=(finder->getNext());
	}
	return NULL;
}

Node* LinkedList::deleteNode(E value){
	if (head == NULL){
		return NULL;
	}

	//if not NULL
	Node *finder = head->getNext();
	Node *previous = head;
	if (head->getValue() == value){
		finder = head;
		//if head equal to tail, tail should be updated
		if (head == tail){
			tail = NULL;
		}

		head = (head->getNext());
		length--;
		return finder;
	}
	while (finder){
		if (finder->getValue() == value){
			if (finder == tail){
				tail = previous;
			}
			previous->setNext(finder->getNext());
			length--;
			return finder;
		}
		previous = finder;
		finder = finder->getNext();
	}
	return NULL;
}

int LinkedList::deleteat(int i){
	if (i > length || i<=0){
		return NULL;
	}
	
	if (i == 1){
		//cout << "come" << endl;
		Node* finder = head;
		if (head == tail){
			cout << "come too" << endl;
			tail = NULL;
		}
		head = head->getNext();
		//cout << "\t\ttotext" << endl;
		//printList();
		length--;
		return finder->getValue();
	}

	//if position higher than one
	Node *finder = head->getNext();
	Node *previous = head;
	int posn = 2;
	while (posn<i){
		previous = previous->getNext();
	}
	finder = previous->getNext();
	// now finder= to_delete_node
	if (finder == tail){
		tail = previous;
	}
	previous->setNext(finder->getNext());
	length--;
	return finder->getValue();
}

bool LinkedList::insert(E value){
	Node *newNode = new Node;
	newNode->setValue(value);
	if (head == NULL){
		head = newNode;
		tail = newNode;
		newNode->setNext(NULL);
		length++;
		return true;
	}
	tail->setNext(newNode);
	tail=newNode;
	newNode->setNext(NULL);
	length++;
	return true;
}

bool LinkedList::insertat(E value, int i){
	if (i <= 0){
		return false;
	}

	Node *newNode = new Node;
	newNode->setValue(value);
	
	if (head == NULL){
		//cout << "came";
		head = newNode;
		tail = newNode;
		head->setNext(NULL);
		length = 1;
		return true;
	}
	//if the i==1; head will be updated
	if (i == 1){
		newNode->setNext(head);
		head = newNode;
		length++;
		return true;
	}

	if (i > length){
		//cout << "came1";
		tail->setNext(newNode);
		tail = newNode;
		newNode->setNext(NULL);
		length++;
		return true;
	}
	
	Node *finder;
	Node *previous = head;
	//bring previous to previous Node
	for (int j = 2; j < i; j++){
		previous = previous->getNext();
	}
	finder = previous->getNext();
	previous->setNext(newNode);
	newNode->setNext(finder);
	length++;
	return true;
}

int LinkedList::list_length(){
	return length;
}

void LinkedList::printList(){
	if (head == NULL){
		cout << "Empty List";
	}
	Node* finder = head;
	int i = 1;
	while(finder != NULL){
		cout << "val no:" << i << "- " << finder->getValue()<<endl ;
		finder = finder->getNext();
		i++;
	}
	cout <<"Lngth is: " << length << endl;
}

/*
bigining of the stack
*/
class MyStack{
private:
	LinkedList values;

public:
	void MyStack::init_Stack();
	bool MyStack::is_Stack_Empty();
	bool MyStack::push(int value);
	int MyStack::pop();
	int MyStack::peek();
	void MyStack::prints();
};

void MyStack::init_Stack(){
	values.init_list();
}

bool MyStack::is_Stack_Empty(){
	return values.is_list_empty();
}

bool MyStack::push(int value){
	return values.insertat(value, 1);
}

int MyStack::pop(){
	return values.deleteat(1);
}

int MyStack::peek(){
	int temp = values.deleteat(1);
	values.insertat(temp, 1);
	return temp;
}

void MyStack::prints(){
	cout << "----Stack is:------------- "<< endl;
	values.printList();
	cout << endl;
}

class MyQueue{
private:
	LinkedList queue;

public:
	void MyQueue::init_queue();
	bool MyQueue::is_queeu_emppty();
	bool MyQueue::enqueue(int value);
	int MyQueue::dequeue();
	int MyQueue::peekvalue();
	void MyQueue::printq();
};

void MyQueue::init_queue(){
	queue.init_list();
}

bool MyQueue::is_queeu_emppty(){
	return queue.is_list_empty();
}

bool MyQueue::enqueue(int value){
	return queue.insert(value);
}

int MyQueue::dequeue(){
	return queue.deleteat(1);
}

int MyQueue::peekvalue(){
	int temp = queue.deleteat(1);
	queue.insertat(temp, 1);
	return temp;
}

void MyQueue::printq(){
	cout << "----Queue is:------------- "<< endl;
	queue.printList();
	cout << endl;
}

//----------------------------------------------------------
int main(){
	MyQueue myqueue;
	MyStack mystack; 

	cout << "Opperations on stack" << endl;
	cout << "initialise the stack"<<endl;
	mystack.init_Stack();
	mystack.prints();
	cout << "push first" << endl;
	mystack.push(1);
	mystack.prints();
	cout << "push second,third,fourth elements element" << endl;
	mystack.push(2);
	mystack.push(3);
	mystack.push(4);
	mystack.prints();
	cout << "peek" << endl;
	cout << "peeked value: " << mystack.peek() << endl;
	mystack.prints();
	cout << "pop" << endl;
	cout << "poped value is: " << mystack.pop() << endl;
	mystack.prints();

	cout << endl;
	cout << "initialising the queue" << endl;
	myqueue.init_queue();
	myqueue.printq();
	cout << "Enqueue first Node" << endl;
	myqueue.enqueue(1);
	myqueue.printq();
	cout << "Enqueue second, third, fourth element" << endl;
	myqueue.enqueue(2);
	myqueue.enqueue(3);
	myqueue.enqueue(4);
	myqueue.printq();
	cout << "dequee Nodes" << endl;
	myqueue.dequeue();
	myqueue.printq();
	cout << "dequeue another" << endl;
	myqueue.dequeue();
	myqueue.printq();
	cout << "dequeue another" << endl;
	myqueue.dequeue();
	myqueue.printq();
	cout << "dequeue another" << endl;
	myqueue.dequeue();
	myqueue.printq();

	cout << endl;
	LinkedList linkedlist;
	cout << "------------linked List------------------" << endl;
	cout << "initialise the list" << endl;
	linkedlist.init_list();
	linkedlist.printList();
	cout << "Enter fist node through back" << endl;
	linkedlist.insert(1);
	linkedlist.printList();
	cout << "delete the first node // omly for testing" << endl;
	linkedlist.deleteat(1);
	linkedlist.printList();
	cout << "Enter the first node through front" << endl;
	linkedlist.insertat(1,1);
	linkedlist.printList();
	cout << "Enter second third fourth elements" << endl;
	linkedlist.insert(2);
	linkedlist.insert(3);
	linkedlist.insert(5);
	linkedlist.printList();
	cout << "Test of insertat function" << endl;
	cout << "insert 4 using insertat function" << endl;
	linkedlist.insertat(4, 4);
	linkedlist.printList();
	cout << "code -- insertat(6,10) //at the tail" << endl;
	linkedlist.insertat(6, 10);
	linkedlist.printList();
	cout << "code -- insertat(0,1) at the head" << endl;
	linkedlist.insertat(0, 1);
	linkedlist.printList();
	cout << "testing of delete function" << endl;
	cout << "code -- deleteNode(0) //firstnode" << endl;
	linkedlist.deleteNode(0);
	linkedlist.printList();
	cout << "code -- deleteNode(6) //last node" << endl;
	linkedlist.deleteNode(6);
	linkedlist.printList();
	cout << "code -- deleteNode(3) // middle value" << endl;
	linkedlist.deleteNode(3);
	linkedlist.printList();
	cout << "rebuild the list" << endl;
	linkedlist.insertat(3, 3);
	linkedlist.insert(6);
	linkedlist.printList();
	

	cout << endl;
	int k;
	cout << "Enter a int: ";
	cin >> k;
	return 0;
}