#pragma once

#include "Node.h"

template <typename T>
class NodeForwardList
{
public:
	NodeForwardList();

	//size stuffs
	std::size_t size() const;
	bool empty() const;
	//std::size_t max_size() const;

	//element access
	T& front();
	T& at(std::size_t position);
	T& operator[](std::size_t position); //const overloading
	//const T& operator[](std::size_t position) const;

	//manipulation
	void insert(std::size_t position, const T& value);
	void erase(std::size_t position);
	//void emplace(std::size_t position, Args&& ...);
	void push_front(const T& value);
	void pop_front();
	void sort();
	void unique();
	void remove(const T& value);
	//void remove_if(Predicate pred);


private:
	Node<T>* find_before(std::size_t position);
	void remove_after(Node<T>* prev);
	void insert_after(Node<T>* prev, const T& value);

	std::size_t mSize;
	Node<T> *mHead; //equivalent to forward_list::before_begin()
	Node<T> *mSentinel;
};

template <typename T>
NodeForwardList<T>::NodeForwardList() : mSize(0), mHead(new Node<T>()), mSentinel(new Node<T>())
{
	mHead->mNext = mSentinel;
}

template <typename T>
Node<T>* NodeForwardList<T>::find_before(std::size_t position)
{
	Node<T>* temp = mHead;
	while(position--) temp = temp->mNext;
	return temp;
}

template <typename T>
void NodeForwardList<T>::remove_after(Node<T>* location)
{
	Node<T>* temp = location->mNext;
	location->mNext = temp->mNext;
	delete temp;
}

template <typename T>
void NodeForwardList<T>::insert_after(Node<T>* location, const T& value)
{
	Node<T>* temp = new Node<T>(value, location->mNext);
	location->mNext = temp;
}

template <typename T>
T& NodeForwardList<T>::front()
{
	return mHead->mNext->mData;
}

template <typename T>
T& NodeForwardList<T>::at(std::size_t position)
{
	Node<T> *location = find_before(position);

	return location->mNext->mData;
}

template <typename T>
T& NodeForwardList<T>::operator[](std::size_t position)
{
	return at(position);
}

template <typename T>
void NodeForwardList<T>::push_front(const T& value)
{
	insert_after(mHead, value);
}

template <typename T>
void NodeForwardList<T>::pop_front()
{
	remove_after(mHead);
}

template <typename T>
void NodeForwardList<T>::insert(std::size_t position, const T& value)
{
	Node<T> *location = find_before(position);

	insert_after(location, value);
}


template <typename T>
void NodeForwardList<T>::erase(std::size_t position)
{
	Node<T> *location = find_before(position);

	remove_after(location);
}