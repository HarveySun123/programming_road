typedef int* int_p;
static int a = 42;
static int b = 43;

void foo() {
	const int_p p1 = &a;
	p1 = &b;
	*p1 = 44;
}

void fun() {
	int const* p2 = &a;
	p2 = &b;
	*p2 = 45;
}

int main() {
	foo();
	fun();
	return 0;
}