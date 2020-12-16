
#pragma warning(disable:4996)	
#include <stdio.h>
#include <process.h>
#define LINE "\n====================================================\n\n"
#include <string.h>
void movierecommend(int a);


typedef struct ticket {
	char name[20];
	char phonenum[20];
	char time[30];
	int seatnum;
	int cinema;
	


}ticket;
typedef struct movie {
	int count[2] ;
	struct ticket tickets[2][50];
	char runtime[30];
	


}movie;

void moviereserve(int a, movie* kk,int b);


void main(void)
{
	int num1,i,j,choice;
	int rcm=0;
	char ch;
	movie spiderman = { {0,0},{0},"2 �ð� 5 ��" };
	movie aladin = { {0,0},{0},"2 �ð� 8 ��" };
	movie johnwick3 = { {0,0},{0},"2 �ð� 11 ��" };
	
	select:
	printf("����Ͻ� ����� ���ÿ�\n1. ��ȭ��õ�ޱ� 2.��ȭ�����ϱ� 3.����Ȯ�� 4.�������\n");
	scanf("%d", &num1);
	scanf("%c", &ch);
	if (num1 != 1 && num1 != 2&&num1!=3 && num1 != 4) {
		printf("1,2,3,4�� �Է��ϽǼ� �ֽ��ϴ�.\n");
		goto select;
	}
	system("cls");
	//��ȭ ��õ�ޱ�
	if (num1 == 1)
	{
		while (1) {
			printf("����� ���ɴ븦 �����Ͻÿ�\n");
			printf("1. 20�� �̸�    2. 20���̻� 40�� �̸�   3. 40�� �̻�\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 || choice == 3) {
				rcm = rcm + choice * 100;
				break;
			}
			printf("����!!!! �����߿� ���ڸ� ���ÿ�\n");
		}
		while (1) {
			printf("�����ϴ� �帣�� ���ÿ�\n");
			printf("1. ���    2. �׼�   3. �ڹ̵�   4.����\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 || choice == 3||choice==4) {
				rcm = rcm + choice * 10;
				break;
			}
			printf("����!!!! �����߿� ���ڸ� ���ÿ�\n");
		}
		while (1) {
			printf("�ؿܿ�ȭ?  ������ȭ?\n");
			printf("1. �ؿܿ�ȭ    2. ������ȭ\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 ) {
				rcm = rcm + choice;
				break;
			}
			printf("����!!!! �����߿� ���ڸ� ���ÿ�\n");
		}

		system("cls");
		movierecommend(rcm);
		printf("\n");
		goto select;
		




	}
	//��ȭ �����ϱ�
	int m,f;
	movie* mp=NULL;
	
	if (num1 == 2) {
		printf("���� ������ ��ȭ \n***�����̴��� �� ����Ȩ***\n***�˶��***\n***�� �� 3***\n");
		printf(LINE);
		printf("� ��ȭ�� ���� �Ͻðڽ��ϱ�?\n1.�����̴���\n2.�˶��\n3.����3\n");
		scanf("%d",&f);
		system("cls");
		//�����̴��� ����
		switch (f)
		{
			case 1 :
			mp = &spiderman;
			printf("***********�����̴��� ����**************\n\n\n ���Ͻô� �ð��� �����ϼ���\n");
			printf("1. 7:50�� (7��) 2D\t");
			printf("���� �¼�:  %d\n", 50-spiderman.count[0]);
			printf("2. 11:30�� (8��) 4D\t");
			printf("���� �¼�:  %d\n", 50-spiderman.count[1]);

			scanf("%d", &m);
			scanf("%c", &ch);
			moviereserve(m-1,mp,f*m+6);

			break;
			case 2:
				mp = &aladin;
				printf("************�˶�� ����**************\n\n\n ���Ͻô� �ð��� �����ϼ���\n");
				printf("1. 7:50�� (2��) 2D\t");
				printf("���� �¼�:  %d\n", 50 - aladin.count[0]);
				printf("2. 11:30�� (4��) 4D\t");
				printf("���� �¼�:  %d\n", 50 - aladin.count[1]);

				scanf("%d", &m);
				scanf("%c", &ch);
				moviereserve(m - 1, mp,f*m);
				break;
			case 3:
				mp = &johnwick3;
				printf("*************����3 ����**************\n\n\n ���Ͻô� �ð��� �����ϼ���\n");
				printf("1. 7:50�� (3��) 2D\t");
				printf("���� �¼�:  %d\n", 50 - johnwick3.count[0]);
				printf("2. 11:30�� (6��) 4D\t");
				printf("���� �¼�:  %d\n", 50 - johnwick3.count[1]);

				scanf("%d", &m);
				scanf("%c", &ch);
				moviereserve(m - 1, mp, f* m);
				break;

		}
		
		printf("[���ſϷ�]  ���������� Ȯ���ϼ���!!\n");
		goto select;




	}
	char reservename[20];
	char reservephone[30];
	//����Ȯ��
	
	if (num1 == 3) {

		printf("� ��ȭ�� ���� �ϼ̽��ϱ�?\n1.�����̴���\n2.�˶��\n3.����3\n");
		scanf("%d", &f);
		switch (f) {
		case 1:
			scanf("%c", &ch);
			printf("�����ڹ�ȣ�� �Է��Ͻÿ�: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(spiderman.tickets[i][j].phonenum, reservephone) == 0)
						goto complete;
					else goto none;
				}

			}
		
		complete:
			printf("������:%s\n��ȭ���� �ð�:%s\n%d��%d��°�ڸ�\nruntime:%s\n", spiderman.tickets[i][j].name, spiderman.tickets[i][j].time, spiderman.tickets[i][j].cinema, spiderman.tickets[i][j].seatnum, spiderman.runtime);
			break;
		case 2:
			scanf("%c", &ch);
			printf("�����ڹ�ȣ�� �Է��Ͻÿ�: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(aladin.tickets[i][j].phonenum, reservephone) == 0)
						goto complete2;
					else goto none;
				}

			}
			
		complete2:
			printf("������:%s\n��ȭ���� �ð�:%s\n%d��%d��°�ڸ�\nruntime:%s\n", aladin.tickets[i][j].name, aladin.tickets[i][j].time, aladin.tickets[i][j].cinema, aladin.tickets[i][j].seatnum, aladin.runtime);
			break;
		case 3:
			scanf("%c", &ch);
			printf("�����ڹ�ȣ�� �Է��Ͻÿ�: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(johnwick3.tickets[i][j].phonenum, reservephone) == 0)
						goto complete3;
					else goto none;
				}

			}
			
		complete3:
			printf("������:%s\n��ȭ���� �ð�:%s\n%d��%d��°�ڸ�\nruntime:%s\n", johnwick3.tickets[i][j].name, johnwick3.tickets[i][j].time, johnwick3.tickets[i][j].cinema, johnwick3.tickets[i][j].seatnum, johnwick3.runtime);
			break;
		}
		goto select;
		none:
		printf("���������� �����ϴ�.\n");

		goto select;






	}
	
	
	
	
	
	
	if (num1 == 4)
		exit(1);










}

