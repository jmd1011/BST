#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


template <class tType>
class TreeNode
{
public:
	tType element;
	TreeNode* left;
	TreeNode* right;
	TreeNode( tType e = 0, TreeNode* l = NULL, TreeNode* r = NULL ) : 
		element( e ), left( l ), right( r ) {} // this is called an initialization list
	//it will accomplish the same thing as:  element=e; left=l; right=r;
};


template <class tType>
class BinarySearchTree
{
protected:
	TreeNode<tType>* root;

	int getSize( TreeNode<tType>* t );
	TreeNode<tType>* findLargest( TreeNode<tType>* t );
	int countLeaves( TreeNode<tType>* t );

	void printShort( TreeNode<tType>* t );
	void shedLeaves( TreeNode<tType>*& t );
	tType removeSuccessor( tType deleteValue, TreeNode<tType> * & t );

	TreeNode<tType>* findKthInOrder( TreeNode<tType> * t, int k );
	TreeNode<tType>* isRelated( tType a, tType b );
	int getWidthHeight( TreeNode<tType>* t, int & height );

	bool insert( tType& x, TreeNode<tType>*& t );
	TreeNode<tType>* find( TreeNode<tType>* t, tType value );
	void printTree( TreeNode<tType>* t, string indent, char direction );

public:

	BinarySearchTree( ) { root= NULL; }

	// The following functions are called wrapper functions, they are public helper functions.
	// All they do is call the protected function and pass it the proper parameters.  We use these
	// becasue from main I don't have access to the root node to pass to the other function.
	// you don't need to worry about these, they are written to facilitate testing from main.cpp
	int getSize() { return getSize( root ); }
	int getLargest() 
	{ 
		TreeNode<tType>* find = findLargest(root);
		if (find != NULL) return find->element;
		cout<<"No largest element";
		return -1;
	}
	int getLeafCount() { return countLeaves(root); }
	void printShort() { printShort(root); }
	void shedLeaves() { shedLeaves( root ); }

	tType removeSuccessor( tType deleteValue ) 
	{ 
		TreeNode<tType>* toDelete = find(root, deleteValue);
		if (toDelete == NULL){
			cout<<"The value "<<deleteValue<<" is not in the tree";
			return NULL;
		}
		tType successor = removeSuccessor(deleteValue, toDelete->right);
		if (!successor)
			cout<<"There is no successor";
		return successor;
	}

	int findKthInOrder( int k ) 
	{
		TreeNode<tType>* find = findKthInOrder(root, k);
		if( find != NULL) return find->element;
		cout<<"No "<< k << "-th element";
		return -1;
	}

	tType getRelated( tType a, tType b )
	{
		TreeNode<tType>* parent = isRelated(a, b);
		if(parent != NULL) return parent->element;
		cout<<"No ancestral relation";
		return -1;
	}

	int getWidth() { int height; return getWidthHeight(root, height); }
	bool insert( tType x ) {return insert(x, root);}
	void printTree() {printTree( root, "", '>' );}
};

//Function: getSize
//use: Recursively returns the size of the tree
//Parameters: takes a TreeNode(starts with root), then passes the left nodes, then the right nodes
//Complexity is: O(n), as every node must be hit
//Worst case is: O(n), as every node must be hit
template <class tType>
int BinarySearchTree<tType>::getSize(TreeNode<tType> * t)
{
	int s = 1; //initialize the size to one, as each node is worth one

	if (!t) //if we've hit null, return 0
	{
		return 0;
	}

	if (t->left) //if the node has a left, move to that left and add the sizes
	{
		s += getSize(t->left);
	}

	if (t->right) //if the node has a right, move to that right and add the sizes
	{
		s += getSize(t->right);
	}

	return s; //return the size, which will add one for each node on the way up to what s is
}

//Function: findLargest
//use: Recursively finds the largest node in the tree
//Parameters: takes a TreeNode(starts with root), then goes as far right as possible
//Complexity is: O(log n) for both balanced and not balanced, as only one direction needs to be traveled (right)
template <class tType>
TreeNode<tType>* BinarySearchTree<tType>::findLargest(TreeNode<tType>* t)
{
	if (!t->right)
	{
		return t;
	}

	return findLargest(t->right);
}

//Function: countLeaves
//Use: Recursively counts the number of leaf nodes
//Complexity: O(n) because every node must be hit
template <class tType>
int BinarySearchTree<tType>::countLeaves( TreeNode<tType>* t )
{
	if (!t)
	{
		return 0;
	}

	int count = 0;

	count += countLeaves(t->left);
	count += countLeaves(t->right);

	if (!t->left && !t->right)
	{
		return 1;
	}

	return count;
}

//Function: printShort
//Use: Recursively prints the nodes from smallest to largest
//Complexity: O(n) because every node must be hit
template <class tType>
void  BinarySearchTree<tType>::printShort( TreeNode<tType>* t )
{
	if (!t)
	{
		return;
	}

	printShort(t->left);

	cout << t->element << ", ";

	printShort(t->right);

	return;
}

