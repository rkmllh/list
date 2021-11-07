#pragma once
#include "list.h"
#include "memory.h"
#include <iostream>
using namespace std;

/*
* A class to work with position of a generic list
*/
template <typename T>
class position
{
public:
	position(T val) : m_position_obj{ val } {};
private:
	T m_position_obj;
};

template <typename Type, class Pos>
class double_linked_list : public list<Type, Pos>
{

public:

	//Default costructor 
	double_linked_list() : m_head{ nullptr }, m_tail{ nullptr }, m_current_item{m_head} {};

	virtual Pos m_insert(Pos pos)   override;
	virtual Pos m_remove(Pos pos)   override;

	virtual bool m_is_empty() const override;
	virtual Pos m_push(Type x)      override;
	virtual Pos m_pop()             override;
	virtual void m_destroy()        override;

	Type* get_next();
	Type* get_prev();

	//Overloading operators
	ostream& operator<<(ostream& os);

private:

	struct items_s
	{
		Type m_s_data;				//Effective value
		items_s* m_s_prev;			//Previous value
		items_s* m_s_next;			//Next value
	};

	items_s* m_head;					//First value
	items_s* m_tail;					//Last value
	items_s* m_current_item;			//Keep trace of current item referenced by a user
};

template <typename Type, class Pos>
bool double_linked_list<Type, Pos>::m_is_empty() const
{
	return (this->m_head == this->m_tail);
}

template <typename Type, class Pos>
Pos double_linked_list<Type, Pos>::m_insert(Pos pos)
{
	return pos;
}

template <typename Type, class Pos>
Pos double_linked_list<Type, Pos>::m_remove(Pos pos)
{
	return pos;
}

template <typename Type, class Pos>
Pos double_linked_list<Type, Pos>::m_push(Type x)
{
	items_s* item = (items_s*)smart_new(sizeof(items_s));
	Pos p (&item->m_s_data);

	item->m_s_data = x;

	if (this->m_tail != nullptr)
	{
		item->m_s_next = nullptr;
		item->m_s_prev = this->m_tail;
		this->m_tail->m_s_next = item;
		this->m_tail = item;
	}
	else  //I suppose we have an empty list
	{
		this->m_head = item;
		this->m_tail = item;
	}

	return p;
}

template <typename Type, class Pos>
Pos double_linked_list<Type, Pos>::m_pop()
{
	Pos pos{0};
	return pos;
}

template <typename Type, class Pos>
void double_linked_list<Type, Pos>::m_destroy()
{
}

template <typename Type, class Pos>
ostream& double_linked_list<Type, Pos>::operator<<(ostream& os)
{
	items_s* p = this->m_head;
	while (p)
	{
		os<< p->m_s_data << std::endl;
		p = p->m_s_next;
	}

	return os;
}

template <typename Type>
using dll = double_linked_list<Type, position<Type*>>;