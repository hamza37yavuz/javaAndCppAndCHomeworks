/*
your name: Muhammet Hamza Yavuz
for what reason it is written,
how it works, etc? 
		changeuser username
		password: first 5 characters from the third column
		example:
			changeuser VPGR
			password: 1BXOO

Programda gerekli yerlere de aciklamalar yaziniz, // kullanmayiniz.

test.c de bir degisiklik yapmayiniz bos olarak kalsin..
*/
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>    
#include <sys/types.h> 
#include <sys/stat.h>  
#include <stdio.h>    
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

#define MAX_USERNAME_LENGTH 4
#define MAX_PASSWORD_LENGTH 6
#define MAX_COMMAND_LENGTH 100

int main() 
{	
	/*
	user1: Sifre dogrulanirsa dosyadan alinacak isim burada tutulur
	line: Dosyanin her bir satirini bu degisken sira sira alir
	randstr: Dosyanin icerisinde bulunan sifrelem icin kullanilan veri buraya kopyalanir
	username: Kullanicidan alinan username bu degiskene atanir
	password: Kullanicidan alinan sifre bu degiskene atanir
	command: Yazilabilecek komutun karakterini sinirlar
	*/

	int sz,i=0,a=0;
	char *usern1 = (char *) calloc(5, sizeof(char));
	char *line = (char *) calloc(22, sizeof(char));
	char *randstr = (char *) calloc(5, sizeof(char));
	
	char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char command[MAX_COMMAND_LENGTH];
	
	printf("$ ");
	
	/*
	Bu while dongusu terminal kismini olusturmak icindir
	*/
    while (fgets(command, MAX_COMMAND_LENGTH, stdin)) 
    {
        command[strcspn(command, "\n")] = 0;
    
		if (strncmp(command, "changeuser ", 11) == 0) 
		{	
			int fd = open("users",O_RDONLY);
			if (fd<0){
				if(a>0)printf("%4s$",username); 
				else perror("$");
				
				continue;
				}
			/*Dosyadaki imleci basa alir*/	
			off_t offset = lseek(fd, 0, SEEK_SET);
			if (offset == -1) {
				if(a>0)printf("%4s$",username); 
				else perror("$");
			}
            sscanf(command, "changeuser %4s", username);
			
			/*Bu dongu Dosyadaki her satirin gezilebilmesi icindir */	
			while(1)
			{	
				i++;
				sz = read(fd, line, 21);
				line[sz] = '\0';
				
				if(strncmp(line, username,4) == 0)
				{
					printf("password: ");
					fflush(stdout);
					fgets(password, MAX_PASSWORD_LENGTH, stdin);
					
					memcpy(randstr, &line[5], 4);
					randstr[5] = '\0';
					
					strcat(password, randstr);
					
					if(strncmp(password, &line[10],9) == 0){ a = 1;memcpy(usern1, line, 4);usern1[5] = '\0'; break;}
					else {close(fd); printf("Your username or password is incorrect \n"); break;}
				}
					
				else if(i==30) {printf("invalid username\n");	close(fd); printf("$");break;}
				else continue;
			}
		}

        else if (strcmp(command, "exit") == 0) 
        {
			if(a>0)printf("%4s$",usern1);
            else printf("$ ");
            break;
		}
		else 
		{
			system(command);
			if(a>0) printf("%4s$ ",usern1);
			else printf("$ ");
			continue;
		}
	}

    free(line);   
    free(randstr);   
	return 0;
	
}
