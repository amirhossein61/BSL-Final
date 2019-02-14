#include "stdafx.h"
#include "Attribute.h"
#include<string>

Attribute::Attribute()
{
}

std::string Attribute::getKey() const
{
	return key;
}

std::string Attribute::getValue() const
{
	return value;
}

void Attribute::setKey(std::string key)
{
	this->key = key;
}

void Attribute::setValue(std::string value)
{
	this->value = value;
}
