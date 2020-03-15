#pragma once
#include "FixedVector.h"
namespace lab8
{
	template <size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		~FixedVector();
		FixedVector(const FixedVector& other);
		FixedVector& operator=(const FixedVector& rhs);
		bool Add(const bool& bT);
		bool Remove(const bool& bT); //ó�� �߰��ϴ� T�� �����Ѵ�.
		const bool Get(const unsigned int& index) const;
		const bool operator[](const unsigned int& index);
		int GetIndex(const bool& bT) const; //ã�� �������� -1 ��ȯ
		size_t GetSize() const;
		size_t GetCapacity() const;
	private:
		size_t mSize;
		uint32_t mFixedVector[(N - 1) / 32 + 1];
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector() : mSize(0), mFixedVector{ 0 }
	{
		for (size_t i = 0; i < (N - 1) / 32 + 1; i++)
		{
			mFixedVector[i] = 0;
		}
	}

	template <size_t N>
	FixedVector<bool, N>::~FixedVector()
	{

	}

	template <size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector& other)
		: mSize(other.mSize), mFixedVector(other.mFixedVector)
	{

	}

	template <size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector& rhs)
	{
		if (this != &rhs)
		{
			mSize = rhs.mSize;
			mFixedVector = rhs.mFixedVector;
		}
		return *this;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(const bool& bT)
	{
		if (mSize >= N)
		{
			return false;
		}

		if (bT)
		{
			mFixedVector[mSize / 32] |= (1 << (mSize % 32));
		}
		else
		{
			mFixedVector[mSize / 32] &= ~(1 << (mSize % 32));
		}
		mSize++;
		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bT)
	{
		const size_t index = static_cast<size_t>(GetIndex(bT));
		if (index == -1) //���� ���
		{
			return false;
		}
		uint32_t mBeforeVector[(N - 1) / 32 + 1];
		memset(mBeforeVector, 0, sizeof(mBeforeVector));
		size_t arrayIndex = 0;
		for (size_t nowIndex = 0; nowIndex < mSize - 1; nowIndex++)
		{
			if (nowIndex < index)
			{
				if ((nowIndex % 32) == 31) //���ܿ;���
				{
					if (arrayIndex != (N - 1) / 32)
					{
						if (static_cast<bool>(mFixedVector[arrayIndex + 1] & (1 << 0)))
						{
							mBeforeVector[arrayIndex] |= (1 << 31);
						}
						else
						{
							mBeforeVector[arrayIndex] &= ~(1 << 31);
						}
						arrayIndex++;
					}
				}
				else //�׳�
				{

					if (static_cast<bool>(mFixedVector[arrayIndex] & (1 << nowIndex % 32)))
					{
						mBeforeVector[arrayIndex] |= (1 << (nowIndex % 32));
					}
					else
					{
						mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 32));
					}
				}
			}
			else if (nowIndex >= index)
			{
				if ((nowIndex % 32) == 31) //�� �տ� ���� ���� �迭�� �ִٸ�
				{
					if (arrayIndex != N / 32) //�� �� �迭�� �������� �ƴ϶��
					{
						if (static_cast<bool>(mFixedVector[arrayIndex + 1] & (1 << 0)))
						{
							mBeforeVector[arrayIndex] |= (1 << 31);
						}
						else
						{
							mBeforeVector[arrayIndex] &= ~(1 << 31);
						}
						arrayIndex++;
					}
				}
				else //�׳� �ٷ� �ڿ��� ���ܿ�
				{
					if (static_cast<bool>(mFixedVector[arrayIndex] & (1 << ((nowIndex % 32) + 1))))
					{
						mBeforeVector[arrayIndex] |= (1 << (nowIndex % 32));
					}
					else
					{
						mBeforeVector[arrayIndex] &= ~(1 << (nowIndex % 32));
					}
				}
			}
		}
		memcpy(mFixedVector, mBeforeVector, sizeof(mFixedVector));
		mSize--;
		return true;
	}

	template <size_t N>
	const bool FixedVector<bool, N>::Get(const unsigned& index) const
	{
		return mFixedVector[(index / 32)] & (1 << (index));
	}

	template <size_t N>
	const bool FixedVector<bool, N>::operator[](const unsigned& index)
	{
		return mFixedVector[(index / 32)] & (1 << (index));
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& bT) const
	{
		for (size_t i = 0; i < (mSize / 32) + 1; i++)
		{
			size_t endIndex = 32;
			if (i == (mSize / 32))
			{
				endIndex = mSize % 32;
			}
			for (size_t j = 0; j < endIndex; j++)
			{
				if (static_cast<bool>(mFixedVector[i] & (1 << j)) == bT)
				{
					return static_cast<int>(j + (32 * i));
				}
			}
		}
		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}

}
