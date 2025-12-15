#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
	std::string _string;
	void remove_leading_zeros();

public:
	// Constructors
	bigint();
	bigint(unsigned long long n);
	bigint(const std::string &str);
	bigint(const bigint &other);
	~bigint();

	// Getter
	std::string getvalue() const;

	// Arithmetic
	bigint operator+(const bigint &other) const;
	bigint &operator+=(const bigint &other);

	// Increment
	bigint operator++(int);
	bigint &operator++();

	// Digit shift (base 10)
	bigint operator<<(size_t shift) const;
	bigint &operator<<=(size_t shift);
	bigint operator>>(size_t shift) const;
	bigint &operator>>=(size_t shift);

	// Comparison
	bool operator<(const bigint &other) const;
	bool operator>(const bigint &other) const;
	bool operator<=(const bigint &other) const;
	bool operator>=(const bigint &other) const;
	bool operator==(const bigint &other) const;
	bool operator!=(const bigint &other) const;

	// Output
	friend std::ostream &operator<<(std::ostream &out, const bigint &num);
};

#endif