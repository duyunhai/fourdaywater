#include <iostream>
using namespace std;
class vehicle
{
protected:
	int wheels;//车轮个数
	float weight;//车重
public:
	vehicle();
	int get_wheels();
	float get_weight();
};
vehicle::vehicle()
{
	cout << "请输入 wheels：" << endl;
	cin >> wheels;
	cout << "请输入 weight：" << endl;
	cin >> weight;
}
int vehicle::get_wheels()
{
	return wheels;
}
float vehicle::get_weight()
{
	return weight;
}
class car:private vehicle
{
private:
	int passenger_load;//承载人数
public:
	car();
	int get_passenger_load();
};
car::car()
{
	cout << "请输入passenger_load:" << endl;
	cin >> passenger_load;
	cout << "wheels is:" << endl;
	cout << get_wheels() << endl;
	cout << "weight is:" << endl;
	cout << get_weight() << endl;
	cout << "passenger_load is:" << endl;
	cout << get_passenger_load() << endl;
}
int car::get_passenger_load()
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
	int get_passenger_load();
	float get_payload();
};
truck::truck()
{
	cout << "请输入passenger_load:" << endl;
	cin >> passenger_load;
	cout << "请输入payload" << endl;
	cin >> payload;
	cout << "wheels is:" << endl;
	cout << get_wheels() << endl;
	cout << "weight is:" << endl;
	cout << get_weight() << endl;
	cout << "passenger_load is:" << endl;
	cout << get_passenger_load() << endl;
	cout << "payload is:" << endl;
	cout << get_payload() << endl;
}
int truck::get_passenger_load()
{
	return passenger_load;
}
float truck::get_payload()
{
	return payload;
}
int main()
{
	cout << "请输入car的信息：" << endl;
	car a;
	cout << "请输入truck的信息：" << endl;
	truck b;
	return 0;
}

