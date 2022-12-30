#include <stdio.h>

main()
{
	int i,j,k,toplam,a;
	int matris[3][3],matris1[3][3],sonuc[3][3];
	printf("Matrisiniz 3'e 3 luktur.\n"); 
	
	printf("1. Matrisin elemanlarini satir satir giriniz...\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a);
			matris[i][j]=a;
		}
	}
	
	printf("2. Matrisin elemanlarini satir satir giriniz...\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a);
			matris1[i][j]=a;
		}
	}
		
	printf("Matrisin ekrandaki ciktisi\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",matris[i][j]);
		}
		printf("\n");
	}
	
	printf("Matrisin ekrandaki ciktisi\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",matris1[i][j]);
		}
		printf("\n");
	}
	
	printf("Matris1 ve Matris2 skaler olarak carpilacaktir ve ekrana bastirilacaktir:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d	",((matris[i][j])*(matris1[i][j])));
		}
		printf("\n");
	}
	printf("Matris1 ve Matris2 vektorel olarak carpilacaktir ve ekrana bastirilacaktir:\n");	
	for(i=0; i<3; i++)
	{  
	    for(j=0; j<3; j++)
		{
	        for(k=0; k<3; k++)
			{
	            toplam += matris[i][k] * matris1[k][j];
	        }
	    	sonuc[i][j] = toplam;
	        toplam = 0;
	        printf("%d ", sonuc[i][j]);
	    }
	    printf("\n");
	}

}
