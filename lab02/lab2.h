#ifndef __LAB2_H__
#define __LAB2_H__

#include <forward_list>
#include <iostream>
#include <sstream>

using namespace std;

template <typename Type>
class Node {
    private:
    template <typename T> friend class List;
    Type data; // data of the Node
    Node<Type> *next; // points to the next Node
    
    public:
    Node<Type>(Type data) // constructs Node with passed in character
    : data(data), next(0) // initialize data and next
    {}
};

template <typename Type>
class List {
    private:
    Node<Type> *head; // points to first item
    Node<Type> *tail; // points to last item
    
    public:
    List() // default constructor, creates empty list
    : head(0), tail(0) // initialize head and tail to 0
    {}
    
    // constructs list from passed in string
    List(const string& str)
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
    
    List(List &list) // copy constructor
    : head(0), tail(0) // initialize head and tail to 0
    {
        // use curr (a Node pointer to traverse the list)
        // loop ends when curr reaches the last Node
        for(Node<Type> *curr = list.head; curr != 0; curr = curr->next)
        {
            push(curr->data); // push function to add Nodes to the list
        }
    }
    
    // destructor
    ~List()
    {
        // go through the list and delete each node
        for(Node<Type> *curr = head; curr != 0; curr = curr->next)
        {
            delete curr;
        }
    }
    
    // inserts val to the end of the list
    void push(Type val)
    {
        Node<Type> *tmp = new Node<Type>(val); //create new Node that contains the val
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
    void display() const
    {
        if(head == 0) // if the list is empty, nothing is displayed 
        {
            cout << "";
            return;
        }
        // go throught the list and print the data of each node
        // use curr (a Node pointer) to traverse the list
        for(Node<Type> *curr = head; curr != 0; curr = curr->next)
        {
            cout << curr->data; // prints the data of each Node
            // if statement to make sure a space is not added at the end of list
            if(curr->next != 0)
            {
                cout << ' ';
            }
        }
    }
    
    void elementSwap(int pos)
    {
    	if(pos < 0) // if the position passed in is negative
    	{
    		cout << "Error. Negative position is invalid for elementSwap.";
    		cout << endl;
    		return;
    	}
    	if((head == 0) || (head->next == 0)) // if the list is empty or size 1
    	{
    		cout << "Error. Cannot swap on a list that is empty or of size 1.";
    		cout << endl;
    		return;
    	}
    	int counter = 0;
    	// count the number of nodes in the list
    	for(Node<Type> *curr = head; curr != 0; curr = curr->next)
    	{
    		counter++;
    	}
    	if(pos >= counter - 1)//check if the position passed in is out of bounds
    	{
    		cout << "Error. Invalid position when calling elementSwap." << endl;
    		return;
    	}
    	if(head->next->next == 0) // if the list has two nodes
    	{
    		if(pos == 1) //check if the position passed in is of the second node
    		{
    			cout << "Error. Invalid position when calling elementSwap.";
    			cout << endl;
    			return;
    		}
    		// adjust the links to swap the nodes
    		Node<Type> *temp = head; // temp Node pointer to keep track of head
    		head = temp->next;
    		head->next = temp;
    		temp->next = 0; // set the new last node's next to 0 
    		return;
    	}
    	if(pos == 0) // if the position is 0 and has more than two nodes
    	{
    		// create temporary pointers for the the node at pos and
    		// the node after
    		Node<Type> *atPos = head;
    		Node<Type> *after = head->next;
    		// adjust the links to swap the two nodes
    		atPos->next = after->next;
    		head = after;
    		after->next = atPos;
    		return;
    	}
    	
    	// before is a pointer to keep track of the node before node at pos
    	Node<Type> *before = head;
    	Node<Type> *atPos = head; // pointer to keep track of the node at position pos
    	
    	Node<Type> *after = 0;
    	// after is a pointer to keep track of the node after the node at pos
    	// traverse the list until before and and atPos point to the node 
    	// before the node at position pos
    	for(int i = 0; i < pos - 1; i++)
    	{
    		before = before->next;
    		atPos = atPos->next;
    	}
    	
    	atPos = atPos->next; // make atPos point to the node at position pos
    	after = atPos->next;//make after point to the node after the node at pos
    	
    	if(after->next == 0)//if after is pointing to the last node, update tail
    	{
    		tail = atPos;
    	}
    	// adjust the links to swap the nodes pointed to by atPos and after
    	before->next = after;
    	atPos->next = after->next;
    	after->next = atPos;
    }
        
};

template <typename Type>
void listCopy(forward_list<Type> L, forward_list<Type> &P)
{
    class forward_list<Type> temp; // temp forward-list to store P's values
    class forward_list<Type>::iterator it1; // iterator for list P
	for(it1 = P.begin(); it1 != P.end(); ++it1)
	{
		//push front all of P's values onto a temporary forward_list
		temp.push_front(*it1);
	}
	P.resize(0); // resize P to size 0
	class forward_list<Type>::iterator it2;
	for(it2 = L.begin(); it2 != L.end(); ++it2)
	{
		//push front all of L's values onto P so that they will be reversed in P
		P.push_front(*it2);
	}
	class forward_list<Type>::iterator itt;
	for(itt = temp.begin(); itt != temp.end(); ++itt)
	{
		//push front all of temp's values back onto P
		// since they were stored in reverse order in temp they will now be
		// in the original order
		P.push_front(*itt);
	}
}

template <typename Type>
void printLots(forward_list<Type> L, forward_list<int> P)
{
	//check if any of the positions specified by list P are invalid
	class forward_list<Type>::iterator itLS = L.begin();
	int sizeL = 0; // variable to store the size
	// first count the number of elements in list L
	for(itLS = L.begin(); itLS != L.end(); itLS++)
	{
		sizeL++;
	}
	forward_list<int>::iterator itPS = P.begin();
	for(itPS = P.begin(); itPS != P.end(); itPS++)
	{
		//check if any of the positions specified by P are out of bounds
		if((*itPS < 0) || (*itPS >= sizeL))
		{
			cout << "Error. Invalid position when calling printLots.";
			cout << endl;
			return;
		}
	}
	int positionInL = 0;
	class forward_list<Type>::iterator itL = L.begin(); // iterator for list L
	forward_list<int>::iterator itP = P.begin(); // iterator for list P
	for(itL = L.begin(); itL != L.end(); itL++) // print the values in list P
	{
		if(itP == P.end()) break;//if end of list P is reached break 
		if(*itP == positionInL) 
		{
			// print the value of L at position specified by P
			cout << *itL << ' ';
			itP++; // increment itP
		}
		positionInL++; // increment positionInL
	}
}

template <typename Type>
void print(forward_list<Type> &L) // prints out the values in a list
{
	class forward_list<Type>::iterator itt;
	for(itt = L.begin(); itt != L.end(); ++itt) // print each value
	{
		cout << *itt << ' ';
	}
}

#endif