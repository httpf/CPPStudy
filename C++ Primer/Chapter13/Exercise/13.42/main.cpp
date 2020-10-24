#include <iostream>
#include <fstream>
#include <string>
#include "TextQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    while(true)
    {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        if(!(cin >> s) || s=="q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main(int argc, char* argv[])
{
    ifstream in("test.txt");

    if(!in.is_open())
    {
        cout << "Error open file!" << endl;
        exit(1);
    }
    else
        runQueries(in);

    in.close();

    return 0;
}