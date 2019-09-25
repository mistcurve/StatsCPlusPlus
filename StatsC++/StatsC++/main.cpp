#include <iostream>

using namespace std;

void confidenceIntervalCalculation(int numberOfObservations, double stdDev, double samplemean, double confidenceInterval);

int main()
{
	confidenceIntervalCalculation(10, 1, 64.46, .95);
}

void confidenceIntervalCalculation(int numberOfObservations, double stdDev, double samplemean, double confidenceInterval)
{
	if (confidenceInterval < 0 || confidenceInterval > 1)
	{
		cout << "confidence interval out of bounds, terminating.\n\n";
		return;
	}
	if (numberOfObservations < 0)
	{
		cout << "number of observations must be a positive integer.";
	}

	double Z;
	if (confidenceInterval == .95)
	{
		Z = 1.960;
	}
	else
	{
		cout << "that confidence interval does not currently have a solution. Current solutions include: .95.";
		return;
	}

	double marginOfError = (Z * stdDev) / sqrt(numberOfObservations);

	cout << "Confidence interval for " << (confidenceInterval * 100) << "%:\n" << samplemean - marginOfError << " < mu < " << samplemean + marginOfError;
}