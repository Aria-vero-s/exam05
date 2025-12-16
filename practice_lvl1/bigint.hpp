#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <sstream>
#include <string>

class bigint {
	private:
		std::string _string;

	public:
		bigint();
		~bigint();
		bigint(unsigned long long num);
		bigint(const std::string &str);
		void remove_leading_zeros();
		bigint bigint::operator+(const bigint &obj) const;
		bigint &bigint::operator+=(const bigint &obj);
};

#endif