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
	double xCoor, yCoor;
};

class Customer{
public:
	int id;
	vector<Location> locationList;
	double demand;

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
	int nbOfVehicle;
	int timeHorizon;

	vector<Vehicle> vehicleList;
	vector<Customer> customerList;
	vector<Location> locationList;

	double disBtwLocation[500][500];

	void ReadProblem(char* filename);
	void BuildDistArray();
};

int main(){
	Solution *s = new Solution();
	char* filename = "instance_0-triangle.txt";
	s->ReadProblem(filename);
	cout << s->nbOfCustomer << " " << s->nbOfLocation << " " << s->timeHorizon <<endl;
	cout << s->customerList[1].id << " " << s->customerList[1].demand << " " << endl;
}

void Solution::ReadProblem(char* filename){
	
//	freopen(filename, "r", stdin);
//	int maxCapacity;
//	//read in nb customer ...
//	cin >> nbOfCustomer >> nbOfLocation >> timeHorizon >> maxCapacity;
//	cout << nbOfCustomer << " " << nbOfLocation << " " << timeHorizon << " " << maxCapacity << endl;
//	//read customer info
//	for(int i=0; i<=nbOfCustomer; i++){
//		Customer *c = new Customer();
//		cin >> c->id >> c->demand;
//		string line;
//		
//	}

	int maxCapacity;
	ifstream file(filename);
	string line;
	getline(file, line);
	int value;
	istringstream iss(line);
	//read in nbCustomer...
	iss >> value;
	nbOfCustomer = value;
	iss >> value;
	nbOfLocation = value;
	iss >> value;
	timeHorizon = value;
	iss >> value;
	maxCapacity = value;
	
	getline(file, line);
	getline(file, line);
	getline(file, line);
	getline(file, line);
	//read customer info
	for(int i=0; i<=nbOfCustomer+1; i++){
		getline(file, line);
		cout << line <<endl;
		
		Customer *c = new Customer();
		int count = 1;
		while(iss >> value){
			if(count == 1){
				c->id = value;
				count ++;
			} else if(count == 2){
				c->demand = value;
				count ++;
			} else if(count >=3){
				Location *l = new Location();
				if(count%3 ==0){
					l->id = value;
					count ++;
				} else if(count%3 ==1){
					l->windowStartTime = value*1.0;
					count ++;
				} else{
					l->windowEndTime = value*1.0;
					count ++;
				}
				c->locationList.push_back(*l);
				locationList.push_back(*l);
			}
		}
		customerList.push_back(*c);
	}
}
