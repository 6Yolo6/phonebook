#include "head.h"
#include "function.h"

int main()
{
	Linklist List = nullptr;
	init_list(List);
	delay_output((char*)"\n\n\n\t\t\t     欢迎进入通讯录管理系统\n..........");
	Sleep(900);
	system("cls");
	menu();
	int choice;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			print_list(List);
		}
			break;
		case 2:
		{
			Linklist num = search_num(List, 1);
			if (num)
			{
				cout << "\n搜索成功" << endl;
				cout << "人员信息如下：" << endl;
				print(num);
			}
			else
				cout << "搜索失败，通信录中无此人信息" << endl;
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 3:
		{
			add_message(List);
		}
			break;
		case 4:
		{
			cout << "请输入修改的人员姓名" << endl;
			Linklist name_ = search_name(List, 0);
			if (name_)
			{
				cout << "请按1.姓名 2.微信号 3.电话号码 4.地址 进行修改" << endl;
				int select;
				cout << "输入0结束修改" << endl;
				do
				{
					cin >> select;
					switch (select)
					{
					case 1:
					{
						char name2[20];
						cin >> name2;
						strcpy(name_->name, name2);
					}
					break;
					case 2:
					{
						char num2[20];
						cin >> num2;
						strcpy(name_->num, num2);
					}
					break;
					case 3:
					{
						char tele_num2[20];
						cin >> tele_num2;
						strcpy(name_->tele_num, tele_num2);
					}
					break;
					case 4:
					{
						char address2[20];
						cin >> address2;
						strcpy(name_->address, address2);
					}
					break;
					case 0:
						break;
					}
				} while (select != 0);
				cout << "修改成功" << endl;
				cout << "修改人员信息如下：\n" << endl;
				print(name_);
				cout << endl;
			}
			else
			{
				cout << "修改失败，通信录中无此人信息" << endl;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 5:
		{
			cout << "1.按姓名删除\n2.按微信号删除" << endl;
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				cout << "请输入删除人员的姓名：" << endl;
				Linklist name = search_name(List, 0);
				if (name)
				{
					cout << "删除成功" << endl;
					cout << "删除人员信息如下：\n" << endl;
					print(name);
					cout << endl;
					delete_node(List, name);
				}
				else
					cout << "删除失败，通信簿中无此人信息" << endl;
			}
			break;
			case 2:
			{
				cout << "请输入删除人员的微信号：" << endl;
				Linklist num = search_num(List, 0);
				if (num)
				{
					cout << "删除成功" << endl;
					cout << "删除人员信息如下：\n" << endl;
					print(num);
					cout << endl;
					delete_node(List, num);
				}
				else
					cout << "删除失败，通信簿中无此人信息" << endl;
			}
			default:
				break;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 6:
		{
			sort_list(List);
			cout << "排序成功，人员信息如下：\n" << endl;
			print_list(List);
		}
			break;
		case 7:
		{
			cout << "1.按姓名查询\n2.按微信号查询" << endl;
			int choice3;
			cin >> choice3;
			cnt1 = 0;
			cout << "查询成功\n" << endl;
			switch (choice3)
			{
			case 1:
				fuzzy_search_name(List);
				break;
			case 2:
				fuzzy_search_num(List);
				break;
			default:
				cout << "输入不合法" << endl;
				break;
			}
			cout << "\n共查询到" << cnt1 << "条记录" << endl;
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 8:
		{
			cout << "请选择是否加密：" << endl;
			cout << "1.加密\n2.不加密" << endl;
			int choice4;
			cin >> choice4;
			switch (choice4)
			{
			case 1:
				save_list(List, 1);
				break;
			case 2:
				save_list(List, 0);
				break;
			default:
				cout << "输入不合法" << endl;
				break;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 9:
		{
			cout << "请选择是否解密：" << endl;
			cout << "1.解密\n2.不解密" << endl;
			int choice5;
			cin >> choice5;
			switch (choice5)
			{
			case 1:
				load_list(List, 1);
				break;
			case 2:
				load_list(List, 0);
				break;
			default:
				cout << "输入不合法" << endl;
				break;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 10:
		{
			exit(0);
		}
			break;
		default:
			break;
		}
	} while (1);
	return 0;
}


