#include <iostream>
#include <fstream>

using namespace std;


double calculateTotalCost(int numDays, double dailyRate, double medCost, double serviceCost) {
    return numDays * dailyRate + medCost + serviceCost;
}


double calculateTotalCost(double medCost, double serviceCost) {
    return medCost + serviceCost;
}

int main() {
    char patientType;
    int numDays;
    double dailyRate, medCost, serviceCost, totalCost;

    cout << "Nhap Loai Benh Nhan (I Cho Benh Nhan Noi Tru, O Cho Benh Nhan Ngoai Tru): ";
    cin >> patientType;

    if (patientType == 'I' || patientType == 'i') {
       
        cout << "Nhap So Ngay Nam Vien: ";
        cin >> numDays;
        cout << "Nhap Ty Gia Hang Ngay: ";
        cin >> dailyRate;
        cout << "Nhap Chi Phi Thuoc: ";
        cin >> medCost;
        cout << " Nhap Phi Dich Vu: ";
        cin >> serviceCost;

        totalCost = calculateTotalCost(numDays, dailyRate, medCost, serviceCost);
    }
    else if (patientType == 'O' || patientType == 'o') {
        
        cout << "Enter medication cost: ";
        cin >> medCost;
        cout << "Enter service cost: ";
        cin >> serviceCost;

       
        totalCost = calculateTotalCost(medCost, serviceCost);
    }
    else {
        cout << "Benh Nhan Da Nhap Khong Hop Le." << endl;
        return 0;
    }

   
    cout << "Tong Chi Phi: $" << totalCost << endl;

   
    ofstream report("report.txt");
    report << "Benh Nhan: " << patientType << endl;
    if (patientType == 'I' || patientType == 'i') {
        report << "So Ngay Nam Vien: " << numDays << endl;
        report << "Ty Gia Hang Ngay: $" << dailyRate << endl;
    }
    report << "Medication cost: $" << medCost << endl;
    report << "Chi Phi Dich Vu: $" << serviceCost << endl;
    report << "Tong Chi Phi: $" << totalCost << endl;
    report.close();

    return 0;
}