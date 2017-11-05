#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

std::mutex m;

void thread_main(int& n)
{
	std::lock_guard<std::mutex> l(m);
	cout<<"---->"<<n<<endl;
	--n;
	
}

int main()
{
	int x=50;
	unsigned int max_thread = std::thread::hardware_concurrency()==0?4:std::thread::hardware_concurrency()*4;
	
	for(int i=0;i<max_thread;i++)
	{
		std::thread th(thread_main,std::ref(x));
		th.detach();
	}

	std::this_thread::sleep_for(std::chrono::seconds(1));

	return 0;
}
