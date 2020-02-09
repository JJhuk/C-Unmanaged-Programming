#pragma once

#include "eGrassType.h"

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

		//m2 �� �ܵ��� ����
		const double COST_BERMUDA;
		const double COST_BAHIA;
		const double COST_BENT_GRASS;
		const double COST_PERENNIAL_RYEGRASS;
		const double COST_ST_AUGUSTINE;

		//�� �ܵ��� ����
		const double AREA_ROLL_LAWN;

		//��Ÿ�� ���� ����
		const unsigned int COST_RED_CENDAR = 6;
		const unsigned int COST_SPRUCE = 7;

		//��Ÿ�� �ʺ�
		const double WIDTH_FENCE = 0.25;
	};
}
