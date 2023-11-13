#include <iostream>
#include <string>
using namespace std;


// Do not edit the structure of the Node class
template<class Type>
class Node
{
public:
    Node(Type value) { data = value; }
    Node* nextNode;
    Node* previousNode;
    Type data;
};


template <class Type>
class LinkedList
{
public:
    // Constructor
    // Do not edit this function.
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // 5 Points
    // This function returns a pointer to the head. 
    // If head is null, return it anyway.
    Node<Type>* first()
    {
       Node<Type>* first = head;
        return first;
    }

    // 5 Points
    // This function returns a pointer to the tail. 
    // If tail is null, return it anyway.
    Node<Type>* last()
    {
        Node<Type>* last = tail;
        return last;
    }

    // 5 Points
    // This function returns true if there are no Nodes in the LinkedList.
    // It returns false if there are any number of Nodes in the LinkedList.
    bool isEmpty()
    {
      if(head == NULL)
        return true;
      else
        return false;  
    }

    // 15 Points
    // This function takes an argument of the template type Type.
    // It creates a Node with this value as the field data and places this new Node in the last position of the LinkedList.
    void addNode(Type value)
    {
     
      if(head == NULL)
      {
        head  = new Node<Type>(value);
        tail = head;
        head -> previousNode = NULL;
        head -> nextNode = NULL; 
       return;
        }
      else
      {
        Node<Type>* temp = tail;
        Node<Type>* newNode = new Node<Type>(value);
        temp -> nextNode = newNode;
        Node<Type>* prev = temp;
        temp = temp ->nextNode;
        temp -> previousNode = prev;
        temp ->nextNode = NULL;
        tail = temp;
      }
        return;
    }
    
    // 10 Points
    // This function returns how many Nodes are currently in the LinkedList.
    int size()
    {
      
      Node<Type>* current = head;
      int count = 0;
      
        while(current != nullptr)
        {
            current = current->nextNode;
          count++;
        }
        
        return count;
    }

    // 20 Points
    // The integer argument given to this function is in 0-indexed format.
    // Meaning: getNodeAtPosition(0) indicates that the first item should be returned.
    // The returned data is a pointer to the Node in that current position in the LinkedList.
    Node<Type>* getNodeAtPosition(int position)
    {
      
      Node<Type>* current = head;
        int spot = 0;
      if(position<0 || position>size()-1)
      {
          return NULL;
        }
      while(current != NULL)
        {
          if(spot == position)
          {
          return current;
            }
          spot++;
        current = current -> nextNode;
          }
      
      return NULL;
      
    }

    // 45 Points
    // The first argument to this function is the value for data of a Node to be added.
    // The second argument is the position to add it at.
    // The function will create and add the Node to the LinkedList at the requested 0-indexed position.
    void addNodeAtPosition(Type value, int position)
    {
      if(position<0 || position>size())
      {
        cout<<"Invalid Position"<<endl;
          return;
        }
      else if(isEmpty())
      {
        addNode(value);
      }
     else if(position == 0)
      {
        Node<Type>* newNode = new Node<Type>(value);
        newNode -> nextNode = head;
        newNode -> previousNode = NULL;
        head -> previousNode = newNode;
        head = newNode;
      }
    else if(position == size())
    {
        addNode(value);
      }
     else
    { 
      Node<Type>* spot = head;
      for(int i=0; i<position-1; i++)
        {
          spot=spot->nextNode;
        }
           Node<Type>* newNode = new Node<Type>(value);
          newNode -> nextNode = spot ->nextNode;
      newNode -> previousNode = spot;
      spot ->nextNode = newNode;
    
       }
      
    }



    // 20 Points
    // This function removes the Node at the provided 0-indexed position from the LinkedList. 
    // This function should also explicitly delete the Node at this position to make sure it does not get lost in memory.
    // Node pointers for other items in the list should be updated appropriately to account for this deletion.
    void deleteNodeAtPosition(int position)
    {
      if(isEmpty())
        {
        cout<<"Invalid Position"<<endl;
        return;
        }
       Node<Type>* deleteNode = NULL;
      
        if (position == 0) 
        {
            deleteNode = head;
            head = head->nextNode;
            head->previousNode = NULL;  
        }
        else if (position = size()) 
        {
            deleteNode = tail;
            tail = tail->previousNode;
            tail->nextNode = NULL;
        }
        
        else 
        {
            
            Node<Type>* spot = head;
             for(int i=0; i<position-1; i++)
                {
                    spot=spot->nextNode;
                }
            spot->previousNode->nextNode = spot->nextNode;
            spot->nextNode->previousNode = spot->previousNode;
            deleteNode = spot;
        }

        if (deleteNode != NULL) 
        {
            delete deleteNode;
        }    
      }


