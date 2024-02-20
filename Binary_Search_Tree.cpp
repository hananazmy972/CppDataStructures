#include <iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* left;
   Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class BSTree{
 public:
 Node* root;
 BSTree();
 bool IsEmpty();
 void insert(int data);
 int maxDepth(Node* root);
 void deleteNode(Node*& root,int k);
 void printInorder(Node* myroot);
 void printPreorder(Node* myroot);
 void printPostorder(Node* myroot);
 int countNodes(Node* myroot);
 int maxNode(Node* myroot);//traverse the node from root to the right recursivly return the node whose left is NULL
 int minNode(Node* myroot);//traverse the node from root to the left recursivly  return the node whose right is NULL
 bool isFound(int k);
 //to do
 void deleteTree(); 

};

// ..................................................................Notes...............................................................

    //   A Binary Search Tree (BST) is a hierarchical data structure where each node has at most two children, referred to as
    //   the left child and the right child. The key in each node must be greater than or equal to any key stored in the left 
    //   subtree and less than or equal to any key stored in the right subtree.

    /*
        Binary Search Tree (BST):
                  4
                /   \
               2     6
              / \   / \
             1   3 5   7
    */

  // .................................................methods implementaions...............................................................
BSTree::BSTree()
{
   root = NULL;
}
bool BSTree:: IsEmpty()
{
    return (root == NULL);
}

void BSTree::insert(int data)
{
    Node* mynode = new Node(data);
    Node* temp1 = root ;
    Node* temp2 = NULL ;
    
    if(IsEmpty())
    {
       root = mynode;
       return;
    }
    while(temp1 != NULL)
    {
        temp2 = temp1;
        if(data <= temp1->data)
        {
            temp1 = temp1->left;
        }
        else
        {
           temp1 = temp1->right; 
        }
    }
    //temp 2 has the right position 
    if(data<=temp2->data)
    {
        temp2->left = mynode;
    }
    else{
        temp2->right = mynode;
    }
}

//calc the maximuam depth or height of a tree
int BSTree::maxDepth(Node* myroot)
{
    if(myroot == NULL)
    {
        return 0 ;
    }
    else
    {
    int ldepth = maxDepth(myroot->left);
    int rdepth = maxDepth(myroot->right);

    if (ldepth > rdepth)
            return (ldepth + 1);
        else
            return (rdepth + 1);
    }
}


//delete sepecific node 
// (1-tree empty 2-search in right suptree 3- search left suptree 4- root is the node to delete)
// when the root is the node to delete 
// 1-have one child or not have
// 2-two children
// -need to find succesor (min in right subtree or max in left subtree)

void BSTree::deleteNode(Node*& myroot, int k)
{
    // base case
    if (myroot == NULL)
    {
        return;
    }

    // Recursive calls for ancestors of the node to be deleted
    if (k > myroot->data)
    {
        deleteNode(myroot->right, k);
    }
    else if (k < myroot->data)
    {
        deleteNode(myroot->left, k);
    }
    else
    {
        // We reach here when root is the node to be deleted.

        // case 1: the node has one child (if it does not have, the root will be NULL)
        if (myroot->left == NULL)
        {
            // has right child
            Node* temp = myroot->right;
            delete myroot;
            myroot = temp;
        }
        else if (myroot->right == NULL)
        {
            // has left child
            Node* temp = myroot->left;
            delete myroot;
            myroot = temp;
        }
        // case 2: the node has two children
        else
        {
            Node* succParent = myroot;
            Node* succ = myroot->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != myroot)
            {
                succParent->left = succ->right;
            }
            else
            {
                succParent->right = succ->right;
            }

            myroot->data = succ->data;
            delete succ;
        }
    }
}


void BSTree::printInorder(Node* myroot)
{
    if(myroot == NULL){
        return;
    }
     //left visit right
     printInorder(myroot->left);
     cout<<myroot->data<<" ";
     printInorder(myroot->right);
}

void BSTree::printPreorder(Node* myroot)
{
    if(myroot == NULL){
        return;
    }
     //visit left right
     cout<<myroot->data<<" ";
     printPreorder(myroot->left);
     printPreorder(myroot->right);
}

void BSTree::printPostorder(Node* myroot)
{
    if(myroot == NULL){
        return;
    }
     //left right visit
     printPostorder(myroot->left);
     printPostorder(myroot->right);
      cout<<myroot->data<<" ";
}

int BSTree::countNodes(Node* myroot)
{
  
    if(myroot == NULL){
        return 0;
    }
    else{
      int count = 1; 
     //left visit right
     count += countNodes(myroot->left);
     count += countNodes(myroot->right);
     return count;
 
    }
}

int BSTree::maxNode(Node* myroot)
{
    if(myroot == NULL)
    {
        cout<<"Your Tree Is Empty"<<endl;
        return -1;
    }
    else
    {
        Node* temp = myroot;
        while(temp->right != NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }
}

int BSTree::minNode(Node* myroot)
{
    if(myroot == NULL)
    {
        cout<<"Your Tree Is Empty"<<endl;
        return -1;
    }
    else
    {
        Node* temp = myroot;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }
}
bool BSTree::isFound(int k)
{
    Node* temp = root;
     if(IsEmpty())
     {
       cout<<"Your Tree Is Empty"<<endl;
        return false;
     }
     else
     {
        while(temp != NULL)
        {
            if(temp->data > k)
            {
                temp = temp->left;
            }
            else if(temp->data < k)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
     }
}
void BSTree::deleteTree() {
    // Implementing postorder traversal for deletion
    while (root != NULL) {
        deleteNode(root, root->data);
    }
}

int main(){
 BSTree t1;

    int choice;
    int data;

    do {
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Print Inorder\n";
        cout << "4. Print Preorder\n";
        cout << "5. Print Postorder\n";
        cout << "6. Count Nodes\n";
        cout << "7. Find Maximum Node\n";
        cout << "8. Find Minimum Node\n";
        cout << "9. Check if a value is present\n";
        cout << "10. Find Tree Height\n";
        cout << "11. Delete Tree\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                t1.insert(data);
                break;

            case 2:
                cout << "Enter data to delete: ";
                cin >> data;
                t1.deleteNode(t1.root, data);
                break;

            case 3:
                cout << "Inorder Traversal: ";
                t1.printInorder(t1.root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder Traversal: ";
                t1.printPreorder(t1.root);
                cout << endl;
                break;

            case 5:
                cout << "Postorder Traversal: ";
                t1.printPostorder(t1.root);
                cout << endl;
                break;

            case 6:
                cout << "Number of nodes: " << t1.countNodes(t1.root) << endl;
                break;

            case 7:
                cout << "Maximum Node: " << t1.maxNode(t1.root) << endl;
                break;

            case 8:
                cout << "Minimum Node: " << t1.minNode(t1.root) << endl;
                break;

            case 9:
                cout << "Enter value to check: ";
                cin >> data;
                cout << (t1.isFound(data) ? "Value found" : "Value not found") << endl;
                break;

            case 10:
                cout << "Tree Height: " << t1.maxDepth(t1.root) << endl;
                break;

            case 11:
                t1.deleteTree();
                cout << "Tree deleted.\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
