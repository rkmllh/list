#pragma once
#include "one_side_list.h"

template <typename Type, class Pos>
class list : public one_side_list <Type, Pos>
{

public:

	//Setters
	virtual Pos m_insert(Pos pos) = 0;
	virtual Pos m_remove(Pos pos) = 0;
};