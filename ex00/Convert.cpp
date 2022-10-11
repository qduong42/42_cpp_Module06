#include "Convert.hpp"

//	CONSTRUCTORS | DESTRUCTOR

Convert::Convert():_inter(0)
{}

Convert::Convert(char *str):_str(str), _rest(NULL)
{
	this->_inter = std::strtod(this->_str.c_str(), &(this->_rest));
	if ((!isdigit(this->_str.c_str()[0]) && strlen(this->_str.c_str()) > 1) || (isdigit(this->_str.c_str()[0]) && (strlen(this->_rest) >= 1 && (this->_rest[0] != 'f' || strlen(this->_rest) > 1))))
		throw Convert::ConversionImpossible();
}

Convert::Convert(Convert const& obj)
{
	(*this = obj);
}

Convert& Convert::operator=(Convert const& obj)
{
	this->_inter = obj.getInter();
	return (*this);
}

Convert::~Convert()
{}

//	MEMBER FUNCTIONS

double Convert::getInter()const
{
	return (this->_inter);
}

char Convert::getCha()const
{
	return (this->_str[0]);
}

std::string Convert::printChar()const
{
	std::string out = "char: ";
	char c;
	if (isdigit(_str[0]))
	{
		c = static_cast<char> (this->getInter());
	}
	else
		c = static_cast<char> (_str[0]);
	if (this->_inter > static_cast<double>(CHAR_MAX) || this->_inter < static_cast<double> (CHAR_MIN))
		out = out + "impossible";
	else
		if (std::isprint(c))
			out = out + c;
		else
			out = out + "Non displayable";
	return (out + "\n");
}

//std to_string

std::string Convert::printInt()const
{
	std::string out = "int: ";
		int i = static_cast<int>(this->getInter());
		if (!isdigit(_str[0]) || isnan(this->_inter) || this->_inter > static_cast<double>(INT_MAX) || this->_inter < static_cast<double>(INT_MIN))
			out += "impossible";
		else
			out += std::to_string(i);
	return (out + "\n");
}

float Convert::printFloat()const
{
		// std::string out = "float: ";
		float i = static_cast<float>(this->getInter());
		// out += std::to_string(i);
	return (i);
}

double Convert::printDouble()const
{
		// std::string out= "double: ";
		double d = static_cast<double>(this->getInter());
		// out += std::to_string(d);
		return (d);
}

std::ostream& operator<<(std::ostream &o, Convert const &i)
{
	o << i.printChar()
	<< i.printInt();
	if (isdigit(i.getCha()))
	{
		o << "float: " << std::fixed <<  std::setprecision(1) << i.printFloat() << "f\n"
		<< "double: " << std::fixed << std::setprecision(1) << i.printDouble() << std::endl;
	}
	else
		o << "float: impossible\ndouble: impossible\n";
	return (o);
}

const char* Convert::ConversionImpossible::what() const throw()
{
	return ("Conversion not possible ERROR 404");
}
