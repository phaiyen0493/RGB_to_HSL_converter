/*
Name: Yen Pham
Assignment #1
Description: This program just convert RGB to HSL color

to compile: go to Putty using cse machine: cse01.cse.unt.edu
gcc pham1.c -lm

to run: ./a.out
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

double getmin(double R, double G, double B) // get min
{
	double min = R;
	if (G < min)
	{
		min = G;
	}

	if (B < min)
	{
		min = B;
	}
	return min;
}

double getmax(double R, double G, double B) // get max
{
	double max = R;
	if (G > max)
	{
		max = G;
	}

	if (B > max)
	{
		max = B;
	}
	return max;

}

int main()
{
	int input;
	double R, G, B;
	double min, max;
	double H = 0, S = 0, L = 0;
	char answer;

	do
	{
	do
	{
	printf("Enter red collor R (0-255): ");
	scanf("%d", &input); // input R
	} while(input > 255 || input < 0);
	R = (double) (input) / 255;

	do
	{
	printf("Enter green color G (0-255): ");
	scanf("%d", &input); // input G
	} while(input > 255 || input < 0);
	G = (double) (input) / 255;
	
	do
	{
	printf("Enter blue color B (0-255): ");
	scanf("%d", &input); // input B
	} while(input > 255 || input < 0);
	B = (double) (input)/ 255;

	min = getmin(R, G, B);
	max = getmax(R, G, B);

	L = (min + max)/2;
	
	if (max == min)
	{
		S = 0;
	}
	else if (L == 0.5)
	{
		S = 1;
	}
	else if (L < 0.5)
	{
		S = (max - min) / (max + min);
	}
	else if (L > 0.5)
	{
		S = (max - min) / (2 - max - min);
	}

	if (R == max)
	{
		H = (G - B) / (max - min);
	}
	else if (G == max)
	{
		H = 2.0 + (B-R)/ (max - min); 
	}
	else if (B == max)
	{
		H = 4.0 + (R - G) / (max - min);
	}

	H *= 60;
	while (H < 0)
	{
		H += 360;
	}

	if (max == min)
	{
		H = 360;
	}

	S *= 100;
	L *= 100;

	//Print results
	printf("Hue: %d degree\n", (int)(round(H)));
	printf("Saturation: %d%% \n", (int)(round(S)));
	printf("Lightness: %d%% \n", (int)(round(L)));

	printf("Continue? Press y: ");
	scanf("%s", &answer);

	} while (tolower(answer) == 'y');

	return 0;
}