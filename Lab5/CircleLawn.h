#pragma once
#include "Lawn.h"

class CircleLawn : public lab5::Lawn	//��Ÿ���� ���� �� ���� ����
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

