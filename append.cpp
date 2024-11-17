#include <iostream>
#include <vector>
using namespace std;

class Array {
private:
	vector<int>arr;
public:
	void Append(int value) {
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

	myArray.Append(10);

	myArray.Append(20);

	myArray.display();
	return 0;
    
}