//��ȭ��õ �Լ�
void movierecommend(int a)
{
	switch (a)
	{
	case 111: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �˶��\n���� :  9.45/10\n�󿵿���:  o\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=163788&mid=41880#tab");
		break;
	case 112: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �ҳ���\n���� :  7.04/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=158181&mid=35625#tab");
		break;
	case 121: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �巡�� ����̱�3\n���� :  9.25/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=109193&mid=40957#tab");
		break;
	case 122: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ������ �ѹݵ��� ����2\n���� :  9.16/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=180379&mid=40728#tab");
		break;
	case 131: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���� ���̺�\n���� :  9.06/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=149278&mid=41029#tab");
		break;
	case 132: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���� ����:������ ������\n���� :  8.15/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=94183&mid=34357#tab");
		break;
	case 141: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���� ���丮3\n���� :  9.38/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=66463&mid=12404#tab");
		break;
	case 142: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �����\n���� :  9.47/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=144318&mid=41075#tab");
		break;
	case 211: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ��ٿ� Ÿ��\n���� :  9.22/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=92075&mid=22030#tab");
		break;
	case 212: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ��Ƽ �λ��̵�\n���� :  8.25/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=129050&mid=27694#tab");
		break;
	case 221: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �����̴���: �� ����Ȩ\n���� :  9.05/10\n�󿵿���:  o\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=173123&mid=42823#tab");
		break;
	case 222: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ������\n���� :  9.23/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=71509&mid=13246#tab");
		break;
	case 231: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �������� ���̾\n���� :  8.09/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=38739&mid=3409#tab");
		break;
	case 232: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ��������\n���� :  9.20/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=167651&mid=40949#tab");
		break;
	case 241: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �� ����\n���� :  9.34/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=73372&mid=32318#tab");
		break;
	case 242: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �ȱ��\n���� :  8.52/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=145804&mid=32048#tab");
		break;
	case 311: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  �� ���� ��\n���� :  8.78/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=137915&mid=30445#tab");
		break;
	case 312: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���� �״븸\n���� :  9.12/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=82219&mid=16184#tab");
		break;
	case 321: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���� 3: �Ķ󺧷�\n���� :  8.67/10\n�󿵿���:  o\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=181698&mid=42713#tab");
		break;
	case 322: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ��ö��\n���� :  8.73/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=155665&mid=36785#tab");
		break;
	case 331: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ��ī�� ���丮\n���� :  8.66/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=139488&mid=29444#tab");
		break;
	case 332: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ������ �׳�\n���� :  9.09/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=107924&mid=22491#tab");
		break;
	case 341: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ���÷���\n���� :  8.87/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=119632&mid=26076#tab");
		break;
	case 342: printf("***********��õ��ȭ*************\n");
		printf("��ȭ��:  ����\n���� :  9.02/10\n�󿵿���:  x\n������ ����Ʈ:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=174050&mid=41704#tab");
		break;
	

	}







}
//��ȭ ���� �Լ�

void moviereserve(int a,movie * kk,int b)//b=cinema�ޱ�
{
	
	printf("�����ڸ��� �Է��Ͻÿ�:   ");
	scanf("%s", (kk->tickets[a][kk->count[a]]).name);
	printf("������ ��ȭ��ȣ�� �Է��Ͻÿ�(-���� ���ڸ� �Է�!!!):    ");
	scanf("%s", (kk->tickets[a][kk->count[a]]).phonenum);
	(kk->tickets[a][kk->count[a]]).cinema = b;
	(kk->tickets[a][kk->count[a]]).seatnum = (kk->count[a]) + 1;
	if (a == 0)
		strcpy((kk->tickets[a][kk->count[a]]).time, "7��50��");
	 else
		strcpy((kk->tickets[a][kk->count[a]]).time, "11��50��");
	(kk->count[a])++;


}