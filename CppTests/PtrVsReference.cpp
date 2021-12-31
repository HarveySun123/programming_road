#include <iostream>

using namespace std;
int main() {
	int a = 1;
	long long b = 2.0;
	int* p = &a;
	long long& r = b;
	cout << sizeof(p) << " " << sizeof(r) << endl;
	cout << &a << " " << ++p << " " << ++(r) << endl;

	getchar();
	return 0;
}