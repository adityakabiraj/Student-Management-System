#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//#include<graphics.h>
void search();
void add();
void menu();
void view();
void modify();
void delete();
void payfees();
void print(int a,int b)   //function to perform printing lines at paricular position
{
    int i,j;
    for(i=0;i<=a;i++)
    {
        printf("\n");
        for(j=0;j<=b;j++)
           printf(" ");
    }
}
struct student
{
    char name[20],surname[20],roll[20],phno[15];
    char branch[50];
    float fees;
};
void main()
{
    print(0,40);
    printf("<-----Student Management system----->\n");
   menu();
}
void menu()
{
    int choice;
    print(0,20);
    printf("----- MENU DETAILS -----\n");
    print(0,20);
    printf("1.Add data \n");
    print(0,20);
    printf("2.search data\n");
    print(0,20);
    printf("3.pay fees\n");
    print(0,20);
    printf("4.view data\n");
    print(0,20);
    printf("5.delete data\n");
    print(0,20);
    printf("Enter your choice -->");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            search();
            break;
        case 3:
            payfees();
            break;
        case 4:
            view();
            break;
        case 5:
            delete();
            break;
        default:
             print(0,20);
             printf("Invalid Choice");
    }
}
void add()
{
    int n,i,last;
    FILE *fp1;
    struct student s1;
    fp1=fopen("fees.txt","a+");
    print(0,40);
    printf("<--ADDITION OF DATA-->");
    print(0,20);
    printf("Enter no of students data to be entered -->");
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       print(0,20);
       printf("Enter name -->");
       scanf("%10s",s1.name);
       scanf(" %10s",s1.surname);
       print(0,20);
       printf("Enter branch -->");
       scanf("%5s",s1.branch);
       print(0,20);
       printf("Enter your phone number -->");
       scanf("%s",s1.phno);
       print(0,20);
       printf("Amount of fees paid -->");
       scanf("%5f",&s1.fees);
       print(0,20);
       printf("Enter the roll no -->");
       scanf("%10s",s1.roll);
       fprintf(fp1,"%10s %10s %15s %5s %5f %10s\n",s1.name,s1.surname,s1.phno,s1.branch,s1.fees,s1.roll);
    }
    print(0,20);
    printf("Wait data is being added....");
    sleep(3);
    system("cls");
    print(0,20);
    printf("Data added successfully");
    fclose(fp1);
    print(0,20);
    printf("\nEnter 1 to goto main menu else 0 to exit --> ");
    scanf("%d",&last);
    if(last==1)
      menu();
    else
      exit(1);
}
void view()
{
    FILE *fp1;
    int last;
    fp1=fopen("fees.txt","a+");
    struct student s1;
    print(0,20);
    printf("Wait data is loading.....");
    print(0,40);
    printf("<--VIEWING THE DATA-->");
  
    sleep(2);
    system("cls");
    while(1)
    {
        fscanf(fp1,"%s %s %s %s %f %s",s1.name,s1.surname,s1.phno,s1.branch,&s1.fees,s1.roll);
        if(feof(fp1))
          break;
        print(0,20);
        printf("Name of the student          -->%10s %10s",s1.name,s1.surname);
        print(0,20);
        printf("Mobile number of the student -->%15s",s1.phno);
        print(0,20);
        printf("Branch of the student        --> %5s",s1.branch);
        print(0,20);
        printf("Amount of fees paid          -->%5f",s1.fees);
        print(0,20);
        printf("Roll no of the student       -->%10s",s1.roll);
        printf("\n");

    }fclose(fp1);
    printf("\nEnter 1 to goto main menu else 0 to exit --> ");
    scanf("%d",&last);
    if(last==1)
      menu();
    else
      exit(1);
}
void payfees()
{
    int last;
    char aname[100],saname[20];
    FILE *fp1,*fp2;
    struct student s1;
    fp1=fopen("fees.txt","a+");
    fp2=fopen("ak.txt","a+");
    float extra;
    print(0,40);
    printf("<--PAYMENT OF FEES-->");
    print(0,20);
    printf("Enter the name of the student -->");
    scanf("%s",aname);
    scanf(" %s",saname);
    print(0,20);
    printf("Enter the amount to be paid -->");
    scanf("%f",&extra);
    while(1)
    {
        fscanf(fp1,"%s %s %s %s %f %s",s1.name,s1.surname,s1.phno,s1.branch,&s1.fees,s1.roll);
        if(feof(fp1))
              break;
        if(strcmp(s1.name,aname)==0 && strcmp(s1.surname,saname)==0)
        {
            s1.fees+=extra;
            fprintf(fp2,"%10s %10s %15s %5s %5f %10s\n",s1.name,s1.surname,s1.phno,s1.branch,s1.fees,s1.roll);
            print(0,20);
            printf("processing payment...");
            sleep(2);
            system("cls");
            print(0,20);
            printf("Fees added succesfully");
        }
    }
    fclose(fp1);
    remove("fees.txt");
    rename("ak.txt","fees.txt");
    fclose(fp2);
    printf("\nEnter 1 to goto main menu else 0 to exit --> ");
    scanf("%d",&last);
    if(last==1)
      menu();
    else
      exit(1);
}
void search()
{
    int last;
      system("cls");
      FILE *fp1;
      fp1=fopen("fees.txt","a+");
      struct student s1;
      char aname[100],asname[20];
      print(0,40);
      printf("<--SEARCHING THE DATA-->");
      print(0,20);
      again:
      printf("Enter the name --> ");
      scanf("%s",aname);
      scanf(" %s",asname);
      print(0,20);
      printf("Wait data is being searched...");
      sleep(2);
      while(fscanf(fp1,"%s %s %s %s %f %s",s1.name,s1.surname,s1.phno,s1.branch,&s1.fees,s1.roll)!=EOF)
      {
        if(strcmp(s1.name,aname)==0 && strcmp(s1.surname,asname)==0)
        {
            print(0,20);
            printf("Name of the student          --> %s %s",s1.name,s1.surname);
            print(0,20);
            printf("Branch of the student        --> %5s",s1.branch);
            print(0,20);
            printf("Mobile number of the student -->%15s",s1.phno);
            print(0,20);
            printf("Fees paid by the student     --> %5f",s1.fees);
            print(0,20);
            printf("Roll no of the studfent      --> %10s",s1.roll);
        }  
      }
    fclose(fp1);
    printf("\nEnter 1 to goto main menu else 0 to exit --> ");
    scanf("%d",&last);
    if(last==1)
      menu();
    else
      exit(1);
}
void delete()
{
    int last;
    struct student s1;
    char aname[20],sname[20];
    printf("Enter the name whos data is to be deleted -->");
    scanf("%s %s",aname,sname);
    FILE *fp1,*fp2;
    fp1=fopen("fees.txt","a+");
    fp2=fopen("change.txt","a+");
    rewind(fp1);
      while(1)
    {
        fscanf(fp1,"%s %s %s %s %f %s",s1.name,s1.surname,s1.phno,s1.branch,&s1.fees,s1.roll);
        if(feof(fp1))
              break;
        if(strcmp(s1.name,aname)!=0 || strcmp(s1.surname,sname)!=0)
        {
            fprintf(fp2,"%s %s %s %s %f %s",s1.name,s1.surname,s1.phno,s1.branch,s1.fees,s1.roll);
        } 
    }
    fclose(fp1);
    remove("fees.txt");
    rename("change.txt","fees.txt");
    fclose(fp2);
    print(0,20);
    printf("Removing record from data...");
    sleep(2);   
    print(0,20);
    printf("Data removed succesfully");
    printf("\nEnter 1 to goto main menu else 0 to exit --> ");
    scanf("%d",&last);
    if(last==1)
      menu();
    else
      exit(1);
}
/*void modify()
{
    print(0,40);
    printf("<---- MODIFICATION OF DATA ---->");
    print(0,20);
    printf("*** DATA TO BE MODIFIED ***");
    print(0,20);
    printf("1.modify name\n");
    print(0,20);
    printf("2.modify branch\n");
    print(0,20);
    printf("3.modify roll no\n");
    print(0,20);
    printf("4.modify details\n");
    print(0,20);
    printf("5.modify entire details\n");
    
}*/