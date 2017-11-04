#include <iostream>
#include <thread>

using namespace std;

char g_input;
void thread_main()
{
	while(std::tolower(g_input) != 'q')
	{
		cout<<g_input<<endl;
	}
	cout<<"---->end running"<<endl;
}

int main()
{
	g_input = '0';
	std::thread my_thread(thread_main);
	my_thread.detach();
	while(g_input = getchar())
	{
		if(std::tolower(g_input) == 'q')
			break;
	}
	cout<<"====>quit"<<endl;
return 0;
}
