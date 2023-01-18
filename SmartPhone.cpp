#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Smartphone{
    int id;// mã sản phẩm
    string brand;
    string name;
    float price;
    int ram;
    int externalMem;
    string dateOfManufacture;

public:
	Smartphone() {
		id = 0;
		brand = "";
		name = "";
		ram = 0;
		price = 0;
		externalMem = 0;
		dateOfManufacture = "";
	}

	Smartphone(int id) : id(id) {}

	Smartphone(int id, string brand, string name, float price, int ram, int externalMem, string dom);

	void createInfo();

	void showInfo();

	float compareByPrice(Smartphone& other);

	int compareByName(Smartphone& other);

	int getId() { return id; }

	void setId(int id) { this->id = id; }

	string getBrand() { return brand; }

	string getName() { return name; }

	void setBrand(string brand) { this->brand = brand; }

	void setName(string name) { this->name = name; }

	float getPrice() { return price; }

	void setPrice(float price) { this->price = price; }

	int getRam() { return ram; }

	void setRam(int amount) { ram = amount; }

	int getExternalMem() { return externalMem; }

	string getDOM() { return dateOfManufacture; }

	void setDOM(string dom) { this->dateOfManufacture = dom; }
};

Smartphone::Smartphone(int id, string brand, string name,
	float price, int ram, int externalMem, string dom) : id(id), 
	price(price), ram(ram), externalMem(externalMem) {
	this->brand = brand;
	this->name = name;
	this->dateOfManufacture = dom;
}

void Smartphone::createInfo() {
	cout << "Ma san pham: ";
	cin >> id;
	cout << "Ten san pham: ";
	cin.ignore();
	getline(cin, name);
	cout << "Hang san xuat: ";
	getline(cin, brand);
	cout << "Bo nho RAM: ";
	cin >> ram;
	cout << "Bo nho ngoai: ";
	cin >> externalMem;
	cout << "Ngay san xuat: ";
	cin.ignore();
	getline(cin, dateOfManufacture);
	cout << "Gia ban: ";
	cin >> price;
}

void Smartphone::showInfo() {
	cout << left << setw(10) << id << setw(20) << name 
		<< setw(20) << brand << setw(15) << price
		<< setw(15) << ram << setw(15) << externalMem 
		<< setw(20) << dateOfManufacture << endl;
}

int Smartphone::compareByName(Smartphone& other) {
	return name.compare(other.name);
}

float Smartphone::compareByPrice(Smartphone& other) {
	return price - other.price;
}

int main(){
    int choice;
    Smartphone products[100];
    int n = 0;
    do{
        cout << "==================== MENU ====================\n";
		cout << "1. Them moi mot smartphone.\n";
		cout << "2. Sua gia ban theo ma san pham.\n";
		cout << "3. Xoa san pham theo ma.\n";
		cout << "4. Tim san pham theo ten.\n";
		cout << "5. Tim san pham theo hang san xuat.\n";
		cout << "6. Hien thi danh sach ra man hinh.\n";
		cout << "7. Sap xep danh sach san pham theo ma tang dan.\n";
		cout << "8. Sap xep danh sach san pham theo gia giam dan.\n";
		cout << "0. Thoat chuong trinh\n";
		cout << "Ban chon? ";
		cin >> choice;
        cin.ignore();
        switch(choice)
        {
        case 0:
        {
            cout << "<== Ket thuc chuong trinh. Xin chao va hen gap lai. ==>" << endl;
            break;
        }
        case 1:
        {
            Smartphone s;
            s.createInfo();
            products[n++] = s;
            break;
        }
        case 2:
        {
            if(n == 0){
                cout << "<== Danh sach san pham rong. ==>\n";
            }
            else{
                cout << "Nhap ma san pham: ";
                int id;
                float price;
                bool removeSuccess = false;
                cin >> id;
                for (int i = 0; i < n; i++)
                {
                    if(products[i].getId() == id){
                        cout << "Nhap gia moi cho san pham: ";
                        cin >> price;
                        products[i].setPrice(price);
                        cout << "Cap nhat thanh cong!\n";
						removeSuccess = true;
                    }
                }
                if (!removeSuccess) {
					cout << "<== Khong tim thay san pham ma " << id << " ==> \n";
				}
            }
            break;
        }
        case 3:
        {
            if(n == 0){
                cout << "<== Danh sach san pham rong. ==>\n";
            }
            else{
                cout << "Nhap ma san pham: ";
                int id;
                cin >> id;
                bool removeSuccess = false;
                for (int i = 0; i < n; i++)
                {
                    if(products[i].getId() == id){
                        for (int j = i; j < n; j++)
                        {
                            products[j] = products[j + 1];
                        }
                    }
                    --n;
                    cout << "<== Xoa san pham thanh cong ==>\n";
					removeSuccess = true;
                }
                if (!removeSuccess) {
					cout << "<== Khong tim thay san pham can xoa ==>\n";
				}
            }
            break;
        } 
        case 4:
        {
            if(n == 0){
                cout << "Danh sach san pham rong.\n";
            }
            else{
                cout << "Nhap ten san pham: ";
                string name;
                cin.ignore();
                getline(cin, name);
                bool found= false;
                for (int i = 0; i < n; i++)
                {
                    if(products[i].getName().compare(name) == 0){
                        found = true;
                        products[i].showInfo();
                    }
                }
                if (!found) {
					cout << "<== Khong tim thay san pham nao thoa man ==>\n";
				}
            }
            break;
        }
        case 5:
        {
            if(n == 0){
                cout << "<== Danh sach san pham rong. ==>\n";
            }   
            else{
                cout << "Nhap ten hang san xuat: ";
                cin.ignore();
                string brand;
                getline(cin, brand);
                bool found = false;
                for (int i = 0; i < n; i++)
                {
                    if(products[i].getBrand().compare(brand) == 0){
                        found = true;
                        products[i].showInfo();
                    }
                }
                if(!found){
                    cout << "<== Khong tim thay san pham nao thoa man ==>\n";
                }
            }
            break;
        }
        case 6:
        {
            if (n == 0) {
				cout << "<== Danh sach san pham rong. ==>\n";
			}
            else{
                cout << "<== Danh sach san pham hien co. ==>\n";
                cout << left << setw(10) << "Ma SP" << setw(20) << "Ten san pham"
                        << setw(20) << "Hang san xuat" << setw(15) << "Gia ban" << setw(15)
                        << "RAM" << setw(15) << "Bo nho ngoai" << setw(20) << "Ngay san xuat\n";
                for (int i = 0; i < n; i++)
                {
                    products[i].showInfo();
                }
            }
            break;
        }
        case 7:
        {
            if(n == 0){
                cout << "<== Danh sach san pham rong. ==>\n";
            }
            else{
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = n - 1; j > i; j--)
                    {
                        if(products[j].getId() < products[j - 1].getId()){
                            swap(products[j], products[j - 1]);
                        }
                    }   
                }
            }
        }
        case 8:
        {
            if(n > 0){
                for (int i = 0; i < n - 1; i++)
                {
                    for (int j = n - 1; j > i; j--)
                    {
                        if(products[j - 1].compareByPrice(products[j]) < 0){
                            swap(products[j], products[j - 1]);
                        }
                    }
                    
                }
            }
            else{
                cout << "<== Danh sach san pham rong, ==>\n";
            }
            break;
        }
    }

}while(choice != 0);

    return 0;
}