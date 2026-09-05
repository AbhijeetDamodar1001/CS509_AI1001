#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int assignment;

    cout << "1. Assignment 1" << endl;
    cout << "2. Assignment 2" << endl;
    cout << "3. Assignment 3" << endl;
    cout << "4. Assignment 4" << endl;
    cout << "Enter choice: ";
    cin >> assignment;

    // Assignment 1
    if (assignment == 1)
    {
        int part;

        cout << "\nAssignment 1" << endl;
        cout << "1. GEMM" << endl;
        cout << "2. CSR" << endl;
        cout << "Enter choice: ";
        cin >> part;

        if (part == 1)
        {
            string tests[] = {
                "test_01.txt",
                "test_02.txt",
                "test_03.txt"
            };

            cout << "\nGEMM Test Cases" << endl;
            for (int i = 0; i < 3; i++)
                cout << i + 1 << ". " << tests[i] << endl;

            cout << "Enter test case: ";

            int test;
            cin >> test;

            if (test < 1 || test > 3)
            {
                cout << "Invalid test case." << endl;
                return 0;
            }

            string file = tests[test - 1];

            system(
                "cd /d ..\\assignment_01\\GEMM && "
                "g++ -std=c++17 driver\\driver.cpp "
                "src\\simple.cpp src\\blocking.cpp -o gemm.exe"
            );

            cout << "\nRunning: " << file << endl;

            string command =
                "cd /d ..\\assignment_01\\GEMM && "
                "gemm.exe tests\\" + file;

            system(command.c_str());
        }

        else if (part == 2)
        {
            string tests[] = {
                "graph_1.txt",
                "graph_2.txt"
            };

            cout << "\nCSR Test Cases" << endl;
            for (int i = 0; i < 2; i++)
                cout << i + 1 << ". " << tests[i] << endl;

            cout << "Enter test case: ";

            int test;
            cin >> test;

            if (test < 1 || test > 2)
            {
                cout << "Invalid test case." << endl;
                return 0;
            }

            string file = tests[test - 1];

            system(
                "cd /d ..\\assignment_01\\CSR && "
                "g++ -std=c++17 driver\\driver.cpp src\\csr.cpp -o csr.exe"
            );

            cout << "\nRunning: " << file << endl;

            string command =
                "cd /d ..\\assignment_01\\CSR && "
                "csr.exe tests\\" + file;

            system(command.c_str());
        }
    }

    // Assignment 2
    else if (assignment == 2)
    {
        int part;

        cout << "\nAssignment 2" << endl;
        cout << "1. Bellman-Ford" << endl;
        cout << "2. Floyd-Warshall" << endl;
        cout << "Enter choice: ";
        cin >> part;

        string algorithm;
        string tests[5];

        if (part == 1)
        {
            algorithm = "bf";
            tests[0] = "bf_10.txt";
            tests[1] = "bf_100.txt";
            tests[2] = "bf_10000.txt";
            tests[3] = "bf_50000.txt";
            tests[4] = "bf_100000.txt";

            cout << "\nBellman-Ford Test Cases" << endl;
        }
        else if (part == 2)
        {
            algorithm = "fw";
            tests[0] = "fw_10.txt";
            tests[1] = "fw_100.txt";
            tests[2] = "fw_500.txt";
            tests[3] = "fw_1000.txt";
            tests[4] = "fw_2000.txt";

            cout << "\nFloyd-Warshall Test Cases" << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return 0;
        }

        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". " << tests[i] << endl;

        cout << "Enter test case: ";

        int test;
        cin >> test;

        if (test < 1 || test > 5)
        {
            cout << "Invalid test case." << endl;
            return 0;
        }

        string file = tests[test - 1];

        int result = system(
            "cd /d ..\\assignment_02 && "
            "g++ -std=c++17 driver\\driver.cpp "
            "src\\bellmanford.cpp src\\floydwarshall.cpp "
            "../assignment_01/CSR/src/csr.cpp "
            "-I../assignment_01/CSR/src -o assignment.exe"
        );

        if (result != 0)
        {
            cout << "Compilation failed." << endl;
            return 0;
        }

        cout << "\nRunning: " << file << endl;

        string command =
            "cd /d ..\\assignment_02 && "
            "assignment.exe " + algorithm + " tests\\" + file;

        system(command.c_str());
    }

    // Assignment 3
    else if (assignment == 3)
    {
        int part;

        cout << "\nAssignment 3" << endl;
        cout << "1. Kruskal" << endl;
        cout << "2. Prim" << endl;
        cout << "Enter choice: ";
        cin >> part;

        string algorithm;

        if (part == 1)
            algorithm = "kruskal";
        else if (part == 2)
            algorithm = "prim";
        else
        {
            cout << "Invalid choice." << endl;
            return 0;
        }

        string tests[] = {
            "mst_10.txt",
            "mst_100.txt",
            "mst_10000.txt",
            "mst_50000.txt",
            "mst_100000.txt"
        };

        cout << "\nTest Cases" << endl;
        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". " << tests[i] << endl;

        cout << "Enter test case: ";

        int test;
        cin >> test;

        if (test < 1 || test > 5)
        {
            cout << "Invalid test case." << endl;
            return 0;
        }

        string file = tests[test - 1];

        int result = system(
            "cd /d ..\\assignment_03 && "
            "g++ -std=c++17 driver\\driver.cpp "
            "src\\kruskal.cpp src\\prim.cpp "
            "../assignment_01/CSR/src/csr.cpp "
            "-I../assignment_01/CSR/src -o assignment.exe"
        );

        if (result != 0)
        {
            cout << "Compilation failed." << endl;
            return 0;
        }

        cout << "\nRunning: " << file << endl;

        string command =
            "cd /d ..\\assignment_03 && "
            "assignment.exe " + algorithm + " tests\\" + file;

        system(command.c_str());
    }

    // Assignment 4 - Individual
    else if (assignment == 4)
    {
        int part;

        cout << "\nAssignment 4" << endl;
        cout << "1. Coloring" << endl;
        cout << "2. PageRank" << endl;
        cout << "Enter choice: ";
        cin >> part;

        string algorithm;
        string tests[5];

        if (part == 1)
        {
            algorithm = "color";

            tests[0] = "color_10.txt";
            tests[1] = "color_100.txt";
            tests[2] = "color_10000.txt";
            tests[3] = "color_50000.txt";
            tests[4] = "color_100000.txt";

            cout << "\nColoring Test Cases" << endl;
        }
        else if (part == 2)
        {
            algorithm = "pagerank";

            tests[0] = "pagerank_10.txt";
            tests[1] = "pagerank_100.txt";
            tests[2] = "pagerank_1000.txt";
            tests[3] = "pagerank_10000.txt";
            tests[4] = "pagerank_50000.txt";

            cout << "\nPageRank Test Cases" << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return 0;
        }

        for (int i = 0; i < 5; i++)
            cout << i + 1 << ". " << tests[i] << endl;

        cout << "Enter test case: ";

        int test;
        cin >> test;

        if (test < 1 || test > 5)
        {
            cout << "Invalid test case." << endl;
            return 0;
        }

        string file = tests[test - 1];

        int result = system(
            "cd /d ..\\assignment_04 && "
            "g++ -std=c++17 driver\\driver.cpp "
            "src\\coloring.cpp src\\pagerank.cpp "
            "../assignment_01/CSR/src/csr.cpp "
            "-Isrc -I../assignment_01/CSR/src "
            "-o assignment4.exe"
        );

        if (result != 0)
        {
            cout << "Compilation failed." << endl;
            return 0;
        }

        cout << "\nRunning: " << file << endl;

        string command =
            "cd /d ..\\assignment_04 && "
            "assignment4.exe " + algorithm + " tests\\" + file;

        system(command.c_str());
    }

    else
    {
        cout << "Invalid assignment choice." << endl;
    }

    return 0;
}
