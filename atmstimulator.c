#include <stdio.h>
#include <stdbool.h>

int balance = 100000;
int pin = 1234;
int transactionHistory[100];
int transactionCount = 0;

void displayMenu();
bool verifyPIN(int pin);
void withdraw();
void deposit();
void checkBalance();
void displayTransactionHistory();

int main()
{
    int option;
    int enteredPIN;

    printf("Welcome to ATM Simulator!\n");

    printf("Enter your PIN: ");
    scanf("%d", &enteredPIN);

    if(!verifyPIN(enteredPIN))
    {
        printf("Invalid PIN. Exiting the program.\n");
        return 0;
    }
    do {
        displayMenu();

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            withdraw();
            break;
        case 2:
            deposit();
            break;
        case 3:
            checkBalance();
            break;
        case 4:
            displayTransactionHistory();
            break;
        case 5:
            printf("Thank you for using the ATM simulator. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);
    return 0;
}


void displayMenu()
{
    printf("\n");
    printf("1. Withdraw money\n");
    printf("2. Deposit money\n");
    printf("3. Check balance\n");
    printf("4. Display transaction history\n");
    printf("5. Exit\n");

}

bool verifyPIN(int enteredPIN)
{
    if (enteredPIN == pin)
    {
        return true;
    }
    else {
        return false;
    }
}


void withdraw()
{
    int amount;

    printf("Enter the amount to withdraw: ");
    scanf("%d", &amount);

    if(amount > balance) {
        printf("Insufficient Balance");
    }
    else {
        balance -= amount;
        transactionHistory[transactionCount++] = amount;

        printf("Deposit amount: %d\n", amount);
        printf("Total balance: %d\n", balance);
    }

}


void deposit()
{
    int amount;

    printf("Enter the amount to deposit: ");
    scanf("%d", &amount);

    balance += amount;
    transactionHistory[transactionCount++] = amount;
    printf("Deposit amount: %d\n", amount);
    printf("Total balance: %d\n", balance);

}


void checkBalance()
{
    printf("Your current balance is: %d\n", balance);
}

void displayTransactionHistory()
{
    printf("Transaction History:\n");
    if (transactionCount == 0) {
        printf("No transaction available.\n");
        return 0;
    }
    for (int i = 0; i < transactionCount; i++)
    {
        if (transactionHistory[i] > 0){
            printf("Deposit: %d\n", transactionHistory[i]);
        }
        else {
            printf("Withdrawal: %d\n", -transactionHistory[i]);
        }
    }


}