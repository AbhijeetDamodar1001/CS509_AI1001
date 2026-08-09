#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int choice;

    cout << "==============================" << endl;
    cout << "       CS509 WRAPPER" << endl;
    cout << "==============================" << endl;

    cout << "1. Assignment 1" << endl;
    cout << "2. Assignment 2" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int option;

        cout << "\nAssignment 1" << endl;
        cout << "1. GEMM" << endl;
        cout << "2. CSR" << endl;
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1)
        {
            system("cd /d assignment_01\\GEMM && gemm.exe");
        }
        else if (option == 2)
        {
            system("cd /d assignment_01\\CSR && csr.exe");
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
    else if (choice == 2)
    {
        system("cd /d assignment_02 && assignment.exe");
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
