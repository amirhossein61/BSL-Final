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

void Animation::pushBackAtt(Attribute *attribute)
{
	atts.push_back(attribute);
}


std::string Animation::getName() const
{
	return name;
}

void Animation::setName(std::string n)
{
	name = n;
}
