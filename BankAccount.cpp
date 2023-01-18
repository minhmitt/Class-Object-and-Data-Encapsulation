#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class BankAccount{
private:
    int id;
    string owner;
    string cardNumber;
    long ballance = 0;
    string startDate;
    string endDate;
    string bankName;
public:
    // initialization function 
    BankAccount();
    BankAccount(int, string, string, long, string, string, string);
    //action 
    void checkBallance();
    bool withdraw(long amount);
    bool transfer(BankAccount other, long amount);
    bool deposit(long amount);
    // getter/setter
    void setOwner(string owner){ this->owner = owner; }

    string getOwner(){ return owner; }

    void setCardNumber(string cardNumber){ this->cardNumber = cardNumber; }

    string getCardNumber(){ return cardNumber; }

    void setBallance(long ballance){ this->ballance = ballance; }

    long getBallance(){ return ballance; }

    void setStartDate(string startDate){ this->startDate = startDate; }

    string getStartDate(){ return startDate; }

    void setEndDate(string endDate){ this->endDate = endDate; }

    string getEndDate(){ return endDate; }

    void setBankName(string bankName){ this->bankName = bankName; }

    string getBankName(){ return bankName; }
};

// không khai báo access modifier sẽ tự động hiểu là private 

BankAccount::BankAccount(int id, string owner, string cardNumber, 
            long ballance, string startDate, string endDate, string bankName){
            this->id = id;
            this->owner = owner;
            this->cardNumber = cardNumber;
            this->ballance = ballance;       
            this->startDate = startDate;
            this->endDate = endDate;
            this->bankName = bankName;
}

void BankAccount::checkBallance(){
    cout << "=========================================\n";
    cout << "Owner: " << owner << endl;
    cout << "Card number: " << cardNumber << endl;
    cout << "Ballance: " << ballance << endl;
    cout << "Start date: " << startDate << endl;
    cout << "End date: " << endDate << endl;
}

bool BankAccount::withdraw(long amount){
    cout << "=========================================\n";
    if(amount > 0 && amount <= ballance){
        ballance -= amount;
        cout << "Withdrawn successfully.\n";
        cout << "Account " << cardNumber << " - " << amount << endl;
        cout << "Your current ballance is: " << ballance << endl;
        return true;
    }
    else{
        cout << "Your ballance is not enough. Please try other amount.\n";
        return false;
    }
}

bool BankAccount::transfer(BankAccount other, long amount){
    cout << "=========================================\n";
    if(amount < ballance){
        other.ballance += amount;
        ballance -= amount;
        cout << "Transferred successfully.\n";
        cout << "Account " << cardNumber << " -" << amount << endl;
		cout << "Account " << other.cardNumber << " +" << amount << endl;
		cout << "Your current ballance is " << ballance << endl;
		return true;
    }
    else {
		cout << "Transfer failed. Ballance is not enough." << endl;
		return false;
	}
}

bool BankAccount::deposit(long amount){
    cout << "=========================================\n";
    if(amount > 0){
        ballance += amount;
        cout << "Deposit successfully.\n";
        cout << "Transaction + " << amount << endl;
        cout << "Account " << cardNumber << endl;
        cout << "Your current ballance is " << ballance << endl;
        return true;
    }
    else{
        cout << "Invalid deposit amount. Please check again." << endl;
        return false;
    }
}

int main(){
    BankAccount acc1{ 1, "LE VIET HUNG", "9704 3668 1450 3266 098",
		99825000, "01/01/2023", "01/01/2028", "Vietcombank" };
	BankAccount acc2{ 2, "HOANG TRONG TU", "9704 3668 1450 3266 338",
		5925000, "01/05/2023", "01/05/2028", "Vietcombank" };
    int choice = 0;
    do{
        cout << "==================== MENU ====================\n";
        cout << "1. Check ballance.\n";
        cout << "2. Deposit.\n";
        cout << "3. Withdraw.\n";
        cout << "4. Bank Transfer.\n";
        cout << "0. Exit.\n";
        cout << "Your choice? ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
            {
                cout << "<== Thank you for using our service! ==>\n";
			    break;
            }
            case 1:
            {
                cout << "Enter card number: ";
                string cardNumber;
                getline(cin, cardNumber);
                if(cardNumber.compare(acc1.getCardNumber()) == 0){
                    acc1.checkBallance();
                }
                else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
                    acc2.checkBallance();
                }
                else {
                    cout << "Card number mismatch. Please try again!\n";
                }
                break;
            }
            case 2:
            {
                long amount;
                cout << "Enter amount you want to deposit: ";
                cin >> amount;
                cin.ignore();
                string cardNumber;
                cout << "Enter card number: ";
                getline(cin, cardNumber);
                if(cardNumber.compare(acc1.getCardNumber()) == 0){
                    acc1.deposit(amount);
                }
                else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
                    acc2.deposit(amount);
                }
                else {
                    cout << "Card number mismatch. Please try again!\n";
                }
                break;
            }
            case 3:
            {
                long amount;
                cout << "Enter amount you want to withdraw: ";
                cin >> amount;
                cin.ignore();
                string cardNumber;
                cout << "Enter card number: ";
                getline(cin, cardNumber);
                if(cardNumber.compare(acc1.getCardNumber()) == 0){
                    acc1.withdraw(amount);
                }
                else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
                    acc2.withdraw(amount);
                }
                else {
                    cout << "Card number mismatch. Please try again!\n";
                }
                break;
            }
            case 4:
            {
                BankAccount* accPtr = nullptr;
                cout << "Enter card number: ";
                string cardNumber;
                getline(cin, cardNumber);
                if(cardNumber.compare(acc1.getCardNumber()) == 0){
                    accPtr = &acc1;
                }
                else if (cardNumber.compare(acc2.getCardNumber()) == 0) {
                    accPtr = &acc2;
                }
                else {
                    cout << "Card number mismatch. Please try again!\n";
                }
                if(accPtr != nullptr){
                    long amount;
                    cout << "Enter amount you want to transfer: ";
                    cin >> amount;
                    acc1.transfer(*accPtr, amount);
                }
                break;
            }
            default:
            {
                cout << "Invalid choice. Please try again!\n";
                break;
            }
		}
    }while(choice != 0);

    return 0;
}
