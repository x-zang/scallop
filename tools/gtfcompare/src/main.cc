#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>

#include "genome.h"
#include "compare.h"

using namespace std;

int main(int argc, const char **argv)
{
	if(argc != 3)
	{
		cout<<"usage: "<<argv[0]<< "<gtf-file-1> <gtf-file-2>"<<endl;
		return 0;
	}

	genome g1(argv[1]);
	genome g2(argv[2]);
	compare_genome(g1, g2);

    return 0;
}