#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount) : mSize(0)
	{
		mNowMoveCount = 0;
		mNowRestCount = 0;
		mTotalMoveCount = 0;
		if (maxPassengersCount >= 0 && maxPassengersCount <= 100)
		{
			mMaxPassengersCount = maxPassengersCount;
		}
		else
		{
			mMaxPassengersCount = 100;
		}
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle() : mSize(0), mMaxPassengersCount(100)
	{
		mNowMoveCount = 0;
		mNowRestCount = 0;
		mTotalMoveCount = 0;
		for (unsigned int i = 0; i < mMaxPassengersCount; i++)
		{
			mPassenger[i] = nullptr;
		}
	}

	Vehicle::Vehicle(const Vehicle& other)
	{
		if (&other != nullptr)
		{
			mNowMoveCount = 0;
			mNowRestCount = 0;
			mTotalMoveCount = 0;
			mMaxPassengersCount = other.mMaxPassengersCount;

			for (unsigned int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}
			mSize = other.mSize;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}
		}
		else
		{
			mMaxPassengersCount = 100;
			mSize = 0;
			for (int i = 0; i < mMaxPassengersCount; i++)
			{
				mPassenger[i] = nullptr;
			}

			mNowMoveCount = other.mNowMoveCount;
			mNowRestCount = other.mNowRestCount;
			mMaxMoveCount = other.mMaxMoveCount;
			mTotalMoveCount = other.mTotalMoveCount;
			mMustRestCount = other.mMustRestCount;
		}

	}

	Vehicle& Vehicle::operator=(const Vehicle& other) {
		if (&other != &(*this))
		{
			mMaxPassengersCount = other.mMaxPassengersCount;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = nullptr;
			}
			mSize = other.mSize;

			for (unsigned int i = 0; i < mSize; i++)
			{
				mPassenger[i] = new Person(*other.mPassenger[i]);
			}

			mNowMoveCount = other.mNowMoveCount;
			mNowRestCount = other.mNowRestCount;
			mMaxMoveCount = other.mMaxMoveCount;
			mTotalMoveCount = other.mTotalMoveCount;
			mMustRestCount = other.mMustRestCount;
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mSize; i++)
		{
			delete mPassenger[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mSize < mMaxPassengersCount)
		{
			mPassenger[mSize] = person;
			mSize++;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= 0 && i < mSize)
		{
			const Person* temp[100] = { nullptr };
			for (unsigned int beforeRemoveIndex = 0; beforeRemoveIndex < i; beforeRemoveIndex++)
			{
				temp[beforeRemoveIndex] = mPassenger[beforeRemoveIndex];
			}
			delete mPassenger[i];
			for (unsigned int afterRemoveIndex = i + 1; afterRemoveIndex < mSize; afterRemoveIndex++)
			{
				temp[afterRemoveIndex - 1] = mPassenger[afterRemoveIndex];
			}
			mSize -= 1;
			for (unsigned int fillNullptr = 0; i < mMaxPassengersCount; fillNullptr++)
			{
				mPassenger[fillNullptr] = nullptr;
			}
			memcpy(mPassenger, temp, sizeof(mPassenger));
			return true;
		}
		else
		{
			return false;
		}
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mSize;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	unsigned Vehicle::GetTotalMoveCount() const
	{
		return mTotalMoveCount;
	}

	void Vehicle::InitTravel(unsigned maxMoveCount, unsigned mustRestCount)
	{
		setMaxMoveCount(maxMoveCount);
		setMustRestCount(mustRestCount);
	}

	void Vehicle::setMustRestCount(unsigned int mustRestCount)
	{
		mMustRestCount = mustRestCount;
	}

	void Vehicle::setMaxMoveCount(unsigned int maxMoveCount)
	{
		mMaxMoveCount = maxMoveCount;
	}

	void Vehicle::TravelVehicle()
	{
		if (mNowMoveCount < mMaxMoveCount)	//�׳� �̵��� �� ������
		{
			mTotalMoveCount++;	//�󸶳� �̵� ���� �ø���
			mNowMoveCount++;	//���� ��� �̵����� üũ
		}
		else if (mNowMoveCount == mMustRestCount)	//�ִ� �̵����� �� (����� ��)
		{
			if (mNowRestCount < mMustRestCount) //���� �� ������ ��
			{
				mNowRestCount++;	//ī��Ʈ �ø�
			}
			else if (mNowRestCount == mMustRestCount) //�� ��������
			{
				mNowRestCount = 0;
				mNowMoveCount = 0;
			}
		}

	}


	const Person* Vehicle::MovePassenger(unsigned int idx)
	{
		if (idx >= 0 && idx < mSize)
		{
			mSize--;

			const Person* temp = mPassenger[idx];
			mPassenger[idx] = nullptr;
			return temp;
		}
		else
		{
			return nullptr;
		}
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= 0 && i < mSize)
		{
			return mPassenger[i];
		}
		else
		{
			return nullptr;
		}
	}
}
