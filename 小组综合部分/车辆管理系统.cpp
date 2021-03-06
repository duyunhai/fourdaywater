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
	cout << "要添加几个车辆？";
	cin >> num;
	system("cls");
	cout << "请输入车牌号、制造商、生产时间、型号、座位数、颜色、价格、油耗" << endl;
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
	cout << "添加成功！" << endl;
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
	cout << "修改成功！" << endl;
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
	cout << " 车牌号        制造商    生产时间       型号  座位数    颜色    价格    油耗    id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n数据超出页面容量显示，按y可查看下一页，按n保留在此页";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << "车牌号" << "制造商" << "生产时间" << "型号" << "座位数" << "颜色" << "价格" << "油耗  \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n按任意键退出查询\n";
	_getch();
	system("cls");
	mysql_free_result(result);     //释放结果集所占用的内存
}
void Manage::mysql_initall(MYSQL * con)
{
	mysql_init(con);
	if (0 == mysql_options(con, MYSQL_SET_CHARSET_NAME, "gbk"))//设置字符集
	{
		cout << "\t-----设置字符集成功----\n" << endl;
	}
	if (mysql_real_connect(con, "127.0.0.1", "root", "duyunhai", "duyunhai", 3307, NULL, 0))  //连接到mysql
	{
		cout << "\t-----  MySQL已连接 ----\n" << endl;
	}
	cout << "\t-----  初始化成功 ----\n" << endl;;
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
	cout << " 车牌号        制造商    生产时间       型号  座位数    颜色    价格    油耗    id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n是否翻页 y/n ?";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << " 车牌号 " << "       制造商     " << "  生产时间     " << "     型号     " << " 座位数 " << "         颜色         " << "        价格         " << " 油耗   \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n按任意键退出查询\n";
	_getch();
	system("cls");
}

void Manage::delet_contract(MYSQL * con, int id)
{
	char sql[100];
	sprintf_s(sql, "delete  FROM contacts where id = %d", id);
	if (!mysql_query(con, sql))
		cout << "删除成功！" << endl;
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
		cout << "*******************************************车辆信息管理系统*************************************************\n" << endl;
		cout << "******************************************** 指令1:添加车辆 ************************************************\n" << endl;
		cout << "******************************************** 指令2:删除车辆 ************************************************\n" << endl;
		cout << "******************************************** 指令3:显示车辆 ************************************************\n" << endl;
		cout << "******************************************** 指令4:修改车辆 ************************************************\n" << endl;
		cout << "******************************************** 指令5:查找车辆 ************************************************\n" << endl;
		cout << "*****************四天之水车辆管理平台提醒您，道路千万条，安全第一条，行车不规范，亲人两行泪！***************\n" << endl;
		cout << "请输入您要操作的指令代码：" << endl;
		cin >> cmd;
		if (cmd == '1')
		{
			a.insert_data(&con);
		}
		else if (cmd == '2')
		{
			cout << "\n请输入要删除的车辆的id:";
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
			cout << "\n属性   1：车牌号   2：制造商   3：生产时间   4：型号   5：座位数  6：颜色   7：价格    8：油耗\n" << endl;
			cout << "请输入要修改的属性、修改的内容、要修改车辆的id" << endl;
			cin >> type_4 >> inf_4 >> license_c;
			a.correct_data(&con, type_4, inf_4, license_c);
		}
		else if (cmd == '5')
		{
			cout << "\n类型指令  1：车牌号     2：制造商    3：生产时间    4：型号    5：座位数\n" << endl;
			cout << "请输入要查询的类型？";
			cin >> type_t;
			cout << "\n" << endl;
			cout << "请输入要查询的信息？";
			cin >> name_t;
			cout << endl;
			a.search_contract(&con, type_t, name_t);
		}
		system("cls");

	}
	mysql_close(&con);          //关闭与mysql的连接

}
