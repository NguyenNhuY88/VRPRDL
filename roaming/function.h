
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;

class Location {
public:
	int id;
	double windowStartTime;
	double windowEndTime;
	long double xCoor, yCoor;
	void printTimeWindow() {
       cout << id <<"toa do(" << xCoor <<","<<yCoor<<") "
            << "[" << windowStartTime << "," << windowEndTime << "] \t";

    }
};

class Customer{
public:
	int id;
	vector<Location> locationList;
	double demand;

    void printListLocation() {
        for (int i = 0; i < locationList.size(); i++) {
            locationList[i].printTimeWindow();
        }
        cout << endl;
    }
};

class Vehicle {
public:
	double capacity;
	vector<Location> route;
};

class Solution{
public:

	int nbOfCustomer;
	int nbOfLocation;
	int timeHorizon;
	float vehCapacity;
	int nbOfVehicle;

	vector<Vehicle> vehicleList;
	vector<Customer> customerList;
	//vector<Location> locationList;

//	double disBtwLocation[500][500];
    double timeTravel[500][500];
	void ReadProblem(char* filename);
//	void BuildDistArray();
    void PrintInput();
};

