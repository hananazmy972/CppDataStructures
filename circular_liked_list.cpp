#include <iostream>
using namespace std;

// CREATE NODE AS A CLASS
class Node{
  public:
  int data ;
  Node* next;      
};

//CREATE A LINKED LIST
class circularList{
     public:
     Node* head;
     circularList();
     bool isEmpty();
     bool isFound(int key);
     void addToHead(int value);
     void addToTail(int value);
     void deleteFromHead();
     void deleteFromTail();
     void Printlist();
     void Printlist2();
     int CountNodes();
     void reverse();
     int getMinimum();
     int getMaximum();
};
  // ..................................................................Notes...............................................................
    //    Unlike a singly linked list, which has a NULL pointer at the end of the list
    //    , a circular linked list has a pointer that points back to the first node in the list. 

    /*
    Circular Linked List:
    head -> Node1 -> Node2 -> ... -> LastNode -> head 

    Example:
    head -> [value1 | next] -> [value2 | next] -> ... -> [lastValue | head]
    */


  // .................................................methods implementaions...............................................................

 //constructor to make the head pointer point to NULL
 circularList::circularList(){
      head = NULL;
 }

 //check if the node is exist or not
    bool circularList::isFound(int key)
    {
       
     bool res = false;
     Node* temp = head;
     do
     {
       if(temp->data == key)
       {
          res = true;
          break;
       }
         temp = temp->next ;
    }
     while(temp != head);
    return res;    
    }

 //Check if the list is empty.
 bool circularList::isEmpty(){
      return (head == NULL);
}

 void circularList::addToHead(int value){
    Node* mynewnode = new Node;
    mynewnode->data = value;
    mynewnode->next = head;
    //case 1 list is empty
    if(head == NULL)
    {
       head = mynewnode;
       mynewnode->next = mynewnode;
    }
    else
    {
        Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = mynewnode;
        head = mynewnode;
    }
}

    void circularList::addToTail(int value){
         Node* mynewnode = new Node;
         mynewnode->data = value;
         mynewnode->next = head;
         if(head == NULL )
         {
            head = mynewnode;
            mynewnode->next = mynewnode;
         }
         else
         {
            Node*  temp =head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = mynewnode;
         }
    }

    void circularList::deleteFromHead()
    {
        //empty list
        if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        //one node list
        else if(head->next == head)
        {
            delete head;
            head =NULL;
        }
        //at least two nodes
        else
        {
            Node* temp = head ,*delp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
            delete delp;
        }
    }

    void circularList::deleteFromTail()
    {
        //empty list
        if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        // one node list
        else if(head->next == head)
        {
            delete head;
            head = NULL;
        }
        //at least two nodes
        else
        {
            Node* temp = head ,*prev = NULL;
            while(temp->next != head)
            {
                prev = temp;
                temp = temp->next;
            }
            delete temp;
            prev->next = head;
        }

    }
      //Print all Nodes
     void circularList::Printlist()
     {
        if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        else{
         Node* temp = head;
         while(temp->next != head)
         {
            cout<<temp->data<<" ";
            temp = temp->next;
         }
         cout<<temp->data;
         cout<<endl;
        }
     }

     //print list using do while
         void circularList::Printlist2()
         {
             if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        else
        {
            Node* temp = head;
            do
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            while(temp != head);
            cout<<endl;

        }
         }

    //count the number of nodes
     int circularList::CountNodes()
     {
       if(isEmpty()) return 0;
       else
       {
        Node* temp = head;
        int count = 1;
         while(temp->next != head)
         {
            count++;
            temp = temp->next;
         }
         return count;
       }
     }

     // reverse the linked list
     void circularList::reverse()
     {
         Node* curr = head ,*temp = curr->next , *prev = NULL;
         while(temp->next != NULL)
         {
            temp = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = temp ;
         }
         head->next = prev;
         head = prev;
     }

     //return the minimum  data in the list
    int circularList::getMinimum()
    {
            if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        else
        {
            int min = INT_MAX;
            Node* temp = head;
            do
            {
              if(min > temp->data)
              {
                min = temp->data;
              }
                temp = temp->next;
            }
            while(temp != head);
            return min;
        }
    }

    //return the Maximum  data in the list
    int circularList::getMaximum()
    {
            if(head == NULL)
        {
            cout<<"YOUR LIST IS EMPTY"<<endl;
        }
        else
        {
            int max = INT_MIN;
            Node* temp = head;
            do
            {
              if(max < temp->data)
              {
                max = temp->data;
              }
                temp = temp->next;
            }
            while(temp != head);
            return max;
        }
    }
    
    int main(){

    circularList myList; 
    int choice;
    do {
        cout << "\nChoose an operation on the Circular linked list:\n";
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
            myList.Printlist();
            break;

        case 3:
            cout << "Number of nodes: " << myList.CountNodes() << endl;
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
