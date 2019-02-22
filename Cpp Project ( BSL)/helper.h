#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

class helper
{
public:
	helper();
	~helper();
	static size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
};

