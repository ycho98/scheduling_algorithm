#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <istream>
#include <iterator>
#include <array>
#include <iomanip>
#include <sstream>
using namespace std;

void fcfs(vector<int> bt, vector<string> name, int totalJob)
{
	vector<int> startTime;
	vector<int> endTime;
	double avgTimeFCFS = 0.0;
	double sumEndTime = 0.0;
	
	startTime.push_back(0);
	startTime.push_back(bt.front());

	for (int i = 1; i != bt.size(); i++)
	{
		startTime.push_back(startTime[i] + bt[i]);
	}

	for (int i = 0; i != bt.size(); i++)
	{
		endTime.push_back(bt[i] + startTime[i]);
	}

	for (int i = 0; i != bt.size(); i++)
	{
		sumEndTime += endTime[i];
	}
	
	/*totalJob = sumEndTime / bt.size();
	cout << totalJob << endl;*/

	avgTimeFCFS = sumEndTime / totalJob;

	for (int i = 0; i != bt.size(); i++)
	{ 
		cout << "  " <<  name[i] << "               " << bt[i] << "                  " << startTime[i] << "                 " << endTime[i] << endl;
	}

	cout << '\n';
	cout << "     Average Turn Around time for this data set is: " << fixed << setprecision(1) << avgTimeFCFS << "ms" << '\n' << endl;
	cout << "                       -----Done-----" << endl;
}


void shortestJob(vector<int> bt, vector<string> name, double totalJob)
{
	vector<int> startTime;
	vector<int> endTime;
	vector<pair <string, int>> together;
	double avgTimeshortest = 0.0;
	double sumEndTime = 0.0;

	for (int i = 0; i != bt.size(); i++)
	{
		together.push_back(make_pair(name[i], bt[i]));
	}

	sort(together.begin(), together.end(), [](const auto x, const auto y) {return x.second < y.second;});

	startTime.push_back(0);

	for (int i = 0; i != bt.size(); i++)
	{
		startTime.push_back(startTime[i] + together[i].second);
	}

	for (int i = 0; i != bt.size(); i++)
	{
		endTime.push_back(together[i].second + startTime[i]);
	}

	for (int i = 0; i != bt.size(); i++)
	{
		sumEndTime += endTime[i];
	}

	/*totalJob = sumEndTime / bt.size();
	cout << totalJob << endl;*/

	avgTimeshortest = sumEndTime / totalJob;

	for (int i = 0; i != bt.size(); i++)
	{
		cout << "  " << together[i].first << "               " << together[i].second << "                  " << startTime[i] << "                 " << endTime[i] << endl;
	}

	cout << '\n';
	cout << "     Average Turn Around time for this data set is: " << fixed << setprecision(1) << avgTimeshortest << "ms" << '\n' << endl;
	cout << "                       -----Done-----" << endl;
}

void roundRobin2(vector<int> bt, vector<string> name, int totalJob)
{
	int timeSlice = 2;
	vector<int> startTime (totalJob);
	vector<int> endTime(totalJob);
	vector<int> remaining;
	int turningTime = 0;
	double avgTimerr2 = 0.0;
	double sumEndTime = 0.0;

	startTime.push_back(0);

	for (int i = 0; i != bt.size(); i++)
	{
		remaining.push_back(bt[i]);
	}

	while (1)
	{
		bool out = true;

		for (int i = 0; i != bt.size(); i++)
		{
			if (remaining[i] > 0)
			{
				out = false;

				if (remaining[i] > timeSlice)
				{
					turningTime += timeSlice;
					remaining[i] -= timeSlice;
				}
				else
				{
					turningTime += remaining[i];
					endTime[i] = turningTime;
					remaining[i] = 0;
				}
			}
		}
		if (out == true)
			break;
	}


	for (int i = 1; i != bt.size(); i++)
	{
		if (bt[i - 1] >= timeSlice)
			startTime[i] = timeSlice + startTime[i - 1];
		else
			startTime[i] = bt[i - 1] + startTime[i - 1];
	}

	for (int i = 0; i != bt.size(); i++)
	{
		sumEndTime += endTime[i];
	}

	avgTimerr2 = sumEndTime / totalJob;

	/* totalJob = sumEndTime / bt.size();
	cout << totalJob << endl;*/

	for (int i = 0; i != bt.size(); i++)
	{
		cout << "  " << name[i] << "               " << bt[i] << "                  " << startTime[i] << "                 " << endTime[i] << endl;
	}

	cout << '\n';
	cout << "     Average Turn Around time for this data set is: " << fixed << setprecision(1) << avgTimerr2 << "ms" << '\n' << endl;
	cout << "                       -----Done-----" << endl;
}

