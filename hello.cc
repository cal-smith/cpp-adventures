#include <iostream>

using namespace std;

int main(){
	auto name = string{};
	cout << "Name: ";
	cin >> name;
	cout << "Hello " << name << endl;
	return 0;
}