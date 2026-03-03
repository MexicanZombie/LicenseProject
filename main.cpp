#include <iostream>
#include <string>
using namespace std;

// So this part is the base class from the top of the draw io Diagram. This Blue part is going to be what I did (Wadan Mehraban)
 class LicensePlate {
 public:
string plateNumber;
string stateOrigin;
// Simple constructor
LicensePlate(string n) {
plateNumber = n;
}
virtual bool isValid() {
if (plateNumber.length() == 8) {
return true;
}
return false;
}
};
// Okay I did this part
// --- TODO:  please finish the PlateType class
// This is the middle-left box in the diagram

class PlateType : public LicensePlate {
public:
 string vehicleType;


// The diagram says # vehicleType
 // IDK how ownerRegistration works here?
// I just added vehicleType for now.


PlateType(string n, string type) : LicensePlate(n) {
vehicleType = type;
}
void display() {
cout << "Type: " << vehicleType << endl;
 }
 };

// Ok so this part is going to be the child class which gets everything from LicensePlate

Class VanityPlate : public LicensePlate {
public:
	VanityPlate(string n) : LicensePlate(n) {}

bool isValid() override {
	Int size = plateNumber.length();
	if (size>= 2 && size <= 7) {
	return true;
}

};

// I also need help here for the PlateOwner Class.
//I started this but I got stuck and I am very confused on the private variables.
// I also need help figuring out how to link the plate to the owner.
// I have no clue what AI is telling me

class PlateOwner
private:
	string driversLicense;
	string owner Registration;
public:

	// Please Add a constructor here, I think thats whats suppose to be here
	// Also please do this part. How do we show the connection to License Plate?
};

int main () {
// so this part is going to be the standard plate test on the diagram
LicensePlate p1 ('ABC-1234');
cout << “Standard Plate: “ << p1.plateNumber <<endl;
if (p1.isValid()) {
	cout << "Status: Valid" << endl;
} else {
	cout << "Status: Invalid" << endl;
}

cout << "-------------------" << endl;

// Vanity plate test
VanityPlate v1("FAST");
cout << "Vanity Plate: " << v1.plateNumber << endl;
if (v1.isValid()) {
	cout << "Status: Valid" << endl;
 } else {
	cout << "Status: Invalid" << endl;
}

// Testing the unfinished PlateType part
PlateType t1("XYZ-123", "Truck");
t1.display();

return 0;
}
