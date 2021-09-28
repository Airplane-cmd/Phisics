#include<iostream>
#include<array>
#include<cmath>
int main()
{
	std::array<double, 5>tg;
	tg[0] = 0.966;
	tg[1] = 0.354;
	tg[2] = 0.543;
	tg[3] = 0.795;
	tg[4] = 1.036;
	std::array<double, 5>cur;
	cur[0] = 0.015;
	cur[1] = 0.030;
	cur[2] = 0.045;
	cur[3] = 0.06;
	cur[4] = 0.075;
	double cOnst = 1.2566e-6;
	double t = 2.776;
	double radius;
	double number;
	std::cout << "Radius: " << std::endl;
	std::cin >> radius;
	std::cout << "Number: " << std::endl;
	std::cin >> number;
	std::array<double, 5> ind;
	std::array<double, 5> indV;
	double error = 0;
	double errorSum = 0;
	double medianInd = 0;
	for (int i = 0; i < 5; ++i)
	{
		ind[i] = cOnst * cur[i] * number / 2 / radius / tg[i];
		indV[i] = ind[i] * tg[i];
		medianInd += ind[i];
	}
	medianInd /= 5;
	for (int i = 0; i < 5; ++i)
	{
		errorSum += (ind[i] - medianInd) * (ind[i] - medianInd);
	}
	error = t * sqrt(errorSum / 20);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << i + 1 << "   hor:   " << ind[i] << "   Median induction: " << medianInd<<"  Accindal error:  "<<error<< "     vert: " << indV[i] << std::endl;
	}
	std::cout << "Next?(Y/N)";
	char answer;
	std::cin >> answer;
	if (answer == 'Y')
		system("cls");
	std::array<double, 5>dist;
	std::array<double, 5>indVer;
	double currC;
	std::cout << "currC: ";
	std::cin >> currC;
	dist[0] = 0;
	dist[1] = 0.03;
	dist[2] = 0.06;
	dist[3] = 0.09;
	dist[4] = 0.12;
	for (int i = 0; i < 5; ++i)
	{
		indVer[i] = cOnst * currC * radius * radius * number / (2 * pow(radius * radius + dist[i] * dist[i], (3 / 2)));
			std::cout << i + 1 << ": " << indVer[i]<<std::endl;
	}
	return 0;

}
