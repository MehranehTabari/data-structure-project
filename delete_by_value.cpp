#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
	vector<int>arr;
public:
	void add(int value) {
		arr.push_back(value);
	}

	int Delete_By_Value(int value) {
		for (size_t i = 0; i < arr.size(); ++i) {
			if (arr[i] == value) {
				arr.erase(arr.begin() + i);
				return i;
			}
		}
		return -1;
	}
	void display() const {
		for (int value : arr) {
			cout << value;
		}
		cout << endl;
	}

};

int main()
{
	Array myArray;
	for (int i = 1; i <= 5; ++i) {
		myArray.add(i);
	}
	cout << "initial array:";
	myArray.display();

	int value_to_delete;
	cout << "enter value to delete";
	cin >> value_to_delete;

	int index = myArray.Delete_By_Value(value_to_delete);

	if (index != -1) {
		cout << "value" << value_to_delete << "not found in the array.n";
	}
	cout << "Array after delection:";
	myArray.display();

	return 0;

}

