#pragma once
#include "poly_clip.hpp"

static class Globals
{
public:
	
	static void setDatastorage(vector<vector<point_3d>> *v);
	static vector<vector<point_3d>>* getDatastorage();

private:
	//vectoer c++ 2001 templates in includes?
	static vector<vector<point_3d>> *g_data_storage;
};

