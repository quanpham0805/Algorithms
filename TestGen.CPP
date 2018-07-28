#include <bits/stdc++.h>
#include <direct.h>
using namespace std;
#define Task "???"
const int nTest = 50;
const string Directory = "D:\\Important Data\\Documents\\Work\\Test";
string Problem_name;
int testno = 0;

bool make_folder()
{
    if(mkdir((Directory + Task).c_str())) return true;
    return false;
}

ofstream input;
ofstream output;

void make_input()
{
    testno ++;
    cout << testno << '\n';
}

void make_output()
{

}

void make_test(string test_address)
{
    input.open((test_address + "/" + Task + ".inp").c_str());
    make_input();
    input.close();
    //-----------------------------------------------------------------
    output.open((test_address + "/" + Task + ".out").c_str());
    make_output();
    output.close();
}

void Gen()
{
    for (int i = 0; i < nTest; i++)
    {
        stringstream ss;
        string test_id = "";
        ss << i;
        ss >> test_id;
        string thisTest_address = Directory + Task + "/" + "Test0" + test_id;
        mkdir(thisTest_address.c_str());
        make_test(thisTest_address);
    }
}

int main()
{
    srand(time(NULL));
    Problem_name = Task;
    make_folder();
    Gen();
    return 0;
}
