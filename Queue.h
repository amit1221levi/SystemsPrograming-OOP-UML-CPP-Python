#ifndef EX3_2_QUEUE_H
#define EX3_2_QUEUE_H
#include <iostream>

template <class T>
class Queue
{
public:
  /**
   * C'tor, D'tor, copy constructor and assignment operator
   * all of the above use dynamic allocation of memory
   */
  Queue();
  Queue(const Queue &);
  ~Queue();
  Queue &operator=(const Queue &);

  /**
   *Adds a given value to the queue
    * @param value
    */
  void pushBack(const T &toPush);

  /**
   * @return - the value at the front of the queue
   */
  T &front() const;

  /**
   * removes the value at the front of the queue
   */
  void popFront();

  /**
   * @return the size of the queue
   */
  int size() const;
  
  /**
  *an iterator suitable for non-const queue
  */
  class Iterator;
  Iterator begin();
  Iterator end();

  /**
  *an iterator suitable for const queue
  */
  class ConstIterator;
  ConstIterator begin() const;
  ConstIterator end() const;

  /**
   * an exception to be thrown when a method
   * non-suitable for an empty queue is used on one
   */
  class EmptyQueue
  {
  };

private:
  struct Node
  {
    T data;
    Node *next;

    Node();
    ~Node() = default;
    Node(const Node &) = default;
    Node &operator=(const Node &) = default;
  };
  Node *m_head;

  void deleteNodes();
};

template <class T>
class Queue<T>::Iterator
{
public:
  T &operator*();
  Iterator &operator++();
  bool operator!=(const Iterator &it) const;

  Iterator(const Iterator &) = default;
  Iterator &operator=(const Iterator &) = default;

  class InvalidOperation
  {
  };

private:
  Node *m_currentNode;
  explicit Iterator(Node *queue);
  friend class Queue;
};

template <class T>
class Queue<T>::ConstIterator
{
public:
  const T &operator*() const;
  ConstIterator &operator++();

  bool operator!=(const ConstIterator &it) const;

  class InvalidOperation
  {
  };

private:
  Node *m_queue;
  explicit ConstIterator(Node *queue);
  friend class Queue;
};

//*********** Queue::Iterator implementations ***********

template <class T>
Queue<T>::Iterator::Iterator(Node *queue) : m_currentNode(queue)
{
}

template <class T>
T &Queue<T>::Iterator::operator*()
{
  if (!m_currentNode)
  {
    throw InvalidOperation();
  }
  return m_currentNode->data;
}

template <class T>
typename Queue<T>::Iterator &Queue<T>::Iterator::operator++()
{
  if (!m_currentNode)
  {
    throw InvalidOperation();
  }
  m_currentNode = m_currentNode->next;
  return *this;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator &it) const
{
  return m_currentNode != it.m_currentNode;
}

//*********** Queue::ConstIterator implementations ***********

template <class T>
Queue<T>::ConstIterator::ConstIterator(Node *queue) : m_queue(queue)
{
}

template <class T>
const T &Queue<T>::ConstIterator::operator*() const
{
  if (!m_queue)
  {
    throw InvalidOperation();
  }
  return m_queue->data;
}

template <class T>
typename Queue<T>::ConstIterator &Queue<T>::ConstIterator::operator++()
{
  if (!m_queue)
  {
    throw InvalidOperation();
  }
  m_queue = m_queue->next;
  return *this;
}

template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator &it) const
{
  return m_queue != it.m_queue;
}

//*********** Queue::Node implementations ***********

template <class T>
Queue<T>::Node::Node()
{
  data = T();
  next = nullptr;
}

//*********** Queue implementations ***********

//* iterator begin and end implementations *

template <class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
  return Iterator(this->m_head->next);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end()
{
  return Iterator(nullptr);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
  return ConstIterator(this->m_head->next);
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
  return ConstIterator(nullptr);
}

//* More Queue implementations *

template <class T>
Queue<T>::Queue() : m_head(new Node())
{
}

template <class T>
Queue<T>::~Queue()
{
  deleteNodes();
}

template <class T>
Queue<T>::Queue(const Queue &other)
{
  m_head = new Node();
  try
  {
    for (const T &i : other)
    {
      pushBack(i);
    }
  }
  catch (...)
  {
    deleteNodes();
    throw;
  }
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue &other)
{
      if(this == &other){
        return *this;
    }
    Queue tempCopy(*this);
    Node* currentNode = m_head->next;
    while (currentNode){
        Node* toDelete = currentNode;
        currentNode = currentNode->next;
        delete toDelete;
    }
    m_head->next = currentNode;
    try {
        for (typename Queue<T>::ConstIterator i = other.begin(); i != other.end(); ++i) {
            pushBack(*i);
        }
    }
    catch (...) {
        currentNode = m_head->next;
        while (currentNode) {
            Node *toDelete = currentNode;
            currentNode = currentNode->next;
            delete toDelete;
        }
        *this = tempCopy;
        throw;
    }
    return *this;
}

template <class T>
void Queue<T>::pushBack(const T &value)
{
  T valueCopy = value;

  Node *ptr;
  ptr = new Node();
  ptr->data = valueCopy;
  ptr->next = nullptr;
  if (!m_head->next)
  {
    m_head->next = ptr;
  }
  else
  {
    Node *currentNode = m_head;
    while (currentNode->next)
    {
      currentNode = currentNode->next;
    }
    currentNode->next = ptr;
  }
}

template <class T>
T &Queue<T>::front() const
{
  if (!m_head->next)
  {
    throw EmptyQueue();
  }
  return m_head->next->data;
}

template <class T>
void Queue<T>::popFront()
{
  if (!m_head->next)
  {
    throw EmptyQueue();
  }
  Node *toDelete = m_head->next;
  m_head->next = m_head->next->next;
  delete toDelete;
}

template <class T>
int Queue<T>::size() const
{
  if (!m_head->next)
  {
    return 0;
  }
  int counter = 0;
  Node *currentNode = m_head;
  while (currentNode->next)
  {
    ++counter;
    currentNode = currentNode->next;
  }
  return counter;
}

//*********** non-member functions ***********
template <class T>
void Queue<T>::deleteNodes()
{
  Node *currentNode = m_head;
  while (currentNode)
  {
    Node *toDelete = currentNode;
    currentNode = currentNode->next;
    delete toDelete;
  }
}

template <class T, class C>
Queue<T> filter(const Queue<T> &queue, C condition)
{
  Queue<T> filteredQueue;
  for (const T &i : queue)
  {
    if (condition(i))
    {
      filteredQueue.pushBack(i);
    }
  }
  return filteredQueue;
}

template <class T, class C>
void transform(Queue<T> &queue, C condition)
{
  for (typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i)
  {
    condition(*i);
  }
}

#endif // EX3_2_QUEUE_H