// Monica Moreno
// 861174030
// May 9, 2015
// Approach: I modified my BST class implementation by adding additional
// functions. I implemented the function minCover which finds the smallest 
// vertex cover of the tree. I added the data member selected in the Node class 
// to keep track of which nodes are selected as part of the vertex cover. To 
// find the minimum cover, for each leaf in the tree, I select its parent(this 
// is done in the function minCoverLeaf). Additionally, I select each internal 
// node if any of its children are not selected(this is done in the function
// minCoverParent). I also implemented the function displayMinCover to display 
// the smallest vertex cover and its size. I implemented the function 
// findSumPath to display all of the paths to the passed-in sum. Its helper 
// function uses a counter to keep track of the position of the last value that
// was put into the buffer. The sum is decremented by the value of each node in
// the path using recursion. A path is found if the sum is 0 when a leaf is 
// reached. Otherwise, a path was not found. If no paths are found, a 0 is
// printed. The helper function print_path is used to print the values in the 
// buffer when a path is found. The function vertSum finds the vertical sums of
// the nodes that are in the same vertical line. The function calls its helper 
// function which recursively calls itself to insert all the Node values into 
// the passed-in map. After the map is filled with the Node values, the values 
// are printed.

#ifndef BST_H
#define BST_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    
    class Node { // binary tree node
    
    // size recursive helper function
    int size_n(Node *n)
    {
        if(!n) // base case
        {
            return 0;
        }
        else
        {
            // increment by 1 and call size recursively on left and right
            return 1 + size_n(n->left) + size_n(n->right);
        }
    }
    // height recursive helper function
    int height_n(Node *n)
    {
        if(!n) // base case
        {
            return -1; // in order for the leaves to have height 0
        }
        int lft = height_n(n->left); // find the height of the left side
        int rght = height_n(n->right); // find the height of the right side
        return (lft > rght) ? 1 + lft : 1 + rght; // return the greater height
    }
        
    public:
        Value value;
        Node* left;
        Node* right;
        bool selected;
        Node( const Value v = Value() )
        : value(v), left(nil), right(nil), selected(false)
        {}
        
        Value& content() { return value; }
        
        bool isInternal() { return left != nil && right != nil; }
        
        bool isExternal() { return left != nil || right != nil; }
        
        bool isLeaf() { return left == nil && right == nil; }
        
        int height() {
            // returns the height of the subtree rooted at this node
            if(this == nil) // if node points to nil 0
            {
                return 0;
            }
            else
            {
                return height_n(this); // call the recursive helper function
            }
        }
        
        int size() {
            // returns the size of the subtree rooted at this node,
            return size_n(this); // call the recursive helper function
        }
        
    }; // Node
    
    // const Node* nil; // later nil will point to a sentinel node.
    int count;
    
    // search recursive helper function
    bool search( Value x, Node* n )
    {
        if(!n) // base case
        {
            return false;
        }
        if(n->value == x) // if the value is found, return true
        {
            return true;
        }
        // if the value x is less than the value at n, recursively call search
        // on the left 
        if(x < n->value)
        {
            return search (x, n->left);
        }
        // else the value x is greater than the value at n 
        // recursively call search on the right
        else
        {
            return search (x, n->right);
        }
    }
    
    // inorder recursive helper function
    void inorder(Node *n)const
    {
        if(!n) // base case
        {
            return;
        }
        inorder(n->left); // call inorder recursively on the left
        cout << n->value << endl; // print the value of the node
        inorder(n->right); // call inorder recursively on the right
    }
    
    // preorder recursive helper function
    void preorder(Node *n)const
    {
        if(!n) // base case
        {
            return;
        }
        cout << n->value << endl; // print the value of the node
        preorder(n->left); // call preorder recursively on the left
        preorder(n->right); // call preorder recursively on the right
    }
    
    // postorder recursive helper function
    void postorder(Node *n)const
    {
        if(!n) // base case
        {
            return;
        }
        postorder(n->left); // call postorder recursively on the left
        postorder(n->right); // call postorder recursively on the right
        cout << n->value << endl; // print the value of the node
    }
        
    void fill(vector<Value> &v, Node *n) // [] helper function
    {
        if(!n) // base case
        {
            return;
        }
        fill(v, n->left); // call fill recursively on the left
        v.push_back(n->value); // add the value to the vector
        fill(v, n->right); // call fill recursively on the right
    }
    
    Node* find(Node *n, Value x) // [] helper function
    {
        if(!n) return 0; // base case
    	if(n->value == x) // if value is found
    	{
    		return n;
    	}
    	else if(x < n->value)
    	{
    		return find(n->left, x); // recursive call on left
    	}
    	else
    	{
    		return find(n->right, x); // recursive call on right
    	}
    }
    
    // function to select the parent of every leaf
    void minCoverLeaf(Node *n)
    {
        if(!n) return; // base case
        if(n->right == nil && n->left == nil) return; // second base case
        else if(n->left == nil || n->right == nil) // if either child is nil
        {
            if(n->left == nil) // if the left child is nil
            {
                // if the right child is a leaf, select it
                if(n->right->isLeaf() && (n != root)) n->selected = true;
            }
            if(n->right == nil) // if the right child is nil
            {
                // if the left child is a leaf, select it
                if(n->left->isLeaf() && (n != root)) n->selected = true;
            }
        }
        else // select the node if either of its children are leafs
        {
            if((n->left->isLeaf() || n->right->isLeaf()) && (n != root))
            {
                n->selected = true;
            }
        }
        minCoverLeaf(n->left); // recursive call on the left
        minCoverLeaf(n->right); // recursive call on the right
    }
    
    // function to select a node if any of its children are not selected
    void minCoverParent(Node *n)
    {
        if(!n) return; // base case
        if(n->right == nil && n->left == nil) return;
        if(n->right == nil || n->left == nil)
        {
            if(n->right != nil)
            {
                // if the right child isn't selected, select the node
                if(n->right->selected == false && (n != root)) 
                {
                    n->selected = true;
                }
            }
            if(n->left != nil)
            {
                // if the left child isn't selected, select the node
                if(n->left->selected == false && (n != root))
                {
                    n->selected = true;
                }
            }
        }
        // if the left or right child of a node are not selected, select it
        else
        {
            if((n->right->selected == false || n->left->selected == false)
            && (n != root))
            {
                n->selected = true;
            }
        }
        minCoverParent(n->left); // recursive call on the left
        minCoverParent(n->right); // recursive call on the right
    }
    
    void print_covers(Node *n, int &count)
    {
        if(!n) return; // base case
        print_covers(n->left, count); // recursively calls itself on left
        if(n->selected) // print the selected nodes
        {
            ++count; // updates the count of the vertex cover
            cout << n->value << ' ';
        }
        print_covers(n->right, count); // recursively calls itself on right
    }
        
    // prints the found sum path
    void print_path(int buffer[], int count)
    {
        vector<int> v;
        for(unsigned i = 0; i < count; ++i) // push the values onto a vector
        {
            v.push_back(buffer[i]);
        }
        std::sort(v.begin(), v.end()); // sort the vector
        for(unsigned i = 0; i < v.size(); ++i)
        {
            cout << v.at(i) << ' '; // display the values
        }
        cout << endl;
    }
    
    // helper
    void findSumPath_(Node *n, int sum, int buffer[], int count, int &check)
    {
        if(!n) return; // base case
        buffer[count] = n->value; // add the node's value to the buffer
        if(sum - n->value == 0 && n->isLeaf()) // if a valid path is found
        {
            count = count + 1; // update count
            buffer[count] = n->value; // add the last value to the buffer
            print_path(buffer, count); // print the buffer using helper func
            ++check; // increment check because a path was found
            count = 0; // set count to 0
        }
        // if a leaf is reached and the sum is not found, set count to 0
        if(((sum - n->value) < 0 || (sum - n->value) > 0) && n->isLeaf())
        {
            count = 0;
        }
        // recursive calls on the left and the right
        findSumPath_(n->left, sum - n->value, buffer, count + 1, check);
        findSumPath_(n->right, sum - n->value, buffer, count + 1, check);
    }
    
    // vertSum helper function
    void vertSum_(Node *node, int hd, std::map<int, int>& m)
    {
    	if(!node) return; // base case
    	else
    	{
    	    // add the node value to the existing value at the key hd
    	    m[hd] += node->value;
    		vertSum_(node->left, hd - 1, m); // recursively call on left
    		vertSum_(node->right, hd + 1, m); // recursively call on right
    	}
    }
    
    public:
    	Node* root;
        int size() {
            // size of the overall tree.
            if(root == nil) // if the tree is empty
            {
                return 0;
            }
            return root->size(); // call the size function for Nodes on the root
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) {
            // Print the node’s value.
            cout << n->value << endl;
        }
        
        bool search( Value x ) {
            // search for a Value in the BST and return true iff it was found.
            if(root->value == x) // if x is the value at root, return true
            {
                return true;
            }
            else // call the recursive search helper function
            {
                return search(x, root);
            }
        }
        
        void preorder()const {
            // Traverse and print the tree one Value per line in preorder.
            if(root == nil) // if the tree is empty there is nothing to print
            {
                return;
            }
            else
            {
                preorder(root); // call the recursive preorder helper function
            }
        }
        
        void postorder()const {
            // Traverse and print the tree one Value per line in postorder.
            if(root == nil) // if the tree is empty there is nothing to print
            {
                return;
            }
            else
            {
                postorder(root); // call the recursive postorder helper function
            }
        }
        
        void inorder()const {
            // Traverse and print the tree one Value per line in inorder.
            if(root == nil) // if the tree is empty, there is nothing to print
            {
                return;
            }
            else 
            {
                inorder(root); // call the recursive inorder helper function
            }
        }
        
        Value& operator[] (int n) {
            // returns reference to the value field of the n-th Node.
            if(n >= size() || n < 0) // check for corner case
            {
                cout << "Error. The position passed-in is not valid." << endl;
                exit(0);
            }
            vector<Value> v;
            fill(v, root); // fill v
            return find(root, v.at(n))->value; // return reference to the value
        }
        
        BST() : count(0), root(nil) {}
        
        void insert( Value X ) { root = insert( X, root ); }
        
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ...
            if ( T == nil )
            {
                T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value )
            {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value ) 
            {
                T->right = insert( X, T->right );
            }
            else 
            {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        
        void remove( Value X ) { root = remove( X, root ); }
        
        Node* remove( Value X, Node*& T ) {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                else 
                { // X == T->value
                    if ( T->right != nil )
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    }
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    }
                    else
                    { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        
        void okay( ) { okay( root ); }
        
        void okay( Node* T )
        {
            // diagnostic code can be installed here
            return;
        }
        
        // function to display the smallest vertex cover and its size
        void displayMinCover()
        {
            int count = 0;
            print_covers(root, count); // display the node values
            cout << endl;
            cout << count << endl; // display the count
        }
        
        // to find the smallest cover of the tree such that root is not part of
        // vertex
        void minCover()
        {
            // select the two children of the root if they exist
            if(root->right != nil)
            {
                root->right->selected = true;
            }
            if(root->left != nil)
            {
                root->left->selected = true;
            }
            minCoverLeaf(root); // call the mincCoverLeaf helper function
            minCoverParent(root); // call the minCoverParent helper function
        }
        
        // function that finds and displays all the paths to the passed-in sum
        void findSumPath(Node *n, int sum, int buffer[])
        {
            int check = 0; // check is initially 0
            findSumPath_(n, sum, buffer, 0, check);
            if(check == 0) // if no sum paths are found, print a 0
            {
                cout << '0' << endl;
            }
        }
            
        // function to find the vertical sum of nodes
        void vertSum(Node *node, int hd, std::map<int, int>& m)
        {
        	vertSum_(node, hd, m); // call the helper function
        	for(auto it = m.begin(); it != m.end(); ++it) // print the values
        	{
        		cout << it->second << ' ';
        	}
        	cout << endl;
        }
}; // BST

#endif
