#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight) : mWeight(weight)
	{

		//std::cout << "Trailer ������ ȣ��" << std::endl;
	}

	Trailer::Trailer() : mWeight(0)
	{

		//std::cout << "Trailer ������ ȣ��" << std::endl;
	}

	Trailer::~Trailer()
	{

		//std::cout << "Trailer �Ҹ��� ȣ��" << std::endl;
	}

	unsigned int Trailer::GetWeight() const
	{
		return mWeight;
	}
}
