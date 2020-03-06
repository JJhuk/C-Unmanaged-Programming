#pragma once
#include <queue>
#include <limits>

using namespace std;

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue& operator=(const SmartQueue<T>& rhs);
		~SmartQueue();
		void Enqueue(const T& number);
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
		void renewSmartQueue();
		queue<T> mQueue;
		T mMax;
		T mMin;
		T mSum;
		double mAvg;
		double mVariance;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue() :
		mMax(numeric_limits<T>::min()), mMin(numeric_limits<T>::max()),
		mSum(0), mAvg(0.0), mVariance(0.0)
	{

	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& other) :
		mMax(other.mMax), mMin(other.mMin), mSum(other.mSum), mAvg(other.mAvg), mVariance(other.mVariance)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this != &rhs)
		{
			mQueue = rhs.mQueue;
			mMax = rhs.mMax;
			mMin = rhs.mMin;
			mSum = rhs.mSum;
			mAvg = rhs.mAvg;
			mVariance = rhs.mVariance;
		}
		return *this;
	}

	template <typename T>
	SmartQueue<T>::~SmartQueue()
	{
		mMax = NULL;
		mMin = NULL;
		mSum = NULL;
		mAvg = NULL;
		mVariance = NULL;
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(const T& number)
	{
		mQueue.push(number);
		mSum += number;
		mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		renewSmartQueue();
	}

	template <typename T>
	T SmartQueue<T>::Peek() const
	{
		return mQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		T tempVal = mQueue.front();
		mSum -= tempVal;
		mQueue.pop();
		if (!mQueue.empty()) //ť�� ����ִ��� üũ
		{
			mAvg = static_cast<double>(mSum) / static_cast<double>(mQueue.size());
		}
		else
		{
			mAvg = 0;
		}
		renewSmartQueue();
		return tempVal;
	}

	template <typename T>
	T SmartQueue<T>::GetMax() const
	{
		return mMax;
	}

	template <typename T>
	T SmartQueue<T>::GetMin() const
	{
		return mMin;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage() const
	{
		return round(mAvg * 1000.0) / 1000.0;
	}

	template <typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::GetVariance() const
	{
		return round(mVariance * 1000.0) / 1000.0;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		if (mVariance != 0)
		{
			return round(sqrt(mVariance) * 1000.0) / 1000.0;
		}
		return 0;
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mQueue.size();
	}

	template <typename T>
	void SmartQueue<T>::renewSmartQueue()
	{
		mMax = numeric_limits<T>::min();
		mMin = numeric_limits<T>::max();
		if (!mQueue.empty())
		{
			queue<T> tempQueue = mQueue;


			T forVarianceSum = 0;

			while (!tempQueue.empty())
			{
				T tempVal = tempQueue.front();
				tempQueue.pop();
				//,,,,,,,
				mMax = mMax > tempVal ? mMax : tempVal;
				mMin = mMin < tempVal ? mMin : tempVal;
				forVarianceSum += (tempVal - static_cast<T>(mAvg)) * (tempVal - static_cast<T>(mAvg));
			}
			mVariance = static_cast<double>(forVarianceSum) / static_cast<double>(mQueue.size());
		}
		else
		{
			mVariance = 0.0;
		}
	}
}
