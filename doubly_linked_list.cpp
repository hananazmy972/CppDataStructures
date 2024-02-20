#include <iostream>
using namespace std;

//create a node class
class Node{
    public:
    Node* prev ;
    int data ;
    Node* next;
};

//create a doubly linked list class
class DoublyLinkedList{
    public:
    Node* head ;
    DoublyLinkedList();
    bool isEmpty();
    bool isFound(int key);
    void addToHead(int item );
    void addToTail(int  item);
    void deleteFromHead();
    void deleteFromTail();
    void printDoublyList();
    int countNodes();
    void reverse();
    int getMinimum();
    int getMaximum();
};
  // ..................................................................Notes...............................................................
    //   A doubly linked list (DLL) is a special type of linked list in which each node contains a pointer to the previous node 
    //   as well as the next node of the linked list.
    /*
        Doubly Linked List:
        NULL <-> head <-> Node1 <-> <-> Node2 <-> ... <-> LastNode <-> NULL

        Example:
        NULL <-> head <-> [prev | value1 | next] <-> <-> [prev | value2 | next] <-> ... <-> <-> [prev | lastValue | NULL]
    */



  // .................................................methods implementaions...............................................................

//CONSTRUSCTOR
DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
}
//check if list is empty
 bool DoublyLinkedList::isEmpty(){
    return (head == NULL);
}

 //check if the node is exist or not
bool DoublyLinkedList::isFound(int key)
{
   bool res = false;
   Node* temp = head;
   while(temp != NULL)
    {
       if(temp->data == key)
       {
        res = true ;
        break;
       }
       temp = temp->next;
    }
    return res;
}

//add a new Node to head 
void DoublyLinkedList::addToHead(int item){
    Node* newnode = new Node;
    newnode->data = item;
    newnode->prev = NULL;
    if(isEmpty())
    {
        head = newnode;
       newnode->next = NULL;
       
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

//add a new node to tail
void DoublyLinkedList::addToTail(int item)
{
    Node* newnode = new Node ;
    newnode->data = item ;
    newnode->next = NULL ;
    if(isEmpty())
    {
        head = newnode;
        newnode->prev = NULL;
    }
    else{
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        
    }
}
//delete a node from head
void DoublyLinkedList::deleteFromHead(){
   if(isEmpty())
   {
     cout<<"your list is empty"<<endl;
   }
   //one node list
   else if(head->next == NULL)
   {
    delete head ;
    head = NULL;
   }
   //at least two nodes list
   else
   {
    Node* delp = head ;
    head = head->next ;
    head->prev = NULL;
    delete delp ;
   }
}
//delete a node from tail
void DoublyLinkedList::deleteFromTail()
{
    if(isEmpty())
   {
     cout<<"your list is empty"<<endl;
   }
   // one node list 
   else if(head->next == NULL)
   {
    delete head;
    head =NULL;
   }
   //at least two nodes list
   else
   {
      Node* delp = head ,*prevp =NULL;
      while(delp->next != NULL)
      {
        prevp = delp;
        delp = delp->next; 
      }
      delete delp;
      prevp->next = NULL;
   }
}

//print all nodes
void DoublyLinkedList::printDoublyList(){
     if(isEmpty())
   {
     cout<<"your list is empty"<<endl;
   }
   else
   {
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
   } 
}
//count nodes
int DoublyLinkedList::countNodes(){
    int counter = 1;
    Node* temp = head;
    if(isEmpty())
    {
        return 0;
    }
    else{
    while(temp->next != NULL)
    {
        counter++;
       temp = temp->next;
    }
     return counter;
    }
   } 

   //reverse the doubly linked list
   void DoublyLinkedList::reverse(){
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    else{
        Node* curr = head ,*temp = NULL;
        while(curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp ;
            curr = curr->prev;
        }
        if(temp != NULL)
        {
            head = temp->prev;
        }

    }
   }
   
   //return the minimum  data in the list
    int DoublyLinkedList::getMinimum()
    {
        if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
            return 0;
        }
        else
        {
            int min = INT_MAX;
            Node* temp = head;
             while(temp != NULL)
             {
              if(min > temp->data)
              {
                min = temp->data;
              }
                temp = temp->next;
             }
            return min;
        }
    }

    //return the Maximum  data in the list
    int DoublyLinkedList::getMaximum()
    {
            if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
            return 0;
        }
        else
        {
            int max = INT_MIN;
            Node* temp = head;
            while(temp != NULL)
            {
              if(max < temp->data)
              {
                max = temp->data;
              }
                temp = temp->next;
            }
            
            return max;
        }
    }
   
    int main(){
  
    DoublyLinkedList myList; 
    int choice;
    do {
        cout << "\nChoose an operation on the Doubly linked list:\n";
        cout << "1. Add to Head\n";
        cout << "2. Print List\n";
        cout << "3. Count Nodes\n";
        cout << "4. Search Node\n";
        cout << "5. Add to Tail\n" ;
        cout << "6. Delete One Node From Head\n";
        cout << "7. Delete One Node From Tail\n";
        cout << "8. Get Minimum\n";
        cout << "9. Get Maximum\n";
        cout << "10. Reverse List\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value to add to the head: ";
            cin >> value;
            myList.addToHead(value);
            break;
        }

        case 2:
            myList.printDoublyList();
            break;

        case 3:
            cout << "Number of nodes: " << myList.countNodes() << endl;
            break;

        case 4: {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            cout << (myList.isFound(key) ? "Found" : "Not Found") << endl;
            break;
        }
        
        case 5: {
            int value;
            cout << "Enter value to add to the tail: ";
            cin >> value;
            myList.addToTail(value);
            break;
        }
        case 6: {
            myList.deleteFromHead();
            break;
        }
        case 7:
            myList.deleteFromTail();
            break;

        case 8:
            cout << "Minimum value in the list: " << myList.getMinimum() << endl;
            break;

        case 9:
            cout << "Maximum value in the list: " << myList.getMaximum() << endl;
            break;

        case 10:
            myList.reverse();
            cout << "List reversed.\n";
            break;

        case 0:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
        return 0;
    }
