#pragma once
#include<iostream>
#include<string>
#include "Job.h"
#include"Partition.h"
using namespace std;

class memory{
private:
	Partition p[5];
	Job j[5];
	int const memorySpace = 200;
	int fullMem;
	int emptyMem;
	void setParts();
	void setJobs();
public:
	memory();
	void firstFit();
	void bestFit();
	void nextFit();
	void worstFit();
	~memory(){ delete p; delete j; }
};

memory::memory()
{
	fullMem = 0;
	emptyMem = memorySpace;
	setParts();
	setJobs();
}
void memory::setJobs() 
{
	Job j1("J01", 12);
	j[0] = j1;
	Job j2("J02", 20);
	j[1] = j2;
	Job j3("J03", 60);
	j[2] = j3;
	Job j4("J04", 45);
	j[3] = j4;
	Job j5("J05", 58);
	j[4] = j5;
}
void memory::setParts()
{
	Partition part1(30, 1);
	p[0] = part1;
	Partition part2(20, 2);
	p[1] = part2;  
	Partition part3(50, 3);
	p[2] = part3; 
	Partition part4(60, 4);
	p[3] = part4;
	Partition part5(40, 5);
	p[4] = part5;
}

void memory::firstFit()
{
	for (int i = 0; i < 5; i++)
	{
		for (int h = 0; h < 5; h++)
		{
			if (j[i].getJobSize() <= p[h].getpSize())
			{
				p[h].addJob(j[i]);
				emptyMem -= j[i].getJobSize();
				fullMem += j[i].getJobSize();
				break;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		p[i].printPartition();
}