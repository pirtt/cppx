#include <iostream>
#include <thread>
#include <mutex>
#include <mutex>
#include <chrono>
using namespace std;

std::mutex deal_mutex;

void thread_main1(int& num_deal,const std::string& deal_name)
{
	cout<<"--------------------------------------------"<<endl;
	cout<<"Enter thread:"<<deal_name<<endl;
	if(num_deal>0)
	{
		deal_mutex.lock();
		if(num_deal>0)
		{
				cout<<"current deal num:"<<num_deal<<endl;
				--num_deal;
		}
		deal_mutex.unlock();
	}

}


void thread_main(int& num)
{
	while(num!=0)
	{
		std::thread t1(thread_main1,std::ref(num),"main1");
		t1.detach();
		std::thread t2(thread_main1,std::ref(num),"main2");
		t2.detach();
	}
}

int main()
{
		int num=10;
		std::thread th(thread_main,std::ref(num));
		th.detach();
		
		while(num!=0)
		{

		}
		this_thread::sleep_for(std::chrono::seconds(2));
		cout<<"====>quit"<<endl;
return 0;
}


