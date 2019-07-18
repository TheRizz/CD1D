/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * STUDENT ID	: 389657
 * Assignment	: 7
 * CLASS		: CS1D
 * SECTION		: MW: 3:30 PM
 * DUE DATE		: 10/17/2016
 ************************************************************************/

#ifndef DOUBLEHASH_H_
#define DOUBLEHASH_H_

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


/*************************************************************************
 *
 * STRUCT  instance
 *________________________________________________________________________
 * Stores the data to be put in to a structure by a hashing function
 ************************************************************************/
template <typename T>
struct instance
{
	instance(): info(T()) {}
	T info;
	int key;
};

/*************************************************************************
 *
 * CLASS  hash
 *________________________________________________________________________
 * Stores values in to an array via hashing functions
 ************************************************************************/
template <typename T>
class hash
{
private:
	struct instance<T> list[29];
public:
	hash();
	void input(int key, T item);
	instance<T> remove(int key);
	void printList();
};

template <typename T>
hash<T>::hash()
{
}

//This method reads in a key and an item value and then stores them in to a
//a temporary variable and then inputs it in to the array via the hashing
//functions. If there is a collision then the value is input in to an
//incremented hashing function
template <typename T>
void hash<T>::input(int key, T item)
{
	instance<T> temp;
	temp.info = item;
	temp.key = key;
	if(list[(key % 29)].info == T())
	{
		list[(key % 29)] = temp;
	}
	else
	{
		int k;
		int j = 1;
		k = key % 29;
		k = j * (k + (17 - k % 17)) % 29;
		j++;
		while(list[k].info == T())
		{
			k = (key % 29) + j *(17 - k % 17);
			k = k % 29;
			j ++;
		}
		list[k] = temp;
	}
}

//This method checks for the key value of the item that is in the array at
//the key location. If the key is not equivalent then the hashing function
//incriments
template <typename T>
instance<T> hash<T>::remove(int key)
{
	instance<T> temp;
	int i = key % 29;
	int j = 1;
	while(key != list[i].key)
	{			//15				//5
		i = ((key % 29) + j * (17 - key % 17)) % 29;
		j++;
	}
	temp = list[i];
	list[i].info = T();
	return temp;
}

//This method will output all of the information in a print list, even the
//values that are empty
template <typename T>
void hash<T>::printList()
{
	cout << "The full hash list:\n";
	for(int i = 0; i <= 28; i++)
	{
		cout << right << "Index:" << setw(3) << i << left << setw(5) << " ";
		if(list[i].info == T())
		{
			cout << "Available\n";
		}
		else
		{
			cout << "(" << list[i].key << "," << list[i].info << ")\n";
		}
	}
}

#endif /* DOUBLEHASH_H_ */
