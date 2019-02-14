#include "stdafx.h"
#include "Animation.h"

using namespace std;
Animation::Animation()
{
}

std::vector<Attribute*> Animation::getAtt() const
{
	return atts;
}

void Animation::setAtt(std::vector<Attribute*>& att)
{
	atts = att;
}


std::string Animation::getName() const
{
	return name;
}

void Animation::setName(std::string n)
{
	name = n;
}
