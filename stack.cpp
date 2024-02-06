#include <iostream>
#define MAX 20  //to define the size of the stack

using namespace std;

class Stack{
  int* numbers ; 
  int top;
  public:
  Stack();
  ~Stack();
  bool isEmpty();
  bool isFull();
  void push(int num);
  void clear();
  int pop();
  int topElement();
  int size();
  void print();
  void reverse();
  bool isFound(int key);
  int getMinimum();
  int getMaximum();

};

 // ..................................................................Notes.....................................................................

   /*
        - stack is LIFO( Last In First Out ):
        - the top hold the index of last element add to the stack.
       
        Stack :index
        +---+ 
        | 3 | -  2  (top)
        +---+    
          |
        +---+   
        | 2 | -  1
        +---+  
          |
        +---+   
        | 1 | -  0  (first element )
        +---+    


   */

  

  // .................................................methods implementaions...............................................................

//constructor
 Stack::Stack(){
 numbers = new int[MAX];// to make it dynamic
  top = -1;
 }

//distrauctor
Stack::~Stack()
{
   delete numbers;
}


// returns true if stack is empty else false.
bool Stack::isEmpty()
{
      return (top == -1);
}

//check if stack full
bool Stack::isFull()
{
      return (top == MAX - 1);
}

//to insert an element into the stack
void Stack::push(int num)
{
  if(isFull()) cout<<"Stack Overflow"<<endl;
  else
  {
    numbers[++top] = num ;
  }
}

//clear the stack
void Stack::clear()
{
  top = -1 ;
}

 // to remove a top element from the stack
 int Stack::pop()
 {
    if(isEmpty())
    {
       cout<<"Stack Is Empty"<<endl;
       return -1;
    }
    else{
       return numbers[top--];
    }
 }

//Returns the top element of the stack.
int Stack::topElement()
{
    if(isEmpty()) 
    {
      return -1;
    }
    else
    {
      return numbers[top];
    }
}

// return the number of elements in the stack
int Stack::size()
{
  if(isEmpty()) return 0;
  else
  {
    return (top + 1);
  }
}

//print stack elements
void Stack::print()
{
  if(isEmpty())
  {
    cout<<"Stack Is Empty"<<endl;
  }
  else
  {
    for(int i = 0 ; i <= top ; i++)
    {
      cout<<numbers[i]<<" ";
    }
    cout<<endl;
  }
}

    void Stack::reverse() {
        int n = size();
        int* tmp = new int[n]; 
        for (int i = 0; i < n; i++) {
            tmp[i] = pop();
        }
        for (int i = 0; i < n; i++) {
            push(tmp[i]); 
        }
        delete[] tmp; // Free the temporary array
    }


  //check if the number is exist or not
  bool Stack::isFound(int key)
  {
     bool res = false;
     for(int i = 0 ; i<= top ;i++)
     {
       if(numbers[i] == key)
       {
        res = true;
       }
     }
     return res;
  }

  int Stack::getMinimum()
  {
        int min = INT_MAX;
      
        for(int i = 0 ; i<= top ;i++)
        {
          if(min > numbers[i])
          {
            min = numbers[i];
          }
        }
          return min;
      }

      int Stack::getMaximum()
 {
      int max = INT_MIN;
    
      for(int i = 0 ; i<= top ;i++)
      {
        if(max < numbers[i])
        {
           max = numbers[i];
        }
       }
         return max;
    }

int main(){
Stack myStack; 

  int choice;
  do {
    cout << "\nChoose an operation on the linked list:\n";
    cout << "1. Push to the stack\n";
    cout << "2. pop from the stack\n";
    cout << "3. Count the elements in the stack\n";
    cout << "4. Get the top element\n";
    cout << "5. Print all elements in the stack\n" ;
    cout << "6. Reverse the stack\n";
    cout << "7. Get Maximum\n";
    cout << "8. Get Minimum\n";
    cout << "9. Search for element\n";
    cout << "0. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        int value;
        cout << "Enter value to push to the stack: ";
        cin >> value;
        myStack.push(value);
        break;
      }
      case 2:
        myStack.pop();
        break;
      case 3:
        cout << "Number of elements: " << myStack.size() << endl;
        break;
      case 4: {
        cout<<"the top element is: " <<myStack.topElement() << endl;
        break;
      }
     
      case 5: {
        myStack.print();
        break;
      }
      case 6: {
       myStack.reverse();
       cout<< "Reversed Stack " << endl;
        break;
      }
      case 7:
        cout << "Maximum value in the list: " << myStack.getMaximum() << endl;
        break;

      case 8:
        cout << "Minimum value in the list: " << myStack.getMinimum() << endl;
        break;

      case 9:
        int key;
        cout << "Enter key to search: ";
        cin >> key;
        cout << (myStack.isFound(key) ? "Found" : "Not Found") << endl;
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
