#include "iostream"
using namespace std;
class vehicle
{
protected:
	int wheels;//车轮个数
	float weight;//车身重量
public:
	vehicle();
	int gain_wheels();
	float gain_weight();
};
vehicle::vehicle()
{
	cout << "请输入车轮个数:";
	cin >> wheels;
	cout << "请输入车重:";
	cin >> weight;
}
int vehicle::gain_wheels()
{
	return wheels;
}
float vehicle::gain_weight()
{
	return weight;
}
class car:private vehicle
{
private:
	int passenger_load;//载客量
public:
	car();
	int gain_passenger_load();
};
car::car()
{
	cout << "请输入载客量:";
	cin >> passenger_load;
	cout << "车轮个数:"<<gain_wheels()<<" "<<"车身重量:"<<gain_weight()<<" "<<"载客量:"<<gain_passenger_load()<<endl;
}
int car::gain_passenger_load()
{
	return passenger_load;
}
class truck :private vehicle
{
private:
	int passenger_load;
	float payload;//载重量
public:
	truck();
	int gain_passenger_load();
	float gain_payload();
};
truck::truck()
{
	cout << "请输入载客量:";
	cin >> passenger_load;
	cout << "请输入载重量:";
	cin >> payload;
	cout << "车轮个数:"<<gain_wheels()<<" "<<"车身重量:"<<gain_weight()<<" "<<"载客量:"<<gain_passenger_load()<<" "<<"载重量:"<<gain_payload()<<endl;
}
int truck::gain_passenger_load()
{
	return passenger_load;
}
float truck::gain_payload()
{
	return payload;
}
int main()
{
	cout << "请输入轿车的信息" << endl;
	car c;
	cout << "请输入卡车的信息" << endl;
	truck t;
	return 0;
}