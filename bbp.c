#include<stdio.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
int main(){
    FILE *file;
    char a, file_name[100], input[1000], read[5000], temp[5000], find[100], replace[100];
    int ch1=1, ch2=1, i, ch3=1, t=0, change=0;
    printf("Enter file name : ");
    gets(file_name);
    while(file_name[0]!='0'){
        if(file = fopen(file_name,"r")){
            fclose(file);
            system("cls");
            printf("\n0. Exit\n1. Read\n2. Write\n3. Append\n4. Process Text\nEnter your choice : ");
            scanf("%d",&ch1);
            while(ch1){
                if(ch1==1){
                    system("cls");
                    file = fopen(file_name,"r");
                    a=fgetc(file);
                    if(a == EOF){
                        printf("File is empty");
                    }
                    while(a != EOF){
                        printf("%c",a);
                        a=fgetc(file);
                    }
                    fclose(file);
                    printf("\nPress any key to continue");
                    getch();
                }
                else if(ch1==2){
                    system("cls");
                    printf("\n\nEnter To Write :\n");
                    fflush(stdin);
                    gets(input);
                    file = fopen(file_name,"w");
                    fputs(input,file);
                    fclose(file);
                    printf("Written in File Succesfully");
                    printf("\nPress any key to continue");
                    getch();
                }
                else if(ch1==3){
                    system("cls");
                    printf("\n\nEnter To Append :\n");
                    fflush(stdin);
                    gets(input);
                    file = fopen(file_name,"a");
                    fputs(input,file);
                    fclose(file);
                    printf("Appended in File Succesfully");
                    printf("\nPress any key to continue");
                    getch();
                }
                else if(ch1==4){
                    system("cls");
                    printf("\n0. Exit\n1. Uppercase\n2. Lowercase\n3. Capitalize\n4. Remove Punctuations\n5. Sentence Tokenization\n6. Remove Numbers\n7. Remove Whitespaces\n8. Replace\nEnter your choice : ");
                    scanf("%d",&ch2);
                    while(ch2){
                        system("cls");
                        if(ch2==1){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                read[i]=a;
                                i++;
                                a=fgetc(file);
                            }
                            read[i]='\0';
                            fclose(file);
                            strupr(read);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Successfully converted into Uppercase\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==2){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                read[i]=a;
                                i++;
                                a=fgetc(file);
                            }
                            read[i]='\0';
                            fclose(file);
                            strlwr(read);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Successfully converted into Lowercase\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==3){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                read[i]=a;
                                i++;
                                a=fgetc(file);
                            }
                            read[i]='\0';
                            fclose(file);
                            if(strlen(read)!=0){
                                if(read[0]>=97 && read[0]<=122){
                                    read[0]=read[0]-32;
                                }
                            }
                            for(int i=1;i<strlen(read)-1;i++){
                                if(read[i]=='.' || read[i]=='?' || read[i]=='\n'){
                                    if(read[i+1]==' '){
                                        i++;
                                    }
                                    if(read[i+1]>=97 && read[i+1]<=122){
                                        read[i+1]=read[i+1]-32;
                                    }
                                }
                            }
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Successfully Capitalized\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==4){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                if(a!='!' && a!='-' && a!='?' && a!='/' && a!='_' && a!='*' && a!=':' && a!=';' && a!='@' && a!='$' && a!='#' && a!='(' && a!=')'){
                                    read[i]=a;
                                    i++;
                                    a=fgetc(file);
                                }
                                else{
                                    a=fgetc(file);
                                }
                            }
                            read[i]='\0';
                            fclose(file);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Punctuations removed Successfully\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==5){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                if(a=='.' || a=='?'){
                                    read[i]=a;
                                    i++;
                                    read[i]='\n';
                                    i++;
                                    a=fgetc(file);
                                    if(a==' '){
                                        a=fgetc(file);
                                    }
                                }
                                else{
                                    read[i]=a;
                                    i++;
                                    a=fgetc(file);
                                }
                            }
                            read[i]='\0';
                            fclose(file);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Sentence Tokenized Successfully\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==6){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                if(a!='0' && a!='1' && a!='2' && a!='3' && a!='4' && a!='5' && a!='6' && a!='7' && a!='8' && a!='9'){
                                    read[i]=a;
                                    i++;
                                    a=fgetc(file);
                                }
                                else{
                                    a=fgetc(file);
                                }
                            }
                            read[i]='\0';
                            fclose(file);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Numbers removed Successfully\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==7){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                if(a==' '){
                                    read[i]=a;
                                    i++;
                                    a=fgetc(file);
                                    while(a==' '){
                                        a=fgetc(file);
                                    }
                                }
                                else{
                                    read[i]=a;
                                    i++;
                                    a=fgetc(file);
                                }
                            }
                            read[i]='\0';
                            fclose(file);
                            file = fopen(file_name,"w");
                            fputs(read,file);
                            printf("Whitespaces removed Successfully\n");
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        else if(ch2==8){
                            system("cls");
                            file = fopen(file_name,"r");
                            a=fgetc(file);
                            i=0;
                            while(a != EOF){
                                read[i]=a;
                                i++;
                                a=fgetc(file);
                            }
                            read[i]='\0';
                            fclose(file);
                            printf("Find : ");
                            scanf("%s",&find);
                            printf("Replace : ");
                            scanf("%s",&replace);
                            file = fopen(file_name,"w");
                            fclose(file);
                            file = fopen(file_name,"a");
                            i=0;
                            for(int k=0;k<strlen(read);k++){
                                if(read[k]==find[0]){
                                    t=0;
                                    for(int j=0;j<strlen(find);j++){
                                        if(read[k+j]==find[j]){
                                            t++;
                                        }
                                    }
                                    if(t==strlen(find)){
                                        temp[i]='\0';
                                        i=0;
                                        fputs(temp,file);
                                        fputs(replace,file);
                                        k=k+strlen(find)-1;
                                        change++;
                                    }
                                    else{
                                        temp[i]=read[k];
                                        i++;
                                    }
                                }
                                else{
                                    temp[i]=read[k];
                                    i++;
                                }
                            }
                            temp[i]='\0';
                            i=0;
                            fputs(temp,file);
                            printf("%d changes occured\n",change);
                            change=0;
                            fclose(file);
                            printf("\nPress any key to continue");
                            getch();
                        }
                        system("cls");
                        printf("\n0. Exit\n1. Uppercase\n2. Lowercase\n3. Capitalize\n4. Remove Punctuations\n5. Sentence Tokenization\n6. Remove Numbers\n7. Remove Whitespaces\n8. Replace\nEnter your choice : ");
                        scanf("%d",&ch2);
                    }
                }
                else{
                    printf("Invalid Choice");
                    printf("\nPress any key to retry");
                    getch();

                }
                system("cls");
                printf("\n0. Exit\n1. Read\n2. Write\n3. Append\n4. Process Text\nEnter your choice : ");
                scanf("%d",&ch1);
            }
            system("cls");
            printf("\nEnter file name : ");
            scanf("%s",file_name);
        }
        else{
            int create = 1;
            printf("File Not Found\n");
            printf("Enter 1 to create file : ");
            scanf("%d", &create);
            if(create == 1){
                file = fopen(file_name, "w+");
            }
            else{
                fflush(stdin);
                printf("Enter file name again : ");
                gets(file_name);
            }
        }
    }
    char stopper;
    scanf("%c",&stopper);
}