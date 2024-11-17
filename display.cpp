#include <iostream>
#include<vector>
using namespace std;

class Array {
private:
	vector<int>arr;
public:
	void add(int value) {
		arr.push_back(value);
	}
	void display() const {
		cout << "Array elemenets:";
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
	myArray.display();
	return 0;
}

