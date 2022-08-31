#include<stdio.h>
int main()
{
	int choice,roman;
	printf("----------CONVERTER----------\nNumber To Romen Numerals\n");
	while(1)
	{
		printf("\nPress 1 to exit \npress 2 to continue:");
		scanf("%d",&choice);
		if(choice==1) break;
		else
		{	printf("please enter a number from 1 to 1000\n");
			scanf("%d",&roman);
			while(roman>0)
			{
				if (roman>1000)
				{
					printf("the input is incorrect");
					break;
				}
				else if (roman == 1000)
				{
					roman -= 1000;
					printf("M");
					break;
				}
				else if (roman >= 900)
				{
					roman -= 900;
					printf("CM");
					continue;
				}
				else if (roman >= 500)
				{
					roman -= 500;
					printf("D");
					continue;
				}
				else if (roman >= 400)
				{
					roman -= 400;
					printf("CD");
					continue;
				}
				else if (roman >= 100)
				{
					roman -= 100;
					printf("C");
					continue;
				}
				else if (roman >= 90)
				{
					roman -= 90;
					printf("XC");
					continue;
				}
				else if (roman >= 50)
				{
					roman -= 50;
					printf("L");
					continue;
				}
				else if (roman >= 40)
				{
					roman -= 40;
					printf("L");
					continue;
				}
				else if (roman >= 10)
				{
					roman -= 10;
					printf("X");
					continue;
				}
				else if(roman >= 9)
				{
					printf("IX");
					roman-=9;
					continue;
				}
				else if(roman >= 5)
				{
					printf("V");
					roman-=5;
					continue;
				}
				else if(roman>=4)
				{
					printf("IV");
					roman-=4;
					continue;
				}
				else if(roman>=1)
				{
					printf("I");
					roman-=1;
					continue;
				}
			if(roman==0) break;
			}
		}
	}
	return 0;
}
