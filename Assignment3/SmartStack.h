#pragma once
#include <stack>
using namespace  std;
namespace assignment3
{
	template <typename T>
	class SmartStack
	{
	public:
		SmartStack();

		~SmartStack();
		SmartStack(const SmartStack& other);

		void Push(const T& val);	//Pop�� push���� ���� �ٽ� ��������
		T Pop();
		T Peek() const;
		T GetMax() const;	//�ð����⵵�� O(1)�̾�� ��.
		T GetMin() const;
		double GetAverage() const;	//4��° �ڸ� �ݿø�.
		T GetSum() const;
		double GetVariance() const;	//�ð����⵵�� O(1)�̾�� ��. 
		double GetStandardDeviation() const;	//�ð����⵵�� O(1)�̾�� ��.
		unsigned int GetCount() const;


		SmartStack& operator=(const SmartStack& rhs);

	private:
		bool RenewSmartStack();
		stack<T> mStack;
		T mMax;
		T mMin;
		T mSum;
		T mAvg;
		double mVariance;

	};


}
