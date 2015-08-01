/**
 * @file LinkedLst.h
 * @author Myanna Harris and Luke Johnson
 * @date 12-10-14
 *
 * LinkedLst Class
 * Generic Singly Linked List
 */

#ifndef LINKEDLST_H
#define LINKEDLST_H

using namespace std;

template <typename T>

/** 
 * @class LinkedLst
 */
class LinkedLst
{
  // Node struct
  struct Node
  {
   T* item;
   Node* next;
   Node(T* itemP, Node* nextP)
   {
    item = itemP;
    next = nextP;
   }
  };

 public:
 // constructors and destructor:

  /** Default constructor. */
  LinkedLst();

  /** Destructor. */
  ~LinkedLst();

 //Checks

  /** Checks if list is empty.
    * @pre An instance of LinkedList exists.
    * @post Return true if list is empty, false otherwise.
    * @return true/false 
    */
  bool isEmpty();

 //Getters

  /** Returns the length of the linked list.
    * @pre An instance of List exists.
    * @post Return the length of the list. 
    * @return size
    */
  int getSize();

  /** Returns the item of the head node.
    * @pre An instance of List exists.
    * @post Return the item of the head node. 
    * @return item
    */
  Node* getHead();

 //Linked List actions

  /** Adds a node to the linked list
    * @pre An instance of LinkedList exists.
    * @post A node is added to the linked list. 
    * @param newPage => pointer to new page to be added
    */
  void add(T* newItem);

  /** Removes a node from the linked list
    * @pre An instance of LinkedList exists.
    * @post A node is removed from the linked list and 
    *       true is returned if successful, false if not found. 
    * @param oldPage => pointer to old node to be removed
    */
  bool remove(T* oldItem);

 protected:
  // head pointer
  Node* head;

  // tail pointer
  Node* tail;

  // size of linked list
  int size;

}; // end LinkedLst

template <typename T>
LinkedLst<T>::LinkedLst()
{
 head = NULL;
 tail = NULL;
 size = 0;
}

template <typename T>
LinkedLst<T>::~LinkedLst()
{
 while(head != NULL)
 {
  remove(head->item);
 }
}

template <typename T>
bool LinkedLst<T>::isEmpty()
{
 if (size == 0)
  return true;
 else
  return false;
}

template <typename T>
int LinkedLst<T>::getSize()
{
 return size;
}

template <typename T>
typename LinkedLst<T>::Node* LinkedLst<T>::getHead()
{
 return head;
}

template <typename T>
void LinkedLst<T>::add(T* newItem)
{
 Node* newNode = new Node(newItem,NULL);

 if (head == NULL)
 {
  head = newNode;
  tail = head;
 }
 else
 {
  tail -> next = newNode;
  tail = newNode;
 }
 size++;
}

template <typename T>
bool LinkedLst<T>::remove(T* oldItem)
{
 Node* prev = NULL;
 Node* h = head;
 while (h != NULL && h -> item != oldItem)
 {
  prev = h;
  h = h -> next;
 }

 if (h == NULL)
 {
  return false;
 }
 else
 {
  if (h == head && h == tail)
  {
   delete head;
   head = NULL;
   tail = NULL;
  }
  else if (h == head)
  {
   Node* temp = head;
   head = head -> next;
   delete temp;
   temp = NULL;
  }
  else if (h == tail)
  {
   Node* temp = tail;
   tail = prev;
   tail -> next = NULL;
   delete temp;
   temp = NULL;
  }
  else
  {
   prev -> next = h -> next;
   delete h;
   h = NULL;
  }

  return true;
 }
}
#endif
// End of header file.
