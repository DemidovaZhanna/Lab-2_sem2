#ifndef LISTSEQUENCE_H
#define LISTSEQUENCE_H


#include "Sequence.h"
#include "LinkedList.h"

template <typename T>
class ListSequence: public Sequence<T>
{
public:
	ListSequence() : _list(new LinkedList <T>()) {}

	ListSequence(T* data, int count);
	ListSequence (LinkedList<T>& list);

	T& GetFirst() {return _list->GetFirst();}
	T& GetLast() {return _list->GetLast();}

	T& Get(int i) {return _list->operator[](i);}
	const T& Get(int i) const {return _list->operator[](i);}

	void erase() {_list->clear();}
	void pop_front() {_list->pop_front();}
	void pop_back() {_list->pop_back();}

	Sequence<T>* GetSubsequence(int startIndex, int endIndex) const;
	Sequence<T>* Concat(Sequence <T> *seq) const;
	Sequence<T>* operator+ (Sequence<T> *a) const {return Concat(a);}

	int getLength() const noexcept {return _list->getLength();}
	void Append(const T& value) {_list->Append(value);}
	void Prepend(const T& value) {_list->Prepend(value);}
	void InsertAt(const T& value, int i) {_list->InsertAt(value, i);}

	bool operator== (const ListSequence<T> &list) const;
	bool operator!= (const ListSequence<T> &list) const {return !(list == *this);}

	~ListSequence();

private:
	LinkedList<T> *_list;
};

template<typename T>
ListSequence<T>::~ListSequence()
{
	delete _list;
}



template<typename T>
ListSequence<T>::ListSequence(T *data, int count)
{
	_list = new LinkedList<T>(data, count);
}

template<typename T>
ListSequence<T>::ListSequence(LinkedList<T> &list) {
	_list = new LinkedList<T>(list);
}


template<typename T>
Sequence<T> *ListSequence<T>::GetSubsequence(int startIndex, int endIndex) const
{

}


template<typename T>
Sequence<T> *ListSequence<T>::Concat(Sequence<T> *seq) const
{
	ListSequence<T> *ret = new ListSequence;
	ListSequence<T> *list = dynamic_cast<ListSequence<T>*>(seq);

	if(list != nullptr) {
		for (int i = 0; i < list->getLength(); i++)
			ret->Get(i) = list->Get(i) + _list->operator[](i);
	}
	else{
		LinkedList<T> t;
		for(int i = 0; i < seq->getLength(); i++)
			t.Append(seq->Get(i));
		for (int i = 0; i < t.getLength(); i++)
			ret->Get(i) = t.operator[](i) + _list->operator[](i);
	}
	return ret;

}

template<typename T>
bool ListSequence<T>::operator==(const ListSequence<T> &list) const
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

#endif // LISTSEQUENCE_H
