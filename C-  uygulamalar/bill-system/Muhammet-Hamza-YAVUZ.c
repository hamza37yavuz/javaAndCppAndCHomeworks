#include<stdio.h>
#include<stdlib.h>
int faturaS(void);
int faturaU(void);
int secim()
{
	int secim1;
	printf("\n------------------------E-Fatura Sistemi------------------------");
	printf("\nFatura yonetim sistemi girisi icin 1'e\nKullanici girisi icin 2'ye\nprogramdan cikmak icin herhangi bir tusa basabilirsiniz :");
	scanf("%d",&secim1);
	switch(secim1)
	{	case 1 :
			faturaS();
			break;
		case 2 :
			faturaU();
			break;
		default :
			printf("Programdan cikis yapiliyor...");
			return 0;
	}
	return 0;
}
int faturaU(void)
{	FILE *oku;
	char ad[50];
	int secim3,buAy,gecenAy,oncekiAy,daireNo,x,etoplam=0,ktoplam=0,atoplam=0,i=0;
	float ort;
	printf("\n------------------------Fatura Sistemi Kullanici Ekrani------------------------\n");
	printf("Kullanim miktarlari sisteme girilmeye baslandi...\n");
	printf("Yapabileceginiz Islemler:\n1-Aciklanan kullanim miktarlarnizi goruntuleyin(kw cinsinden)\n2-Bina elektrik kullanim ortalamsini goruntule\nCikis yapmak icin herhangi bir tus girmeniz yeterlidir:");
	scanf("%d",&secim3);
	oku = fopen("kaynak.txt", "r");
	if ((oku = fopen("kaynak.txt", "r")) == NULL)
    {	printf("Dosya acma hatasi!\n");
        return faturaU();
    }
	switch(secim3)
	{	case 1 :
			printf("Lutfen daire numaranizi giriniz (1-16 arasinda bir sayi girmelisiniz):");
			scanf("%d",&x);
			printf("\nSUANA KADAR SISTEME GIRILMIS OLAN KULLANIM MIKTARINIZ(KW CINSINDEN):\n");
            while(fscanf(oku,"%d %s %d %d %d\n",&daireNo,ad,&buAy,&gecenAy,&oncekiAy)!=EOF)
			{	if(x==daireNo)
				{	printf("%d daire nolu %s adli kullanicinin 3 aylik elektrik kullanim miktari:\nAralik:%2d kw\t%.3f tl \nKasim:%4d kw\t%.2f tl\nEkim:%5d kw\t%.2f tl\n",daireNo,ad,buAy,(float)(buAy*0.92),gecenAy,(float)(gecenAy*0.92),oncekiAy,(float)(oncekiAy*0.92));
	                printf("3 aylik elektrik kullaniminiz: %4d kw\n3 aylik elektrik kullanim ortalamaniz: %.2f kw\n",(buAy+gecenAy+oncekiAy),(float)((buAy+gecenAy+oncekiAy)/3));
	                break;
	            }
	            else if(x>15)
				{	printf("OLMAYAN BIR DAIRENIN NUMARASINI GIRDINIZ\tTekrar Deneyiniz\n");
	            	break;
	            }
	        }
	        printf("\nNOT: Eger dairenizin numarasini dogru girdiyseniz ve hicbirsey cikmadiysa kullanim miktariniz aciklanmamis demektir...\n");
	        fclose(oku);
			return faturaU();
		case 2 :
			printf("\nBu analizler anonim olarak yapilacaktir gizlilik her seyden onemlidir. Tum veri analizleri son 3 aya gore yapilacaktir :)\n");
			printf("\n---SUANA KADAR SISTEME GIRILMIS OLAN BINA KULLANIM MIKTARI ANALIZI(KW CINSINDEN)---\n");
            while(fscanf(oku,"%d %s %d %d %d\n",&daireNo,ad,&buAy,&gecenAy,&oncekiAy)!=EOF)
			{	i++;
				atoplam += buAy;
				ktoplam += gecenAy;
				etoplam += oncekiAy;
			}
		    printf("Binanizda kullanilan toplam elektrik(kw cinsinden)=%6d kw\n1 ayda binanizda 1 diarede kullanilan ortalama elektrik:%.2f kw\tortalama fatura:%.2f tl\n\n",(atoplam+ktoplam+etoplam),(float)((atoplam+ktoplam+etoplam)/(i*3)),(float)(0.92*(atoplam+ktoplam+etoplam)/(i*3)));
			printf("Binada 1 ayda kullanilan toplam elektrik bilgisi:\nEkim ayinda: %5d kw\nKasim ayinda: %5d kw\nAralik ayinda: %5d kw\n",etoplam,ktoplam,atoplam);
			return faturaU();
		default :
			printf("Bir onceki ekrana gidiliyor...\n");
			return secim();
	}
}
int faturaS(void)
{	FILE *fp ;
	FILE *oku;
	oku = fopen("kaynak.txt", "a+b");
	char ad[50],inptad[50];
	int enfazla=0,i=0,atoplam=0,ktoplam=0,etoplam=0,y=0,enaz;
	int buAy,gecenAy,oncekiAy,secim2,x,daireNo,inptdaire,ekim,kasim,aralik;
	float ort=0;
	printf("\n------------------------FATURA YONETIM SISTEMI------------------------\n");
	printf("Bu programla ilk defa analiz yapacaksiniz ve sizden once yapilmis olan analizleri gormek istemiyorsaniz 1'e daha once yapmis oldugunuz analizleri de gormek istiyorsaniz 2'ye basiniz:");
	scanf("%d",&x);
	if(x==1)
	{	fp = fopen("hedef.txt", "w");
		if ((fp = fopen("hedef.txt", "w")) == NULL)
			{	printf("Dosya acma hatasi!\n");
                return faturaS();
            }
    }
	else
	{	fp = fopen("hedef.txt", "a");
		if ((fp = fopen("hedef.txt", "a")) == NULL)
			{	printf("Dosya acma hatasi!\n");
                return faturaS();
            }
	}
	if ((oku = fopen("kaynak.txt", "a+b")) == NULL)
	{	printf("Dosya acma hatasi!\n");
        return faturaS();
    }
	printf("\nYapabileceginiz Islemler:\n1-Tum faturalari goruntule\n2-Faturalarin ayrintili analizini yap ve Faturalarin hepsini kisi kisi analiz et ve dosyaya aktar\n");
	printf("3-Fatura ekle\nCikis yapmak icin herhangi bir tus girmeniz yeterlidir:");
	scanf("%d",&secim2);
	switch(secim2)
	{	case 1 :
			if ((oku = fopen("kaynak.txt", "r")) == NULL)
			{	printf("Dosya acma hatasi!\n");
                return faturaS();
            }
			while(fscanf(oku,"%d %s %d %d %d\n",&daireNo,ad,&buAy,&gecenAy,&oncekiAy)!=EOF)
			{	printf("%d daire nolu %s adli kullanicinin 3 aylik elektrik kullanim miktari:\n",daireNo,ad);
				printf("Aralik:%2d kw\t%.2f tl \nKasim:%4d kw\t%.2f tl\nEkim:%5d kw\t%.2f tl\n\n",buAy,(float)(buAy*0.92),gecenAy,(float)(gecenAy*0.92),oncekiAy,(float)(oncekiAy*0.92));
		    }
		    printf("Bu islemde baska bir dosyaya yazdirmadan islem yaparsiniz. Eger baska bir dosyaya yazdirarak islem yapmak istiyorsaniz 2 numarali tusa basarak devam etmelisiniz.\n");
		    fclose(fp);
		    fclose(oku);
			return faturaS();
		case 2 :
			printf("Sectiginiz islemde istediginiz tum analizler bir dosyaya aktarilip size gonderilecektir.\n");
			printf("Ekrana bu yazdiklarimin disinda baska bir veri bastirilmayacaktir bastirilmasini istiyorsaniz 1'e ardindan enter tusuna basiniz.\n");
			while(fscanf(oku,"%d %s %d %d %d\n",&daireNo,ad,&buAy,&gecenAy,&oncekiAy)!=EOF)
			{	fprintf(fp,"%d daire nolu %s adli kullanicinin 3 aylik elektrik kullanim miktari:\nAralik:%d kw\t%.2f tl \nKasim:%d kw\t%.2f tl\nEkim:%d kw\t%.2f tl\n",daireNo,ad,buAy,(float)(buAy*0.92),gecenAy,(float)(gecenAy*0.92),oncekiAy,(float)(oncekiAy*0.92));
				i++;
				if((buAy+gecenAy+oncekiAy)>x)
				{	x=(buAy+gecenAy+oncekiAy);
					enfazla = daireNo;
				}
				if (i==1) y=(buAy+gecenAy+oncekiAy);
				if((buAy+gecenAy+oncekiAy)<y)
				{	y=(buAy+gecenAy+oncekiAy);
					enaz = daireNo;
				}
				atoplam += buAy;
				ktoplam += gecenAy;
				etoplam += oncekiAy;
				fprintf(fp,"%d numarali daire 3 ayda %d kw elektrik kullanmistir\n\n",daireNo,(buAy+gecenAy+oncekiAy));
			}
			fprintf(fp,"Binada 3 ayda kullanilan toplam elektrik miktari:%d kw\n",(etoplam+ktoplam+atoplam));
			fprintf(fp,"\nBinada ay baþýna kullanilan toplam elektrik miktarlari:\nAralik %d kw\nKasim %d kw\nEkim %d kw\n",atoplam,ktoplam,etoplam);
			fprintf(fp,"\nBinada en fazla elektrik kullanilan daire numarasi %d .\t3 ayda %d kw elektrik kullanmis ve %.2f tl fatura odemistir.\n",enfazla,x,(float)(x*0.92));
			fprintf(fp,"Binada en az elektrik kullanilan daire numarasi %d .\t3 ayda %d kw elektrik kullanmis ve %.2f tl fatura odemistir.\n",enaz,y,(float)(y*0.92));
			fclose(fp);
		    fclose(oku);
			return faturaS();
		case 3 :
			printf("ONEMLI NOT:Bir seferde yalnizca bir daireye ait bilgi girebilirsiniz.\n\n");
			printf("Daire numarasini giriniz:");
			scanf("%d",&inptdaire);
			while(fscanf(oku,"%d %s %d %d %d\n",&daireNo,ad,&buAy,&gecenAy,&oncekiAy)!=EOF)
			{	if(daireNo==inptdaire)
				{	printf("daha once girilmis olan bir daire icin deger girdiniz maalesef bu deger kabul edilemez...");
					return faturaS();
				}
		    }
			printf("Daire sahibinin ismini isim-soyisim seklinde bosluk birakmadan yaziniz:");
			scanf("%s",inptad);
			printf("Bir ayda yaktigi elektrik bilgisini aralik kasim ekim siralamasiyla tam sayi olarak yaziniz:");
			scanf("%d",&aralik);
			scanf("%d",&kasim);
			scanf("%d",&ekim);
		    fprintf(oku,"\n%d %s %d %d %d",inptdaire,inptad,aralik,kasim,ekim);
			fclose(fp);
		    fclose(oku);
			return faturaS();
		default :
			printf("Bir onceki ekrana gidiliyor...\n");
			return secim();
	}
}
int main()
{
	printf("ONEMLI NOT:Bu sistemde yapilan tum islemler 2021 yili verileri baz alinarak yapilmistir.\n");
	secim();
	return 0;
}
