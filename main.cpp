#include "DoubleLinkedList.h"

int main(void)
{
	dll<const char*>d;
	d.m_push("Art");
	d.m_push("of");
	d.m_push("programming");
	d.m_push("in");
	d.m_push("C++");
	d.operator<<(std::cout);
}