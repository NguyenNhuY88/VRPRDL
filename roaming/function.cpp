#include"function.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
void Solution::ReadProblem(char* filename)
{

     string s;
    ifstream openFile(filename);
    if (openFile.is_open())
    {
        getline(openFile,s);

        getline(openFile,s);

    //read  number of Customer, number of Locaton, number of Vehicle, time horizon
        openFile >> nbOfCustomer >> nbOfLocation >> timeHorizon >> vehCapacity;
      //  cout << nbOfCustomer <<"\t"<<nbOfLocation <<"\t"<<timeHorizon <<"\t"<<vehCapacity<<endl;

    // delete line text and empty line
        getline(openFile,s);
        getline(openFile,s);
        getline(openFile,s);
        getline(openFile,s);
        getline(openFile,s);
    //read customer's infomation

        for(int i = 0; i < nbOfCustomer + 2; i++)
        {

            getline(openFile,s);
            cout <<s<<endl;

        // Xoa bo cac ki tu ] [ ,   thi day s se chi con lai cac so
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ']' || s[i] == '[' || s[i] == ',')
                    s[i] = ' ';
            }


            Customer *c = new Customer();

            stringstream iss(s);
            int value;
            int i = 1;
            while (iss >> value)
            {

                if (i == 1)
                {

                    c->id = value;
                    i++;
                }
                else if (i == 2)
                {

                    c->demand = value;
                    i++;
                }
                else if (i % 3 == 0)
                {
                    Location *l = new Location();
                    l->id = value;
                    i++;


                    iss >> value;
                    l->windowStartTime = value;
                    i++;


                    iss >> value;
                    l->windowEndTime = value;
                    c->locationList.push_back(*l);
                    delete l;
                    i++;
                }

            }

            customerList.push_back(*c);
              cout <<"so location: " <<c->locationList.size()<<endl;
           cout <<"so khach = " << customerList.size()<<endl;
            delete c;
        }

        getline(openFile, s);
        getline(openFile, s);
        getline(openFile, s);
        getline(openFile, s);

        // read location coordinate
cout <<"customerList.size()"<<customerList.size()<<endl;
        for (int i = 0; i < customerList.size(); i++)
        {cout <<"customerList[i].locationList.size()" <<customerList[i].locationList.size();
            for (int j = 0; j < customerList[i].locationList.size(); j++)
            {
                int idTemp;
                long double a,b;

                openFile >> idTemp;
                openFile >> customerList[i].locationList[idTemp].xCoor ;
                openFile >> customerList[i].locationList[idTemp].yCoor;
                cout << customerList[i].locationList[idTemp].xCoor <<endl;;
            }
        }

        getline(openFile, s);
        getline(openFile, s);
        getline(openFile, s);
        getline(openFile, s);
        for(int i =0; i <nbOfCustomer*nbOfCustomer ; i++)
        {
            getline(openFile, s);

            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == ')' || s[i] == '(' || s[i] == ',')
                    s[i] = ' ';

            }
            int locationId1,locationId2;
            float timeBw2location;
            stringstream iss(s);
            iss >> locationId1 >> locationId2 >> timeBw2location;
            timeTravel[locationId1][locationId2] = timeBw2location;
        }
        openFile.close();
    }
    else cout <<"unable to open file";
}
void Solution::PrintInput()
{
    cout <<"General parameters: " << endl;
    cout << nbOfCustomer <<"\t"<<nbOfLocation <<"\t"<<timeHorizon <<"\t"<<vehCapacity<<endl;
    cout <<"customer schedules:" << endl;
    for (int i = 0; i < customerList.size(); i++) {
        cout << " khach hang c co id= " << customerList[i].id << " deman = " << customerList[i].demand << endl;
        cout << "so location cua khac hang c la: " << customerList[i].locationList.size() << endl;
        customerList[i].printListLocation();
        cout <<endl;
    }
    for(int i = 0; i <nbOfCustomer; i++)
    {
        for(int j =0; j <nbOfCustomer;i++)
        {
            cout << "Time[" <<i<<"]["<<j<<"]= " <<timeTravel[i][j]<<endl;
        }
    }


}
