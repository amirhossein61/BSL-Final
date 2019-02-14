#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
{
}

std::string Animation::getKey() const
{
	return key;
}

std::string Animation::getValue() const
{
	return value;
}

std::string Animation::getName() const
{
	return name;
}

void Animation::setKey(std::string k)
{
	key = k;
}

void Animation::setValue(std::string val)
{
	value = val;
}

void Animation::setName(std::string n)
{
	name = n;
}
