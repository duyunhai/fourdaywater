#include <iostream>
#include "mysql.h"
#include "conio.h"

using namespace std;
struct Contacts
{
	char license[10];
	char company[20];
	char maketime[20];
	char type[20];
	char seats[10];
	char color[10];
	char price[11];
	char oilcost[10];
};
class Manage
{
private:
	Contacts contracts[10];
public:
	Manage() {};
	void insert_data(MYSQL *con);
	void correct_data(MYSQL * con, char type, char new_data[], int id);
	void show_list(MYSQL * con);
	void mysql_initall(MYSQL * con);
	void search_contract(MYSQL * con, char type, char  name_t[]);
	void delet_contract(MYSQL * con, int id);
};
void Manage::insert_data(MYSQL * con)
{
	char sql[400];
	int num;
	cout << "Ҫ��Ӽ���������";
	cin >> num;
	system("cls");
	cout << "�����복�ƺš������̡�����ʱ�䡢�ͺš���λ������ɫ���۸��ͺ�" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> contracts[i].license >> contracts[i].company >> contracts[i].maketime >> contracts[i].type >> contracts[i].seats >> contracts[i].color >> contracts[i].price >> contracts[i].oilcost;
	}
	for (int i = 0; i < num; i++)
	{
		sprintf_s(sql, "insert into contacts(license,company,maketime,type,seats,color,price,oilcost) values('%s','%s','%s','%s','%s','%s','%s','%s')", contracts[i].license, contracts[i].company, contracts[i].maketime, contracts[i].type, contracts[i].seats, contracts[i].color, contracts[i].price, contracts[i].oilcost);
		if (mysql_query(con, sql))
			cout << mysql_error(con);
	}
	cout << "��ӳɹ���" << endl;
}
void Manage::correct_data(MYSQL * con, char type, char new_data[], int id)
{
	char sql[100];
	if (type == '1')
	{
		sprintf_s(sql, "update contacts set license = '%s' where id = %d", new_data, id);
	}
	else if (type == '2')
	{
		sprintf_s(sql, "update contacts set company = '%s' where id = %d", new_data, id);
	}
	else if (type == '3')
	{
		sprintf_s(sql, "update contacts set maketime = '%s' where id = %d", new_data, id);
	}
	else if (type == '4')
	{
		sprintf_s(sql, "update contacts set type = '%s' where id = %d", new_data, id);
	}
	else if (type == '5')
	{
		sprintf_s(sql, "update contacts set seats = '%s' where id = %d", new_data, id);
	}
	else if (type == '6')
	{
		sprintf_s(sql, "update contacts set color = '%s' where id = %d", new_data, id);
	}
	else if (type == '7')
	{
		sprintf_s(sql, "update contacts set price = '%s' where id = %d", new_data, id);
	}
	else if (type == '8')
	{
		sprintf_s(sql, "update contacts set oilcost = '%s' where id = %d", new_data, id);
	}
	mysql_query(con, sql);
	cout << "�޸ĳɹ���" << endl;
}
void Manage::show_list(MYSQL * con)
{
	MYSQL_ROW row;
	MYSQL_RES *result;
	int num, j = 0;
	char cmd;
	if (mysql_query(con, "SELECT * FROM contacts"))
		return;
	result = mysql_store_result(con);
	num = mysql_num_fields(result);
	cout << " ���ƺ�        ������    ����ʱ��       �ͺ�  ��λ��    ��ɫ    �۸�    �ͺ�    id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //�������һ�У�����ֹѭ��
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n���ݳ���ҳ��������ʾ����y�ɲ鿴��һҳ����n�����ڴ�ҳ";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << "���ƺ�" << "������" << "����ʱ��" << "�ͺ�" << "��λ��" << "��ɫ" << "�۸�" << "�ͺ�  \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			cout << row[i] << "\t";    //row��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n��������˳���ѯ\n";
	_getch();
	system("cls");
	mysql_free_result(result);     //�ͷŽ������ռ�õ��ڴ�
}
void Manage::mysql_initall(MYSQL * con)
{
	mysql_init(con);
	if (0 == mysql_options(con, MYSQL_SET_CHARSET_NAME, "gbk"))//�����ַ���
	{
		cout << "\t-----�����ַ����ɹ�----\n" << endl;
	}
	if (mysql_real_connect(con, "127.0.0.1", "root", "duyunhai", "duyunhai", 3307, NULL, 0))  //���ӵ�mysql
	{
		cout << "\t-----  MySQL������ ----\n" << endl;
	}
	cout << "\t-----  ��ʼ���ɹ� ----\n" << endl;;
	system("cls");
}
void Manage::search_contract(MYSQL * con, char type, char  name_t[])
{
	MYSQL_ROW row;
	MYSQL_RES *result;
	char sql[200];
	int num, j = 0;
	char cmd;
	if (type == '1')
	{
		sprintf_s(sql, "SELECT license,company,maketime,type,seats,color,price,oilcost,id FROM contacts where license = '%s'", name_t);
	}
	else if (type == '2')
	{
		sprintf_s(sql, "SELECT license,company,maketime,type,seats,color,price,oilcost,id FROM contacts where company = '%s'", name_t);
	}
	else if (type == '3')
	{
		sprintf_s(sql, "SELECT license,company,maketime,type,seats,color,price,oilcost,id FROM contacts where maketime = '%s'", name_t);
	}
	else if (type == '4')
	{
		sprintf_s(sql, "SELECT license,company,maketime,type,seats,color,price,oilcost,id FROM contacts where type = '%s'", name_t);
	}
	else if (type == '5')
	{
		sprintf_s(sql, "SELECT license,company,maketime,type,seats,color,price,oilcost,id FROM contacts where seats = '%s'", name_t);
	}
	mysql_query(con, sql);
	result = mysql_store_result(con);
	num = mysql_num_fields(result);
	system("cls");
	cout << " ���ƺ�        ������    ����ʱ��       �ͺ�  ��λ��    ��ɫ    �۸�    �ͺ�    id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //�������һ�У�����ֹѭ��
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n�Ƿ�ҳ y/n ?";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << " ���ƺ� " << "       ������     " << "  ����ʱ��     " << "     �ͺ�     " << " ��λ�� " << "         ��ɫ         " << "        �۸�         " << " �ͺ�   \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //����forѭ����������е�ÿһ��
		{
			cout << row[i] << "\t";    //row��MYSQL_ROW���������Ե�������ʹ�ã�iΪ����
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n��������˳���ѯ\n";
	_getch();
	system("cls");
}

void Manage::delet_contract(MYSQL * con, int id)
{
	char sql[100];
	sprintf_s(sql, "delete  FROM contacts where id = %d", id);
	if (!mysql_query(con, sql))
		cout << "ɾ���ɹ���" << endl;
}
int main()
{
	system("color 30");
	MYSQL con;
	Manage a;
	a.mysql_initall(&con);
	int license_t;
	int license_c;
	char type_4;
	char inf_4[50];
	char cmd;
	char type_t;
	char name_t[50];
	while (1)
	{
		cout << "******************************************Made by Fourdaywater**********************************************\n" << endl;
		cout << "*******************************************������Ϣ����ϵͳ*************************************************\n" << endl;
		cout << "******************************************** ָ��1:��ӳ��� ************************************************\n" << endl;
		cout << "******************************************** ָ��2:ɾ������ ************************************************\n" << endl;
		cout << "******************************************** ָ��3:��ʾ���� ************************************************\n" << endl;
		cout << "******************************************** ָ��4:�޸ĳ��� ************************************************\n" << endl;
		cout << "******************************************** ָ��5:���ҳ��� ************************************************\n" << endl;
		cout << "*****************����֮ˮ��������ƽ̨����������·ǧ��������ȫ��һ�����г����淶�����������ᣡ***************\n" << endl;
		cout << "��������Ҫ������ָ����룺" << endl;
		cin >> cmd;
		if (cmd == '1')
		{
			a.insert_data(&con);
		}
		else if (cmd == '2')
		{
			cout << "\n������Ҫɾ���ĳ�����id:";
			cin >> license_t;
			a.delet_contract(&con, license_t);
		}
		else if (cmd == '3')
		{
			system("cls");
			a.show_list(&con);
		}
		else if (cmd == '4')
		{
			system("cls");
			cout << "\n����   1�����ƺ�   2��������   3������ʱ��   4���ͺ�   5����λ��  6����ɫ   7���۸�    8���ͺ�\n" << endl;
			cout << "������Ҫ�޸ĵ����ԡ��޸ĵ����ݡ�Ҫ�޸ĳ�����id" << endl;
			cin >> type_4 >> inf_4 >> license_c;
			a.correct_data(&con, type_4, inf_4, license_c);
		}
		else if (cmd == '5')
		{
			cout << "\n����ָ��  1�����ƺ�     2��������    3������ʱ��    4���ͺ�    5����λ��\n" << endl;
			cout << "������Ҫ��ѯ�����ͣ�";
			cin >> type_t;
			cout << "\n" << endl;
			cout << "������Ҫ��ѯ����Ϣ��";
			cin >> name_t;
			cout << endl;
			a.search_contract(&con, type_t, name_t);
		}
		system("cls");

	}
	mysql_close(&con);          //�ر���mysql������

}
