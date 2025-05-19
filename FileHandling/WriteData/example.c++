#include<iostream>
#include<fstream>
using namespace std;
int main(){
cout<<"Examples for Writing Data in file"<<endl;
cout<<"_____________________________________"<<endl;

// Mode used: ios::out (default for ofstream)
// Behavior: Creates output.txt if missing; truncates if exists.

    cout << "Using ofstream and ios::out method" << endl;
    ofstream out_file("output.txt", ios::out);

    if (!out_file.is_open())
    {
        cerr << "Error:  not open the output.txt file" << endl;
        return 1;
    }
    cout << "Open the output.txt file" << endl;
    out_file << "Line 1: Hello, file!\n"
             << "Line 2: Writing to disk.\n";
    out_file<<"Hi this is yashvir malik"<<endl;
    out_file.close();

    cout << "Closed the output.txt file" << endl;

    cout << "_______________________________________" << endl;
    cout << "Open in append mode using ofstream and ios::app method" << endl;

    // Mode: std::ios::app
    // Behavior: All << writes go to end of file, preserving existing content.

    ofstream log("output.txt", ios::app);
    if (!log)
    {
        cerr << "Error: not open the output.txt file for appending" << endl;
        return 1;
    }

    log << "This is the append message in the file and found in the last "<<endl;
    log.close();
        return 0;
}