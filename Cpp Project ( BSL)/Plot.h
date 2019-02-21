#pragma once
#include<vector>
#include"SVG.h"
#include"rectangle.h"
#include<fstream>
#include<iostream>
class Plot:
	public Shape
{
public:
	Plot();
	virtual ~Plot() {};
	virtual std::string toSVG() override;
	std::vector<Shape*> getShape()const;
	void setShape(std::vector<Shape*>);
	void pushBackShape(Shape*);
	void readFile();
	void scatterPlot(std::string,std::string);
	std::string linePlot(std::string,std::string);
	void setRectangleFeatures();
	void setText();

private:
	std::vector<Shape*> shape;
	std::string s;
};

