#include"tjpage.h"
void tj_page(int* page, char* vn)
{
	int num = 0;
	int vi[2] = { 1,1 };
	char number[4] = "\0";
	char dbm[18] = "\0";
	clrmous(MouseX, MouseY);
	delay(100);
	cleardevice();
	drawtjpage();
	show_dbm(96, 100, "a160\\3.dat");
	show_dbm(384, 100, "b160\\3.dat");
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		strcat(dbm, "a160\\");
		itoa(vi[0], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(96, 100, dbm);
		delay(10);
		vi[0]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[0] > 686)
		{
			vi[0] = 1;
		}

		strcat(dbm, "b160\\");
		itoa(vi[1], number, 10);
		strcat(dbm, number);
		strcat(dbm, ".dat");
		show_dbm(384, 100, dbm);
		delay(10);
		vi[1]++;
		strcpy(dbm, "\0");
		strcpy(number, "\0");
		if (vi[1] > 686)
		{
			vi[1] = 1;
		}
		if (MouseX > 96 && MouseX < 256 && MouseY>100 && MouseY < 190)//"��ƵA"���ж�
		{
			if (mouse_press(96, 100, 256, 190) == 2)
			{
				
			}
			else if (mouse_press(96, 100, 256, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "a");
				return;
			}
		}
		if (MouseX > 384 && MouseX < 544 && MouseY>100 && MouseY < 190)//"��ƵB"���ж�
		{
			if (mouse_press(384, 100, 544, 190) == 2)
			{
				
			}
			else if (mouse_press(384, 100, 544, 190) == 1)
			{
				MouseS = 0;
				*page = 4;
				strcpy(vn, "b");
				return;
			}
		}
		if (MouseX > 480 && MouseX < 600 && MouseY>400 && MouseY < 470)//"�ҵ�"���ж�
		{
			if (mouse_press(480, 400, 600, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(480, 400, 600, 470, LIGHTMAGENTA, LIGHTGRAY, 1);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 1;
				}
				continue;
			}
			else if (mouse_press(480, 400, 600, 470) == 1)
			{
				MouseS = 0;
				*page = 3;
				return;
			}
		}
		if (MouseX > 590 && MouseX < 640 && MouseY>0 && MouseY < 50)//���ذ�ť
		{
			if (mouse_press(590, 0, 640, 50) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(590, 0, 640, 50, RED, LIGHTGRAY, 2);
					num = 2;
				}
				continue;
			}
			else if (mouse_press(590, 0, 640, 50) == 1)
			{
				MouseS = 0;
				delay(100);
				exit(1);
			}
		}
		if (MouseX > 95 && MouseX < 180 && MouseY>35 && MouseY < 75)//ȫ��
		{
			if (mouse_press(95, 35, 180, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(95, 35, 180, 75, LIGHTRED, LIGHTGRAY, 3);
					num = 3;
				}
				continue;
			}
			else if (mouse_press(95, 35, 180, 75) == 1)
			{
				MouseS = 0;
				*page = 0;
				return;
			}
		}
		if (MouseX > 315 && MouseX < 400 && MouseY>35 && MouseY < 75)//����
		{
			if (mouse_press(315, 35, 400, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(315, 35, 400, 75, LIGHTRED, LIGHTGRAY, 4);
					num = 4;
				}
				continue;
			}
			else if (mouse_press(315, 35, 400, 75) == 1)
			{
				MouseS = 0;
				*page = 12;
				return;
			}
		}
		if (MouseX > 435 && MouseX < 520 && MouseY>35 && MouseY < 75)//����
		{
			if (mouse_press(435, 35, 520, 75) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(435, 35, 520, 75, LIGHTRED, LIGHTGRAY, 5);
					num = 5;
				}
				continue;
			}
			else if (mouse_press(435, 35, 520, 75) == 1)
			{
				MouseS = 0;
				*page = 13;
				return;
			}
		}
		if (MouseX > 40 && MouseX < 160 && MouseY>400 && MouseY < 470)//��ҳ
		{
			if (mouse_press(40, 400, 160, 470) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					lightbutton_tjpage(40, 400, 160, 470, LIGHTMAGENTA, LIGHTGRAY, 6);
					num = 6;
				}
				continue;
			}
			else if (mouse_press(40, 400, 160, 470) == 1)
			{
				MouseS = 0;
				*page = 0;
				return;
			}
		}
		if (num != 0)
		{
			recoverbutton_tjpage(num);
			num = 0;
		}
		if (MouseS != 0)
			MouseS = 0;
	}
}
void drawtjpage()
{
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);

	rectangle(480, 400, 600, 470);//"�ҵ�"��
	puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);

	rectangle(40, 400, 160, 470);//��ҳ��
	//setfillstyle(1, LIGHTMAGENTA);
	//bar(40, 400, 160, 470);
	puthz(60, 420, "��ҳ", 32, 50, LIGHTMAGENTA);

	setcolor(LIGHTRED);
	settextstyle(0, 0, 3);
	outtextxy(165, 200, "a");
	outtextxy(453, 200, "b");
	//outtextxy(165, 390, "c");
	//outtextxy(453, 390, "d");

	setfillstyle(1, LIGHTGRAY);
	bar(205, 35, 290, 75);
	setcolor(LIGHTRED);
	rectangle(205, 35, 290, 75);
	puthz(100, 40, "ȫ��", 32, 45, LIGHTRED);
	puthz(210, 40, "�Ƽ�", 32, 45, LIGHTRED);
	puthz(320, 40, "����", 32, 45, LIGHTRED);
	puthz(440, 40, "����", 32, 45, LIGHTRED);

	setcolor(RED);//���ذ�ť
	rectangle(590, 0, 640, 50);
	line(590, 0, 640, 50);
	line(640, 0, 590, 50);
}
void lightbutton_tjpage(int x, int y, int x1, int y1, int color1, int color2, int flag)
{
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�
	switch (flag)
	{

	case 1://�ҵ�
		puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);
		break;
	case 2://����
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 3://ȫ��
		puthz(100, 40, "ȫ��", 32, 45, LIGHTRED);
		break;
	case 4://����
		puthz(320, 40, "����", 32, 45, LIGHTRED);
		break;
	case 5://����
		puthz(440, 40, "����", 32, 45, LIGHTRED);
		break;
	case 6://��ҳ
		puthz(60, 420, "��ҳ", 32, 50, LIGHTMAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}
}
void recoverbutton_tjpage(int status)
{
	clrmous(MouseX, MouseY);
	switch (status)
	{

	case 1:
		setfillstyle(1, WHITE);
		setcolor(LIGHTMAGENTA);
		bar(480, 400, 600, 470);
		rectangle(480, 400, 600, 470);//"�ҵ�"��;
		puthz(500, 420, "�ҵ�", 32, 50, LIGHTMAGENTA);
		break;
	case 2:
		setfillstyle(1, WHITE);
		setcolor(RED);//���ذ�ť
		bar(590, 0, 640, 50);
		rectangle(590, 0, 640, 50);
		line(590, 0, 640, 50);
		line(640, 0, 590, 50);
		break;
	case 3:
		setfillstyle(1, WHITE);
		bar(95, 35, 180, 75);
		puthz(100, 40, "ȫ��", 32, 45, LIGHTRED);
		break;
	case 4:
		setfillstyle(1, WHITE);
		bar(315, 35, 400, 75);
		puthz(320, 40, "����", 32, 45, LIGHTRED);
		break;
	case 5:
		setfillstyle(1, WHITE);
		bar(435, 35, 520, 75);
		puthz(440, 40, "����", 32, 45, LIGHTRED);
		break;
	case 6:
		setfillstyle(1, WHITE);
		bar(40, 400, 160, 470);
		setcolor(LIGHTMAGENTA);
		rectangle(40, 400, 160, 470);//��ҳ��
		puthz(60, 420, "��ҳ", 32, 50, LIGHTMAGENTA);
		break;
	default:
		closegraph();
		printf("something runs wrong in recoverbutton");
		exit(1);
	}
}