#include <iostream>
#include <thread>
#include <string>
using namespace std;


void edit(const std::string& str)
{
	if(str=="quit")
	{
		cout<<"thread:"<<this_thread::get_id()<<"quit"<<endl;
	}
	else
	{
		string input;
		cout<<"current thread:"<<this_thread::get_id()<<endl;
		cout<<"I had get cmd:"<<str<<endl;
		cout<<"input:";
		cin>>input;
		if(input=="new")
		{
			std::thread th(edit,input);
			th.detach();
		}
		else
		{
			cout<<"cmd is error:"<<input<<endl;
		}
	}
}

int main()
{
		std::string x;
		cout<<"input:";
		cin>>x;
		edit(x);
		cout<<"---->quit main"<<endl;
		return 0;
}
