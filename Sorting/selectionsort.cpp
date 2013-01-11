// Selection Sort

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <ctime>

int main(int argc, char* argv[])
{
	int i,j,x,t,n,min,tmp;
	std::vector<int> A,temp;
	std::string line;
	std::ofstream res;

	if(argc<=2)
		return 0;
	else
	{
		std::string filename = argv[2];
		std::ifstream myfile (filename);
		t = (boost::lexical_cast<int>(argv[1])>1)?boost::lexical_cast<int>(argv[1]):1;
		if(myfile.is_open())
		{
			std::getline(myfile,line);
			n = boost::lexical_cast<int>(line);
			std::getline(myfile,line);
			x = 0;
			A.resize(n);
			while(myfile.good())
			{
				A[x]=boost::lexical_cast<int>(line);
				std::getline(myfile,line);
				x++;
			}

		}
		myfile.close();
		x = 0;
		temp.resize(n);
		while(x<t)
		{
			temp = A;
			clock_t start = clock();
			for(i=0;i<temp.size()-1;i++)
			{
				min = i;
				for(j=i+1;j<temp.size();j++)
					if(temp[j]<temp[min])
						min = j;
				tmp = temp[min];
				temp[min] = temp[i];
				temp[i] = tmp;
			}
			clock_t end = clock();
			res.open("result_sel1.txt",std::fstream::out | std::fstream::app);
			res.setf(std::ios::fixed,std::ios::floatfield);
			res.precision(4);
			res << double(end-start) / CLOCKS_PER_SEC << std::endl;
			res.close();
			x++;
		}
	}
	return 0;
}
