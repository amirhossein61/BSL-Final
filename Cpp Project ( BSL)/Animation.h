#pragma once
#include<string>
#include<vector>
#include"Attribute.h"
class Animation
{
public:
	Animation();
	virtual ~Animation() {};
	std::vector<Attribute*> getAtt()const;
	void setAtt(std::vector<Attribute*>&);
	std::string getName()const;
	void setName(std::string);

private:
	std::vector<Attribute*> atts;
	std::string name;
};

