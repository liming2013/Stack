#include"public.h"

void show_history(int* page, USER* u,char*vn)
{
	int num = 0;
	int label;//��¼��ǰҳ
	int label2=1;//���ڷ�ҳ�ж�
	char test[10]="\0";
	int q;
	FILE* fp1=NULL;
	FILE* fp2=NULL;
	int len;
	HIS* bh;
	int k;
	int j;
	int ab=100;
	char STK_ADR6[50]= { '\0' };
	clrmous(MouseX, MouseY);
	delay(100);
	
	strcat(STK_ADR6, "Database\\USER\\");
	strcat(STK_ADR6, u->user);
	strcat(STK_ADR6, "\\history.dat");
	if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//�������ݿ�
	{
		printf("cannot open file");
		delay(3000);
		exit(1);
	}
	fseek(fp1, 0, SEEK_END);
	len = ftell(fp1) / sizeof(HIS);
	label=(len-1)/10+1;
	q=len%10;

	cleardevice();//�⺯��
	base_draw_history(fp1, len,label,label2);
	base_draw_my_history(u);
/*	if (fclose(fp1) != 0)
	{
		printf("\n cannot close Database.");
		delay(3000);
		exit(1);
	}
	*/
	
	
	while (1)
	{
		/*itoa(q,test,10);
		outtextxy(0,0,test);*/
		
		
		newmouse(&MouseX, &MouseY, &press);
		if(label2*10<=len)
		{
			j=10;
		}
		if(label2*10>len)
		{
			j=q;
		}
	
		
		for (k = 0; k <j ; k++)
		{

			
			if (MouseX > 24 * 3 && MouseX < 24 * 4 * 4 + 25 + 24 && MouseY>k * 27 && MouseY < k * 27 + 24)
			{
				
				if (mouse_press(24 * 3, k * 27, 24 * 4 * 4 + 25 + 24, k * 27 + 24) == 2)
				{
					if (num == 0)
					{
						MouseS = 1;
						//fp1 = fopen(STK_ADR6, "rb+");
						base_history_lightbutton_login_information(24 * 3, k * 27, 24 * 4 * 4 + 25 + 24, k * 27 + 24, WHITE, RED, 3, fp1,len,label,label2,q);//color1Ϊ����ɫ��color2Ϊ���ɫ

						
						num = 3;
						ab = k;
					}

					continue;
				}
				else if (mouse_press(24 * 3, k * 27, 24 * 4 * 4 + 24 + 25, k * 27 + 24) == 1)
				{
					if ((bh = (HIS*)malloc(sizeof(HIS))) == NULL)
					{
						printf("memoryallocation runs wrong in lgfunc.c");
						exit(1);
					}
					/*if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//�������ݿ�
					{
						printf("cannot open file");
						delay(3000);
						exit(1);
					}*/
					fseek(fp1, (len-k-1-5*(label2-1)) * sizeof(HIS), SEEK_SET);
					fread(bh, sizeof(HIS), 1, fp1);//ÿ�ζ�һ����
					MouseS = 0;
					strcpy(vn, bh->name);
					strcpy(vn, bh->name);
					strcpy(vn, bh->name);
					strcpy(vn, bh->name);
					strcpy(vn, bh->name);
					strcpy(vn, bh->name);
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;
					*page = 4;

					if (bh != NULL)
					{
						free(bh);
						bh = NULL;
					}
					if (fclose(fp1) != 0)
					{
						printf("\n cannot close Database.");
						delay(3000);
						exit(1);
					}
					
					return;
				}
				
				
			}
		}
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX > 420+20+10 && MouseX < 530+20+10 && MouseY>300 && MouseY < 350)//������ҳ�ж�
		{
			if (mouse_press(420+20+10, 300, 530+20+10, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_history_lightbutton_login_information(420+20+10, 300, 530+20+10, 350, WHITE, RED, 4,fp2,len,label,label2,q);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 4;
				}
				continue;
			}
			else if (mouse_press(420+20+10, 300, 530+20+10, 350) == 1)
			{
				MouseS = 0;
				if (fclose(fp1) != 0)
				{
					printf("\n cannot close Database.");
					delay(3000);
					exit(1);
				}
				*page = 3;//����Ĭ��0��ҳ
				return;
			}
		}

		if (MouseX > 420+20+10-250-25 && MouseX < 530+20+10-250-25 && MouseY>300 && MouseY < 350)//��һҳ�ж�
		{
			if (mouse_press(420+20+10-250-25, 300, 530+20+10-250-25, 350) == 2)
			{
				if (num == 0)
				{
					if(label2!=1)
					{
						MouseS = 1;
						base_history_lightbutton_login_information(420+20+10-250-25, 300, 530+20+10-250-25, 350, WHITE, RED, 5,fp2,len,label,label2,q);//color1Ϊ����ɫ��color2Ϊ���ɫ
						num = 5;
					}
					
				}
				continue;
			}
			else if (mouse_press(420+20+10-250-25, 300, 530+20+10-250-25, 350) == 1)
			{
				if(label2!=1)
				{
					clrmous(MouseX, MouseY);
					delay(100);
					cleardevice();//�⺯��
					
					/*if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//�������ݿ�
					{
						printf("cannot open file");
						delay(3000);
						exit(1);
					}*/
					label2-=1;
					base_draw_history(fp1, len,label,label2);
					base_draw_my_history(u);
					/*if (fclose(fp1) != 0)
					{
						printf("\n cannot close Database.");
						delay(3000);
						exit(1);
					}*/
					
				}
			}
		}
		
		if (MouseX > 420+20+10-125 && MouseX < 530+20+10-125 && MouseY>300 && MouseY < 350)//��һҳ�ж�
		{
			if (mouse_press(420+20+10-125, 300, 530+20+10-125, 350) == 2)
			{
				if (num == 0)
				{
					if(label!=1&&label2!=label)
					{
						MouseS = 1;
						base_history_lightbutton_login_information(420+20+10-125, 300, 530+20+10-125, 350, WHITE, RED, 6,fp2,len,label,label2,q);//color1Ϊ����ɫ��color2Ϊ���ɫ
						num = 6;
					}	
				}
				continue;
			}
			else if (mouse_press(420+20+10-125, 300, 530+20+10-125, 350) == 1)
			{
				if(label!=1&&label2!=label)
				{
					clrmous(MouseX, MouseY);
					delay(100);
					cleardevice();//�⺯��
					
					/*if ((fp1 = fopen(STK_ADR6, "rb+")) == NULL)//�������ݿ�
					{
						printf("cannot open file");
						delay(3000);
						exit(1);
					}*/
					label2+=1;
					base_draw_history(fp1, len,label,label2);
					
					base_draw_my_history(u);
					/*if (fclose(fp1) != 0)
					{
						printf("\n cannot close Database.");
						delay(3000);
						exit(1);
					}*/
					
				}
			}
		}

		if (MouseX > 25 && MouseX < 110+25 && MouseY>300 && MouseY < 350)//�༭�ж�
		{
			if (mouse_press(25, 300, 110+25, 350) == 2)
			{
				if (num == 0)
				{
					MouseS = 1;
					base_history_lightbutton_login_information(25, 300, 110+25, 350, WHITE, RED, 7,fp2,len,label,label2,q);//color1Ϊ����ɫ��color2Ϊ���ɫ
					num = 7;
				}
				continue;
			}
			else if (mouse_press(25, 300, 110+25, 350) == 1)
			{
				MouseS = 0;
				*page = 21;//����Ĭ��0��ҳ
				return;
			}
		}

		if (MouseX > 24 * 3 && MouseX < 24 * 4 * 4 + 25 + 24 && MouseY>ab * 27 && MouseY < ab * 27 + 24)
		{
			if (mouse_press(24 * 3, ab * 27, 24 * 4 * 4 + 25 + 24, ab * 27 + 24) == 2)
			{
				continue;
			}
		}
		
		if (num != 0)//�����ָ�
		{
			if (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7)
			{
				//fp1 = fopen(STK_ADR6, "rb+");
				base_history_recoverbutton_login_information(num, fp1, ab,len,label,label2,q);//�ָ�
			}
			num = 0;
		}


		
		
		if (MouseS != 0)
			MouseS = 0;
		

		
	}
}
void base_draw_history(FILE* fp1, int len,int label,int label2)
{
	int i;
	int j=0;
	HIS* bh;
	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);//blibliͼ��
	settextstyle(0, 0, 3);
	if (( bh= (HIS*)malloc(sizeof(HIS))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			exit(1);
		}
	for (i=0; i < 10; i++)
	{
		j+=1;
		setbkcolor(WHITE);
		setcolor(WHITE);//outtext����ɫ
		settextstyle(0, 0, 3);

		/*setbkcolor(WHITE);
		setcolor(LIGHTMAGENTA);//outtext����ɫ*/

		setfillstyle(1, LIGHTMAGENTA);//bar����ɫ

		
		//puthz(425, 315, "����", 24, 4 + 24, WHITE);
		
		if(len-i-1-(label2-1)*10<0)
		{
			break;
		}
		fseek(fp1, (len-i-1-(label2-1)*10) * sizeof(HIS), SEEK_SET);
		fread(bh, sizeof(HIS), 1, fp1);//ÿ�ζ�һ����

		bar(24 * 3, i * 27, 24 * 4 * 4 + 25+24, i * 27+24);//����
		puthz(24 * 3, i*27, "����", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 2, i*27, "�ۿ���", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 3+50, i*27, "ʱ", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 4+25, i*27, "��", 24, 24 + 4, WHITE);


		outtextxy(50 + 24 * 3+5, i*27, bh->name);//
		outtextxy(90 + 24 * 4 * 2, i*27, bh->now_hour);//
		outtextxy(30 + 24 * 4 * 3+50, i*27, bh->now_min);//

		setcolor(RED);//blibliͼ��

		rectangle(24 * 3, i * 27, 24 * 4 * 4 + 25+26, i * 27 + 24);
		/*strcpy(all_name[i], bh->name);
		strcpy(all_name[i+20], bh->now_hour);
		strcpy(all_name[i+20*2], bh->now_min);*/
		
		if(j==10)
		{
			break;
		}
		
		
	}
	if (bh != NULL)
		{
			free(bh);
			bh = NULL;
		}

	

}
void base_draw_my_history(USER* u)
{

	setbkcolor(WHITE);
	setcolor(LIGHTMAGENTA);//outtext����ɫ

	setfillstyle(1, LIGHTMAGENTA);//bar����ɫ
	
	bar(25, 300, 25+110, 350);//����
	puthz(25, 315, "�༭", 24, 4 + 24+10, WHITE);
	
	bar(420+20+10-250-25, 300, 530+20+10-250-25, 350);//��һҳ
	puthz(425+20+10-250-25, 315, "��һҳ", 24, 4 + 24+10, WHITE);
	
	bar(420+20+10-125, 300, 530+20+10-125, 350);//��һҳ
	puthz(425+20+10-125, 315, "��һҳ", 24, 4 + 24+10, WHITE);
	
	

	bar(420+20+10, 300, 530+20+10, 350);//����
	puthz(425+20+10, 315, "����", 24, 4 + 24+10, WHITE);

}

