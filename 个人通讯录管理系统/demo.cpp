#include "head.h"
#include "function.h"

int main()
{
	Linklist List = nullptr;
	init_list(List);
	delay_output((char*)"\n\n\n\t\t\t     ��ӭ����ͨѶ¼����ϵͳ\n..........");
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
				cout << "\n�����ɹ�" << endl;
				cout << "��Ա��Ϣ���£�" << endl;
				print(num);
			}
			else
				cout << "����ʧ�ܣ�ͨ��¼���޴�����Ϣ" << endl;
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
			cout << "�������޸ĵ���Ա����" << endl;
			Linklist name_ = search_name(List, 0);
			if (name_)
			{
				cout << "�밴1.���� 2.΢�ź� 3.�绰���� 4.��ַ �����޸�" << endl;
				int select;
				cout << "����0�����޸�" << endl;
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
				cout << "�޸ĳɹ�" << endl;
				cout << "�޸���Ա��Ϣ���£�\n" << endl;
				print(name_);
				cout << endl;
			}
			else
			{
				cout << "�޸�ʧ�ܣ�ͨ��¼���޴�����Ϣ" << endl;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 5:
		{
			cout << "1.������ɾ��\n2.��΢�ź�ɾ��" << endl;
			int choice2;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				cout << "������ɾ����Ա��������" << endl;
				Linklist name = search_name(List, 0);
				if (name)
				{
					cout << "ɾ���ɹ�" << endl;
					cout << "ɾ����Ա��Ϣ���£�\n" << endl;
					print(name);
					cout << endl;
					delete_node(List, name);
				}
				else
					cout << "ɾ��ʧ�ܣ�ͨ�Ų����޴�����Ϣ" << endl;
			}
			break;
			case 2:
			{
				cout << "������ɾ����Ա��΢�źţ�" << endl;
				Linklist num = search_num(List, 0);
				if (num)
				{
					cout << "ɾ���ɹ�" << endl;
					cout << "ɾ����Ա��Ϣ���£�\n" << endl;
					print(num);
					cout << endl;
					delete_node(List, num);
				}
				else
					cout << "ɾ��ʧ�ܣ�ͨ�Ų����޴�����Ϣ" << endl;
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
			cout << "����ɹ�����Ա��Ϣ���£�\n" << endl;
			print_list(List);
		}
			break;
		case 7:
		{
			cout << "1.��������ѯ\n2.��΢�źŲ�ѯ" << endl;
			int choice3;
			cin >> choice3;
			cnt1 = 0;
			cout << "��ѯ�ɹ�\n" << endl;
			switch (choice3)
			{
			case 1:
				fuzzy_search_name(List);
				break;
			case 2:
				fuzzy_search_num(List);
				break;
			default:
				cout << "���벻�Ϸ�" << endl;
				break;
			}
			cout << "\n����ѯ��" << cnt1 << "����¼" << endl;
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 8:
		{
			cout << "��ѡ���Ƿ���ܣ�" << endl;
			cout << "1.����\n2.������" << endl;
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
				cout << "���벻�Ϸ�" << endl;
				break;
			}
			system("pause");
			system("cls");
			menu();
		}
			break;
		case 9:
		{
			cout << "��ѡ���Ƿ���ܣ�" << endl;
			cout << "1.����\n2.������" << endl;
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
				cout << "���벻�Ϸ�" << endl;
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


