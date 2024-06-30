#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <getopt.h>

int main(int argc, char **argv)
{
    std::random_device rd{};
    std::mt19937 gen{rd()};
	int method = 1;
	float a,b;
	float offset=0;
	float scale=1;
	int decimals=0;
	for(;;)
	{
	  switch(getopt(argc, argv, "m:a:b:d:o:s:")) // note the colon (:) to indicate that 'b' has a parameter and is not a switch
	  {
		case 'm':
		  method=std::stoi(optarg);
		  continue;
		case 'a':
		  a=std::stof(optarg);
		  continue;
		case 'b':
		  b=std::stof(optarg);
		  continue;
		case 'd':
		  decimals=std::stof(optarg);
		  continue;
		case 'o':
		  offset=std::stof(optarg);
		  continue;
		case 's':
		  scale=std::stof(optarg);
		  continue;

		case -1:
		  break;
	  }

	  break;
	}
	float roundbase=powf(10,decimals);
	switch(method)
	{
		case 1: // normal distribution
			{
				std::normal_distribution d{a, b};
				std::cout << round(roundbase*d(gen))/roundbase;
				break;
			}
		case 2: // exponetial distribution
			{
				std::exponential_distribution<> e(a);
				std::cout << round(roundbase*(offset + scale*e(gen)))/roundbase;
				break;
			}
		case 3: // gamma distribution
			{
				std::gamma_distribution<> d(a, b);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
		case 4: // weibull distribution
			{
				std::weibull_distribution<> d(a, b);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
		case 5: // Poisson distribution
			{
				std::poisson_distribution<> d(a);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
		case 6: // Lognormal distribution
			{
				std::lognormal_distribution<> d(a,b);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
		case 7: // Student distribution
			{
				std::student_t_distribution<> d(a);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
		case 8: // Fisher distribution
			{
				std::fisher_f_distribution<float> d(a,b);
				std::cout << round(roundbase*(offset + scale*d(gen)))/roundbase;
				break;
			}
	}
}
