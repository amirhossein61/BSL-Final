#pragma once
#include<string>
#include<vector>
#include"Attribute.h"
#include"Animation.h"
class Shape
{
public:
	Shape();
	virtual std::string toSVG() = 0;
	virtual ~Shape() {};
	std::string getName()const;
	void setName(std::string);
	std::vector<Attribute*> getAtt()const;
	void setAtt(std::vector<Attribute*>&);
	void pushBackAtt(Attribute*);
	std::vector<Animation*> getAnimate()const;
	void setAnimate(std::vector<Animation*>&);
	void pushBackAnimate(Animation*);

private:
	std::vector<Attribute*> att;
	std::vector<Animation*> animate;
	std::string nameOfShape;
};

