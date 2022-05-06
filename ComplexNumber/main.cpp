#include <iostream>
#include "Complex.h"


int main() {
	Decart n1(0.,0.), n2(1., 0.), n3(0., 1.), n4(1., 1.), n5(-1., 0.), n6(0., -1.), n7(-1., -1.), n8(11., 4.), n9(2., 6.), nt(0., 0.);
	
	Complex number1(n1);
	Complex number2(n2);
	Complex number3(n3);
	Complex number4(n4);
	Complex number5(n5);
	Complex number6(n6);
	Complex number7(n7);
	Complex number8(n8);
	Complex number9(n9);
	Complex t(nt);

	t = number1 + number2;
	t.PrintInSTDOut();
	t = number2 + number3;
	t.PrintInSTDOut();
	t = number4 - number3;
	t.PrintInSTDOut();
	t = number8 / number3;
	t.PrintInSTDOut();
	t = number8 * number9;
	t.PrintInSTDOut();
	t = number3;
	t = t.Power(2);
	t.PrintInSTDOut();
	t = number3;
	t = t.Power(3);
	t.PrintInSTDOut();
	t = number3;
	t = t.Power(4);
	t.PrintInSTDOut();


	vector<Complex> A;
	t = number3;
	A = t.Root(4);

	for (int i = 0; i < 4; i++) {
		A[i].PrintInSTDOut(USE_TRIGONOMETRIC);
	}
	
	return 0;
}