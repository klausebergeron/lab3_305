#pragma once
#include<iostream>
#include<string>
using namespace std;

class Job
{
private:
	string jobName;
	int jobSize;
	bool jobStatus;


public:
	Job(string, int);
	Job(){};
	void printJob() const;
	string getJobName() const;
	int getJobSize() const;
	void setJobStatus();
	void setPartition(int pNum);
};

string Job::getJobName() const { return jobName; }
int Job::getJobSize() const { return jobSize; };
void Job::setJobStatus() { jobStatus = 1; }

void Job::printJob() const //prints out jobname, size, is or is not active in partition and if so, the number of part
{
	cout << "Job: " << jobName << "  size: " << jobSize;
	if (jobStatus == 1)
		cout << "  job is active in partition ";
	else
		cout << " job is not running." << endl;
}
Job::Job(string name, int size)
{
	jobName = name;
	jobSize = size;
	jobStatus = 0;
}


