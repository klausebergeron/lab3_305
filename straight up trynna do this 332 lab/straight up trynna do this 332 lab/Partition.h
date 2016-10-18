#pragma once
#include<iostream>
#include<string>

#include "Job.h"

using namespace std;

class Partition
{
private:
	int pSize;
	int pNumber;
	bool pStatus;
	int pHole;
	string pJobName;
	Job *job = nullptr;

public:
	Partition(int, int);
	Partition(){};
	void addJob(Job j);
	void endJob(){	delete job; }
	void printPartition() const;
	int getpSize() { return pSize; }
	~Partition(){ endJob();	}
};

Partition::Partition(int s, int n)
{
	pSize = s;
	pNumber = n;
	pHole = s;
	pStatus = 0;
	job = new Job;
}

void Partition::addJob(Job j)
{
	*job = j;
	pJobName = j.getJobName();
	pStatus = 1;
	pHole -= j.getJobSize();
	job->setJobStatus();
}
void Partition::printPartition() const
{
	cout << "Partition " << pNumber << " is " << pSize << "k large, with ";
	if (pStatus == 0)
		cout << "no job running. All memory is free" << endl;
	else
		cout << "job " << pJobName << " running and " << pHole << "k free memory.";
}


