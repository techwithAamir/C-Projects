#include <stdio.h>
#include <stdbool.h>

// Account structure
struct Account {
    int accountNumber;
    float balance;
    int pin;
};

// Function declarations
bool authenticate(struct Account accounts[], int numAccounts, int *loggedInAccount);
void checkBalance(struct Account accounts[], int loggedInAccount);
void depositMoney(struct Account accounts[], int loggedInAccount);
void withdrawMoney(struct Account accounts[], int loggedInAccount);

int main() {
    // Sample account data (for demonstration)
    struct Account accounts[] = {
        {12345, 1000.00, 1234},  // Account 1
        {67890, 500.00, 5678}    // Account 2
        // Add more accounts here if needed
    };
    int numAccounts = sizeof(accounts) / sizeof(accounts[0]);
    int loggedInAccount = -1;

    while (1) {
        if (!authenticate(accounts, numAccounts, &loggedInAccount)) {
            printf("Authentication failed. Exiting.\n");
            break;
        }

        // Display options
        printf("\nAutomatic Teller Machine\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(accounts, loggedInAccount);
                break;
            case 2:
                depositMoney(accounts, loggedInAccount);
                break;
            case 3:
                withdrawMoney(accounts, loggedInAccount);
                break;
            case 4:
                printf("Thank you for using our ATM service!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

bool authenticate(struct Account accounts[], int numAccounts, int *loggedInAccount) {
    int accountNumber, pin;
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accountNumber && accounts[i].pin == pin) {
            *loggedInAccount = i;
            return true;
        }
    }

    return false;
}

void checkBalance(struct Account accounts[], int loggedInAccount) {
    printf("Your current balance is: $%.2f\n", accounts[loggedInAccount].balance);
}

void depositMoney(struct Account accounts[], int loggedInAccount) {
    float depositAmount;
    printf("Enter the amount to deposit: $");
    scanf("%f", &depositAmount);

    if (depositAmount > 0) {
        accounts[loggedInAccount].balance += depositAmount;
        printf("You have successfully deposited $%.2f\n", depositAmount);
    } else {
        printf("Invalid deposit amount!\n");
    }
}

void withdrawMoney(struct Account accounts[], int loggedInAccount) {
    float withdrawAmount;
    printf("Enter the amount to withdraw: $");
    scanf("%f", &withdrawAmount);

    if (withdrawAmount > 0 && withdrawAmount <= accounts[loggedInAccount].balance) {
        accounts[loggedInAccount].balance -= withdrawAmount;
        printf("You have successfully withdrawn $%.2f\n", withdrawAmount);
    } else if (withdrawAmount > accounts[loggedInAccount].balance) {
        printf("Insufficient balance!\n");
    } else {
        printf("Invalid withdraw amount!\n");
    }
}
