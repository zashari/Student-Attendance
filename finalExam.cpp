/*
	2501977172 - Andi Izzat Zaky Ashari
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

struct st{
	char id[15], name[20], time[50];
	struct st* left;
	struct st* right;
	
} *root = NULL;

typedef struct st student;

void insert(student *);
void search();
void show(student *);
int check(char[], char[]); 

int check(char a[], char b[]){
	int i, j , cek;
	for(i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++ , j++){
		if(a[i] > b[j]){
			cek = 1;
			break;
		}else if(a[i] < b[j]){
			cek = -1;
			break;
		}else{
			cek = 0;
		}
	}
	if(cek == 1){
		return 1;
	}else if(cek == -1){
		return -1;
	}else{
		return 0;
	}
}

void search(){
	char id[15];
	
	student *ptr;
	ptr = root;
	int flag = 0;
	
	fflush(stdin);
	printf("Enter Student ID: "); scanf("%s", id);
	
	
	while(ptr != NULL && flag == 0){
		if(check(id ,ptr->id) == 1)
			ptr = ptr->right;
		else if(check(id, ptr->id) == -1)
			ptr = ptr->left;
		else{
		flag = 1;
		system("cls");
		printf("==============================================\n");
		printf("=                                            =\n");
		printf("=         STUDENT ATTENDANCE PROGRAM         =\n");
		printf("=                <2501977172>                =\n");
		printf("==============================================\n");
		printf("Student ID\t: %s\n", ptr->id);
		printf("Student Name\t: %s\n", ptr->name);
		printf("Attending Time\t: %s\n", ptr->time);
		break;
		}
		
	}
	if(flag == 0 && ptr == NULL){
		
		printf("\nstudent with ID %s is not present today!\n", id);
	}
		
	
}

void insert(student* temp){
	student *ptr, *par;
	ptr = root;
	int flag = 0;
	char time[40];
	
	if(root == NULL)
		root = temp;
	else{
		while(ptr != NULL){
			if(check(temp->id ,ptr->id) == 1){
				par = ptr;
				ptr = ptr->right;	
			}
			else if(check(temp->id, ptr->id) == -1){
				par = ptr;
				ptr = ptr->left;
			}
			else{
			flag = 1;
			printf("\nStudent Already Attended!\n");
			break;
			}
		}
		if(flag == 0){
			if(check(par->id, temp->id) == 1)
				par->left = temp;
			else if(check(par->id, temp->id) == -1)
				par->right = temp;
		}
	}
	
}

void show(student *ptr){
	if(root == NULL)
		printf("\nNo Students in Class!\n");

	else{
		if(ptr != NULL){
			show(ptr->left);
			printf("\nStudent ID\t: %s\n", ptr->id);
			printf("Student Name\t: %s\n", ptr->name);
			printf("Attending Time\t: %s\n", ptr->time);
			show(ptr->right);
		}
	}
}	

int main(){
	int option;
	char timel;
	student *temp;
	do{
		system("cls");
		printf("==============================================\n");
		printf("=                                            =\n");
		printf("=         STUDENT ATTENDANCE PROGRAM         =\n");
		printf("=                <2501977172>                =\n");
		printf("==============================================\n");
		printf("= MENU:                                      =\n");
		printf("=  1. Input Student Attendance               =\n");
		printf("=  2. Show Student Attendance                =\n");
		printf("=  3. Search Student                         =\n");
		printf("==============================================\n");
		printf("\nSelect: "); scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				system("cls");
				printf("==============================================\n");
				printf("=                                            =\n");
				printf("=         STUDENT ATTENDANCE PROGRAM         =\n");
				printf("=                <2501977172>                =\n");
				printf("==============================================\n");
				temp = (student *)malloc(sizeof(student));
				temp->left = temp->right = NULL;
				fflush(stdin);
				printf("Enter Student ID\t: "); scanf("%s", temp->id);
				fflush(stdin);
				printf("Enter Student Name\t: "); scanf("%[^\n]s", temp->name);	
				{
				struct tm *newtime;
				time_t ltime;
				
				time(&ltime);
				newtime = localtime(&ltime);
				strcpy(temp->time, asctime(newtime));
				printf("Attendance Time\t\t: %s\n", temp->time);
				}
				
				insert(temp);
			break;
			
			case 2:
				system("cls");
				printf("==============================================\n");
				printf("=                                            =\n");
				printf("=         STUDENT ATTENDANCE PROGRAM         =\n");
				printf("=                <2501977172>                =\n");
				printf("==============================================\n");
				printf("List of Students Attending:\n");
				show(root);
			break;
			
			case 3:
				system("cls");
				printf("==============================================\n");
				printf("=                                            =\n");
				printf("=         STUDENT ATTENDANCE PROGRAM         =\n");
				printf("=                <2501977172>                =\n");
				printf("==============================================\n");
				search();
			break;
			
			case 4:
				exit(0);
		}
		getch();
	}while(option != 0);
}
