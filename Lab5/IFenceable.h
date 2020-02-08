#pragma once

#include "eFenceType.h"

namespace lab5
{
	class IFenceable
	{
	public:
		virtual unsigned int GetMinimumFencesCount() const = 0;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const = 0;
	
		//��Ÿ�� ���� ����
		const unsigned int COST_RED_CENDAR = 6;
		const unsigned int COST_SPRUCE = 7;
		
		//��Ÿ�� �ʺ�
		const unsigned int WIDTH_FENCE = 25;
	};
}