//Function: shedLeaves
//Use: Recursively drops every leaf
//Complexity: O(n) because every leaf(thus, every node) must be hit
template <class tType>
void BinarySearchTree<tType>::shedLeaves(TreeNode<tType>*& t)
{
	if (t == root)
	{
		if (!t->left && !t->right)
		{
			t = NULL;
		}
	}

	if (t->left)
	{
		if (!t->left->left && !t->left->right)
		{
			t->left = NULL;
		}

		else
			shedLeaves(t->left);
	}

	if (t->right)
	{
		if (!t->right->left && !t->right->right)
		{
			t->right = NULL;
		}

		else
			shedLeaves(t->right);
	}
}

//Function: removeSuccessor
//Use: Recursively removes the next (in-order) node in the tree
//Complexity: O(log n) because you should only have to traverse down the left side
//Could be O(n) in an unbalanced tree
template <class tType>
tType BinarySearchTree<tType>::removeSuccessor(tType deleteValue, TreeNode<tType>*& t)
{
	if (!t)
	{
		return 0;
	}

	if (!t->left)
	{
		if (!t->right)
		{
			deleteValue = t->element;
			t = NULL;
		}

		else
		{
			TreeNode <tType> *temp = t;
			t = find(root, deleteValue);
			deleteValue = temp->element;

			if (t->right != temp)
			{
				t = t->right;
			}

			if (t->left != temp && t->left)
			{
				t = t->left;
			}

			if (temp-> element > t->element)
			{
				t->right = temp->right;
			}

			else
			{
				t->left = temp->right;
			}
		}
	}

	else
	{
		return removeSuccessor(deleteValue, t->left);
	}

	return deleteValue;
}

//Function: findKthInOrder
//Use: Recursively finds the nth sized node
//Complexity: O(n^2) because every node must be viewed twice
template <class tType>
TreeNode<tType>* BinarySearchTree<tType>::findKthInOrder( TreeNode<tType>* t, int k )
{
	if (!t)
	{
		return NULL;
	}

	int size;

	if (!t->left && !t->right)
	{
		size = 0;
	}

	else
	{
		size = getSize(t->left);
	}

	if ((size + 1) == k)
	{
		return t;
	}

	else if ((size + 1) < k)
	{
		return findKthInOrder(t->right, k - (size + 1));
	}

	else
	{
		return findKthInOrder(t->left, k);
	}
}

//Function: isRelated
//Use: Recursively sees if two nodes are in the same branch
//Complexity: O(log n) in a balanced tree, as only one branch must be searched
//Could be O(n) in an unbalanced tree, as the whole tree might need to be checked (if the tree has n length/height)
template <class tType>
TreeNode<tType>* BinarySearchTree<tType>::isRelated( tType a, tType b )
{
	TreeNode<tType>* A = find(root, a);
	TreeNode<tType>* B = find(A, b);

	if (!B)
	{
		B = find(root, b);
		A = find(B, a);

		if (!A)
		{
			return NULL;
		}

		return B;
	}

	return A;
}

//Function: getWidthHeight
//Use: Recursively finds the longest path between two nodes in the tre
//Complexity: O(n) because every node must be checked
template <class tType>
int BinarySearchTree<tType>::getWidthHeight(TreeNode<tType>* t, int & height)
{
	if (!t)
	{
		height = 0;
		return 0;
	}

	int LH = 0, RH = 0;

	int leftW = getWidthHeight(t->left, LH);
	int rightW = getWidthHeight(t->right, RH);
	height = max(LH, RH) + 1;


	return max(LH + RH + 1, max(rightW, leftW));
}

// inserts a node into the tree rooted at t
// returns true if the insertion is successful (duplicated are not allowed, so returns false)
// complexity is O(log n) for a balanced tree because the height is log n
// worst case is O(n) because the height could be n
template <class tType>
bool BinarySearchTree<tType>::insert(tType& data, TreeNode<tType>*& t)
{
	if( t == NULL )
	{
		t = new TreeNode<tType>( data, NULL, NULL );
		if (t == NULL) return false;
		return true;
	}
	if (data==t->element) return false;  // ignores duplicates
	if( data < t->element ) return insert( data, t->left );
	return insert( data, t->right );
}


// seaches for a value in the tree rooted at curr
// returns a pointer to the node if successful, otherwise it returns NULL
// complexity is O(log n) for a balanced tree because the height is log n
// worst case is O(n) because the height could be n
template <class tType>
TreeNode<tType>* BinarySearchTree<tType>::find( TreeNode<tType>* t, tType value )
{
	if (t == NULL)
		return NULL;
	if (t->element == value)
		return t;
	if (value < t->element)
		return find(t->left, value);
	return find(t->right, value);
}


// prints tree rooted at t.  The string indent is a string of blanks to print before each node
// to show the depth.  The char direction is a / indicating it is the right child of the parent
// or a \ indicating it is the left child of the parent.  For the root, direction is a >.
// complexity is O(n) regardless of height because every node must be displayed
template <class tType>
void BinarySearchTree<tType>:: printTree( TreeNode<tType>* t, string indent, char direction )
{  
	if (t==NULL) return;
	printTree(t->right, indent+"  ", '/');
	cout <<indent << direction<< t->element << endl;
	printTree(t->left, indent+"  ", '\\');
}