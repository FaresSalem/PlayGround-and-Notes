#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{    
    string strLine = "This is a string!";
    cout << "warming up for tests ...\n";
    cout << strLine << endl;
    cout << "warmed up for tests ...\n";
    
    clock_t cpu_time_start;    // clock() time, CPU time used
    clock_t cpu_time_end;
    auto real_time_start = chrono::high_resolution_clock::now();   // real time, Wall clock time passed
    auto real_time_end = chrono::high_resolution_clock::now();

    //---------------------------------------------------------------------------------------------------
    
    cpu_time_start = clock();
    real_time_start = chrono::high_resolution_clock::now();
    
    for (auto i = 0u; i < strLine.size(); ++i)
        cout << strLine[i];
    cout << endl;
    
    cpu_time_end = clock();
    real_time_end = chrono::high_resolution_clock::now();
    cout << "index-based loop CPU time: " << 1000.0 * (cpu_time_end-cpu_time_start) / CLOCKS_PER_SEC << " ms\n"
         << "index-based loop real time: "<< chrono::duration<double, milli>(real_time_end-real_time_start).count() << " ms\n";

    //---------------------------------------------------------------------------------------------------
    
    cpu_time_start = clock();
    real_time_start = chrono::high_resolution_clock::now();
    for (auto i = strLine.begin(); i != strLine.end(); ++i)
        cout << *i;
    cout << endl;
    cpu_time_end = clock();
    real_time_end = chrono::high_resolution_clock::now();
    cout << "iterator-based loop CPU time: " << 1000.0 * (cpu_time_end-cpu_time_start) / CLOCKS_PER_SEC << " ms\n"
         << "iterator-based loop real time: "<< chrono::duration<double, milli>(real_time_end-real_time_start).count() << " ms\n";
    
    //---------------------------------------------------------------------------------------------------

    cpu_time_start = clock();
    real_time_start = chrono::high_resolution_clock::now();
    for (auto &c: strLine)
        cout << c;
    cout << endl;
    cpu_time_end = clock();
    real_time_end = chrono::high_resolution_clock::now();
    cout << "range-for based loop CPU time: " << 1000.0 * (cpu_time_end-cpu_time_start) / CLOCKS_PER_SEC << " ms\n"
         << "range-for based loop real time: "<< chrono::duration<double, milli>(real_time_end-real_time_start).count() << " ms\n";

    //---------------------------------------------------------------------------------------------------
    
    return 0;
}