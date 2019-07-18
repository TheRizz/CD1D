/*************************************************************************
 * AUTHOR		: Ryan Martinez
 * DUE DATE		: 5/17/2018
 ************************************************************************/
#include "header.h"
#include "VectorArray.h"


int main()
{

	//---------------------------------------------------------------------

	ArrayVector<string> Vector;

	//---------------------------------------------------------------------

	cout << "This is a test of a Vector ADT\n\n";

	cout << "The vector contains " << Vector.size() << " items\n";
	cout << "The vector's capacity is " << Vector.cap() << "\n";
	if (Vector.empty()) {
		cout << "The vector is empty\n";
	}
	else{
		cout << "The vector is not empty\n";
	}
	Vector.insert(0, "No lemon, no melon");
	cout << Vector[0] << " has been added to the vector\n";
	cout << "The vector's capacity is " << Vector.cap() << "\n";
	Vector.insert(1, "A man, a plan, a canal, Panama");
	cout << Vector[1] << " has been added to the vector\n";
	Vector.insert(1, "Sit on a potato pan, Otis");
	cout << Vector[1] << " has been added to the vector\n";
	Vector.insert(1, "Was it a car or a cat I saw?");
	cout << Vector[1] << " has been added to the vector\n";
	cout << "The vector's capacity is " << Vector.cap() << "\n";
	cout << "The vector contains " << Vector.size() << " items\n";
	if (Vector.empty()) {
		cout << "The vector is empty\n";
	}
	else {
		cout << "The vector is not empty\n";
	}
	cout << Vector[0] << " is at the front of the vector\n";
	cout << Vector[1] << " is the second item in the vector\n";
	cout << Vector[1] << " has been removed from the vector\n";
	Vector.erase(1);
	cout << "The vector contains " << Vector.size() << " items\n";
	cout << Vector[1] << " is the second item in the vector\n";

	return 0;
}


