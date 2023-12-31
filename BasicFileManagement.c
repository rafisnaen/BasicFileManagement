#include <stdio.h>
#include <string.h>
#include <windows.h>

void signup(char name[], char password[]){
 
 	//add account / write an file for account lists
	FILE *fp;
	fp = fopen("account.txt", "a");
	//checke the file is either exist or not.
	if(fp == NULL){
		fp = fopen("account.txt", "w");
	}
	
	//input name and password
	printf("Input username: ");
	scanf("%[^\n]", name);
	getchar();
 
	printf("Input password: ");
	scanf("%[^\n]", password);
	getchar();
 
	//Put the string into the file.
	fprintf(fp,"%s %s\n", name, password);
	fclose(fp);
 
	printf("Data saved successfully !\n");
	Sleep(1500);
	system("cls");
 
}

void login(char name[], char password[], int *mark){
	
	//read the file
	FILE *fp;
	fp = fopen("account.txt", "r");
	
	//input string to compare with the data saved in the file
	printf("Input username: ");
	scanf("%[^\n]", name);
	getchar();
 
	printf("Input password: ");
	scanf("%[^\n]", password);
	getchar();
	
	//declare temporary variables to compare the string in file with user input
	char tempname[100];
	char temppass[100];

	int flag = 0;
	//receive string from file, and check whether user input is in the file or not
	//receive string from the first line of file until the end of the file.
	while(fscanf(fp,"%s %s\n", tempname, temppass) != EOF){
		if(strcmp(tempname, name) == 0 && strcmp(temppass,password) == 0){
			flag = 1;
			(*mark)++;
			printf("Data found !\n");
			Sleep(1500);
			system("cls");
			break;
		}
	}
	if(flag == 0){
		printf("Data not found !");
		Sleep(1500);
		system("cls");
	}
	
}
 
int main(){
  
  //declare variables
  int mark = 0;
  char name[100];
  char password[100];

do{
	
	int choose;

	//Main lobby
	printf("Save and read data based on user account.\n");
	printf("===================================");
	printf("\n1. Sign up\n");
	printf("2. Log in\n");
	printf("3. Exit\n>> ");
	scanf("%d", &choose);
	getchar();
	
	//switch case for options
	switch(choose){
		case 1:
			//sign up function
			signup(name,password);
			break;
 
		case 2:
			//log in function
			login(name,password, &mark);
			break;
			
		case 3:
			//Exit the program
			printf("Exiting the program !\n");
			return 0;
 
		default:
			//for any of these options
			printf("Invalid input !");
			Sleep(1500);
			system("cls");
	}
	
}while(mark == 0);

	int opt;
	retry:
	//Second lobby
	printf("Read and write a file based on user account\n");
	printf("===================================");
	printf("\n1. Write\n");
	printf("2. Read\n>> ");
	scanf("%d", &opt); getchar();
	
	//option for user input '1'
	if(opt == 1){
		char str[100];
		printf("Input any string:\n>> ");
		scanf("%[^\n]", str);
		getchar();
		
		FILE *fp;
		//Add file format to the string.
		strcat(name,".txt");
		//write file based on user input's string
		fp = fopen(name,"w");
		fprintf(fp,"%s", str);
		fclose(fp);

		printf("Data saved successfully !\n");

	//option for user input '2'
	}else if(opt == 2){
		//Add file format to the string.
		strcat(name,".txt");
		FILE *fp;
		//read file based on user input's string
		fp = fopen(name,"r");
		char tempstr[100];
		fscanf(fp,"%[^\n]", tempstr);
		fclose(fp);

		printf("Data in the file:\n>> %s\n", tempstr);
	}//for any of these options
	else{
		printf("Invalid input !");
		Sleep(1500);
		system("cls");
		goto retry;
	}
	
	return 0;
}
