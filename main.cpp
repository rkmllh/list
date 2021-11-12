#include "DoubleLinkedList.h"

int main(void)
{
	try
	{
		dll<std::string>d;

		d.m_push("Art");
		d.m_push("of");
		d.m_push("programming");
		d.m_push("in");
		d.m_push("C++");

		for(auto s = d.m_end(); s.m_position_obj; s = d.get_prev())
			std::cout << *s.m_position_obj << std::endl;

		cout << endl;

		d.operator<<(std::cout);
	}
	catch (bad_alloc)
	{
		std::cerr << "exception:bad_alloc" << std::endl;
	}
	catch (list_under_range)
	{
		std::cerr << "exception:list_under_range" << std::endl;
	}

	//catch(...)
}