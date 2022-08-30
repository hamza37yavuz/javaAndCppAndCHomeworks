//rock-paper-sicissors
#include<stdio.h>
#include<time.h>
int main()
{
	int computer=0,i,x,j;
	int R=1,P=2,S=3,skorC=0,skorU=0;
	srand(time(NULL));
	printf("How many times will we play ? :");
	while(1)
	{
		scanf("%d",&i);
		if(i<=3)
		{
			printf("Perfect :)\n");
			break;
		}
		else if((i>=3)&&(i<11))
		{
		    printf("Is no too much?");
		    break;
		}
		else if(i>11)
		{
		    printf("I can't accept that! :");
		    continue;
	    }
		else
		    printf("Wrong choice\nYou can enter only positive numbers :");
		    continue;
	}
	for(j=1;j<=i;j++)
	{
	printf("\n\nRock:1\nPaper:2\nSicissors:3\nEnter your choice:");
	while(1)
	{
		scanf("%d",&x);
		if(x==1)
		{
			printf("Your choice is ROCK");
			break;
		}
		else if(x==2)
		{
		    printf("Your choice is PAPER");
		    break;
		}
		else if(x==3)
		{
		    printf("Your choice is SICISSORS");
		    break;
	    }
		else
		    printf("Wrong choice\nYou can enter only 1,2,3 :");
		    continue;
	}
	computer = rand()%3+1;
	if(computer==1) printf("\nComputer choice is ROCK");
	else if(computer==2) printf("\nComputer choice is PAPER");
	else if(computer==3) printf("\nComputer choice is SICISSORS");
	if(x==computer)
	{
		printf("\ncomputer:%d  User:%d\n",skorC,skorU);
		continue;
	}
	else if(((x==2)&&(computer==1))||(x==3)&&(computer==2)||(x==1)&&(computer==3))
	{
		skorU +=1;
		printf("\ncomputer:%d  User:%d\n",skorC,skorU);
		continue;
	}
	else if(((x==1)&&(computer==2))||(x==2)&&(computer==3)||(x==3)&&(computer==1))
	{
		skorC +=1;
		printf("\ncomputer:%d  User:%d\n",skorC,skorU);
	}
   }
   if(skorU>skorC) printf("\nYou win but you win some you less some :)");
   else if(skorC>skorU) printf("I beat you loser");
   else printf("We should play again");
	return 0;
}
