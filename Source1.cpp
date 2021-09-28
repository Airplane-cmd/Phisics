#include<iostream>
#include <vector>
struct MedianValueAndChanges {
	MedianValueAndChanges(int h)
	{
		RightMeasure = new double[h];
	}
	double MedianValue;
	double* RightMeasure;//=new double[Number];
	int Number1;
};
MedianValueAndChanges Measure1() {
	int Number;
	double MedianValue1 = 0;
	std::cout << "Enter number of measures: " << std::endl;
	std::cin >> Number;
	MedianValueAndChanges Measure(Number);
	for (int i = 0; i < Number; i++) {
		std::cout << "Enter measured value " << i + 1 << ":" << std::endl;
		std::cin >> Measure.RightMeasure[i];
		MedianValue1 = MedianValue1 + Measure.RightMeasure[i];
	}
	Measure.MedianValue = MedianValue1 / Number;
	Measure.Number1 = Number;
	//std::cout<<"Test number of measures: "<< Measure.Number1<<std::endl;
	//delete Measure.RightMeasure;
	return Measure;
}

int main()
{
	int numberOfRightMeasures;
	int maxNumber = 1;
	//maxNumber=0;
	std::vector<std::vector<double>>RightMeasureDelta(numberOfRightMeasures, std::vector<double>(maxNumber));





	std::cout << "Enter number of righ measures in the function: ";
	std::cin >> numberOfRightMeasures;
	for (int n = 0; n < 1; ++n)
	{

		//âîçìîæíî, áóäóò ïðîáëåìû ñ êîëëè÷åñòâîì ôóíêöèé â ìàññèâå
		double Delta;
		//double **RightMeasureDelta0[numberOfRightMeasures]; 
		//double *RightMeasureDelta1[maxNumber];

		int* MaxNumber = new int[numberOfRightMeasures];

		for (int i = 0; i < numberOfRightMeasures; ++i) {
			int g = 1;

			MedianValueAndChanges Function = Measure1();
			MaxNumber[i] = Function.Number1;
			int num = Function.Number1;
			std::cout << g << " function median value: " << Function.MedianValue << '\n';
			for (int k = 0; k < num; k++)
			{
				Delta = Function.RightMeasure[k] - Function.MedianValue;
				std::cout << k + 1 << " measure delta: " << Delta << '\n';

				RightMeasureDelta[i][k] = Delta;//èíèöèàëèçàöèÿ äâóìåðíîãî ìàññèâà çíà÷åíèÿìè delta Measure
			}
			g++;

		}
		for (int i : MaxNumber)
		{
			if (MaxNumber[i] > maxNumber)
				maxNumber = MaxNumber[i];//the biggest number of any right measure;
		}
		char Answer;
		std::cout << "NEXT FUNCTION?(Y/N)";
		std::cin >> Answer;
		if (Answer == 'Y') {
			system("cls");

			n--;
		}
		else
			n++;
	}

	return 0;
}
