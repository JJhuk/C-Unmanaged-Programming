#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn	//��Ÿ���� ���� �� ���� ����
	{
	public:
		CircleLawn();
		CircleLawn(unsigned int raidus);
		CircleLawn(CircleLawn& other);

		CircleLawn& operator=(CircleLawn& other);

		~CircleLawn();
		unsigned int GetArea() const;

	private:
		unsigned int mRadius;
	};

}
