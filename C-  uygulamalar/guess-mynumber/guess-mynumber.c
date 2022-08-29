#include<stdio.h>
#include<conio.h>
void baslik(void){
printf("---------------------------------2 KISILIK SAYI TUTMA OYUNU---------------------------------\n");

}
int main(void)
{
	int p1, p2, time,i,tahmin,flag1=0,flag2=0,d;
	char user1[90], user2[90];
	b:
	baslik();
	printf("********************************************************************************************\n");
	printf("1. Oyuncunun ismini giriniz: ");
	gets(user1);
	printf("2. oyuncunun ismini giriniz: ");
	gets(user2);
	printf("Kac kez tahmin etme hakkiniz olsun sayiyi bilene kadar tahmin etmek istiyorsaniz 20 den buyuk sayi yazin:");
	scanf("%d",&time);
	printf("********************************************************************************************\n");
	if (time>=20) time = 500;
	printf("%s, %s adli oyuncuya gostermeden aklinda tuttugun sayiyi ekrana gir: ",user1,user2);
	scanf("%d",&p1);
	system("CLS");
	baslik();
	printf("%s, %s adli oyuncuya gostermeden aklinda tuttugun sayiyi ekrana gir: ",user2,user1);
	scanf("%d",&p2);
	system("CLS");
	baslik();
	printf("%s tahmin etme sirasi senin\n",user1);
	while(i<time)
	{
		if((time-1)==i) printf("Son deneme hakkiniz\n");
		printf("Sayiyi tahmin et: ");
		scanf("%d",&tahmin);
		if(tahmin>p2) printf("Tahmininiz diger oyuncunun tuttugu sayidan buyuk! \n");
		else if(tahmin<p2) printf("Tahmininiz diger oyuncunun tuttugu sayidan kucuk!\n");
		else
		{
		printf("tahmininiz dogru tebrikler \n");
		flag1++;
		break;
		}
		i++;	
	}
	if(flag1==0) printf("%s sayiyi bulamadi\n",user1);
	else printf("%s sayiyi buldu\n",user1);
	i=0;
	printf("%s tahmin etme sirasi senin\n",user2);
	while(i<time)
	{
		if((time-1)==i) printf("Son deneme hakkiniz\n");
		printf("Sayiyi tahmin et: ");
		scanf("%d",&tahmin);
		if(tahmin>p2) printf("Tahmininiz diger oyuncunun tuttugu sayidan buyuk! \n");
		else if(tahmin<p2) printf("Tahmininiz diger oyuncunun tuttugu sayidan kucuk!\n");
		else
		{
		printf("tahmininiz dogru tebrikler \n");
		flag2++;
		break;
		}
		i++;	
	}
	if(flag2==0) printf("%s sayiyi bulamadi\n",user2);
	else printf("%s sayiyi buldu\n",user2);
	if (flag1==flag2){
	printf("Berabere kaldiniz\n");
	printf("bir daha oynamak ister misiniz? eğer istiyorsaniz 1 e basın");
	scanf("%d",&d);
	if(d==1)	
	goto b;
	}
	else if (flag1>flag2) printf("%s kazandi\n",user1);
	else printf("%s kazandi ",user2);
	return 0;
}
