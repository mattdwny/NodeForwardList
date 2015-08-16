#pragma once

template <typename T>
class Node
{
public:
	Node();
	Node(const T& data, Node<T> *next); 

	T			mData;
	Node<T>*	mNext;
};

template <typename T>
Node<T>::Node() : mData(), mNext(nullptr) {}

template <typename T>
Node<T>::Node(const T& data, Node<T> *next) : mData(data), mNext(next) {} 