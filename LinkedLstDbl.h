/**
 * @file LinkedLstDbl.h
 * @author Myanna Harris and Luke Johnson
 * @date 12-9-14
 *
 * LinkedLstDbl Class
 * Generic Double Linked List
 */

#ifndef LINKEDLSTDBL_H
#define LINKEDLSTDBL_H

using namespace std;

template <typename T>

/** 
 * @class LinkedLstDbl
 */
class LinkedLstDbl
{
  // NodeDbl struct
  struct NodeDbl
  {
   T* item;
   NodeDbl* next;
   NodeDbl* prev;
   NodeDbl(T* itemP, NodeDbl* nextP, NodeDbl* prevP)
   {
    item = itemP;
    next = nextP;
    prev = prevP;
   }
  };

 public:
 // constructors and destructor:

  /** Default constructor. */
  LinkedLstDbl();

  /** Destructor. */
  ~LinkedLstDbl();

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

  /** Returns the head node.
    * @pre An instance of List exists.
    * @post Return the head node. 
    * @return NodeDbl head
    */
  NodeDbl* getHead();

  /** Returns the tail node.
    * @pre An instance of List exists.
    * @post Return the tail node. 
    * @return NodeDbl tail
    */
  NodeDbl* getTail();

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

  /** Sorts the linked list using merge sort.
    * @pre An instance of List exists.
    * @post List is sorted in ascending order using merge sort 
    *       according to the edges' priorities. 
    *       Greater priority = larger number of conflicts
    */
  void sortList();

 protected:
  // head pointer
  NodeDbl* head;

  // tail pointer
  NodeDbl* tail;

  // size of linked list
  int size;

  /** Sorts the linked list using merge sort.
    * @pre An instance of Linked List exists.
    * @post Linked list is sorted in ascending order using merge sort.
    * @param head is the node at the head of the list to be sorted.
    * @param size is the length of the list to be sorted. */
  NodeDbl* mergesort(NodeDbl* head, int size);

  /** Merges two linked lists.
    * @pre Two linked lists exist.
    * @post Lists are merged in sorted order.
    * @param head1 is the node at the head of the list1 to be merged.
    * @param head2 is the node at the head of the list2 to be merged. */
  NodeDbl* merge(NodeDbl* head1, NodeDbl* head2);

}; // end LinkedLstDbl

template <typename T>
LinkedLstDbl<T>::LinkedLstDbl()
{
 head = NULL;
 tail = NULL;
 size = 0;
}

template <typename T>
LinkedLstDbl<T>::~LinkedLstDbl()
{
 while(head != NULL)
 {
  remove(head->item);
 }
}

template <typename T>
bool LinkedLstDbl<T>::isEmpty()
{
 if (size == 0)
  return true;
 else
  return false;
}

template <typename T>
int LinkedLstDbl<T>::getSize()
{
 return size;
}

template <typename T>
typename LinkedLstDbl<T>::NodeDbl* LinkedLstDbl<T>::getHead()
{
 return head;
}

template <typename T>
typename LinkedLstDbl<T>::NodeDbl* LinkedLstDbl<T>::getTail()
{
 return tail;
}

template <typename T>
void LinkedLstDbl<T>::add(T* newItem)
{
 NodeDbl* newNode = new NodeDbl(newItem,NULL, NULL);

 if (head == NULL)
 {
  head = newNode;
  tail = head;
 }
 else
 {
  tail -> next = newNode;
  newNode -> prev = tail;
  tail = newNode;
 }
 size++;
}

template <typename T>
bool LinkedLstDbl<T>::remove(T* oldItem)
{
 NodeDbl* prevNode = NULL;
 NodeDbl* h = head;
 while (h != NULL && h -> item != oldItem)
 {
  prevNode = h;
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
   NodeDbl* temp = head;
   head = head -> next;
   delete temp;
   temp = NULL;
  }
  else if (h == tail)
  {
   NodeDbl* temp = tail;
   tail = prevNode;
   tail -> next = NULL;
   delete temp;
   temp = NULL;
  }
  else
  {
   prevNode -> next = h -> next;
   h -> next -> prev = prevNode;
   delete h;
   h = NULL;
  }

  return true;
 }
}

//ascending
template <typename T>
void LinkedLstDbl<T>::sortList()
{
 head = mergesort(head, size);
}

template <typename T>
typename LinkedLstDbl<T>::NodeDbl* LinkedLstDbl<T>::mergesort(NodeDbl* head, int size)
{
 NodeDbl* headNode;

 //recursive merge sort
 int length1;
 int length2;

 if (head -> next != NULL)
 {
  if (size % 2 != 0)
  {
   length1 = (int)size/2;
   length2 = size - length1;
  }
  else
  {
   length1 = size/2;
   length2 = length1;
  }

  NodeDbl* head1 = head;
  NodeDbl* head2;
  NodeDbl* beforeHead = head;

  for (int i = 1; i < length1; i++)
      beforeHead = beforeHead -> next;

  head2 = beforeHead -> next;
  beforeHead -> next = NULL;

  head1 = mergesort(head, length1);
  head2 = mergesort(head2, length2);

  headNode = merge(head1, head2); 
 }
 else
    headNode = head;

 return headNode;
}

template <typename T>
typename LinkedLstDbl<T>::NodeDbl* LinkedLstDbl<T>::merge(NodeDbl* head1, NodeDbl* head2)
{
  if (head1 == NULL)
  {
   return head2;
  }
  else if (head2 == NULL)
  {
   return head1;
  }
  else if (head1->item->getPriority() > head2->item->getPriority())
  {
     head2->next = (merge(head1, head2->next));
     return head2;
  }
  else if (head1->item->getPriority() < head2->item->getPriority())
  {
     head1->next = (merge(head1->next, head2));
     return head1;
  }
  else
  {
     head1->next = (merge(head1->next, head2));
     return head1;
  }
       
}
#endif
// End of header file.
