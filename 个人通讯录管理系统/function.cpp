#include "head.h"
#include "function.h"



int cnt = 0;
int cnt1 = 0;
int key = 0;
int key1 = 0;

void menu()
{
	cout << "\n\n\t\t------------------------------------------------" << endl;
	cout << "\n\n\t\t\t********************************" << endl;
	cout << "\t\t\t*\t ͨѶ¼����ϵͳ\t       *" << endl;
	cout << "\t\t\t*1.��ʾͨ��¼\t\t       *" << endl;
	cout << "\t\t\t*2.������Ա\t\t       *" << endl;
	cout << "\t\t\t*3.�����Ա\t\t       *" << endl;
	cout << "\t\t\t*4.�޸���Ա\t\t       *" << endl;
	cout << "\t\t\t*5.ɾ����Ա\t\t       *" << endl;
	cout << "\t\t\t*6.��������\t\t       *" << endl;
	cout << "\t\t\t*7.ģ����ѯ\t\t       *" << endl;
	cout << "\t\t\t*8.�ļ�����\t\t       *" << endl;
	cout << "\t\t\t*9.�ļ�����\t\t       *" << endl;
	cout << "\t\t\t*10.�˳�\t\t       *" << endl;
	cout << "\t\t\t********************************" << endl;
	cout << "\n\n\t\t------------------------------------------------" << endl;
}

void delay_output(char* p)
{
	while (1)
	{
		if (*p != 0)
			cout << *p++;
		else
			break;
		Sleep(70);
	}
}

void add_message(Linklist& List)
{
	char ch;
	do
	{
		LNode* p = new LNode;
		cout << "��ֱ�����������΢�źš��绰���롢��ַ" << endl;
		cin >> p->name >> p->num >> p->tele_num >> p->address;
		insert_list(List, p);
		cnt++;
		cout << "\n�����Ա��Ϣ���£�\n" << endl;
		print(p);
		cout << "\n��ӳɹ����Ƿ����Y/N\n" << endl;
		getchar();
		ch = getch();
	} while ('y' == ch || 'Y' == ch);
	system("cls");
	menu();
}

void init_list(Linklist& List)
{
	List = new LNode;//����ͷ���
	List->next = nullptr;
}

void insert_list(Linklist& List, LNode* node)
{
	//ͷ�巨
	node->next = List->next;
	List->next = node;
	//β�巨
	//LNode* end = nullptr;
	//end = List;
	//node->next = nullptr;
	//while (end->next != nullptr)
	//	end = end->next;
	//end->next = node;
}

void print(Linklist p)
{
	cout << "----------------------" << endl;
	cout << "������" << p->name << endl;
	cout << "΢�źţ�" << p->num << endl;
	cout << "�绰���룺" << p->tele_num << endl;
	cout << "��ַ��" << p->address << endl;
	cout << "----------------------" << endl;
}

void print_list(Linklist List)
{
	Linklist p = List->next;
	if (!p)
	{
		cout << "ͨ��¼������Ա�������" << endl;
		system("pause");
		system("cls");
		menu();
		return;
	}
	while (p)
	{
		print(p);
		p = p->next;
	}
	cout << "\nͨѶ¼�й���" << cnt << "����¼" << endl;
	system("pause");
	system("cls");
	menu();
}

void sort_list(Linklist List)
{
	Linklist p = List->next;
	while (p->next)
	{
		if (strcmp(p->name, p->next->name) > 0)
		{
			swap(p->name, p->next->name);
			swap(p->num, p->next->num);
			swap(p->tele_num, p->next->tele_num);
			swap(p->address, p->next->address);
		}
		p = p->next;
	}
	system("cls");
	menu();
}

Linklist search_name(Linklist List, bool flag_name)
{
	char name[20];
	if (flag_name)
		cout << "�����������Ա������" << endl;
	cin >> name;
	Linklist p = List->next;
	while (p)
	{
		if (0 == strcmp(p->name, name))
			break;
		else
			p = p->next;
	}
	return p;
}

Linklist search_num(Linklist List, bool flag_num)
{
	char num[20];
	if (flag_num)
		cout << "�����������Ա��΢�ź�" << endl;
	cin >> num;
	Linklist p = List->next;
	while (p)
	{
		if (0 == strcmp(p->num, num))
			break;
		else
			p = p->next;
	}
	return p;
}

void fuzzy_search_name(Linklist List)
{
	Linklist p = List->next;
	string str, name;
	cout << "����������" << endl;
	cin >> name;
	while (p)
	{
		str = p->name;
		if (str.find(name) < str.length())
		{
			print(p);
			cnt1++;
		}
		p = p->next;
	}
}

void fuzzy_search_num(Linklist List)
{
	Linklist p = List->next;
	string str, num;
	cout << "������΢�ź�" << endl;
	cin >> num;
	while (p)
	{
		str = p->num;
		if (str.find(num) < str.length())
		{
			print(p);
			cnt1++;
		}
		p = p->next;
	}
}

void delete_node(Linklist& List, Linklist p)
{
	Linklist q = nullptr, r = List;
	while (r && r != p)
	{
		q = r;
		r = r->next;
	}
	if (r != nullptr)
	{
		cnt--;
		q->next = r->next;
		delete r;
	}
	else
	{
		cout << "ɾ��ʧ�ܣ��ڵ㲻����" << endl;
	}
}

