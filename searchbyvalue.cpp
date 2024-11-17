#include <iostream>
using namespace std;

class Array{
private:
	int* arr;
	int size;

public:
	Array(int s) {
		size = s;
		arr = new int[size];
	}

	void InsertValues() {
		cout << "enter" << size<< "elements:";
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}
	int Search_By_Value(int value) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == value) {
				return i;
			}
		}
		return -1;
	}

	void Display() {
		cout << "array elements:";
		for (int i = 0; i < size; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	~Array() {
		delete[]arr;
	}

};


int main()
{
	int size;
	cout << "enter the size of the array:";
	cin >> size;

	Array myArray(size);
	myArray.InsertValues();
	myArray.Display();

	int value;
	cout << "enter value to search:";
	cin >> value;

	int index = myArray.Search_By_Value(value);
	if (index != -1) {
		cout << "value found at index:" << index << endl;
	}
	else {
		cout << "value not found in the array" << endl;
			
	}
	return 0;
}

