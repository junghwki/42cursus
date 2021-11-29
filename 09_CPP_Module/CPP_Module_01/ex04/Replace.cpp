#include "Replace.hpp"

Replace::Replace(std::string filename, std::string before, std::string after)
{
	this->_filename = filename;
	this->_before = before;
	this->_after = after;
}

std::string Replace::GetFileName()
{
	return (_filename);
}

std::string Replace::GetBefore()
{
	return (_before);
}

std::string Replace::GetAfter()
{
	return (_after);
}