// Merge Sort

#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <ctime>
#include <limits>

void Merge(std::vector<int> & A,int p, int q, int r)
{
	std::vector<int> L,R;
	int i,j;

	L.resize(q-p+2);
	R.resize(r-q+1);
	std::memcpy(&L.front(),&A.front()+p, sizeof(int)*(L.size()-1)); 
	std::memcpy(&R.front(),&A.front()+p+L.size()-1, sizeof(int)*(R.size()-1));
	L[L.size()-1] = std::numeric_limits<int>::max();
	R[R.size()-1] = std::numeric_limits<int>::max();
	i = 0;
	j = 0;

	for(int k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}
}

void Merge_Sort(std::vector<int> & A,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		Merge_Sort(A,p,q);
		Merge_Sort(A,q+1,r);
		Merge(A,p,q,r);
	}
}


int main(int argc, char* argv[])
{
	int x,t,n;
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
			Merge_Sort(temp,0,temp.size()-1);
			clock_t end = clock();
			res.open("result_merg1.txt",std::fstream::out | std::fstream::app);
			res.setf(std::ios::fixed,std::ios::floatfield);
			res.precision(4);
			res << double(end-start) / CLOCKS_PER_SEC << std::endl;
			res.close();
			x++;
		}
	}
	return 0;
}
