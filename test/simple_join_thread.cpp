#include <iostream>
#include <thread>
#include <string>

using namespace std;

class Task
{
public:
	void run_task()
	{
		cout<<"task run"<<endl;
	}
	void operator()()
	{
		cout<<"operator task"<<endl;
	}
};

struct pack_head
{
	int a:1;
	int b:2;
	int c:3;
	int d:15;
} __attribute__((packed));

struct not_pack_head
{

	int a:1;
	int b:2;
	int c:3;
	int d:15;
};

int main()
{

	cout<<sizeof(pack_head)<<endl;
	cout<<sizeof(not_pack_head)<<endl;
	Task t;
	thread th(t);
	th.join();
	thread th1(&Task::run_task,&t);
	th1.join();
	thread th2((Task()));
	th2.join();
return 0;
}