void base_history_lightbutton_login_information(int x, int y, int x1, int y1, int color1, int color2, int flag, FILE* fp1,int len,int label,int label2,int q)//��ť����
{
	int i;
	HIS* bh;

	i = y / 27;
	
	
	clrmous(MouseX, MouseY);
	delay(10);
	setcolor(color1);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setfillstyle(1, color2);
	bar(x, y, x1, y1);
	rectangle(x, y, x1, y1);	//���߿�

	switch (flag)
	{
	case 1:
		break;
	case 2:
		puthz(425, 115, "�Ժ��ٿ�", 24, 4 + 24, WHITE);
		break;
	case 3:
		if ((bh = (HIS*)malloc(sizeof(HIS))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			exit(1);
		}
		fseek(fp1, (len-i-1-(label2-1)*10) * sizeof(HIS), SEEK_SET);
		fread(bh, sizeof(HIS), 1, fp1);//ÿ�ζ�һ����
		//i=9-i;
		
		puthz(24 * 3, i * 27, "����", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 2, i * 27, "�ۿ���", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 3 + 50, i * 27, "ʱ", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 4 + 25, i * 27, "��", 24, 24 + 4, WHITE);


		outtextxy(50 + 24 * 3 + 5, i * 27, bh->name);//
		outtextxy(90 + 24 * 4 * 2, i * 27, bh->now_hour);//
		outtextxy(30 + 24 * 4 * 3 + 50, i * 27, bh->now_min);//


		if (bh != NULL)
		{
			free(bh);
			bh = NULL;
		}

		/*if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}*/

		break;
	case 4:
		puthz(425+20+10, 315, "����", 24, 4 + 24+10, WHITE);
		break;
	case 5:
		puthz(425+20+10-250-25, 315, "��һҳ", 24, 4 + 24+10, WHITE);
		break;
	case 6:
		puthz(425+20+10-125, 315, "��һҳ", 24, 4 + 24+10, WHITE);
		break;
		
	case 7:
		puthz(25, 315, "�༭", 24, 4 + 24+10, WHITE);
		break;
	default:
		closegraph();
		printf("something runs wrong in lightbutton");
		exit(1);
	}

}


void base_history_recoverbutton_login_information(int status, FILE* fp1,int i,int len,int label,int label2,int q)//�ָ�
{
	HIS* bh;


	clrmous(MouseX, MouseY);
	switch (status)
	{
	
		break;
	case 3://�ҵĶ�̬�ָ�
		if ((bh = (HIS*)malloc(sizeof(HIS))) == NULL)
		{
			printf("memoryallocation runs wrong in lgfunc.c");
			exit(1);
		}
		fseek(fp1, (len-i-1-10*(label2-1)) * sizeof(HIS), SEEK_SET);
		fread(bh, sizeof(HIS), 1, fp1);//ÿ�ζ�һ����
		setcolor(WHITE);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		//i=9-i;
		/*if(label!=label2)
		{
			i=9-i;
		}
		if(label==label2)
		{
			i=q-i-1;
		}*/
		bar(24 * 3, i * 27, 24 * 4 * 4 + 25 + 24, i * 27 + 24);

		puthz(24 * 3, i * 27, "����", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 2, i * 27, "�ۿ���", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 3 + 50, i * 27, "ʱ", 24, 24 + 4, WHITE);
		puthz(24 * 4 * 4 + 25, i * 27, "��", 24, 24 + 4, WHITE);


		outtextxy(50 + 24 * 3 + 5, i * 27, bh->name);//
		outtextxy(90 + 24 * 4 * 2, i * 27, bh->now_hour);//
		outtextxy(30 + 24 * 4 * 3 + 50, i * 27, bh->now_min);//


		if (bh != NULL)
		{
			free(bh);
			bh = NULL;
		}

		/*if (fclose(fp1) != 0)
		{
			printf("\n cannot close Database.");
			delay(3000);
			exit(1);
		}*/
		break;
	case 4://���ػָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420+20+10, 300, 530+20+10, 350);
		puthz(425+20+10, 315, "����", 24, 28+10, WHITE);
		break;
	case 5://��һҳ�ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420+20+10-250-25, 300, 530+20+10-250-25, 350);
		puthz(425+20+10-250-25, 315, "��һҳ", 24, 28+10, WHITE);
		break;
	case 6://��һҳ�ָ�
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(420+20+10-125, 300, 530+20+10-125, 350);
		puthz(425+20+10-125, 315, "��һҳ", 24, 28+10, WHITE);
		break;
	
	case 7://�༭
		setcolor(LIGHTMAGENTA);
		setfillstyle(1, LIGHTMAGENTA);
		setlinestyle(SOLID_LINE, 0, 1);
		bar(25, 300, 25+110, 350);
		puthz(25, 315, "�༭", 24, 28+10, WHITE);
		break;
		
	}
}