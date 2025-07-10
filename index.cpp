#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    int course1;
    int course2;
    int course3;
    int totalSales;
    int commission;
    int netSalary;
};

const int COURSE_PRICES[] = {100000, 150000, 200000};

vector<Employee> readSalesData() {
    ifstream file("sales.txt");
    vector<Employee> employees;
    string name;
    int course1, course2, course3;

    while (file >> name >> course1 >> course2 >> course3) {
        employees.push_back({name, course1, course2, course3, 0, 0, 0});
    }

    file.close();
    return employees;
}

void calculateCommission(vector<Employee> &employees) {
    const int TARGET_SALES = 500000;
    const double COMMISSION_RATE_1 = 0.10;
    const double COMMISSION_RATE_2 = 0.15;
    const int BASE_SALARY = 3000000;

    for (auto &employee : employees) {
        employee.totalSales = employee.course1 * COURSE_PRICES[0] + 
                              employee.course2 * COURSE_PRICES[1] + 
                              employee.course3 * COURSE_PRICES[2];

        if (employee.totalSales >= TARGET_SALES) {
            int extraSales = employee.totalSales - TARGET_SALES;
            employee.commission = TARGET_SALES * COMMISSION_RATE_1 + 
                                  extraSales * COMMISSION_RATE_2;
        } else {
            employee.commission = 0;
        }

        employee.netSalary = BASE_SALARY + employee.commission;
    }
}

void sortEmployeesBySales(vector<Employee> &employees) {
    sort(employees.begin(), employees.end(), 
        [](const Employee &a, const Employee &b) {
            return a.totalSales > b.totalSales;
        });
}

void displayEmployees(const vector<Employee> &employees, int choice) {
    if (choice == 1) {
        cout << "+-----------+-------------------+-------------------+-------------------+-------------------+------------------+" << endl;
        cout << "| Nama      | Course 1          | Course 2          | Course 3          | Total Penjualan   | Komisi           |" << endl;
        cout << "+-----------+-------------------+-------------------+-------------------+-------------------+------------------+" << endl;

        for (const auto &employee : employees) {
            cout << "| " << setw(9) << employee.name << " | " 
                 << setw(17) << employee.course1 << " | " 
                 << setw(17) << employee.course2 << " | " 
                 << setw(17) << employee.course3 << " | " 
                 << setw(17) << employee.totalSales << " | " 
                 << setw(16) << employee.commission << " |" << endl;
        }

        cout << "+-----------+-------------------+-------------------+-------------------+--------------------+-----------------+" << endl;
    } else if (choice == 2) {
        cout << "+-----------+-------------------+-------------------+-------------------+------------------+------------------+" << endl;
        cout << "| Nama      | Course 1          | Course 2          | Course 3          | Komisi           | Gaji Bersih      |" << endl;
        cout << "+-----------+-------------------+-------------------+-------------------+------------------+------------------+" << endl;

        for (const auto &employee : employees) {
            cout << "| " << setw(9) << employee.name << " | "
                 << setw(17) << employee.course1 << " | "
                 << setw(17) << employee.course2 << " | "
                 << setw(17) << employee.course3 << " | "
                 << setw(16) << employee.commission << " | "
                 << setw(16) << employee.netSalary << " |" << endl;
        }

        cout << "+-----------+-------------------+-------------------+-------------------+------------------+------------------+" << endl;
    } else if (choice == 3) {
        cout << "+-----------+-------------------+-------------------+-------------------+-------------------------+" << endl;
        cout << "| Nama      | Course 1          | Course 2          | Course 3          | Total Penjualan         |" << endl;
        cout << "+-----------+-------------------+-------------------+-------------------+-------------------------+" << endl;

        for (const auto &employee : employees) {
            cout << "| " << setw(9) << employee.name << " | "
                 << setw(17) << employee.course1 << " | "
                 << setw(17) << employee.course2 << " | "
                 << setw(17) << employee.course3 << " | "
                 << setw(23) << employee.totalSales << " |" << endl;
        }

        cout << "+-----------+-------------------+-------------------+-------------------+-------------------------+" << endl;
    }
}

void displayTotalSalesPerCourse(const vector<Employee> &employees) {
    int totalCourse1 = 0, totalCourse2 = 0, totalCourse3 = 0;

    for (const auto &employee : employees) {
        totalCourse1 += employee.course1;
        totalCourse2 += employee.course2;
        totalCourse3 += employee.course3;
    }

    cout << "Total Penjualan Perkursus :" << endl;
    cout << "Kursus 1 = " << totalCourse1 << endl;
    cout << "Kursus 2 = " << totalCourse2 << endl;
    cout << "Kursus 3 = " << totalCourse3 << endl;
}

void displayTotalPayment(const vector<Employee> &employees) {
    int totalPayment = 0;

    for (const auto &employee : employees) {
        totalPayment += employee.netSalary;
    }

    cout << "Total Keseluruhan yang Dibayar oleh Perusahaan = " << totalPayment << endl;
}

int main() {
    char repeat;
    do {
        vector<Employee> employees = readSalesData();
        calculateCommission(employees);

        int choice;
        cout << "Pilih menu:" << endl;
        cout << "1. Menghitung komisi" << endl;
        cout << "2. Menghitung gaji bersih" << endl;
        cout << "3. Mengurutkan data" << endl;
        cout << "4. Jumlah penjualan setiap kursus" << endl;
        cout << "5. Jumlah keseluruhan yang harus dibayar oleh perusahaan" << endl << endl;
        cout << "Pilih menu (1/2/3/4/5) : ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2:
                displayEmployees(employees, choice);
                break;
            case 3:
                sortEmployeesBySales(employees);
                displayEmployees(employees, choice);
                break;
            case 4:
                displayTotalSalesPerCourse(employees);
                break;
            case 5:
                displayTotalPayment(employees);
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
		cout << "=============================================" << endl;
        cout << "Apakah Anda ingin memilih menu lagi? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
