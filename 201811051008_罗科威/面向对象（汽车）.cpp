#include <iostream>
using namespace std;
class vehicle
{
protected:
	int wheels;//���ָ���
	float weight;//����
public:
	vehicle();
	int get_wheels();
	float get_weight();
};
vehicle::vehicle()
{
	cout << "������ wheels��" << endl;
	cin >> wheels;
	cout << "������ weight��" << endl;
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
	int passenger_load;//��������
public:
	car();
	int get_passenger_load();
};
car::car()
{
	cout << "������passenger_load:" << endl;
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
	float payload;//������
public:
	truck();
	int get_passenger_load();
	float get_payload();
};
truck::truck()
{
	cout << "������passenger_load:" << endl;
	cin >> passenger_load;
	cout << "������payload" << endl;
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
	cout << "������car����Ϣ��" << endl;
	car a;
	cout << "������truck����Ϣ��" << endl;
	truck b;
	return 0;
}

