#include <iostream>
#include <thread>

using namespace std;

int main()
{

cout<<"support concurrency:"<<thread::hardware_concurrency()<<endl;
return 0;
}
