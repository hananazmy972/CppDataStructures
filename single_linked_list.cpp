#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// CREATE NODE AS A CLASS
class Node{
  public:
  int data ;
  Node* next; 
  Node(int value) 
  {
    data = value;
    next = NULL;
  }   
};

//CREATE A LINKED LIST 
class List{
     public:
     Node* head;
     //methods declaration
     List();
     bool isEmpty();
     void AddToHead(int value);
     void Printlist();
     int CountNodes();
     bool isFound(int key);
     void AddToTail(int value);
     void Deletenode(int item);
     void reverse();
     int getMinimum();
     int getMaximum();
     int countOdd();
     int countEven();
     void lastToFirst();
     void modifyNode(int n , int value);
     void PrintListByRecursion(Node* curr);
     void ReverseListByRecursion(Node* curr); 
};
  // ..................................................................Notes...............................................................
   /*
   Linked List:
   head -> Node1 -> Node2 -> ... -> LastNode -> NULL

   Example:
   head -> [value1 | next] -> [value2 | next] -> ... -> [lastValue | NULL]
   */

  //  - Use the condition (temp != NULL) to iterate through all nodes in the list.
  //  - Use the condition (temp->next != NULL) to stop at the last node.

  // .................................................methods implementaions...............................................................
   
   //constructor to make the head pointer point to NULL
    List::List(){
      head = NULL;
     }

   //Check if the list is empty.
     bool List::isEmpty(){
      return (head == NULL);
     }


    void List::AddToHead(int value){
      Node* newnode = new Node(value);
      if(isEmpty()){
        head = newnode;
      }
      else{
        newnode->next = head;
        head = newnode;
      }
    }

    //Print all Nodes
    void List::Printlist()
    {
      if(isEmpty())
      {
          cout<<"Your list is empty \n";
      }
      else{
        Node* temp  = head;
        while(temp != NULL){
          cout<<temp->data<<" ";
          temp = temp->next;//to traverse the list
        }
        cout<<endl;
      }
    }

     //count the number of nodes
    int List::CountNodes()
    {
     int count = 0 ;
     Node* temp = head;
     while(temp != NULL){
      count++;
      temp = temp->next;
     }
     return count;
    }

    //check if the node is exist or not
    bool List::isFound(int key)
    {
     Node* temp = head;
     bool res = false;
     while(temp != NULL)
     {
      if(temp->data == key){
        res = true;
        break;
      }
      temp = temp->next;
     }
     return res;
    }

 
    
    //add node to the end of the list
    void List::AddToTail(int value)
    {
      Node* mynode = new Node(value);
      Node* temp = head;
       while(temp->next != NULL)
       {
        temp = temp->next;
       }
       temp->next = mynode;
    }

    //delete specific node
    void List::Deletenode(int item)
    {
    struct Node* temp = head, *prev; 
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == item) 
    { 
        head = temp->next; // Changed head 
        delete(temp);      // free old head memory
        return; 
    } 
    
    // Search for the node to be deleted 
    // previous node as we need to change 'prev->next
    while (temp != NULL && temp->data != item) 
    { 
        prev = temp; 
        temp = temp->next; 
    }
    
    // If key was not present in linked list 
    if (temp == NULL) 
       return; 
     // Unlink the node from linked list 
     prev->next = temp->next; 
     delete(temp); // Free memory 
} 
    
    // reverse the linked list
    void List::reverse()
    {
      if (head == NULL || head->next == NULL) {
            // If the list is empty or has only one node, no need to reverse
            return;
        }
      else{
      Node *curr = head , *prev = NULL ,*next = curr->next;
      while(next != NULL)
      {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
         head = prev;
        }
    }
     //return the minimum  data in the list
    int List::getMinimum()
    {
      if(isEmpty())
      {
        cout<<"Your List Is Empty"<<endl;
        return 0;
      }
      else{
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
    int List::getMaximum()
    {
      if(isEmpty())
      {
        cout<<"Your List Is Empty"<<endl;
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
    
    //count odd data nodes
    int List::countOdd(){
      Node* temp = head;
      int count = 0 ;
      while(temp != NULL)
      {
         if((temp->data%2) != 0){
          count++;
         }
         temp = temp->next;
      }
      return count;
    }

    //count even  data nodes
    int List::countEven(){
      Node* temp = head;
      int count = 0 ;
      while(temp != NULL)
      {
         if((temp->data%2) == 0){
          count++;
         }
         temp = temp->next;
      }
      return count;
    }
   
   //Switch the last node to the first node.
    void List::lastToFirst()
    {
      if(isEmpty())
      {
        cout<<"Your List Is Empty"<<endl;
      }
      else
      {
      Node* temp = head , *prev = NULL;
      while(temp->next != NULL){
        prev = temp ;
        temp  = temp->next;
      }
      prev->next = NULL ;
      temp->next = head;
      head = temp ;
      }
    }
    
    //Modify the node number n by this value.
    void List::modifyNode(int n , int  value)
    {
     if(isEmpty()) cout<<"Your List Is Empty"<<endl;
     else if( n > CountNodes()) cout<<"Invaild Node Number"<<endl;
     else
     {
       Node* temp = head ;
       for(int i =1 ; i< n ; i++) 
       {
       temp = temp->next ;
       }
        temp ->data = value ;
      }
    }
//Print and reverse the list by recursion algorithm
  void List::PrintListByRecursion(Node* curr)
  {
    if(curr == NULL) return; //base condition
      cout<<curr->data<<" ";
      PrintListByRecursion(curr->next);
    
  }

  void List::ReverseListByRecursion(Node* curr)
  {
      if(curr == NULL) return; //base condition
      PrintListByRecursion(curr->next);
      cout<<curr->data<<" ";
  }


int main(){
  List myList; // Create an instance of the List class

  int choice;
  do {
    cout << "\nChoose an operation on the linked list:\n";
    cout << "1. Add to Head\n";
    cout << "2. Print List\n";
    cout << "3. Count Nodes\n";
    cout << "4. Search Node\n";
    cout << "5. Add to Tail\n" ;
    cout << "6. Delete Node\n";
    cout << "7. Get Maximum\n";
    cout << "8. Get Minimum\n";
    cout << "9. Count Odd Nodes\n";
    cout << "10. Count Even Nodes\n";
    cout << "11. Move Last to First\n";
    cout << "12. Modify Node\n";
    cout << "13. Print List by Recursion\n";
    cout << "14. Reverse List by Recursion\n";
    cout << "15. Reverse List\n";
    cout << "0. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        int value;
        cout << "Enter value to add to the head: ";
        cin >> value;
        myList.AddToHead(value);
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
        myList.AddToTail(value);
        break;
      }
      case 6: {
        int item;
        cout << "Enter value to delete: ";
        cin >> item;
        myList.Deletenode(item);
        break;
      }
      case 7:
        cout << "Maximum value in the list: " << myList.getMaximum() << endl;
        break;

      case 8:
        cout << "Minimum value in the list: " << myList.getMinimum() << endl;
        break;
      case 9:
        cout << "Number of odd nodes: " << myList.countOdd() << endl;
        break;
      case 10:
        cout << "Number of even nodes: " << myList.countEven() << endl;
        break;
      case 11:
        myList.lastToFirst();
        break;
      case 12: {
        int n, value;
        cout << "Enter node number to modify: ";
        cin >> n;
        cout << "Enter new value: ";
        cin >> value;
        myList.modifyNode(n, value);
        break;
      }
      case 13:
        cout << "Linked List: ";
        myList.PrintListByRecursion(myList.head);
        cout << endl;
        break;
      case 14:
        cout << "Reversed List by Recursion: ";
        myList.ReverseListByRecursion(myList.head);
        cout << endl;
        break;
      case 15:
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
