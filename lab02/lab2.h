#ifndef __LAB2_H__
#define __LAB2_H__

#include <forward_list>
#include <sstream>
#include <iostream>

using namespace std;

typedef int Type;

class Node {
    friend class List;
    
    private:
        Type data; // data of the Node
        Node *next; // points to the next Node
    
    public:
        Node(Type data); // constructs Node with passed in character
};

class List {
    private:
        Node *head; // points to first item
        Node *tail; // points to last item
    public:
        List(); // default constructor
        List(const string& str); // constructs list from a string
        List(List &list); // copy constructor
        ~List(); // destructor
        void display() const; // displays the contents of the list
        void elementSwap(int pos);
        void push(Type val);
};

Node::Node(Type data) // Node constructor
: data(data), next(0) // initialize data and next
{}

List::List() // default constructor, creates empty list
: head(0), tail(0) // initialize head and tail to 0
{}

// constructs list from passed in string
List::List(const string& str)
: head(0), tail(0)
{
    stringstream s; 
    s << str; // put str into s stringstream
    Type c; // variable to hold each individual character
    while(s >> c)
    {
        push(c); // push c onto the list using the function push
    }
}

List::List(List &list) // copy constructor
: head(0), tail(0) // initialize head and tail to 0
{
    // use curr (a Node pointer to traverse the list)
    // loop ends when curr reaches the last Node
    for(Node *curr = list.head; curr != 0; curr = curr->next)
    {
        push(curr->data); // push function to add Nodes to the list
    }
}

// destructor
List::~List()
{
    // go through the list and delete each node
    for(Node *curr = head; curr != 0; curr = curr->next)
    {
        delete curr;
    }
}

// inserts val to the end of the list
void List::push(Type val)
{
    Node *tmp = new Node(val); //create new Node that contains the val passed in
    if(head == 0) // check case of an empty list
    {
        head = tmp; // set head to the new Node
        tail = tmp; // set tail to the new Node
    }
    else // if the list is not empty add the new Node at the end of the list
    {
        tail->next = tmp; // add the new Node to the end of the list
        tail = tmp; // set tail to the new last Node
    }
}

// prints the contents of the list
void List::display() const
{
    if(head == 0) // if the list is empty, nothing is displayed 
    {
        cout << "";
        return;
    }
    // go throught the list and print the data of each node
    // use curr (a Node pointer) to traverse the list
    for(Node *curr = head; curr != 0; curr = curr->next)
    {
        cout << curr->data; // prints the data of each Node
        // if statement to make sure a space is not added at the end of the list
        if(curr->next != 0)
        {
            cout << ' ';
        }
    }
}

void List::elementSwap(int pos)
{
	if(pos < 0) // if the position passed in is negative
	{
		cout << "Error. Negative position is invalid.";
		cout << endl;
		return;
	}
	if((head == 0) || (head->next == 0)) // if the list is empty or size 1
	{
		cout << "Error. Cannot swap on a list that is empty or of size one.";
		cout << endl;
		return;
	}
	int counter = 0;
	// count the number of nodes in the list
	for(Node *curr = head; curr != 0; curr = curr->next)
	{
		counter++;
	}
	if(pos >= counter - 1) // check if the position passed in is out of bounds
	{
		cout << "Error. Invalid position when calling elementSwap." << endl;
		return;
	}
	if(head->next->next == 0) // if the list has two nodes
	{
		if(pos == 1) // check if the position passed in is of the second node
		{
			cout << "Error. Invalid position when calling elementSwap." << endl;
			return;
		}
		// adjust the links to swap the nodes
		Node *temp = head; // temp Node pointer to keep track of head
		head = temp->next;
		head->next = temp;
		temp->next = 0; // set the new last node's next to 0 
		return;
	}
	if(pos == 0) // if the position is 0 and has more than two nodes
	{
		// create temporary pointers for the the node at pos and the node after
		Node *atPos = head;
		Node *after = head->next;
		// adjust the links to swap the two nodes
		atPos->next = after->next;
		head = after;
		after->next = atPos;
		return;
	}
	
	Node *before = head; // pointer to keep track of the node before node at pos
	Node *atPos = head; // pointer to keep track of the node at position pos
	
	Node *after = 0; // pointer to keep track of the node after the node at pos
	// traverse the list until before and and atPos point to the node 
	// before the node at position pos
	for(int i = 0; i < pos - 1; i++)
	{
		before = before->next;
		atPos = atPos->next;
	}
	
	atPos = atPos->next; // make atPos point to the node at position pos
	after = atPos->next; // make after point to the node after the node at pos
	
	if(after->next == 0) // if after is pointing to the last node, update tail
	{
		tail = atPos;
	}
	// adjust the links to swap the nodes pointed to by atPos and after
	before->next = after;
	atPos->next = after->next;
	after->next = atPos;
}

int primeCount(forward_list<int> lst, forward_list<int>::iterator &it);

int primeCount(forward_list<int> lst);

bool isPrime(int i);

void listCopy(forward_list<Type> L, forward_list<Type> &P);

void printLots(forward_list<Type> L, forward_list<int> P);

void print(forward_list<Type> &L);

#endif
