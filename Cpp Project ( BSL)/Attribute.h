#pragma once
#include<string>
class Attribute
{
public:
	Attribute();
	virtual ~Attribute() {};
	std::string getKey()const;
	std::string getValue()const;
	void setKey(std::string);
	void setValue(std::string);

private:
	std::string key;
	std::string value;
};

