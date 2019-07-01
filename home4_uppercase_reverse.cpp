#include <iostream>
#include <cmath>

void reverse(const char* s, int str_length);

int main(const int const argc, const char* const argv[])    //this correct arg types must be
{
	
	int c = 0;
	/*
	while ((c = getchar()) != EOF) {
		if ('a' <= c && c <= 'z') {
			c += 'A' - 'a';
		}
		putchar(c);
	}
	assert (! ferror (stdin));
	*/
	//----------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------
	/*
	int digit = 0, int symbol = 0;
	while ((digit = getchar()) != EOF) {   //is digit
		if ( 48 <= digit && digit <= 57) {  //ascii 0 == 48   8 == 56   9 == 57
			std::cout << "is digit " << std::endl;
		}
		//putchar(c);
	}
	*/

	char str_to_lowercase[128] = { 0 };
	std::cout << "Enter string in Uppercase for conversion to lowercase (max_size 128 symbols)" << std::endl;
	std::cin.getline(str_to_lowercase, 128);
	std::cout << "Our string is " << str_to_lowercase << std::endl;

	for(int i=0; i<sizeof(str_to_lowercase)-1; i++)   //using difference between small and big letters
	{
		if(str_to_lowercase[i] >='A' && str_to_lowercase[i] <='Z') str_to_lowercase[i]+='z'-'Z'; // <= to keep A and Z conversion not just <
		//if(str[i]>'А' && str[i]<'Я') str[i]+='я'-'Я';
		std::cout << str_to_lowercase[i];
	}
	std::cout << std::endl;

	char str_to_uppercase[128] = { 0 };
	std::cout << "Enter string in Lowercase for conversion to Upercase (max_size 128 symbols)" << std::endl;
	std::cin.getline(str_to_uppercase, 128);
	std::cout << "Our string is " << str_to_uppercase << std::endl;
	for (int i = 0; i < sizeof(str_to_uppercase) - 1; i++)   //using difference between small and big letters
	{
		if (str_to_uppercase[i] >= 'a' && str_to_uppercase[i] <= 'z') str_to_uppercase[i] += 'Z' - 'z'; // <= to keep A and Z conversion not just <
		//if(str[i]>'А' && str[i]<'Я') str[i]+='я'-'Я';
		std::cout << str_to_uppercase[i];
		// from lower to upper and from upper to lower in one time variant
		/*                     
		if ('a' <= s[i] && s[i] <= 'z') {
			s[i] = char(((int)s[i]) - 32);
		}
		else if ('A' <= s[i] && s[i] <= 'Z') {
			s[i] = char(((int)s[i]) + 32);
		}
		*/
	}
	std::cout << std::endl;

	char str_for_reverse[128] = { 0 };
	int str_length = 0;
	std::cout << "Enter string for reverse function (max_size 128 symbols)" << std::endl;
	std::cin.getline(str_for_reverse, 128);   //cin string before end of string(enter)
	str_length = strlen(str_for_reverse);
	std::cout << "Our string is " << str_for_reverse << "and str length is " << str_length << std::endl;
	reverse(str_for_reverse, str_length); //cout elements is in body of func
	
	return 0;
}

void reverse(const char* s, int str_length) {

	if (NULL == s || "" == s)
		std::cout << "";
	else {
		for (int i = str_length-1; i >= 0; i--)
			std::cout << s[i];
	}
}