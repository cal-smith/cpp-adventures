#include <iostream>
#include <array>

using namespace std;

template<size_t SIZE>
void swap(array<int, SIZE> &a, int x, int y){
	//cout << a[x] << a[y] << endl;
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
	//cout << a[x] << a[y] << endl;
}

template<size_t SIZE>
string to_str(array<int, SIZE> a) {
	string s = "";
	for (int x: a) {
		s += to_string(x) + ", ";
	}
	return s;
}

template<size_t SIZE>
void qsort(array<int, SIZE> &a, int start, int end) {
	if (end-start > 1) {
		cout << start << end-1 << endl;
		int pivot = end/2;
		swap(a, pivot, end-1);
		int index = start;
		for (int i = start; i < end; i++) {
			if (a[i] <= a[end-1]) {
				swap(a, i, index);
				index += 1;
			}
		}
		swap(a, index, end-1);
		cout << to_str(a) << endl;
		cout << index << endl;
		pivot = index;
		qsort(a, start, pivot);
		qsort(a, pivot+1, end);
	}
}

int main(int argc, char const *argv[]) {
	array<int, 8> b {{2,1,6,3,4,7,5,8}};
	qsort<8>(b, 0, 8);
	cout << to_str<8>(b) << endl;
	return 0;
}