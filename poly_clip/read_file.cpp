#ifndef read_file_cpp
#define read_file_cpp
#include "poly_clip.hpp"
#include "Globals.h"
#include "point_3d.hpp"

//############################### reading input file ###############################//

int read_file(string FILENAME) {
	cout << "function read_file was called" << endl;//control print to console
	cout << "the chosen filename was: " << FILENAME << endl;


	int	nr_poly,//number of polygons
		nr_points;//number of points in polygon
	double dump1;
	double dump2;
	double dump3;

	

	vector<vector<point_3d>> *data_storage = Globals::getDatastorage();


	//############################### open file ###############################//
	ifstream file;
	file.open(FILENAME);

	//############################### exception handling ###############################//
	if (!file.is_open()) {
		cout << "file is missing!" << endl;
		cout << "function read_file is cancelled!" << endl;//control print to console
		cout << endl << "########################################" << endl;//separating print to console
		return 0;
	}
	//############################### start reading ###############################//
	file >> nr_poly;
	cout << "number of polygons ins this file: " << nr_poly << endl;//control print to console

	for (int i = 0; i < nr_poly; i++) {//looping trough polygons
		file >> nr_points;
		cout << "number of points in this polygon:  " << nr_points << endl;//control print to console

		vector<point_3d> poly;

		for (int j = 0; j < nr_points; j++) {//looping trough points of this polygon
			file >> dump1;
			cout << j << " x value: " << dump1 << endl;//control print to console
			file >> dump2;
			cout << j << " y value: " << dump2 << endl;//control print to console
			dump3 = 0;
			cout << j << " z value: " << dump3 << endl;//control print to console
			
			poly.push_back(point_3d(dump1, dump2, dump3));
				

			
		}//point loop
		
		data_storage->push_back(poly);
	}//polygon loop

	Globals::setDatastorage(data_storage);
	cout << endl << "########################################" << endl <<endl;//separating print to console
	
	cout << "controlprint of the data_storage vector" << endl;//control print to console

	for (unsigned int i = 0; i < data_storage->size(); i++)
	{
		for (unsigned int j = 0; j < data_storage[i].size(); j++)
		{
			//zeiger auf den vector 
			cout << data_storage->at(i)[j].Get_x_value() << endl;

		//	cout << data_storage[i][j]->Get_y_value() << endl;
		}
	}


	cout << "function read_file is finished" << endl;//control print to console
	cout << endl << "########################################" << endl;//separating print to console
	
	return 0;
}
#endif read_file_cpp