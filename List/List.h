#pragma once
#include <iostream>
using namespace std;

template<class T>
struct elem
{
	T obj;
	elem<T>*next = nullptr;
	elem<T>*prev = nullptr;
};

template<class T>
class List_
{
	elem<T>*head = nullptr;
	elem<T>*tail = nullptr;
	int size_ = 0;
public:
	List_() = default;

	void push_back(const T&obj);
	void push_back(T&&obj);
	void push_front(const T&obj);
	void push_front(T&&obj);
	void pop_back();
	void pop_front();
	void insert(const T&obj, int pos);
	//hw
	void insert(T&&obj, int pos);
	void erase(int pos);
	bool empty()const;
	int size()const;
	T& front();
	const T& front()const;
	T& back();
	const T& back()const;
	void clear();
	void operator+=(const T&obj);

	void reverse();
	//-----------------------
	List_(const List_<T>&list);
	List_(List_<T>&&list);
	List_<T>&operator=(const List_<T>&list);
	List_<T>&operator=(List_<T>&&list);
	~List_();

	template<class T>
	friend ostream&operator<<(ostream&os, const List_<T>&list);
	//friend istream&operator>>(istream&os, List_<T>&list);
};

template<class T>
inline void List_<T>::push_back(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	if (size_ == 0) {
		head = tail = newElem;
		size_ = 1;
		return;
	}
	tail->next = newElem;
	newElem->prev = tail;
	tail = newElem;
	size_++;
}

template<class T>
inline void List_<T>::push_back(T && obj)
{

	elem<T>*newElem = new elem<T>;

	newElem->obj = obj;

	if (size_ == 0) {
		head = tail = newElem;
		size_ = 1;
		return;
	}
	tail->next = newElem;
	newElem->prev = tail;
	tail = newElem;
	size_++;
}

template<class T>
inline void List_<T>::push_front(const T & obj)
{
	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;
	if (size_ == 0) {
		head = tail = newElem;
		size_ = 1;
		return;
	}

	newElem->next = head;
	head->prev = newElem;
	head = newElem;
	size_++;
}

template<class T>
inline void List_<T>::push_front(T && obj)
{
	elem<T>*newElem = new elem<T>;
	swap(newElem->obj, obj);
	if (size_ == 0) {
		head = tail = newElem;
		size_ = 1;
		return;
	}

	newElem->next = head;
	head->prev = newElem;
	head = newElem;
	size_++;
}

template<class T>
inline void List_<T>::pop_back()
{
	if (size_ == 0) return;
	if (head == tail) {
		delete head;
		head = tail = nullptr;
		size_ = 0;
		return;
	}
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
	size_--;
}

template<class T>
inline void List_<T>::pop_front()
{
	if (size_ == 0) return;
	if (head == tail) {
		delete head;
		head = tail = nullptr;
		size_ = 0;
		return;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
	size_--;
}

template<class T>
inline void List_<T>::insert(const T & obj, int pos)
{
	if (pos > size_) return;
	if (pos == 0) {
		push_front(obj);
		return;
	}
	if (pos == size_) {
		push_back(obj);
		return;
	}

	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;

	elem<T>*tmp;

	if (pos <= size_ / 2) {
		tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (size_t i = size_; i > pos; i--)
		{
			tmp = tmp->prev;
		}
	}

	newElem->prev = tmp;
	newElem->next = tmp->next;
	tmp->next->prev = newElem;
	tmp->next = newElem;

	size_++;
}

template<class T>
inline void List_<T>::insert(T && obj, int pos)
{
	if (pos > size_) return;
	if (pos == 0) {
		push_front(obj);
		return;
	}
	if (pos == size_) {
		push_back(obj);
		return;
	}

	elem<T>*newElem = new elem<T>;
	newElem->obj = obj;

	elem<T>*tmp;

	if (pos <= size_ / 2) {
		tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (size_t i = size_; i > pos; i--)
		{
			tmp = tmp->prev;
		}
	}

	newElem->prev = tmp;
	newElem->next = tmp->next;
	tmp->next->prev = newElem;
	tmp->next = newElem;

	size_++;
}

template<class T>
inline void List_<T>::erase(int pos)
{
	if (pos > size_) return;
	if (pos == 0) {
		pop_back();
		return;
	}
	if (pos == size_) {
		pop_back();
		return;
	}
	elem<T> *tmp, *tmp2;
	if (pos <= size_ / 2) {
		tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tail;
		for (size_t i = size_; i > pos; i--)
		{
			tmp = tmp->prev;
		}
	}
	tmp2 = tmp;
	tmp2->prev->next = tmp->next;
	tmp2->next->prev = tmp->prev;
	delete tmp;
	size_--;
}

template<class T>
inline bool List_<T>::empty() const
{
	return head == nullptr;
}

template<class T>
inline int List_<T>::size() const
{
	return this->size_;
}

template<class T>
inline T & List_<T>::front()
{
	return head->obj;
}

template<class T>
inline const T & List_<T>::front() const
{
	return head->obj;
}

template<class T>
inline T & List_<T>::back()
{
	return tail->obj;
}

template<class T>
inline const T & List_<T>::back() const
{
	return tail->obj;
}

template<class T>
inline void List_<T>::clear()
{
	this->~List_();
}

template<class T>
inline void List_<T>::operator+=(const T & obj)
{
	push_back(obj);
}

template<class T>
inline void List_<T>::reverse()
{
	elem<T>*f = this->head;
	elem<T>*b = this->tail;
	for (size_t i = 0; i < size_/2; i++)
	{
		swap(f->obj, b->obj);
		f = f->next;
		b = b->prev;
	}
}

template<class T>
ostream & operator<<(ostream & os, const List_<T>& list)
{
	elem<T>* it = list.head;
	while (it != nullptr)
	{
		cout << it->obj << " ";
		it = it->next;
	}
	return os;
}

template<class T>
inline List_<T>::List_(const List_<T>& list)
{
	elem<T>*tmp = list.head;
	while (tmp != nullptr)
	{
		this->push_back(tmp->obj);
		tmp = tmp->next;
	}
}

template<class T>
inline List_<T>::List_(List_<T>&& list)
{
	swap(this->head, list.head);
	swap(this->tail, list.tail);
	swap(this->size_, list.size_);

}

template<class T>
inline List_<T>& List_<T>::operator=(const List_<T>& list)
{
	if (this == &list) return *this;
	this->~List_();
	elem<T>*tmp = list.head;
	while (tmp != nullptr)
	{
		this->push_back(tmp->obj);
		tmp = tmp->next;
	}
	return *this;
}

template<class T>
inline List_<T>& List_<T>::operator=(List_<T>&& list)
{
	swap(this->head, list.head);
	swap(this->tail, list.tail);
	swap(this->size_, list.size_);
	return *this;
}

template<class T>
inline List_<T>::~List_()
{
	while (size_ > 0) {
		this->pop_front();
	}
}

