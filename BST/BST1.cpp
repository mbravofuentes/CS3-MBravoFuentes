#include <iostream>
#include <iomanip>
using namespace std;
#ifndef BST
#define BST

class BT
{
private:
	struct node
	{
		char data;
		node* left;
		node* right;
	};
	node* root;
	bool found;
	struct node;
	int nEndNodeCount;		// HELPER TO HOLD LEAF COUNT INTEGER
public:
	BT();			//Constructor
	bool isEmpty() const { return root == NULL; }		//Check for empty
	void insert(char);									//Insert item in BST
	void preorder();									//Preorder traversing driver
	void preorderTrav(node*);							//Preorder traversing
	void Delete(char);									//Delete a Node
	bool Search(char);									//Perform a Search
	void LeafCount(node*);								//Counts number of leaves in BST
	int getLeafCount() { return nEndNodeCount; }		// Helper to return integer of leaf nodes
	bool Siblings(char);								// Finds siblings of a node
};

#endif // !BST
BT::BT()
{
	root = NULL;
}

//Insert new in BST
void BT::insert(string d)
{
	node* t = new node;
	node* parent;

	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	if (isEmpty())
		root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}
		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

//Function - Preorder travesing driver
void BT::preorder()
{
	preorderTrav(root);
}
//Function - Preorder travesing
void BT::preorderTrav(node* p)
{

		while (p != NULL)
		{
			cout << setw(6) << p->data;						// DISPLAY NODE

			if (p->left != NULL)							// CHECK FOR LEFT CHILD
			{
				cout << setw(14) << p->left->data;
			}
			else
			{
				cout << setw(15) << "NIL";
			}
			if (p->right != NULL)							// CHECK FOR RIGHT CHILD
			{
				cout << setw(16) << p->right->data << endl;
			}
			else
			{
				cout << setw(16) << "NIL" << endl;
			}

			preorderTrav(p->left);							// RECURS LEFT
			preorderTrav(p->right);							// RECURS RIGHT
			return;
		}

}

// Function - Binary Search
bool BT::Search(char searchN)
{
	bool found = false;
	node *temp = root;

	while (!found && temp != NULL)
	{
		if (searchN < temp->data)			// GO LEFT
		{
			temp = temp->left;
		}
		else if (searchN > temp->data)		// GO RIGHT
		{
			temp = temp->right;
		}
		else
		{
			found = true;
			cout << endl << "Node Info" << setw(16) << "Left Child" << setw(16) << "Right Child" << endl;
			cout << setw(6) << temp->data;										// PRINT NODE

			if (temp->left != NULL)												// CHECK FOR LEFT CHILD
			{
				cout << setw(14) << temp->left->data;
			}
			else
			{
				cout << setw(15) << "NIL";
			}
			if (temp->right != NULL)												// CHECK FOR RIGHT CHILD
			{
				cout << setw(16) << temp->right->data << endl;
			}
			else
			{
				cout << setw(16) << "NIL" << endl;
			}
		}
	}
	if (!found)
	{
		cout << endl << "NODE " << '"' << searchN << '"' << " IS NOT FOUND IN THE BST!" << endl;				// NODE NOT FOUND IN BST
	}
	return found;
}

// FUNCTION DELETE NODE WIITH 3 OPTIONS
void BT::Delete(char item)
{
	node *x = root;
	node *parent = 0;
	found = false;

	while (!found && x != 0)			// SEARCH FOR NODE
	{
		if (item < x->data)		// GO LEFT
		{
			parent = x;
			x = x->left;
		}
		else if (x->data < item)  // GO RIGHT
		{
			parent = x;
			x = x->right;
		}
		else
		{
			found = true;
		}
	}

	if (!found)
	{
		cout << "The Node " << item << " is NOT IN THE BST!" << endl;		// NODE NOT FOUND IN BST
		return;
	}
	else
	{
		if (x->left && x->right == NULL)				// NO CHILDREN -> DELETE NODE
		{
			delete x;
			return;
		}
		if (x->left != NULL && x->right != NULL)		// DELETE NODE WITH 2 CHILDREN
		{
			node*xSucc = x->right;
			parent = x;

			while (xSucc->left != NULL)
			{
				parent = xSucc;
				xSucc = xSucc->left;
			}

			x->data = xSucc->data;
			x = xSucc;
		}
	}

	node*subtree = x->left;						// DELETE NODE WITH 0 OR 1 CHILDREN

	if (subtree == NULL)
	{
		subtree = x->right;
	}
	if (parent == NULL)
	{
		root = subtree;
	}
	else if (parent->left == x)
	{
		parent->left = subtree;
	}
	else
	{
		parent->right = subtree;
		delete x;
	}
}

