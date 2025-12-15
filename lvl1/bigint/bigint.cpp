#include "bigint.hpp"
#include <algorithm>
#include <sstream>

bigint::bigint() : _string("0") {}

bigint::bigint(unsigned long long n) {
	std::ostringstream oss;
	oss << n;
	_string = oss.str();
}

bigint::bigint(const std::string &str) : _string(str) {
	remove_leading_zeros();
}

bigint::bigint(const bigint &other) : _string(other._string) {}

bigint::~bigint() {}

void bigint::remove_leading_zeros() {
	std::cout << "!!!!!!!!!!!!HHHHHHHHHHHHHIIIIIIIIIII!!!!!!!!!!" << std::endl;
	size_t start = _string.find_first_not_of('0');
	if (start == std::string::npos)
		_string = "0";
	else
		_string = _string.substr(start);
}

std::string bigint::getvalue() const {
	return _string;
}

bigint bigint::operator+(const bigint &other) const {
	std::string s1 = _string;
	std::string s2 = other._string;

	if (s2.size() > s1.size())
		std::swap(s1, s2);

	std::string result = "";
	int i = s1.length() - 1;
	int j = s2.length() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
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

	return bigint(result);
}

bigint &bigint::operator+=(const bigint &other) {
	*this = *this + other;
	return *this;
}

bigint bigint::operator++(int) {
	bigint temp(*this);
	*this += bigint(1);
	return temp;
}

bigint &bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator<<(size_t shift) const {
	if (_string == "0")
		return *this;
	return bigint(_string + std::string(shift, '0'));
}

bigint &bigint::operator<<=(size_t shift) {
	if (_string != "0")
		_string.append(shift, '0');
	return *this;
}

bigint bigint::operator>>(size_t shift) const {
	if (shift >= _string.size())
		return bigint(0);
	return bigint(_string.substr(0, _string.size() - shift));
}

bigint &bigint::operator>>=(size_t shift) {
	if (shift >= _string.size())
		_string = "0";
	else
		_string.erase(_string.size() - shift);
	return *this;
}

bool bigint::operator<(const bigint &other) const {
	if (_string.size() < other._string.size())
		return true;
	if (_string.size() > other._string.size())
		return false;

	int i = 0;
	while (i < (int)_string.size())
	{
		if (_string[i] < other._string[i])
			return true;
		else if (_string[i] > other._string[i])
			return false;
		i++;
	}
	return false;
}

bool bigint::operator>(const bigint &other) const {
	return other < *this;
}

bool bigint::operator<=(const bigint &other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint &other) const {
	return !(*this < other);
}

bool bigint::operator==(const bigint &other) const {
	return _string == other._string;
}

bool bigint::operator!=(const bigint &other) const {
	return !(*this == other);
}

std::ostream &operator<<(std::ostream &out, const bigint &num) {
	out << num.getvalue();
	return out;
}