void roundRobin5(vector<int> bt, vector<string> name, int totalJob)
{
	int timeSlice = 5;
	vector<int> startTime(totalJob);
	vector<int> endTime(totalJob);
	vector<int> remaining;
	int turningTime = 0;
	double avgTimerr5 = 0.0;
	double sumEndTime = 0.0;

	startTime.push_back(0);

	for (int i = 0; i != bt.size(); i++)
	{
		remaining.push_back(bt[i]);
	}

	while (1)
	{
		bool out = true;

		for (int i = 0; i != bt.size(); i++)
		{
			if (remaining[i] > 0)
			{
				out = false;

				if (remaining[i] > timeSlice)
				{
					turningTime += timeSlice;
					remaining[i] -= timeSlice;
				}
				else
				{
					turningTime += remaining[i];
					endTime[i] = turningTime;
					remaining[i] = 0;
				}
			}
		}
		if (out == true)
			break;
	}


	for (int i = 1; i != bt.size(); i++)
	{
		if (bt[i - 1] >= timeSlice)
			startTime[i] = timeSlice + startTime[i - 1];
		else
			startTime[i] = bt[i - 1] + startTime[i - 1];
	}

	for (int i = 0; i != bt.size(); i++)
	{
		sumEndTime += endTime[i];
	}

	avgTimerr5 = sumEndTime / totalJob;

	/* totalJob = sumEndTime / bt.size();
	cout << totalJob << endl; */

	for (int i = 0; i != bt.size(); i++)
	{
		cout << "  " << name[i] << "               " << bt[i] << "                  " << startTime[i] << "                 " << endTime[i] << endl;
	}

	cout << '\n';
	cout << "     Average Turn Around time for this data set is: " << fixed << setprecision(1) << avgTimerr5 << "ms" << '\n' << endl;
	cout << "                       -----Done-----" << endl;
}

int main()
{
	//read text file and store to vectors

	ifstream myFile("5jobs.txt");
	ifstream infile;

	infile.open("5jobs.txt");

	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1);
	}

	string jobName;
	int burstTime;
	vector<string> burstTimeVector;
	vector<string> jobNameVector;
	vector<string> temp;

	if (myFile.is_open())
	{
		while (getline(myFile, jobName))
		{
			temp.push_back(jobName);
		}

		vector<string>::iterator tempIter = temp.begin();
		while (tempIter != temp.end())
		{
			int i = 0;
			jobNameVector.push_back(*tempIter);
			tempIter++;
			burstTimeVector.push_back(*tempIter);
			tempIter++;
		}

		myFile.close();
	}

	vector<int> burstTimeInt;
	for (int i = 0; i != burstTimeVector.size(); i++)
	{
		int k;
		string s = burstTimeVector[i];
		istringstream(s) >> k;
		burstTimeInt.push_back(k);
	}

	/*
	//generating 20 trials
	double turnAround = 0;
	for (int i = 0; i < 20; i++)
	{
		vector<int> myArray(10);
		for (int i = 0; i < 10; i++)
		{
			int random = (rand() % 80 + 20);
			myArray[i] = random;
		}
		fcfs(myArray, jobNameVector, turnAround);
		shortestJob(myArray, jobNameVector, turnAround);
		roundRobin2(myArray, jobNameVector, turnAround);
		roundRobin5(myArray, jobNameVector, turnAround);
	} */



	double jobSize = burstTimeInt.size();

	cout << "      -----You are now using First Come First Serve algorithm-----" << '\n' <<  endl;
	cout << "<Process>      <Burst time>       <Start time>       <End time>"  << endl;
	fcfs(burstTimeInt, jobNameVector, jobSize);

	cout << '\n' << '\n' << '\n' <<"      -----You are now using Shortest Job First algorithm-----" << '\n' << endl;
	cout << "<Process>      <Burst time>       <Start time>       <End time>" << endl;
	shortestJob(burstTimeInt, jobNameVector, jobSize);

	cout << '\n' << '\n' << '\n' << "      -----You are now using Round Robin with time slice of 2-----" << '\n' << endl;
	cout << "<Process>      <Burst time>       <Start time>       <End time>" << endl;
	roundRobin2(burstTimeInt, jobNameVector, jobSize);

	cout << '\n' << '\n' << '\n' << "      -----You are now using Round Robin with time slice of 5-----" << '\n' << endl;
	cout << "<Process>      <Burst time>       <Start time>       <End time>" << endl;
	roundRobin5(burstTimeInt, jobNameVector, jobSize);

	return 0;
}


