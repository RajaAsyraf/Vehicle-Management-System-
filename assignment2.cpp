#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Vehicle {
 protected:
	string brand;
	string name;
	string status;
	double price;
 public:
	Vehicle (){}
	Vehicle (string brand, string name, string status, double price)
	: brand(brand), name(name), status(status), price(price) {}
	string getBrand() {return brand;}
	string getName() {return name;}
	string getStatus() {return status;}
	double getPrice() {return price;}
	friend ostream& operator<< (ostream& os, Vehicle& vehicles) {
	os << vehicles.getBrand() << "\t";
	os << vehicles.getName() << "\t";
	os << vehicles.getStatus() << "\t";
	os << vehicles.getPrice() << endl;
	return os;
	}
};

class Manager {
 protected:
	string nameManager;
 public:
	Manager (string nameManager = "[NA]") : nameManager(nameManager) {}
	string getNameManager() {return nameManager;}
	friend ostream& operator<< (ostream& os, Manager& managers) {

		os << "\t" << managers.getNameManager() << endl;
	
		return os;
	}
};

class Car : public Vehicle, public Manager {
 protected:
	double displacement;
 public:
	Car (string brand = "[NA]", string name = "[NA]", double displacement = 0, string status = "[NA]", double price = 0, string nameManager = "[NA]")
	: Vehicle (brand,name,status,price) , displacement(displacement), Manager(nameManager) {}
	double getDisplacement() {return displacement;}
	friend ostream& operator<< (ostream& os, Car& cars) {
		os << cars.getBrand() << "\t";
		os << cars.getName() << "\t\t";
		os << cars.getDisplacement() << "\t";
		os << cars.getStatus() << "\t";
		os << cars.getPrice() << "\t";
		os << cars.getNameManager() << endl << endl;
		return os;
	}
	friend istream& operator<< (istream& is, Car& cars) {
		is >> cars.brand;
		is >> cars.name;
		is >> cars.displacement;
		is >> cars.status;
		is >> cars.price;
		is >> cars.nameManager;
		return is;
	}
};
class Bus : public Vehicle, public Manager {
 protected:
	int capacity;
 public:
	Bus (string brand = "[NA]", string name = "[NA]", int capacity = 0, string status = "[NA]", double price = 0, string nameManager = "[NA]")
	: Vehicle (brand,name,status,price) ,capacity(capacity) , Manager(nameManager) {}
	int getCapacity() {return capacity;}
	friend ostream& operator<< (ostream& os, Bus& busses) {
		os << busses.getBrand() << "\t";
		os << busses.getName() << "\t\t";
		os << busses.getCapacity() << "\t";
		os << busses.getStatus() << "\t";
		os << busses.getPrice() << "\t";
		os << busses.getNameManager() << endl << endl;
		return os;
	}
	friend istream& operator<< (istream& is, Bus& busses) {
		is >> busses.brand;
		is >> busses.name;
		is >> busses.capacity;
		is >> busses.status;
		is >> busses.price;
		is >> busses.nameManager;
		return is;
	}
};
class Airplane : public Vehicle, public Manager {
 protected:
	int max_dis;
 public:
	Airplane (string brand = "[NA]", string name = "[NA]", int max_dis = 0, string status = "[NA]", double price = 0, string nameManager = "[NA]")
	: Vehicle (brand,name,status,price) ,max_dis(max_dis) , Manager(nameManager) {}
	int getMax_dis() {return max_dis;}
	friend ostream& operator<< (ostream& os, Airplane& air) {
		os << air.getBrand() << "\t";
		os << air.getName() << "\t\t";
		os << air.getMax_dis() << "\t";
		os << air.getStatus() << "\t";
		os << air.getPrice() << "\t";
		os << air.getNameManager() << endl << endl;
		return os;
	}
	friend istream& operator<< (istream& is, Airplane& air) {
		is >> air.brand;
		is >> air.name;
		is >> air.max_dis;
		is >> air.status;
		is >> air.price;
		is >> air.nameManager;
		return is;
	}
};

template <typename T>
struct Node {
	T info;
	Node<T> *next;
};

template <typename T>
class LinkedList{
 public:
	Node<T> *start;
	Node<T> *ptr;
	
	LinkedList() {start = ptr = NULL;}
	~LinkedList() {makeEmpty();}
	
	void makeEmpty() {
		while (start != NULL){
			ptr = start;
			start = start->next;
			delete ptr;
		}
		ptr = NULL;
	}
	
