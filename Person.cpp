#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class FullName{
public:
    string firstName;
    string lastName;
    string midName;
    //hàm khởi tạo
    FullName(){}
    FullName(string firstName, string lastName, string midName) : 
        firstName(firstName), lastName(lastName), midName(midName){}
    void setFirstName(string firstName){
        this->firstName = firstName;
    }

    void setMidName(string midName){
        this->midName = midName;
    }

    void setLastName(string lastName){
        this->lastName = lastName;
    }

    string getFirstName(){
        return firstName;
    }

    string getMidName(){
        return midName;
    }

    string getLastName(){
        return lastName;
    }

    string getFullName(){
        return firstName + " " + midName + " " + lastName;
    }
};

class Address{
public:
    string roadName;
    string number;
    string alley;
    string ward;
    string district;
    string city;
    string nation;
    // initialization function
    Address() {}
    Address(string city, string nation) : city(city), nation(nation){}
    Address(string district, string city, string nation): 
        district(district), city(city), nation(nation){}
    string getFullAddress();
};

string Address::getFullAddress(){
    return number + ", " + alley + ", " + roadName + ward + 
            ", " + district + ", " + city + ", " + nation;
}

class Person {
public:
    string id;
    FullName fullname;
    Address address;
    string dateOfBirth;
    string email;
    string phoneNumber;
    string occupation;
    string gender;
    // initialization function
    Person() {}
    Person(string id, FullName fullname, Address address, string dob,
            string email, string phoneNum, string occupation, string gender) :
            id(id), fullname(fullname), address(address), dateOfBirth(dob), 
            email(email), phoneNumber(phoneNum), occupation(occupation), gender(gender) {}

    // action
    void sleep();
    void work();
    void relax();
    void eat();
};

void Person::sleep(){
    cout << fullname.getFullName() << " is sleeping.\n";
}

void Person::work(){
    cout << fullname.getFullName() << " is working in the garden.\n";
}

void Person::relax(){
    cout << fullname.getFullName() << " is relaxing by playing the piano.\n";
}

void Person::eat(){
    cout << fullname.getFullName() << " is eating dinner.\n";
}

// nguyên mãu hàm
Person addPersonInfo();
void showPersonInfo(Person person);
void showTableCollumnName();
Person* findPersonById(Person* people, const int size, string id);

int main(){
    Person friends[100];
    int n = 0;
    int choice = 0;
    do{
        cout << "======================= MENU =======================\n";
        cout << "1. Add new user information.\n";
        cout << "2. Display user list.\n";
        cout << "3. Find user by name.\n";
        cout << "4. Adjust occupation by national ID.\n";
        cout << "0. Exit program!\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 0:
            {
                cout << "<== GOODBYE AND SEE YOU AGAIN!\n";
                break;
            }
            case 1:
            {
                friends[n++] = addPersonInfo();
                break;
            }
            case 2:
            {
                cout << "================ DANH SACH NHAN SU ===============\n";
                if(n > 0){
                    showTableCollumnName();
                    for (int i = 0; i < n; i++)
                    {
                        showPersonInfo(friends[i]);
                    }
                }
                else{
                    cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
                }
                break;
            }
            case 3:
            {
                if(n > 0){
                    Person results[100];
                    int resultCounter = 0;
                    string firstName;
                    cout << "Nhap ten can tim: ";
                    getline(cin, firstName);
                    for (int i = 0; i < n; i++)
                    {
                        if(friends[i].fullname.firstName.compare(firstName) == 0){
                            results[resultCounter++] = friends[i];
                        }
                    }
                    if (resultCounter == 0) {
					    cout << "<== KHONG CO KET QUA ==>" << endl;
				    }
                    else{
                        showTableCollumnName();
                        for (int i = 0; i < resultCounter; i++)
                        {
                            showPersonInfo(results[i]);
                        }
                    }
                    
                }
            }
            case 4:
            {
                if(n > 0){
                    string id;
                    cout << "Enter national ID: \n";
                    getline(cin, id);
                    Person *person = findPersonById(friends, n, id);
                    if(person == nullptr){
                        cout << "<== KHONG TIM THAY KET QUA. VUI LONG THU LAI ==>\n";
                    }
                    else{
                        string occupation;
                        cout << "Nhap nghe nghiep: ";
                        getline(cin, occupation);
                        person->occupation = occupation;
                        cout << "<== CAP NHAT THANH CONG ==>\n";
                        showTableCollumnName();
                        showPersonInfo(*person);
                    }
                }
                else {
				    cout << "<== DANH SACH RONG. VUI LONG NHAP DU LIEU VAO TRUOC! ==>\n";
			    }
			    break;
            }
            default:
            {
                cout << "Sai chuc nang. Vui long chon lai!\n";
			    break;
            }
        }
    }while(choice != 0);

    return 0;
}

Person addPersonInfo(){
    string personId;
    string firstName;
    string lastName;
    string midName;
    string dob;
    string email;
    string city;
    string nation;
    string phoneNumber;
    string occupation;
    string gender;
    cout << "============== NHAP THONG TIN CA NHAN ==============\n";
    cout << "Nhap so CMND/CC/HC: ";
    getline(cin, personId);
    cout << "Nhap ho: ";
    getline(cin, lastName);
    cout << "Nhap ten dem: ";
    getline(cin, midName);
    cout << "Nhap ten";
    getline(cin, lastName);
    cout << "Nhap ngay sinh: ";
    getline(cin, dob);
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap ten tinh: ";
    getline(cin, city);
    cout << "Nhap ten quoc gia: ";
    getline(cin, nation);
    cout << "Nhap so dien thoai: ";
    getline(cin, phoneNumber);
    cout << "Nhap nghe nghiep: ";
    getline(cin, occupation);
    cout << "Nhap gioi tinh: ";
    getline(cin, gender);
    Address address(city, nation);
    FullName fullName(firstName, lastName, midName);
    Person person(personId, fullName, address, 
		dob, email, phoneNumber, occupation, gender);
    return person;
}

void showTableCollumnName() {	
	cout << left << setw(20) << "CMND/CC/HC" << setw(22) << "Ho va ten"
		<< setw(12) << "Ngay sinh" << setw(25) << "Email" << setw(15)
		<< "Dia chi" << setw(15) << "So dien thoai" << setw(20)
		<< "Nghe nghiep" << setw(12) << "Gioi tinh" << endl;
}

void showPersonInfo(Person person){
    cout << left << setw(20) << person.id << setw(22) << person.fullname.getFullName()
		<< setw(12) << person.dateOfBirth << setw(25) << person.email << setw(15)
		<< person.address.city << setw(15) << person.phoneNumber << setw(20)
		<< person.occupation << setw(12) << person.gender << endl;
}

Person *findPersonById(Person *people, const int size, string id){
    for (int i = 0; i < size; i++)
    {
        if(people[i].id.compare(id) == 0){
            return &people[i];
        }
    }
    return nullptr;
    
}