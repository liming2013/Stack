#ifndef _INFORMATION_H_
#define _INFORMATION_H_

#include"public.h"
void draw_my_information(USER* u);//�����ҵ���Ϣ����
void my_information(int* page,USER* u);
void lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag);//��¼���水ť����
void recoverbutton_login_information(int status);//�ָ�
int control_judge(USER* u);
void cpop(int i);
#endif
