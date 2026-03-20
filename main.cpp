#include <iostream>
#include <string>
using namespace std;

class LicensePlate {
protected:
    string PlateNumber;
public:
    string stateOrigin;
    LicensePlate(string n) {
        PlateNumber = n;
    }
    string getPlateNumber() {
        return PlateNumber; //allows the main to access plateNumber
    }
    virtual bool isValid() {
        if (PlateNumber.length() == 8) {
            return true;
        }
        return false;
    }
};

class PlateType:LicensePlate {
private:
    string ownerRegistration;
protected:
    string vehicleType;
    public:
    string vehicleInsurance;
    string platetype;
    PlateType(string n, string ptype, string vtype):LicensePlate(n) {
        platetype = ptype;
        vehicleType = vtype;
        cout << "Plate Number: " << PlateNumber << endl;
        cout << "Plate Type: " << ptype << endl;
    }
    void displayVehicleType() {
        cout << "Vehicle Type: " << vehicleType << endl;
    }
};

class VanityPlate: public LicensePlate {
public:
    VanityPlate(string n) : LicensePlate(n){}
    bool isValid() override {
        int size = PlateNumber.length();
        if (size>= 2 && size <= 7) {
            return true;
        }
        return false;
    }
};

class PlateOwner {
private:
    string driversLicenseNum;
    string ownerRegistrationNum;
protected:
    string vehicleInsurance;
public:
    PlateOwner(string drLicenseNum, string ownerRegNum, string vinsurance){
        driversLicenseNum = drLicenseNum;
        ownerRegistrationNum = ownerRegNum;
        vehicleInsurance = vinsurance;
    }
    void displayOwnerInfo() {
        cout << "Driver License Number: " << driversLicenseNum << endl;
        cout << "Owner's Registration Number: " << ownerRegistrationNum << endl;
        cout << "Vehicle's Insurance Valid: " << vehicleInsurance << endl;
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
    PlateType t1("080707870", "Standard", "Truck");
    t1.displayVehicleType(); // prints out vehicle type, owner registration Number and if vehicle insurance exists by printing out yes or no
    PlateOwner o1("ABC-1234","o80809808","No"); //prints out license ID, owner registration number, and
    o1.displayOwnerInfo();
    return 0;
}