    // 15 Points
    // This function finds the first Node with the specified value of Type in the LinkedList.
    // The 0-indexed position of that Node is then returned.
    // If there is no Node with this value, it returns -1.
    int findNodeWithValue(Type value)
    {
        Node<Type>* temp = head;
        int pos = 0;
      if(head == NULL)
      {
        return -1;
      }
    
    while (temp->data != value && temp->nextNode != NULL) 
      {
        pos++;
        temp = temp->nextNode;
    }
    if (temp->data != value)
    {
        return -1;
      }
 
    
    return (pos);
    }

    // 20 Points
    // This function reverses the LinkedList.
    // Update all pointers accordingly.
    void reverseLinkedList()
    {
      Node<Type>* temp = NULL;
      Node<Type>* current = head;
      tail = head;
      while(current != NULL)
        {
          temp = current -> previousNode;
          current -> previousNode = current -> nextNode;
          current -> nextNode = temp;
          current = current -> previousNode;
        }
        head = temp -> previousNode;
  
        return;
    }

    // Printer
	// Do not edit this function
    void printListValues()
    {
        Node<Type>* current = head;
        if (isEmpty()) { cout << "Empty List"; }
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->nextNode;
        }
        cout << endl;
    }

    // Destructor
	// Do not edit this function
    ~LinkedList()
    {
        Node<Type>* current = head;
        cout << "Deleting LinkedList" << endl;
        while(current != nullptr)
        {
            Node<Type>* nodeBeingDeleted = current;
            current = current->nextNode;
            delete nodeBeingDeleted;
        }
        cout << "LinkedList Deleted" << endl;
    }

protected:
    // First node in the Linked List - do not edit
    Node<Type>* head;
    // Last node in the Linked List - do not edit
    Node<Type>* tail;
};


// Do not edit any of the functions below this
void first(LinkedList<int>* ll) { cout << ll->first()->data << endl; }
void last(LinkedList<int>* ll) { cout << ll->last()->data << endl; }
void size(LinkedList<int>* ll) { cout << ll->size() << endl; }
void isEmpty(LinkedList<int>* ll) {cout << ll->isEmpty() << endl; }
void addNode(LinkedList<int>* ll, int value) { ll->addNode(value); }
void getNodeAtPosition(LinkedList<int>* ll, int position) 
{if(ll->getNodeAtPosition(position) != nullptr){ cout << ll->getNodeAtPosition(position)->data << endl; }
 else { cout << "Invalid Position" << endl; }}
void addNodeAtPosition(LinkedList<int>* ll, int value, int position) { ll->addNodeAtPosition(value, position); }
void deleteNodeAtPosition(LinkedList<int>* ll, int position) { ll->deleteNodeAtPosition(position); }
void findNodeWithValue(LinkedList<int>* ll, int value) {cout << ll->findNodeWithValue(value) << endl; }
void reverseLinkedList(LinkedList<int>* ll) { ll->reverseLinkedList(); }
void printListValues(LinkedList<int>* ll) { ll->printListValues(); }
void deleteLinkedList(LinkedList<int>* ll) { delete ll; }

void process(LinkedList<int>* ll, string line)
{
    string input1;
    string input2;
    if(line == "first") { first(ll); }
    else if (line == "last") { last(ll); }
    else if (line == "size") { size(ll); }
    else if (line == "isEmpty") { isEmpty(ll); }
    else if (line == "addNode") { getline(cin, input1); addNode(ll, stoi(input1)); }
    else if (line == "getNodeAtPosition") { getline(cin, input1); getNodeAtPosition(ll, stoi(input1)); }
    else if (line == "addNodeAtPosition") { getline(cin, input1); getline(cin, input2); addNodeAtPosition(ll, stoi(input1), stoi(input2)); }
    else if (line == "deleteNodeAtPosition") { getline(cin, input1); deleteNodeAtPosition(ll, stoi(input1)); }
    else if (line == "findNodeWithValue") { getline(cin, input1); findNodeWithValue(ll, stoi(input1)); }
    else if (line == "reverseLinkedList") { reverseLinkedList(ll); }
    else if (line == "printListValues") { printListValues(ll); }
    else if (line == "deleteLinkedList") { deleteLinkedList(ll); }
}

int main()
{
    LinkedList<int>* ll = new LinkedList<int>();
    string line;
    while (getline(cin, line)) { if(line == "eof") break; process(ll, line); }
    cout << "Run finished." << endl;
}