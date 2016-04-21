#include "Globals.h"
#include <cstddef>

vector<vector<point_3d>> Globals::*g_data_storage;

void Globals::setDatastorage(vector<vector<point_3d>> *v)
{
	g_data_storage = v;
}

vector<vector<point_3d>>* Globals::getDatastorage()
{
	if (g_data_storage == 0) {
		g_data_storage = new vector<vector<point_3d>>;
	}
	return g_data_storage;
}
