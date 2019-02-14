#pragma once
#include"Shape.h"
class SVG
{
public:
	SVG();
	virtual ~SVG() {};
	std::vector<Shape*>& getShape();
	void setShape(std::vector<Shape*>);
	std::string& makePic();
	void setWidth(std::string);
	void setHeight(std::string);
	std::string getWidth()const;
	std::string getHeight()const;

private:
	std::vector<Shape*> shape;
	std::string defaultSvg;
	std::string width;
	std::string height;
	std::string cmpSvg;
};

