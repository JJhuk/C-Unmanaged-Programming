#include "EquilateralTriangleLawn.h"
#include <cmath>

namespace lab5
{

	EquilateralTriangleLawn::EquilateralTriangleLawn() : IFenceable(), Lawn(), mSide(0)
	{

	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side) : IFenceable(), Lawn(), mSide(side)
	{
	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(const EquilateralTriangleLawn& other) : IFenceable(), Lawn(), mSide(other.mSide)
	{

	}

	EquilateralTriangleLawn& EquilateralTriangleLawn::operator=(const EquilateralTriangleLawn& other)
	{
		if (&(*this) != &other)
		{
			mSide = other.mSide;
		}

		return *this;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned int round = mSide * 3;
		double temp = static_cast<double>(round) / static_cast<double>(WIDTH_FENCE);
		temp = ceil(temp);

		return static_cast<unsigned int>(temp);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int round = mSide * 3;
		switch (fenceType)
		{
		case RED_CEDAR:
			return round * COST_RED_CENDAR;
		case SPRUCE:
			return round * COST_SPRUCE;
		default:
			return 0;
		}
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double height = (static_cast<double>(mSide) / 2) * sqrt(3.0);
		double area = (height * static_cast<double>(mSide)) / 2;
		area = round(area);

		return static_cast<unsigned int>(area);
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

}