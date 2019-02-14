#pragma once
#include<string>
class Animation
{
public:
	Animation();
	virtual ~Animation() {};
	std::string getKey()const;
	std::string getValue()const;
	std::string getName()const;
	void setKey(std::string);
	void setValue(std::string);
	void setName(std::string);

private:
	std::string key;
	std::string value;
	std::string name;
};

