#pragma once
#include <queue>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue& operator=(const SmartQueue& rhs);
		~SmartQueue();
		void Enqueue(const T &number);
		T Peek() const;
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const; //�Ҽ� �׹�° �ڸ� ��ȯ�ؾ� ��
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
		
	private:
		void RenewSmartQueue();
		queue<T> mQueue;
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
		double mVariance;
		
	};
}

