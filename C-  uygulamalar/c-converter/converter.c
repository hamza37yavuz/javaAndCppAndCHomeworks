#include<stdio.h>
#include<math.h>
int binToDec(long long int bin,int a)
{
    int x,dec=0,i=1;
    while(bin>0)
	{
		x=0;
		x += bin%10;
		dec += x*i;
		bin = bin/10;
		i = i*2;
	}
	if(a==0)
    	printf("\ndecimal number = %d\n",dec);
    else if(a==1)
		return decTOct(dec);
}
int decToBin(int dec)
{
    long long int bin=0;
    printf("\nDecimal number= %d\tBinary number=",dec);
    while(dec>0)
	{
		bin = dec%2;
		printf("%lld",bin);
		dec = dec/2;
	}
}
int decTOct(int dec)
{
	int oct[100],i=1,j;
	while(dec>0)
	{
		oct[i] = dec%8;
		dec /=8;
		i++;
	}
	printf("Octal number=");
	for (j = i - 1; j > 0; j--)
        printf("%d", oct[j]);
    printf("\n");
}
int octToDec(int oct,int x)
{
	int a,dec=0,i=0;
	while(oct>0)
	{
		a = oct%10;
		oct /= 10;
		dec += a * pow(8,i);
		i++;
	}
	if(x==0)
		printf("\nDecimal number = %d\n",dec);
	else if(x==1)
		return decToBin(dec);
}
int main()
{
	int x,dec,oct,i=1;
	long long int bin;
	dec = 0;
	printf("------------------------------CONVERTER------------------------------");
	while(1)
	{
		printf("\n1-Binary to decimal\n2-Decimal to binary\n3-Binary to octal\n4-Octal to binary\n5-Octal to decimal\n6-Decimal to octal\n7-EXIT \tEnter a number:");
		scanf("%d",&x);
		if(x==7) break;
		switch(x)
		{
			case 1:
				printf("Enter a binary number :");
				scanf("%lld",&bin);
				x=0;
				binToDec(bin,x);
				break;
			case 2:
				printf("Enter a decimal number :");
				scanf("%d",&dec);
				decToBin(dec);
				break;
			case 3:
				printf("Enter a binary number :");
				scanf("%lld",&bin);
				x=1;
				binToDec(bin,x);
				break;
			case 4:
				printf("Enter a octal number :");
				scanf("%d",&oct);
				x=1;
				octToDec(oct,x);
				break;
			case 5:
				printf("Enter a octal number :");
				scanf("%d",&oct);
				x=0;
				octToDec(oct,x);
				break;
			case 6:
				printf("Enter a decimal number :");
				scanf("%d",&dec);
				decTOct(dec);
				break;
			default:
				break;
		}         		
	}
	return 0;
}
