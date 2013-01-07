// Insertion Sort

#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <ctime>

int main(int argc, char* argv[])
{
	int i,j,x,t,n,key;
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
		std::cout << "Inizio lettura input:" << std::endl;
		if(myfile.is_open())
		{
			std::getline(myfile,line);
			n = boost::lexical_cast<int>(line);
			std::getline(myfile,line);
			while(myfile.good())
			{
				A.push_back(boost::lexical_cast<int>(line));
				std::getline(myfile,line);
			}

		}
		myfile.close();
		std::cout << "Fine lettura input." << std::endl;
		x = 0;
		while(x<t)
		{
			temp = A;
			/*{for(i=0;i<temp.size();i++)
				std::cout << temp[i] << " ";
			std::cout << std::endl;}*/
			clock_t start = clock();
			for(j=1;j<temp.size();j++)
			{
				key = temp[j];
				i = j-1;
				while(i>=0 && temp[i]>key)
				{
					temp[i+1] = temp[i];
					i--;
				}
				temp[i+1]=key;
			}
			clock_t end = clock();
			/*{for(i=0;i<temp.size();i++)
				std::cout << temp[i] << " ";
			std::cout << std::endl;}*/
			res.open("result_ins1.txt",std::fstream::out | std::fstream::app);
			res << double(end-start) / CLOCKS_PER_SEC << std::endl;
			res.close();
			x++;
		}
	}
	return 0;
}
