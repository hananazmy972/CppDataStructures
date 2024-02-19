#include <iostream>
#define MAX 20

using namespace std;
//first in  first out
class Queue{
  int numbers[MAX];
  int rear;
  int front;
  public:
  Queue();
  bool isEmpty();
  bool isFull();
  bool isFound(int key);
  void enqueue(int n);
  int dequeue();
  void display();
  int count();
  void reverse();
  int getMinimum();
  int getMaximum();

};
// ..................................................................Notes.....................................................................

/*
    - Circular Queue is  FIFO (First In First Out) 
    - It has a front and rear, and elements are enqueued at the rear and dequeued from the front.
    - Unlike a linear queue, a circular queue allows efficient use of memory by reusing the space.
    - Enqueue: Add an element to the rear of the queue.
    - Dequeue: Remove an element from the front of the queue.
    - Overflow: Trying to add an element to a full queue.
    - Underflow: Trying to remove an element from an empty queue.
   
    Circular Queue:
    Front    Rear
      |       |
    +---+---+---+---+---+
    | 0 | 1 | 2 | 3 | 4 |
    +---+---+---+---+---+
             |
      Front and Rear point to the current positions for enqueue and dequeue operations.

*/




  // .................................................methods implementaions...............................................................

//constructor
Queue::Queue()
{
    front = rear = -1;
}

//check if Queue is empty
bool Queue::isEmpty()
{
    return (front == -1 && rear == -1);
}

//check if queue is full
bool Queue::isFull()
{
  return((front== 0 && rear == MAX-1) || (front == rear +1));
}

//check if an ele,ent exict
bool Queue::isFound(int key){
  bool res = false; int i;
    for( i = front ; i != rear ; i= (i+1)%MAX)
    {
      if(numbers[i] == key)
      {
        res = true ;
        break;
      }
    }
    if(numbers[i] == key)
      {
        res = true ;
      }  
}

//input elemnt to queue  (by moving rear)
void Queue::enqueue(int n)
{
  if(isFull()) cout<<"Error :OVer Flow"<<endl;
  else
  {
    if(isEmpty())
    {
      front = 0;
    }
    rear = (rear+1) % MAX;
    numbers[rear] = n;
  }
}
//delete element from queue (by moving front)
int Queue::dequeue()
{
   int n;
   if(isEmpty()) cout<<"Under Flow "<<endl;
   else
   {
    n = numbers[front];
    if(front == rear)
    {
      front = rear = -1;
    }
    else
    {
      front = (front+1) % MAX;
    }
   }
    return n; 
}

//print queue elemnts
void Queue::display(){
  if(isEmpty()) cout<<"Your Queue is Empty"<<endl;
  else
  {
    int i ;
    for(i = front ; i != rear ; i= (i+1)%MAX)
    {
      cout<<numbers[i]<<" ";
    }
    cout<<numbers[i]<<" ";
    cout<<endl;
  }
}
//count queue elemnts
int Queue::count(){
  if(isEmpty()) return 0 ;
  else
  {
   int count = 1;
    for(int i = front ; i != rear ; i= (i+1)%MAX)
    {
      count++;
    } 
    return count;
  }
}
// Reverse the queue
void Queue::reverse() {
  int counter = count();
  int* tempArr = new int[counter];
  
  for (int i = 0; i < counter; i++) {
    tempArr[i] = this->dequeue();
  }

  for (int i = counter - 1; i >= 0; i--) {
    this->enqueue(tempArr[i]);
  }

  delete[] tempArr;
}

// Get the minimum element in the queue
int Queue::getMinimum() {
  if (isEmpty()) {
    cout << "Queue is empty." << endl;
    return -1; 
  }
  int i;
  int min = numbers[front];
  for (i = front + 1; i != rear; i = (i + 1) % MAX) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }
   if (numbers[i] < min) {
      min = numbers[i];
    }
  return min;
}

// Get the maximum element in the queue
int Queue::getMaximum() {
  if (isEmpty()) {
    cout << "Queue is empty." << endl;
    return -1; 
  }
  int i;
  int max = numbers[front];
  for ( i = front + 1; i != rear; i = (i + 1) % MAX) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  if (numbers[i] > max) {
      max = numbers[i];
    }
  return max;
}


int main(){
  Queue q1;
  int choice;

  do {
    cout << "Please Choose an Option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Reverse" << endl;
    cout << "5. Get Minimum" << endl;
    cout << "6. Get Maximum" << endl;
    cout << "0. Exit" << endl;
    cout << "Your Choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        int num;
        cout << "Enter the number to enqueue: ";
        cin >> num;
        q1.enqueue(num);
        break;
      }
      case 2: {
        int removed = q1.dequeue();
        cout << "Dequeued: " << removed << endl;
        break;
      }
      case 3:
        q1.display();
        break;
      case 4:
        q1.reverse();
        cout << "Queue reversed." << endl;
        break;
      case 5:
        cout << "Minimum Element: " << q1.getMinimum() << endl;
        break;
      case 6:
        cout << "Maximum Element: " << q1.getMaximum() << endl;
        break;
      case 0:
        cout << "Exiting the program." << endl;
        break;
      default:
        cout << "Invalid option. Try again." << endl;
        break;
    }
  } while (choice != 0);

return 0;
}