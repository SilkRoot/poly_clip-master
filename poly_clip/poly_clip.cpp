//############################### main method ###############################//

#include "poly_clip.hpp"
#include "Globals.h"

const int len_filename = 50;//maximum length of input file

int main() {
	//############################### object/variable definitions ###############################//
	char	Filename[len_filename];//input file name
	std::string filename = std::string("");
	

//	int		nr_poly = 0,//number of polygons
//			nr_points = 0;//number of points in polygon
//	vector< vector<point_3d> > polygons;//two-dimensional vector: 1st level polygon, 2nd level points of polygon
	
	//############################### read ###############################//
	
	cout << "name of input file:" << endl;
	cin >> filename;
	cout << "entered name of input file: " << Filename << endl;//controlprint to console
	cout << endl << "########################################" << endl <<endl;//separating print to console
	read_file(filename);
//	read_file(filename, &data_storage); --> *

	cout << endl << "########################################" << endl << endl;//separating print to console

	cout << "controlprint of the data_storage vector" << endl;//control print to console

	vector<vector<point_3d>> *data_storage = Globals::getDatastorage();
	for (unsigned int i = 0; i < data_storage->size(); i++)
	{
		for (unsigned int j = 0; j < data_storage[i].size(); j++)
		{
			cout << data_storage->at(i)[j].Get_x_value() << endl;
			cout << data_storage->at(i)[j].Get_y_value() << endl;
		}
	}

	//prevents console from closing
	int p;
	cin >> p;

	return 0;
}