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


void menu();//菜单
void delay_output(char* p);//延时输出
void add_message(Linklist& List);//添加成员
void init_list(Linklist& List);//申请头结点
void insert_list(Linklist& List, LNode* node);//插入节点
void delete_node(Linklist& List, Linklist p);//删除节点
void print(Linklist p);//输出单个人员信息
void print_list(Linklist List);//输出通信簿
void sort_list(Linklist List);//排序
void fuzzy_search_name(Linklist List);//模糊查询
void fuzzy_search_num(Linklist List);//模糊查询
void save_list(Linklist List, bool flag1);//保存
void load_list(Linklist List, bool flag2);//载入
Linklist search_name(Linklist List, bool flag_name);//按姓名搜索
Linklist search_num(Linklist List, bool flag_num);//按微信号搜索

void file(fstream& file, Linklist p, int key);//加密/解密