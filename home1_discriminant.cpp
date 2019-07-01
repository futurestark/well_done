#include <iostream>
#include <cmath>

int main(const int const argc, const char* const argv[])    //this correct arg types must be
{
	int two = 2;
	int four = 4;
	double a = 0, b = 0, c = 0, x = 0, discriminant = 0, root_x1 = 0, root_x2 = 0;

	std::cout << "Enter a b c values, where a != 0, for example 1 -8 12" << std::endl;
	std::cin >> a >> b >> c;  // 1 -8 12  result must be 16, -131, 7

	if (a == 0) std::cout << "a == 0 enter value where a > 0" << std::endl;
	discriminant = b*b - four * a * c;
	std::cout << discriminant << std::endl;

	if (discriminant < 0) std::cout << " D < 0 so there are no roots" << std::endl;

	else if (discriminant > 0) {
		std::cout << "Discriminant > 0 so equation has 2 roots" <<  std::endl;
		root_x1 = (-b + sqrt(b * b - four * a * c)) / two * a;
		root_x2 = (-b - sqrt(b * b - four * a * c)) / two * a;
		std::cout << "first root is " << root_x1 << " second root is " << root_x2 << std::endl;
	}
	else if (discriminant == 0) {
		std::cout << "D == 0 so equation has 1 root" << std::endl;
		root_x1 = (-b + sqrt(b * b - four * a * c)) / two * a;
		std::cout << "root is " << root_x1 << std::endl;
	}
	return 0;
}