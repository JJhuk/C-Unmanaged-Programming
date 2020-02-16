#pragma once

#include "Person.h"
#include <string>

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle();
		Vehicle(const Vehicle& other);

		Vehicle& operator=(const Vehicle& other);

		virtual  ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalMoveCount() const;

		void Deinitializer();

		void InitTravel(unsigned int maxMoveCount, unsigned int mustRestCount);

		void TravelVehicle();
		unsigned int GetTotalPassengerWeight() const;

		const Person* MovePassenger(unsigned int idx);

	private:
		const Person* mPassenger[100];
		unsigned int mTotalPassengerWeight;
		unsigned int mSize;
		unsigned int mMaxPassengersCount;

		void setMustRestCount(unsigned int mustRestCount);
		void setMaxMoveCount(unsigned int maxMoveCount);

		//����
		unsigned int mNowRestCount;	//���� �󸶳� ��������
		unsigned int mMustRestCount; //�ִ� ����� �ϴ���

		unsigned int mMaxMoveCount;	//�ִ� �󸶳� �� �� �ִ���
		unsigned int mNowMoveCount;	//���� �󸶳� ������.

		unsigned int mTotalMoveCount;	//�� �󸶳� ����.
	};
}
