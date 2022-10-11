#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <limits.h>
#include <math.h>
#include <iomanip>

class Convert
{
	public:

		Convert();
		Convert(char *str);
		Convert(Convert const& obj);
		Convert& operator=(Convert const& obj);
		~Convert();

		double	getInter()const;
		char getCha()const;
		std::string	printChar() const;
		std::string	printInt() const;
		float	printFloat() const;
		double	printDouble() const;

		class ConversionImpossible: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
	private:


		double _inter;
		std::string _str;
		char* _rest;
};

std::ostream &operator<<(std::ostream &o, Convert const &i);

#endif
