#include "bigint.hpp"

bigint::bigint() {
	std::cout << "bigint default constructor" << std::endl;
}

bigint::bigint(unsigned long long num) {
	std::ostringstream oss;
	oss << num;
	_string = oss.str();
}

bigint::bigint(const std::string &str) : _string(str) {
	remove_leading_zeros();
}

bigint::~bigint() {
	std::cout << "bigint destructor" << std::endl;
}

void	bigint::remove_leading_zeros() {
	size_t start = _string.find_first_not_of('0');
	if (start == std::string::npos)
		_string = "0";
	else
		_string = _string.substr(start);
}

bigint bigint::operator+(const bigint &obj) const {
	std::string s1 = _string;
	std::string s2 = obj._string;
	std::string result = "";

	if (s2.size() > s1.size())
		std::swap(s1, s2);

	int i = s1.length() - 1;
	int j = s2.length() - 1;
	int carry = 0;

	while(i >= 0 || j >= 0 || carry) {
		int digit1;
		if (i >= 0)
			digit1 = s1[i] - '0';
		else
			digit1 = 0;
		int digit2;
		if (j >= 0)
			digit2 = s2[j] - '0';
		else
			digit2 = 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		sum = sum % 10;

		result.insert(result.begin(), sum + '0');
		i--;
		j--;
	}
	return(bigint(result));
}

bigint &bigint::operator+=(const bigint &obj) {
	*this = *this + obj;
	return(*this);

}

bigint bigint::operator++(bigint &obj) {
	int temp;

	temp = 
}