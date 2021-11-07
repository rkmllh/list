#pragma once

template <typename Type, class Pos>
class one_side_list
{

public:

	one_side_list() : m_number_items{ 0 } {};

	virtual bool m_is_empty() const                    = 0;
	virtual Pos m_push(Type x)                         = 0;
	virtual Pos m_pop()                                = 0;
	virtual void m_destroy()                           = 0;
	
	//Getters
	unsigned int m_size() const noexcept { return this->m_number_items; }

protected:
	unsigned int m_increment_size() const noexcept { return (++this->m_number_items); };
	unsigned int m_decrement_size() const noexcept { return (--this->m_number_items); };

private:
	unsigned int m_number_items;			//Number of items in structure
};