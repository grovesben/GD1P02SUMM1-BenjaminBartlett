#include<cassert>
#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H

template<typename T>

class CQuickSortAlgo
{
public:
	CQuickSortAlgo(int size, int growBy = 1) : m_array(NULL), m_maxSize(0),
		m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}

	~CQuickSortAlgo()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	void push(T val)
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		m_array[m_numElements] = val;
		m_numElements++;
	}

	void pop()
	{
		if (m_numElements > 0)
			m_numElements--;
	}

	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
		{
			return;
		}
		for (int k = index; k < m_maxSize - 1; k++)
			m_array[k] = m_array[k + 1];
		m_maxSize--;
		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;
	}

	T& operator[](int index)
	{
		assert(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}

	int search(T val)
	{
		assert(m_array != NULL);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}
		return -1;
	}

	void QuickSort(T _arrayFirst, T _arrayLast)
	{
		if (_arrayLast < 1 || _arrayLast > 4)
		{
			return;
		}
		assert(m_array != NULL);
		int pivotPoint, upCounter = _arrayFirst, downCounter = _arrayLast, head, tail;
		bool upValueFound = false;
		bool downValueFound = false;
		pivotPoint = (_arrayLast - _arrayFirst) / 2;

		// swap pivot to start
		T temp = m_array[pivotPoint];
		m_array[pivotPoint] = m_array[_arrayFirst];
		m_array[_arrayFirst] = temp;

		head = _arrayFirst;
		tail = _arrayLast;

		// convert while to for loop
		if (upCounter > downCounter)
		{
			return;
		}
		while (upCounter < downCounter)
		{
			while (!upValueFound) //increment through array to find value value greater than first value;
			{
				upCounter++;
				if (m_array[upCounter] > m_array[_arrayFirst])
				{
					upValueFound = true;
				}
			}
			while (!downValueFound)
			{
				downCounter--;
				if (m_array[downCounter] < m_array[_arrayFirst])
				{
					downValueFound = true;
				}
			}
			// swap 		
			if (_arrayLast < 1 || _arrayLast > 4)
			{
				return;
			}
			temp = m_array[upCounter];
			m_array[upCounter] = m_array[downCounter];
			m_array[downCounter] = temp;
		}
		if (_arrayLast < 1 || _arrayLast > 4)
		{
			return;
		}
		temp = m_array[downCounter];
		m_array[downCounter] = m_array[_arrayFirst];
		m_array[_arrayFirst] = temp;

		if (_arrayLast < 1 || _arrayLast > 4)
		{
			return;
		}
		if (pivotPoint < 1 || pivotPoint >= m_numElements)
		{
			return;
		}
		this->QuickSort(_arrayFirst, pivotPoint - 1);
		this->QuickSort(pivotPoint + 1, _arrayLast);
	}

	void clear() { m_numElements = 0; }
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}
private:
	T* m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;
};
#endif