	void isEmpty(Node<T> *start) {
		if(start == NULL) {
			cout << "The list is empty." << endl;
			return;
		}
	}
	
	void insertFront(T& newElement){
		Node<T> *newNode = new Node<T>;
		newNode->info = newElement;
		newNode->next = start;
		start = newNode;
	}
	
	void insertMiddle(T& newElement, int index){
		int i = 1;
		Node<T> *ptr = start;
		Node<T> *newNode = new Node<T>;
		while (ptr != NULL && i != index) {
			if (i !=index) {
				ptr = ptr->next;
				i ++;
			}
			if (i == index) {
				newNode->info = newElement;
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}
	}
	
	void insertEnd(T& newElement) {
		Node<T> *newNode = new Node<T>;
		newNode->info = newElement;
		newNode->next = NULL;
		if(start == NULL)
			start = newNode;
		else {
			Node<T> *ptr = start;
			while(ptr->next != NULL){
				ptr = ptr->next;
				ptr->next = newNode;
			}
		}	
	}
	
	void insertBack (T & newElement){
		Node<T> *newNode = new Node<T>;
		newNode->info = newElement;
		newNode->next = NULL;
		if (start == NULL) { 
			start = newNode;
			return;
		}
		Node<T>* ptr = start;    
		while (ptr->next != NULL) 
		ptr = ptr->next;
		ptr->next = newNode;
 }

	
	void eraseMiddle(int index) {
		int i = 1;
		Node<T> *ptr = start;
		Node<T> *ptr2 = ptr->next;
		Node<T> *ptr3 = ptr;
		Node<T> *newNode = new Node<T>;
		while (ptr != NULL && i != index) {
			if (i != index){
				ptr3 = ptr;
				ptr = ptr2;
				ptr2 = ptr->next;
				i++;
			}
			if (i == index) {
				if (index == 1) {
					Node<T> *ptr3 = ptr;
					ptr = ptr2;
					ptr2 = ptr2->next;
					start = ptr;
					delete ptr3;
				}
				else {
					ptr = ptr3;
					ptr3 = ptr->next;
					ptr->next = ptr2;
					delete ptr3;
				}			
			}
		}
	}
	
	void updateManager(T& newElement, int index) {
		int i = 1;
		Node<T> *ptr = start;
		while(ptr != NULL && i != index) {
			if(i != index){
				ptr = ptr->next;
				i++;
			}
			if(i == index)
				ptr->info = newElement;
		}
	}
	
	friend ostream& operator<< (ostream& os, LinkedList<T>& vehicles){
			vehicles.ptr = vehicles.start;
			int i = 0;
			while (vehicles.ptr != NULL) {
				os << "\t[" << i+1 << "] " << vehicles.ptr->info;
				vehicles.ptr = vehicles.ptr->next;
				i++;
			}
			return os;
	}
	
	 bool retrieve (int targetindex, T*& retrievedItem) {
    // retrievedItem is a pointer to avoid duplicating the item.
    // first item has index 0.
    if (targetindex < 0 || start == NULL)
      return false;
    Node<T>* ptr = start;
    int i = 0;
    while (ptr != NULL && i <= targetindex) {
      if (i == targetindex) {
        retrievedItem = &(ptr->info);
        return true;
      }
      else {
        ptr = ptr->next;
        i++;
      }
    }
    return false;
	}
	
};


int main() {
	string brand, name, status, nameManager;
	int capacity, max_dis;
	double displacement,price;
	LinkedList<Car> cars;
	LinkedList<Bus> busses;
	LinkedList<Airplane> air;
	LinkedList<Manager> managers;
	
	Car* retrievedCar;
	Manager* retrievedMan;
	
	Car newCar;
	Bus newBus;
	Airplane newAir;
	Manager newManager;
	
	Car c1("Proton", "Wira", 1.6, "Not Sold", 20000);
	Car c2("Honda", "Perdana", 1.6, "Sold\t", 30000 );
	Bus b1("TATA", "RapidKL", 500, "Sold\t", 100 );
	Airplane a1("Boeing", "MH730", 15000, "Not Sold", 150000 );
	Manager m1("Jae Suk");
	Manager m2("Raju");
	Manager m3("Hairul");
	
	cars.insertBack(c1);
	cars.insertBack(c2);
	busses.insertBack(b1);
	air.insertBack(a1);
	managers.insertBack(m1);
	managers.insertBack(m2);
	managers.insertBack(m3);
	
	
	int choice;
	system("cls");
	do {
		cout << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "                      Vehicle Management Program" << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		cout << endl;
		cout << "[1] Display all vehicles" << endl;
		cout << "[2] Create new vehicle" << endl;
		cout << "[3] Assign vehicle to manager" << endl;
		cout << "[4] Delete vehicle" << endl;
		cout << "[5] Display all managers" << endl;
		cout << "[6] Create new manager" << endl;
		cout << "[7] Delete manager" << endl;
		cout << "[8] Exit" << endl << endl;
		cout << "Enter the number : ";
		cin >> choice;
		cout << endl;
		
		switch (choice) {
			case 1: {
				system("cls");
				cout << endl;
				cout << "\t============================CARS====================================" << endl;
				cout << "\tNo.\tBrand\tName\tDisplacement\tStatus\t\tPrice\tManager"<<endl;
				cout << "\t====================================================================" << endl;
				cout << cars;
				cout << "\t=============================BUS====================================" << endl;
				cout << "\tNo.\tBrand\tName\t     Capacity\tStatus\t\tPrice\tManager"<<endl;
				cout << "\t====================================================================" << endl;
				cout << busses;
				cout << "\t===========================AIRPLANE================================="<< endl;
				cout << "\tNo.\tBrand\tName\tMax Distance\tStatus\t\tPrice\tManager"<<endl;
				cout << "\t====================================================================" << endl;
				cout << air;
				system("pause");
				break;}
			
			case 2: {
				int choice_vehicle;
				system("cls");
				do {
					cout << "Choose type of vehicle: " << endl;
					cout << "[1] Car" << endl;
					cout << "[2] Bus" << endl;
					cout << "[3] Airplane" << endl;
					cout << "[4] Back" << endl;
					cout << "Enter the number: ";
					cin >> choice_vehicle;
					cout << endl;
					switch (choice_vehicle) {
						case 1: {
							bool repeat = 1;
							system("cls");
							cout << "Enter brand of the car: ";
							cin >> brand;
							cout << "Enter name of the car: ";
							cin >> name;
							cout << "Enter the displacement of the car: ";
							cin >> displacement;
							while (repeat){
								cout << "Enter the status of the car (Chose 1/2): " <<endl;
								cout << "[1] Not Sold" << endl;
								cout << "[2] Sold" << endl;
								cin >> status;
								if (status == "1"){
									status = "Not Sold";
									repeat = 0;
								}
								else if (status == "2") {
									status = "Sold\t";
									repeat = 0;
								}
								else {
									cout << "Invalid input, try again." << endl;
								}
							}
							cout << "Enter the price of the car:";
							cin >> price;
							Car newCar;
							newCar = Car(brand, name, displacement, status, price);
							cars.insertBack(newCar);
							system("cls");
							break;}
						case 2: { 
							bool repeat = 1;
							system("cls");
							cout << "Enter brand of the bus: ";
							cin >> brand;
							cout << "Enter name of the bus: ";
							cin >> name;
							cout << "Enter the capacity of the bus: ";
							cin >> capacity;
							while (repeat){
								cout << "Enter the status of the car (Chose 1/2): " <<endl;
								cout << "[1] Not Sold" << endl;
								cout << "[2] Sold" << endl;
								cin >> status;
								if (status == "1"){
									status = "Not Sold";
									repeat = 0;
								}
								else if (status == "2") {
									status = "Sold\t";
									repeat = 0;
								}
								else {
									cout << "Invalid input, try again." << endl;
								}
							}
							cout << "Enter the price of the bus:";
							cin >> price;
							Bus newBus;
							newBus = Bus(brand, name, capacity, status, price);
							busses.insertBack(newBus);
							system("cls");
							break;}
						case 3: {
							bool repeat = 1;
							system("cls");
							cout << "Enter brand of the airplane: ";
							cin >> brand;
							cout << "Enter name of the airplane: ";
							cin >> name;
							cout << "Enter the maximum distance of the airplane: ";
							cin >> max_dis;
							while (repeat){
								cout << "Enter the status of the airplane (Chose 1/2): " <<endl;
								cout << "[1] Not Sold" << endl;
								cout << "[2] Sold" << endl;
								cin >> status;
								if (status == "1"){
									status = "Not Sold";
									repeat = 0;
								}
								else if (status == "2") {
									status = "Sold\t";
									repeat = 0;
								}
								else {
									cout << "Invalid input, try again." << endl;
								}
							}
							cout << "Enter the price of the airplane:";
							cin >> price;
							Airplane newAir;
							newAir = Airplane(brand, name, max_dis, status, price);
							air.insertBack(newAir);
							system("cls");
							break;} 
					}
				} while (choice_vehicle != 4);
				
				break;}
				
			case 3: {
				int choice_veh;
				int choice_veh2;
				int choice_car;
				int choice_man1;
				int choice_man2;
				
				system("cls");
				cout << "[1] Car" << endl;
				cout << "[2] Bus" << endl;
				cout << "[3] Airplane" << endl;
				cout << "Choose the vehicle to assign to manager: ";
				cin >> choice_veh2;
				switch (choice_veh2) {
					case 1: {
						cout << endl;
						cout << "\t============================CARS====================================" << endl;
						cout << "\tNo.\tBrand\tName\tDisplacement\tStatus\t\tPrice\tManager"<<endl;
						cout << "\t====================================================================" << endl;
						cout << cars;
						cout << "Choose car to be assigned to the manager: ";
						cin >> choice_car;
						cout << "\t================== MANAGER ===================" << endl;
						cout << "\tNo.\tName" << endl;
						cout << managers << endl;
						cout << "Choose manager: ";
						cin >> choice_man1;
						cars.retrieve (choice_car-1, retrievedCar);
						cout << *retrievedCar;
						managers.retrieve (choice_man2, retrievedMan);
						//cout << *retrievedMan;
						//Car newCar(retrievedCar);
						//cars.insertBack(newCar);
						break;}
					case 2: {	
						cout << "\t=============================BUS====================================" << endl;
						cout << "\tNo.\tBrand\tName\t     Capacity\tStatus\t\tPrice\tManager"<<endl;
						cout << "\t====================================================================" << endl;
						cout << busses;
						
						
						break;}
						
					}	
				break;}
				
			case 4: {
				int choice_del_veh, choice_del;
				system("cls");
				cout << "[1] Car" << endl;
				cout << "[2] Bus" << endl;
				cout << "[3] Airplane" << endl;
				cout << "Choose the vehicle to delete: ";
				cin >> choice_del;
				switch (choice_del) {
					case 1: {
						cout << endl;
						cout << "\t============================CARS====================================" << endl;
						cout << "\tNo.\tBrand\tName\tDisplacement\tStatus\t\tPrice\tManager"<<endl;
						cout << "\t====================================================================" << endl;
						cout << cars;
						cout << "Choose car to be deleted: ";
						cin >> choice_del_veh;
						cars.eraseMiddle(choice_del_veh);
						break;}
					case 2: {
						cout << "\t=============================BUS====================================" << endl;
						cout << "\tNo.\tBrand\tName\t     Capacity\tStatus\t\tPrice\tManager"<<endl;
						cout << "\t====================================================================" << endl;
						cout << busses;
						cout << "Choose bus to be deleted: ";
						cin >> choice_del_veh;
						busses.eraseMiddle(choice_del_veh);
						break;}
					case 3: {
						cout << "\t===========================AIRPLANE================================="<< endl;
						cout << "\tNo.\tBrand\tName\tMax Distance\tStatus\t\tPrice\tManager"<<endl;
						cout << "\t====================================================================" << endl;
						cout << air;
						cout << "Choose airplane to be deleted: ";
						cin >> choice_del_veh;
						air.eraseMiddle(choice_del_veh);
						
					break;}					
					}
				
				break;}
				
			case 5: {
				system("cls");
				cout << "\t================== MANAGER ===================" << endl;
				cout << "\tNo.\tName" << endl;
				cout << "\t==============================================" << endl;
				cout << managers << endl;
				break;}
				
			case 6: {
				string man_name;
				cout << "Enter manager name: ";
				cin >> man_name;
				Manager newMan;
				newMan = Manager(man_name);
				managers.insertBack(newMan);
				break;}
				
			case 7: {
				int choice_del_man;
				system("cls");
				cout << "\t================== MANAGER ===================" << endl;
				cout << "\tNo.\tName" << endl;
				cout << managers << endl;
				cout << "Choose a manager to delete:" << endl;
				cin >> choice_del_man;
				break;}
		}
		
	} while (choice != 8);
	
}
