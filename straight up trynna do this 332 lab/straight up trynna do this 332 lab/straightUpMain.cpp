#include<iostream>
#include<string>
#include "Job.h"
//#include "Partition.h"
#include "memory.h"
using namespace std;

int main()
{
	Job j1("J01", 12);
	j1.printJob();
	memory mem;
	//mem.firstFit();
}