// LEAF COUNT FUNCTION
void BT::LeafCount(node*pCurNode)
{
	if (pCurNode == NULL)
	{
		pCurNode = root;
		nEndNodeCount = 0;						// INITIALIZE COUNTER
	}

	if (!pCurNode->left && !pCurNode->right)	// IF LEAF, ADD TO COUNTER
	{
		nEndNodeCount++;
	}
	else
	{
		if (pCurNode->left != NULL)		// RECURSE LEFT
			LeafCount(pCurNode->left);
		if (pCurNode->right != NULL)	// RECURSE RIGHT
			LeafCount(pCurNode->right);
	}
}

// SIBLING FUNCTION
bool BT::Siblings(char sib)
{
	node *p = root;
	bool found = false;

	while (p != NULL)
	{
		while (!found && p->data != NULL)
		{
			if (sib < p->data)				// SEARCH LEFT SUBTREE
			{
				if (p->data != sib && p->left == NULL && p->right == NULL)			// NODE NOT FOUND IN BST
				{
					cout << "The node " << sib << " is NOT IN THE BST!" << endl;
					return found;
				}
				if (p->left->data == sib && p->right != NULL)				// NODE FOUND IN LEFT SUBTREE & SIBLING FOUND
				{
					found = true;
					cout << endl << "The sibling of " << sib << " is " << p->right->data << "." << endl;
					return found;
				}
				else                         // NODE NOT FOUND YET IN LEFT SUBTREE
				{
					p = p->left;				// GO LEFT
				}
			}
			if (sib > p->data)					// SEARCH RIGHT SUBTREE IF NODE GREATER THAN ROOT
			{
				if (p->data != sib && p->right == NULL && p->left == NULL)					// NODE NOT FOUND IN BST
				{
					cout << "The node " << sib << " is NOT IN THE BST!" << endl;
					return found;
				}
				if (p->right->data == sib && p->left != NULL)					// NODE FOUND IN RIGHT SUBTREE & SIBLING FOUND
				{
					found = true;
					cout << endl << "The sibling of " << sib << " is " << p->left->data << "." << endl;
					return found;
				}
				else                        // NODE NOT FOUND YET IN RIGHT SUBTREE
				{
					p = p->right;			// GO RIGHT
				}
			}
			if (sib == p->data)				// NODE IS FOUND, BUT HAS NO SIBLINGS
			{
				found = true;
				cout << endl << "The Node " << sib << " has NO SIBLINGS!" << endl;
				return found;
			}
		}
	}
	return found;
}
void fillTree(BT b)//Line 368
{
    ifstream file;
    file.open("CSI.txt");
    if(!file) {
        cout<<" Error opening file. " << endl;
    }
    //variables used to load data into the tree
    string word;
    while(file >> word)
    {

        cout << word;
        //b.insert(p);
        (*b).insert(p); //Line 384
    }
    file.close();
}

int main()
{
	BT b;
	int ch, num;
	char tmp, searchN, item, sib;

	system("cls");
	cout << "-----------Menu-------------" << endl;
	cout << endl;
	cout << "1. Insert node(s) in BST" << endl;
	cout << "2. Pre-order Traversal" << endl;
	cout << "3. Search BST" << endl;
	cout << "4. Delete Node in BST" << endl;
	cout << "5. Perform Leaf Count" << endl;
	cout << "6. Find Siblings of a Node" << endl;
	cout << "7. Quit" << endl << endl;

	do
	{
		cout << endl << "Enter Your Choice <1..7> ?";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter number of nodes to insert: ";
			cin >> num;
			for (int i = 0; i<num; i++)
			{
				cout << endl;
				cout << "Enter node: ";
				cin >> tmp;
				b.insert(tmp);
			}
			break;

		case 2:
			cout << endl;
			cout << "Pre-Order Traversal" << endl;
			cout << endl << "Node Info" << setw(16) << "Left Child" << setw(16) << "Right Child" << endl;
			b.preorder();		//call to Preorder traversing driver
			break;

		case 3:
			cout << endl;
			cout << "Search BST" << endl;
			cout << "Enter Node to Search: ";
			cin >> searchN;
			b.Search(searchN);	// CALL SEARCH NODE
			break;

			case 4:
			cout << endl;
			cout << "Delete Node in BST" << endl;
			cout << "Enter Node to Delete: ";
			cin >> item;
			b.Delete(item);		// CALL DELETE A NODE
			break;

		case 5:
			b.LeafCount(NULL);				// CALL FOR LEAF COUNT
			cout << endl;
			cout << "Leaf Count" << endl;
			cout << "There are " << b.getLeafCount() << " leaves in the BST!" << endl;  // RETURN LEAF COUNT
			break;

		case 6:
			cout << endl;
			cout << "Siblings Info" << endl;
			cout << "Enter node to check for sibling: ";
			cin >> sib;
			b.Siblings(sib);			// CALL FIND CHECK FOR SIBLINGS
			break;

		case 7:
			cout << endl << "Good-Bye!" << endl << endl;
			return 0;
			//break;

		case 8:
		default:
			cout << endl << "Invalid Data Entry" << endl;
		}
	} while (ch != 7);

	system("pause");
	return 0;
}