void save_list(Linklist List, bool flag1)
{
	key = 0;
	cout << "�������ļ���(.xls)��" << endl;
	char File[50] = { 0 };
	cin >> File;
	ofstream _write(File);
	if (!(_write.is_open()))
		return;
	_write.close();
	fstream write_(File);
	Linklist p = List->next;
	if (write_.is_open())
	{
		for (int i = 0; i < 10000; i++)
		{
			write_ << endl;
		}
		write_.close();
	}
	fstream write(File);
	if (write.is_open())
	{
		write << "����" << "\t" << "΢�ź�" << "\t" << "�绰����" << "\t" << "��ַ" << endl;
		while (p)
		{
			if (flag1)
			{
				cout << "��������Կ��" << endl;
				cin >> key;
				file(write, p, key);
			}
			write << p->name << "\t" << p->num << "\t" << p->tele_num << "\t" << p->address << endl;
			p = p->next;
		}
		write.close();
		cout << "����ɹ�" << endl;
		cout << "�ļ�Ϊ" << File << endl;
		system(File);
	}
	else
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
}

void load_list(Linklist List, bool flag2)
{
	int cnt3 = 0, cnt4 = 0;
	LNode* p = nullptr;
	if (flag2)
	{
		cout << "�������ļ���(.xls)��" << endl;
		char File[50] = { 0 };
		cin >> File;
		fstream load(File);
		cout << "��������Կ��" << endl;
		cin >> key1;
		if (!(key == key1))
		{
			cout << "��Կ����ȷ���޷�����" << endl;
			return;
		}
		if (load.is_open())
		{
			cout << endl << "�����ļ��ɹ�" << endl;
			cout << "������Ա��Ϣ���£�" << endl;
			char buffer[500];
			memset(buffer, 0, 500);
			while (load >> buffer)
			{
				if ((0 == strcmp(buffer, "����")))
					continue;
				else if ((0 == strcmp(buffer, "΢�ź�")))
					continue;
				else if ((0 == strcmp(buffer, "�绰����")))
					continue;
				else if ((0 == strcmp(buffer, "��ַ")))
					continue;
				if (cnt4 % 4 == 0)
				{
					p = new LNode;
					insert_list(List, p);
					cnt++;
				}
				cnt4++;
				if (0 == cnt3)
				{
					strcpy(p->name, buffer);
					cnt3 = 1;
				}
				else if (1 == cnt3)
				{
					strcpy(p->num, buffer);
					cnt3 = 2;
				}
				else if (2 == cnt3)
				{
					strcpy(p->tele_num, buffer);
					cnt3 = 3;
				}
				else if (3 == cnt3)
				{
					strcpy(p->address, buffer);
					cnt3 = 0;
				}
				if (cnt4 % 4 == 0)
				{
					file(load, p, key);
					print(p);
				}
				memset(buffer, 0, 500);
			}
			load.close();
		}
		else
		{
			cout << "���ļ�ʧ��" << endl;
			return;
		}
	}
	else
	{
		cout << "�������ļ���(.xls)��" << endl;
		char File[50] = { 0 };
		cin >> File;
		ofstream save_(File);
		if (!(save_.is_open()))
			return;
		save_.close();
		ofstream save(File);
		if (save.is_open())
			save << "����" << "\t" << "΢�ź�" << "\t" << "�绰����" << "\t" << "��ַ" << endl;
		else
		{
			cout << "�ļ���ʧ��" << endl;
			return;
		}
		save.close();
		system(File);
		system("pause");
		fstream load(File);
		if (load.is_open())
		{
			cout << endl << "�����ļ��ɹ�" << endl;
			cout << "������Ա��Ϣ���£�" << endl;
			char buffer[500];
			memset(buffer, 0, 500);
			while (load >> buffer)
			{
				if ((0 == strcmp(buffer, "����")))
					continue;
				else if ((0 == strcmp(buffer, "΢�ź�")))
					continue;
				else if ((0 == strcmp(buffer, "�绰����")))
					continue;
				else if ((0 == strcmp(buffer, "��ַ")))
					continue;
				if (cnt4 % 4 == 0)
				{
					p = new LNode;
					insert_list(List, p);
					cnt++;
				}
				cnt4++;
				if (0 == cnt3)
				{
					strcpy(p->name, buffer);
					cout << "-------------------" << endl;
					cout << "������" << p->name << endl;
					cnt3 = 1;
				}
				else if (1 == cnt3)
				{
					strcpy(p->num, buffer);
					cout << "΢�źţ�" << p->num << endl;
					cnt3 = 2;
				}
				else if (2 == cnt3)
				{
					strcpy(p->tele_num, buffer);
					cout << "�绰���룺" << p->tele_num << endl;
					cnt3 = 3;
				}
				else if (3 == cnt3)
				{
					strcpy(p->address, buffer);
					cout << "��ַ��" << p->address << endl;
					cout << "-------------------" << endl;
					cnt3 = 0;
				}
				memset(buffer, 0, 500);
			}
			load.close();
		}
		else
		{
			cout << "���ļ�ʧ��" << endl;
			return;
		}
	}
	
}

void file(fstream& file, Linklist p, int key)
{
	for (int i = 0; p->name[i]; i++)
		p->name[i] ^= key;
	for (int i = 0; p->num[i]; i++)
		p->num[i] ^= key;
	for (int i = 0; p->tele_num[i]; i++)
		p->tele_num[i] ^= key;
	for (int i = 0; p->address[i]; i++)
		p->address[i] ^= key;
}





