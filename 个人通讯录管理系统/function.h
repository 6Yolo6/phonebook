#pragma once

typedef struct LNode
{
	char name[20] = { 0 };
	char num[20] = { 0 };
	char tele_num[20] = { 0 };
	char address[50] = { 0 };
	struct LNode* next = nullptr;
}lNode, * Linklist;

extern int key;
extern int key1;
extern int cnt;
extern int cnt1;


void menu();//�˵�
void delay_output(char* p);//��ʱ���
void add_message(Linklist& List);//��ӳ�Ա
void init_list(Linklist& List);//����ͷ���
void insert_list(Linklist& List, LNode* node);//����ڵ�
void delete_node(Linklist& List, Linklist p);//ɾ���ڵ�
void print(Linklist p);//���������Ա��Ϣ
void print_list(Linklist List);//���ͨ�Ų�
void sort_list(Linklist List);//����
void fuzzy_search_name(Linklist List);//ģ����ѯ
void fuzzy_search_num(Linklist List);//ģ����ѯ
void save_list(Linklist List, bool flag1);//����
void load_list(Linklist List, bool flag2);//����
Linklist search_name(Linklist List, bool flag_name);//����������
Linklist search_num(Linklist List, bool flag_num);//��΢�ź�����

void file(fstream& file, Linklist p, int key);//����/����