#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void display()
{
    puts("                                         *********MENU*************");
    puts("                                         *                        *");
    puts("                                         *  1. Check balance      *");
    puts("                                         *                        *");
    puts("                                         *  2. Deposit            *");
    puts("                                         *                        *");
    puts("                                         *  3. Withdraw           *");
    puts("                                         *                        *");
    puts("                                         *  4. Account details    *");
    puts("                                         *                        *");
    puts("                                         *  5. Exit               *");
    puts("                                         *                        *");
    puts("                                         **************************");
}

void pass()
{
    const char loginPassword[]="5555";
    const int maxPasswordLength=4;
    char password[maxPasswordLength+1];
    char ch;
    int characterPosition=0;
    puts("Enter the pin...");
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            break;
        }
        else if(ch==8)
        {
            if(characterPosition>0)
            {
                characterPosition--;
                password[characterPosition]='\0';
                printf("\b \b");
            }
        }
        else if(ch==32 || ch== 9)
        {
            puts("Enter a valid Character");
            continue;
        }
        else
        {
            if(characterPosition < maxPasswordLength)
            {
                password[characterPosition]=ch;
                characterPosition++;
                printf("*");
            }
            else
            {
                puts("\nYour input exceeds maximum pin length!");
            }
        }
    }
    password[characterPosition]='\0';
    puts("\n");
    if(strcmp(password,loginPassword)==0);
    else if(strlen(password)==0)
    {
        system("cls");
        puts("No password entered!");
        pass();
    }
    else
    {
        system("cls");
        puts("\nPin entered is incorrect, try again...");
        pass();
    }
}
struct record
{
    int accountNumber;
    char name[30];
    char accountType[20];
    int balance;

};

void getrecord(struct record C){
    printf("Account number: %d\n",C.accountNumber);
    printf("Name: %s\n",C.name);
    printf("Account type: %s\n",C.accountType);
    printf("Account balance: %d\n",C.balance);
}
void condition()
{
    int n;
    int debit;
    int withdraw;
    int checkBalance;
    int exit;

    struct record C;
    C.accountNumber=123456789;
    C.balance=0;
    strcpy(C.name,"Lohith");
    strcpy(C.accountType,"Savings account");

    do{
    display();
    printf("Option: ");
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
    case 1:
        {
            checkBalance=C.balance;
            printf("Account balance is: %d\n",checkBalance);
            puts("\nPress any key to continue...");
            system("pause>0");
            system("cls");
            break;
        }
    case 2:
        {
            printf("Enter the amount: ");
            scanf("%d",&debit);
            printf("%d$ is added to your bank account.\n",debit);
            C.balance+=debit;
            puts("\nPress any key to continue...");
            system("pause>0");
            system("cls");
            break;
        }
    case 3:
        {
            printf("\nEnter the amount to withdraw: ");
            scanf("%d",&withdraw);
            if(C.balance<withdraw)
            {
                puts("Insufficient bal!");
            }
            else
            {
                printf("%d has deducted.\n",withdraw);
                C.balance-=withdraw;
            }
            puts("\nPress any key to continue...");
            system("pause>0");
            system("cls");
            break;
        }
    case 4:
        {
            getrecord(C);
            puts("\nPress any key to continue...");
            system("pause>0");
            system("cls");
            break;
        }
    case 5:
        {
            puts("Program Terminated.");
            break;
        }
    default:
        {
            puts("Please enter a number from 1 to 4.");
        }
    }
    }while(n!=5);
}
int main()
{
    pass();
    system("cls");
    condition();
    return 0;
}


