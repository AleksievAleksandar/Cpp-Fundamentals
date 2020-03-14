#include "IndexedSet.h"

IndexedSet::IndexedSet():
	valuesArray(nullptr)
{
}

IndexedSet::IndexedSet(const IndexedSet& other)
{
	if (this != &other)
	{
		this->valuesSet = other.valuesSet;
		this->valuesArray = nullptr;
	}
}

void IndexedSet::add(const Value& v)
{
	this->valuesSet.insert(v);
	if (this->valuesArray != nullptr)
	{
		delete[] this->valuesArray;
	}
	else
	{
		valuesArray = nullptr;
	}
}

size_t IndexedSet::size() const
{
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (index < valuesSet.size() && valuesArray == nullptr)
	{
		this->valuesArray = new Value[this->valuesSet.size()];
		size_t cnt = 0;
		for (auto i : valuesSet)
		{
			this->valuesArray[cnt] = i;
			cnt++;
		}
		return valuesArray[index];
	}
	else
	{
		return valuesArray[index];
	}
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	if (&other == this)
	{
		return *this;
	}
	else
	{
		this->valuesSet = other.valuesSet;
		if (this->valuesArray != nullptr)
		{
			delete[] this->valuesArray;
			this->valuesArray = nullptr;
		}	
		return *this;
	}
}

IndexedSet::~IndexedSet()
{
	delete[] this->valuesArray;
	this->valuesArray = nullptr;
}

