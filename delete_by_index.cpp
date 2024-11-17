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
	void Delete_By_Index(int index) {
		if (index < 0 || index >= arr.size()) {
			cout << "Index out of bounds";
			return;
		}
		arr.erase(arr.begin() + index);

		cout << "element at index" << index << "deleted";
	}
	void display()const {
		for (int value : arr) {
			cout << value;
		}
		cout << endl;
	}
};


int main()
{
	Array myArray;

	for (int i = 1; i <= 5;++i) {
		myArray.add(i);
		
}
	
	cout << "initial array:";
	myArray.display();

	int index_to_delete;
	cout << "enter index to delete";
	cin >> index_to_delete;

	myArray.Delete_By_Index(index_to_delete);

	
	cout << "Array after delection:";
	myArray.display();

	return 0;



}
