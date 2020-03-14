#include "IndexedSet.h"
#pragma once

IndexedSet::IndexedSet():
	valuesArray(nullptr)
{
}

IndexedSet::IndexedSet(const IndexedSet& other)
{
	if (this != &other)
	{
		this->valuesSet = other.valuesSet;
		this->valuesArray = other.valuesArray;
	}
}

void IndexedSet::add(const Value& v)
{
	this->valuesSet.insert(v);
	delete[] this->valuesArray;
}

size_t IndexedSet::size() const
{
	return valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index)
{
	if (index < valuesSet.size())
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
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other)
{
	this->valuesSet = other.valuesSet;
	delete[] this->valuesArray;
	for (size_t i = 0; i < this->valuesSet.size(); i++)
	{
		this->valuesArray[i] = other.valuesArray[i];
	}
	return *this;
}

IndexedSet::~IndexedSet()
{
	delete[] this->valuesArray;
}
