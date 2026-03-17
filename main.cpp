#include <iostream>
#include <string>
using namespace std;

class LicensePlate {
protected:
    string plateNumber;
public:
  //string PlateSize; //does nothing for our program as plate number checks if size is correct or not *remove variable
    string stateOrigin;
    LicensePlate(string n) {
        plateNumber = n;
    }
    string getPlateNumber() {
        return plateNumber; //allows the main to access plateNumber
    }
    virtual bool isValid() {
        if (plateNumber.length() == 8) {
            return true;
        }
        return false;
    }
};

class PlateType: public LicensePlate {
protected:
    string vehicleType;
    public:

    PlateType(string n, string type):LicensePlate(n) {
        vehicleType = type;
    }
    void displayVehicleType() {
        cout << "Type: " << vehicleType << endl;
    }
};

class VanityPlate: public LicensePlate {
public:
    VanityPlate(string n) : LicensePlate(n){}
    bool isValid() override {
        int size = plateNumber.length();
        if (size>= 2 && size <= 7) {
            return true;
        }
        return false;
    }
};

class PlateOwner: public LicensePlate {
private:
    string driversLicense;
    string ownerRegistration;
public:
    PlateOwner(string n, string license, string ownerReg):LicensePlate(n){
        driversLicense = license;
        ownerRegistration = ownerReg;
    }
    void displayOwnerInfo() {
        cout << "Driver License " << driversLicense << endl;
        cout << "Owner's Registration: " << ownerRegistration << endl;
    }
};

int main() {
    LicensePlate p1("ABC-1234");
    cout << "Standard Plate: " << p1.getPlateNumber() << endl; //prints out standard license plate number

    if (p1.isValid()) { //checks if the standard license plate number is valid
        cout << "Status: Valid" << endl;
    }else{
        cout << "Status: Invalid" << endl;
    }
    cout << "------------------" << endl;

    VanityPlate v1("FAST");
    cout << "Vanity Plate: " << v1.getPlateNumber() << endl; //prints out vanity license plate number/string
    if (v1.isValid()) { // checks if the vanity plate number/ string is valid
        cout << "Status: Valid" << endl;
    }else {
        cout << "Status: Invalid" << endl;
    }
    cout << "------------------" << endl;
    PlateType t1("XYZ-123", "Truck"); //prints out the plate number and vehicle type
    t1.displayVehicleType();
    PlateOwner o1("ABC-1234", "D1209746", "D-12234");
    o1.displayOwnerInfo();
    return 0;
}