#ifndef QUEUE_H
#define QUEUE_H


#include "ListSequence.h"

template <typename T>
class Queue
{
public:
	Queue() : _list(new ListSequence<T>) {}

	Queue(T* data, int count);

	void Append(const T& value) {return _list->Append(value);}
	void Prepend(const T& value) {return _list->Prepend(value);}
	void Assign(int i, const T& value) {return _list->InsertAt(i, value);}
	T& Get(int i);
	const T& Get (int i) const;

	bool empty() {return _list->getLength() == 0;}
	int getLength() const {return _list->getLength();}

	void erase() {return _list->erase();}
	void pop_front() {return _list->pop_front();}
	void pop_back() {return _list->pop_back();}

	bool operator== (const Queue<T> &list) const ;
	bool operator!= (const Queue<T> &list) const {return !(list == *this);}

private:
	ListSequence<T> *_list;
};


template<typename T>
Queue<T>::Queue(T *data, int count): Queue()
{
	for (int i = 0; i < count; i++)
		Prepend(data[i]);
}


template<typename T>
T& Queue<T>::Get(int i)
{
	if (i == 0)
		_list->GetFirst();
	if (i == _list->GetLength() - 1)
		_list->GetLast();
	else
		_list->Get(i);
}


template<typename T>
const T& Queue<T>::Get(int i) const
{
	if (i == 0)
		_list->GetFirst();
	if (i == _list->getLength() - 1)
		_list->GetLast();
	else
		_list->Get(i);
}


template<typename T>
bool Queue<T>::operator==(const Queue<T> &list) const
{
	if (this->getLength() == 0 && list.getLength() == 0)
		return true;

	if (this->getLength() == list.getLength()) {
		for (int i = 0; i < list.getLength(); i++) {
			if (this->Get(i) == list.Get(i))
				return true;
		}
	}
	else return false;
}

#endif // QUEUE_H
