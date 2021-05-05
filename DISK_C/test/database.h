#ifndef _DATA_H_
#define _DATA_H_
typedef struct userinfo
{
	char user[15];           //6-12λ���û���
	char ID[20];             //18λ���˺�
	char password[20];       //8-16λ������
	char phone[21];       //19λ���ֻ���
}USER;	//��װ�û���Ϣ
typedef struct videoinfo
{
	char vn[2];//��Ƶ����
	char comment[200];//����
	int bingo;//������
	char dan[15][30];//��Ļ,�ֱ��¼ʱ�估���� 
}VIDEO;

typedef struct history
{
	char name[10];  //��������
	char now_hour[10];
	char now_min[10];
}HIS;

typedef struct collect
{
	char name[10];
	char num_page[10];
}COLL;

typedef struct pinglun
{
	char name[20];
	char plun[100];	
	char now_hour[10];
	char now_min[10];
}PING;



#endif