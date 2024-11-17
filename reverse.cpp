#include <iostream>
using namespace std;

void Reverse(int arr[], int size) {
	int left = 0;
	int right = size - 1;

	while(left < right) {
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

void Display(int arr[], int size) {
	cout << "Array elements:";
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
	cout << endl;
}

int main()
{
	int arr[] = { 1,2,3,4,5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "original";
	Display(arr, size);

	Reverse(arr, size);

	cout << "reversed";
	Display(arr, size);

	return 0;

}
