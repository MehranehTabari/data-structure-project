#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
	vector<int>arr;
public:
	void Insert(int index, int value) {
		if (index<0 || index>arr.size()) {
			cout << "Index out of bounds";
			return;
		}
		arr.insert(arr.begin() + index, value);
	}
	void Display() {
		for (int i : arr) {
			cout << i;
		}
		cout << endl;
	}

};

int main()
{
	Array myArray;
	myArray.Insert(2, 25);

	myArray.Display();
		return 0;
}

