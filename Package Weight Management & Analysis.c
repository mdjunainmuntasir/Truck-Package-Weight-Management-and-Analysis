/*
		Name: Md Junain Muntasir
		Lab project
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>



double getTruckPackageWeights()
{
	int count, package;
	double packageWeight, totalPackageWeight=0;
	printf("How many packeges are there? ");
	scanf(" %d", &package);
	for (count = 1 ; count <= package ; count++)
	{
		printf("what is the weight for every package?");
		scanf(" %lf", &packageWeight);
		totalPackageWeight = totalPackageWeight + packageWeight;
	}
	
	return totalPackageWeight;
}

void displayTruckPackageWeightAnalysis(int numberOfTrucks, double average, double highestWeight, double lowestWeight)
{
	printf("Truck Packege weight Analysis\n");
	printf("Number of trucks:%28d\n", numberOfTrucks);
	printf("The highest truck packege weight is:%.1lf\n", highestWeight);
	printf("The lowest truck packege weight is:%.1lf\n", lowestWeight);
	printf("The average truck packet weight is:%.1lf\n", average);
}

int main()
{
	char choice;
	double getAmount, totalWeightAllTrucks=0, highest=-1, lowest=100000, avg;
	int numTrucks = 0;
	printf("(E) Enter package weights for a truck\n (D)Display truck package weight analysis\n (L) Leave the application");
	printf("Enter a letter\n");
	scanf(" %c", &choice);
	while (choice == 'D' ||choice == 'd' || choice == 'E' || choice == 'e' || choice == 'L' || choice == 'l')
	{
		if (choice == 'E' || choice == 'e')
		{
			getAmount = getTruckPackageWeights();
			
			while (getAmount > 0)
			{
				if (getAmount < lowest)
				{
					lowest = getAmount;
				}
				if (getAmount > highest)
				{
					highest = getAmount;
				}
			}
			
			totalWeightAllTrucks = +getAmount;
			numTrucks++;
		}
		else if (choice == 'D' || choice == 'd')
		{
			if (numTrucks == 0)
			{
				printf("You have not entered any truck package weights \n");
			}
			else
			{
				avg = totalWeightAllTrucks / numTrucks;
				displayTruckPackageWeightAnalysis(numTrucks, avg, highest, lowest);
			}
		}
		else
		{
			break;
		}
		printf("(E) Enter package weights for a truck\n (D)Display truck package weight analysis\n (L) Leave the application");
		printf("Enter a letter\n");
		scanf(" %c", &choice);
	}

	
	return 0;
}
