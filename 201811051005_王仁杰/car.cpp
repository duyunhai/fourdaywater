#include "iostream"
using namespace std;
class vehicle
{
protected:
	int wheels;//���ָ���
	float weight;//��������
public:
	vehicle();
	int gain_wheels();
	float gain_weight();
};
vehicle::vehicle()
{
	cout << "�����복�ָ���:";
	cin >> wheels;
	cout << "�����복��:";
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
	int passenger_load;//�ؿ���
public:
	car();
	int gain_passenger_load();
};
car::car()
{
	cout << "�������ؿ���:";
	cin >> passenger_load;
	cout << "���ָ���:"<<gain_wheels()<<" "<<"��������:"<<gain_weight()<<" "<<"�ؿ���:"<<gain_passenger_load()<<endl;
}
int car::gain_passenger_load()
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
	int gain_passenger_load();
	float gain_payload();
};
truck::truck()
{
	cout << "�������ؿ���:";
	cin >> passenger_load;
	cout << "������������:";
	cin >> payload;
	cout << "���ָ���:"<<gain_wheels()<<" "<<"��������:"<<gain_weight()<<" "<<"�ؿ���:"<<gain_passenger_load()<<" "<<"������:"<<gain_payload()<<endl;
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
	cout << "������γ�����Ϣ" << endl;
	car c;
	cout << "�����뿨������Ϣ" << endl;
	truck t;
	return 0;
}