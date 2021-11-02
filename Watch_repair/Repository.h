#pragma once

#include"Error.h"
#include<iostream>
#include<fstream>
using namespace std;

template <class T>
class Repository {
	T* arr;
	int maxCapacity;
	int currentCapacity;

public:
	Repository(int maxCapacity = 100)
	{
		this->maxCapacity = maxCapacity;
		currentCapacity = 0;
		arr = new T[maxCapacity];
	}

	~Repository()
	{
		//ctor -> baseCtor -> childCtor
		//dest -> childDest -> baseDest

		//WriteToFile(); -> error: getFileName = ""
		delete[] arr;
	}

	void Add(T& item)
	{
		if (currentCapacity >= maxCapacity)
			throw Error(ErrorCode::MaxSizeReached);

		arr[currentCapacity++] = item;
	}
	void Remove(int idx)
	{
		if (idx < 0 || idx >= currentCapacity)
			throw Error(ErrorCode::IdxOutsideLimit);

		for (int i = idx; i < (currentCapacity - 1); i++)
			arr[i] = arr[i + 1];

		currentCapacity--;
	}
	void Print()
	{
		cout << GetTitle() << endl;
		for (int i = 0; i < currentCapacity; i++)
		{
			cout << "\nЗамовлення №" << i + 1 << endl << arr[i] << /* << i << "--" << arr[i].ToString() << */ endl;
		}
	}

	T& operator[](int idx)
	{
		return this->arr[idx];
	}

protected:
	virtual string GetTitle() { return ""; }
	virtual string GetFileName() { return ""; }

	void WriteToFile()
	{
		ofstream fout(GetFileName());
		for (int i = 0; i < currentCapacity; i++)
		{
			fout << arr[i] << endl;
		}
		fout.close();
	}
};