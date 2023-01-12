#include <stdio.h>
 struct clien {
    char first_name[20];
    char last_name[20];
    int code;
    char date[8];
    float py;
};
  void add(){
   char another;
     FILE *fp;
     int n,i;
     struct clien info;
   do{
       system("cls");
       printf("\t\t\t\t=======add clein Info=======\n\n\n");
       fp=fopen("information.txt","a");
        printf("\n\t\t\tEnter First Name     : ");
          scanf("%s",&info.first_name);
          printf("\n\t\t\tEnter Last Name     : ");
          scanf("%s",&info.last_name);
          printf("\n\t\t\tEnter the code of clein      : ");
          scanf("%d",&info.code);
          printf("\n\t\t\tEnter tody's date : ");
          scanf("%s",&info.date);
          printf("\n\t\t\tEnter amount paid      : ");
          scanf("%f",&info.py);
          printf("\n\t\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }

    fwrite(&info, sizeof(struct clien), 1, fp);
    fclose(fp);

    printf("\t\t\tYou want to add another record?(y/n) : ");


    scanf("%s",&another);


   }while(another=='y'||another=='Y');};
   void cliens_cord(){

     FILE *fp;

    struct clien info;
    fp=fopen("information.txt","r");

     printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");

    if(fp==NULL){

        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

        while(fread(&info,sizeof(struct clien ),1,fp)){
        printf("\n\t\t\t\t clien Name  : %s %s",info.first_name,info.last_name);
        printf("\n\t\t\t\t code      : %d",info.code);
        printf("\n\t\t\t\t date      : %s",info.date);
        printf("\n\t\t\t\t paid: %f",info.py,"da");

        printf("\n\t\t\t\t ________________________________\n");

         }
        fclose(fp);


  };
  void search (){
  struct clien info;
      FILE *fp;
      int code,found=0;

    fp=fopen("information.txt","r");
    printf("\t\t\t\t=======SEARCH CLIEN RECORD=======\n\n\n");
    printf("\t\t\t\ttEnter code of clien : ");

    scanf("%d",&code);

    while(fread(&info,sizeof(struct clien),1,fp)>0){

        if(info.code == code){

        found=1;
        printf("\n\n\t\t\tclien Name : %s %s",info.first_name,info.last_name);
        printf("\n\t\t\tclien code        : %d",info.code);
        printf("\n\t\t\t date         : %s",info.date);
        printf("\n\t\t\tamounte paid        : %s",info.py);

        printf("\n\t\t\t______________________________________\n");

         };

    };

    if(!found){
       printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    };
  void delet (){
       struct clien info;
      FILE *fp, *fp1;


    int code,found=0;

       printf("\t\t\t\t=======CLIEN RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");
    printf("\t\t\t\tEnter the code : ");
    scanf("%d",&code);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(1);
      }

    while(fread(&info,sizeof(struct clien),1,fp)){
        if(info.code == code){

            found=1;

        }else{
           fwrite(&info,sizeof(struct clien),1,fp);
        }

    }
     fclose(fp);
     fclose(fp1);

    if(!found){
          printf("\n\t\t\t\tRecord not found\n");
        };
      if(found){
        remove("information.txt");
        rename("temp.txt","information.txt");
        printf("\n\t\t\t\tRecord deleted succesfully\n");
        };

  };
    void modify()
{
    FILE *fp;
    struct clien info;
    system("cls");
     int code,found=0;

    fp=fopen("information.txt","rb+");
    printf("\t\t\t\t=======MODIFAT CLIEN RECORD=======\n\n\n");
    printf("\t\t\t\ttEnter code of clien : ");
    scanf("%d",&code);
    if(fp == NULL){
    printf("\n\n\t\tError opening file");
    exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&info,sizeof(struct clien),1,fp)>0){
       if(info.code == code){
            found=1;


        }else{
           fwrite(&info,sizeof(struct clien),1,fp);
        }
	{
    printf("\nEnter first_ Name : ");
    gets(info.first_name);
    printf("enter last_name : ");
    gets(info.last_name);
    printf("Enter the code of clein : ");
    scanf("%d",&info.code);
    printf("Enter the date : ");
    scanf("%s",&info.date);
	fflush(stdin);
    printf("the paide : ");
    scanf("%f",&info.py);
    fseek(fp ,-sizeof(struct clien),SEEK_CUR);
    fwrite(&info,sizeof(struct clien),1,fp);
    break;
        };
    };
    if(!found){
       printf("\n\t\t\t clien not found\n");
    };
    fclose(fp);

}

int main()
{


    int choice;
    while (choice != 6){

    printf("CLIEN DATABASE MANAGEMENT SYSTEM=====\n");
    printf(" 1. Add clein\n");
    printf(" 2. clien record\n");
     printf(" 3. Search clein\n");
    printf(" 4. Delete clein\n");
    printf(" 5. modify \n");
    printf(" 6. Exit\n");
    printf("    _____________________\n");
    scanf("%d",&choice);

   switch(choice){
        case 1:
        add();
        break;
    case 2:
         cliens_cord();
         break;
    case 3:
        search();
       break;
    case 4:
        delet();
        break;
    case 5:
        modify();
        break;
    case 6:
        exit(0);
        break;
     default:
         system("cls");
         getch();
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
         getch();
         system("cls");
         break;
        };
        system("cls");};



    return 0;

}
