///////////////////////////////////////////////////////////
///////////////////Coded by: James Decker//////////////////
//////////////////////////CS 2420//////////////////////////
////Coded using Microsoft Visual Studio in January 2013////
///////////////////////////////////////////////////////////

#include "bst.h"
#include <ctime>
using namespace std;

int main()
{
    BinarySearchTree<int> tree;
    
    tree.insert(10);
    tree.insert(15);
    tree.insert(50);
    tree.insert(4);
    tree.insert(99);
    tree.insert(12);
    tree.insert(115);
    tree.insert(5);
    tree.insert(8);
    tree.insert(3);
    
    cout<<"Printing the tree\n";
    tree.printTree();
    cout<<"\nOrdered list of values in the tree: \n";
    tree.printShort();
     
    cout << "\nThe count of nodes in tree is " << tree.getSize() << endl;
    cout << "The count of leaf nodes is " <<tree.getLeafCount() <<endl;
    
    cout << "The largest value is " << tree.getLargest()<<endl;
    cout << "The smallest value is  "  << tree.findKthInOrder(1) << endl;
    cout << "The 7th smallest value is  "  << tree.findKthInOrder(7) << endl;
    cout << "The 12th smallest value is  ";
    tree.findKthInOrder(12);
     
    cout << "\nThe width of the tree is " << tree.getWidth() << endl;
    
    
    cout<<"\nFall has come, so the tree sheds its leaves \n";
    tree.shedLeaves();
    cout<<"Now it looks like: \n";
    tree.printTree();
    cout << "\nNow the count of nodes in tree is " << tree.getSize() << endl;
    
    cout<<"\nLooking at the family tree, and want to know the relation between 10 and 5\n";
    cout<<tree.getRelated(10, 5)<<" is the parent\n";
    cout<<"Looking the other way, "<<tree.getRelated(5, 10)<<" is still the parent.\n";
    
    cout<<"\nLooking at the family tree, and want to know the relation between 10 and 555 ";
    tree.getRelated(10, 555);
    
    cout<<"\nLets try out the remove successor function, lets remove the successor of 50";
    cout<<"\n50's successor is "<<tree.removeSuccessor(50);
    cout<<"\nWith it removed, the tree looks like\n";
    tree.printTree();
    
    cout<<"\nLets try with a leaf node, lets remove the successor of 5";
    cout<<"\n5's successor is ";
    tree.removeSuccessor(5);
    cout<<"\nOur tree still looks like\n";
    tree.printTree();
    
    cout<<"\nLets try with a value not in the tree, lets remove the successor of 1";
    cout<<"\n1's successor is ";
    tree.removeSuccessor(1);
    cout<<"\nOur tree still looks like\n";
    tree.printTree();
    
    
    
    cout<<"\n\n\nNow lets try making another tree to see if all the functions still work\n";
    
    BinarySearchTree<int> tree2;
    
    tree2.insert(88);
    tree2.insert(53);
    tree2.insert(37);
    tree2.insert(174);
    tree2.insert(123);
    tree2.insert(56);
    tree2.insert(87);
    tree2.insert(170);
    tree2.insert(17);
    tree2.insert(130);
    tree2.insert(15);
    tree2.insert(28);
    tree2.insert(175);
    tree2.insert(99);
    
    cout<<"Printing the tree\n";
    tree2.printTree();
    cout<<"\nOrdered list of values in the tree: \n";
    tree2.printShort();
    
    cout << "\nThe count of nodes in tree is " << tree2.getSize() << endl;
    cout << "The count of leaf nodes is " <<tree2.getLeafCount() <<endl;
    
    cout << "The largest value is " << tree2.getLargest()<<endl;
    cout << "The smallest value is  "  << tree2.findKthInOrder(1) << endl;
    cout << "The 7th smallest value is  "  << tree2.findKthInOrder(7) << endl;
    cout << "The 12th smallest value is  "  << tree2.findKthInOrder(12) << endl;
    
    cout << "The width of the tree is " << tree2.getWidth() << endl;
    
    
    cout<<"\nFall has come, so the tree is shedding its leaves \n";
    tree2.shedLeaves();
    cout<<"Now it looks like: \n";
    tree2.printTree();
    cout << "\nNow the count of nodes in tree is " << tree2.getSize() << endl;
    
    cout<<"\nLooking at the family tree, and want to know the relation between 88 and 123\n";
    cout<<tree2.getRelated(88, 123)<<" is the parent\n";
    cout<<"Looking the other way, "<<tree2.getRelated(123, 88)<<" is still the parent.\n";
    
    cout<<"\nLooking at the family tree, and want to know the relation between 37 and 170 ";
    tree2.getRelated(37, 170);
    
    cout<<"\n\nLets try out the remove successor function, lets remove the successor of 88";
    cout<<"\n88's successor is "<<tree2.removeSuccessor(88);
    cout<<"\nWith it removed, the tree looks like\n";
    tree2.printTree();
    
    
    
    cout<<"\n\n\nNow lets try making a really off balance tree to see if all the functions still work\n";
    
    BinarySearchTree<int> tree3;
    
    tree3.insert(1);
    tree3.insert(2);
    tree3.insert(3);
    tree3.insert(4);
    tree3.insert(5);
    tree3.insert(6);
    tree3.insert(7);
    tree3.insert(8);
    tree3.insert(9);
    tree3.insert(10);
    
    cout<<"Printing the tree\n";
    tree3.printTree();
    cout<<"\nOrdered list of values in the tree: \n";
    tree3.printShort();
    
    cout << "\nThe count of nodes in tree is " << tree3.getSize() << endl;
    cout << "The count of leaf nodes is " <<tree3.getLeafCount() <<endl;
    
    cout << "The largest value is " << tree3.getLargest()<<endl;
    cout << "The smallest value is  "  << tree3.findKthInOrder(1) << endl;
    cout << "The 7th smallest value is  "  << tree3.findKthInOrder(7) << endl;
    cout << "The 12th smallest value is  ";
    tree3.findKthInOrder(12);
    
    cout << "\nThe width of the tree is " << tree3.getWidth() << endl;
    
    
    cout<<"\n\nFall has come, so the tree is shedding its leaves \n";
    tree3.shedLeaves();
    cout<<"Now it looks like: \n";
    tree3.printTree();
    cout << "\nNow the count of nodes in tree is " << tree3.getSize() << endl;
    
    cout<<"\nLooking at the family tree, and want to know the relation between 9 and 1\n";
    cout<<tree3.getRelated(9, 1)<<" is the parent\n";
    cout<<"Looking the other way, "<<tree3.getRelated(1, 9)<<" is still the parent.\n";
    
    cout<<"\nLooking at the family tree, and want to know the relation between 0 and 9\n";
    tree3.getRelated(0, 9);
    
    cout<<"\n\nLets try out the remove successor function, lets remove the successor of 7";
    cout<<"\n7's successor is "<<tree3.removeSuccessor(7);
    cout<<"\nWith it removed, the tree looks like\n";
    tree3.printTree();
    
    cout<<"\nLets try it with the root, lets remove the successor of 1";
    cout<<"\n1's successor is "<<tree3.removeSuccessor(1);
    cout<<"\nWith it removed, the tree looks like\n";
    tree3.printTree();

	return 0;
}