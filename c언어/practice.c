
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
	movie spiderman = { {0,0},{0},"2 시간 5 분" };
	movie aladin = { {0,0},{0},"2 시간 8 분" };
	movie johnwick3 = { {0,0},{0},"2 시간 11 분" };
	
	select:
	printf("사용하실 기능을 고르시오\n1. 영화추천받기 2.영화예매하기 3.예매확인 4.기계종료\n");
	scanf("%d", &num1);
	scanf("%c", &ch);
	if (num1 != 1 && num1 != 2&&num1!=3 && num1 != 4) {
		printf("1,2,3,4만 입력하실수 있습니다.\n");
		goto select;
	}
	system("cls");
	//영화 추천받기
	if (num1 == 1)
	{
		while (1) {
			printf("당신의 연령대를 선택하시오\n");
			printf("1. 20대 미만    2. 20대이상 40대 미만   3. 40대 이상\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 || choice == 3) {
				rcm = rcm + choice * 100;
				break;
			}
			printf("오류!!!! 보기중에 숫자를 고르시오\n");
		}
		while (1) {
			printf("좋아하는 장르를 고르시오\n");
			printf("1. 멜로    2. 액션   3. 코미디   4.교육\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 || choice == 3||choice==4) {
				rcm = rcm + choice * 10;
				break;
			}
			printf("오류!!!! 보기중에 숫자를 고르시오\n");
		}
		while (1) {
			printf("해외영화?  국내영화?\n");
			printf("1. 해외영화    2. 국내영화\n");
			scanf("%d", &choice);
			if (choice == 1 || choice == 2 ) {
				rcm = rcm + choice;
				break;
			}
			printf("오류!!!! 보기중에 숫자를 고르시오\n");
		}

		system("cls");
		movierecommend(rcm);
		printf("\n");
		goto select;
		




	}
	//영화 예매하기
	int m,f;
	movie* mp=NULL;
	
	if (num1 == 2) {
		printf("지금 상영중인 영화 \n***스파이더맨 파 프롬홈***\n***알라딘***\n***존 윅 3***\n");
		printf(LINE);
		printf("어떤 영화를 예매 하시겠습니까?\n1.스파이더맨\n2.알라딘\n3.존윅3\n");
		scanf("%d",&f);
		system("cls");
		//스파이더맨 예매
		switch (f)
		{
			case 1 :
			mp = &spiderman;
			printf("***********스파이더맨 예매**************\n\n\n 원하시는 시간을 선택하세요\n");
			printf("1. 7:50분 (7관) 2D\t");
			printf("남은 좌석:  %d\n", 50-spiderman.count[0]);
			printf("2. 11:30분 (8관) 4D\t");
			printf("남은 좌석:  %d\n", 50-spiderman.count[1]);

			scanf("%d", &m);
			scanf("%c", &ch);
			moviereserve(m-1,mp,f*m+6);

			break;
			case 2:
				mp = &aladin;
				printf("************알라딘 예매**************\n\n\n 원하시는 시간을 선택하세요\n");
				printf("1. 7:50분 (2관) 2D\t");
				printf("남은 좌석:  %d\n", 50 - aladin.count[0]);
				printf("2. 11:30분 (4관) 4D\t");
				printf("남은 좌석:  %d\n", 50 - aladin.count[1]);

				scanf("%d", &m);
				scanf("%c", &ch);
				moviereserve(m - 1, mp,f*m);
				break;
			case 3:
				mp = &johnwick3;
				printf("*************존윅3 예매**************\n\n\n 원하시는 시간을 선택하세요\n");
				printf("1. 7:50분 (3관) 2D\t");
				printf("남은 좌석:  %d\n", 50 - johnwick3.count[0]);
				printf("2. 11:30분 (6관) 4D\t");
				printf("남은 좌석:  %d\n", 50 - johnwick3.count[1]);

				scanf("%d", &m);
				scanf("%c", &ch);
				moviereserve(m - 1, mp, f* m);
				break;

		}
		
		printf("[예매완료]  예매정보를 확인하세요!!\n");
		goto select;




	}
	char reservename[20];
	char reservephone[30];
	//예매확인
	
	if (num1 == 3) {

		printf("어떤 영화를 예매 하셨습니까?\n1.스파이더맨\n2.알라딘\n3.존윅3\n");
		scanf("%d", &f);
		switch (f) {
		case 1:
			scanf("%c", &ch);
			printf("예매자번호를 입력하시오: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(spiderman.tickets[i][j].phonenum, reservephone) == 0)
						goto complete;
					else goto none;
				}

			}
		
		complete:
			printf("예매자:%s\n영화시작 시간:%s\n%d관%d번째자리\nruntime:%s\n", spiderman.tickets[i][j].name, spiderman.tickets[i][j].time, spiderman.tickets[i][j].cinema, spiderman.tickets[i][j].seatnum, spiderman.runtime);
			break;
		case 2:
			scanf("%c", &ch);
			printf("예매자번호를 입력하시오: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(aladin.tickets[i][j].phonenum, reservephone) == 0)
						goto complete2;
					else goto none;
				}

			}
			
		complete2:
			printf("예매자:%s\n영화시작 시간:%s\n%d관%d번째자리\nruntime:%s\n", aladin.tickets[i][j].name, aladin.tickets[i][j].time, aladin.tickets[i][j].cinema, aladin.tickets[i][j].seatnum, aladin.runtime);
			break;
		case 3:
			scanf("%c", &ch);
			printf("예매자번호를 입력하시오: ");
			scanf("%s", reservephone);
			for (i = 0; i < 2; i++) {
				for (j = 0; j < 50; j++) {
					if (strcmp(johnwick3.tickets[i][j].phonenum, reservephone) == 0)
						goto complete3;
					else goto none;
				}

			}
			
		complete3:
			printf("예매자:%s\n영화시작 시간:%s\n%d관%d번째자리\nruntime:%s\n", johnwick3.tickets[i][j].name, johnwick3.tickets[i][j].time, johnwick3.tickets[i][j].cinema, johnwick3.tickets[i][j].seatnum, johnwick3.runtime);
			break;
		}
		goto select;
		none:
		printf("예매정보가 없습니다.\n");

		goto select;






	}
	
	
	
	
	
	
	if (num1 == 4)
		exit(1);










}

//영화추천 함수
void movierecommend(int a)
{
	switch (a)
	{
	case 111: printf("***********추천영화*************\n");
		printf("영화명:  알라딘\n평점 :  9.45/10\n상영여부:  o\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=163788&mid=41880#tab");
		break;
	case 112: printf("***********추천영화*************\n");
		printf("영화명:  소나기\n평점 :  7.04/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=158181&mid=35625#tab");
		break;
	case 121: printf("***********추천영화*************\n");
		printf("영화명:  드래곤 길들이기3\n평점 :  9.25/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=109193&mid=40957#tab");
		break;
	case 122: printf("***********추천영화*************\n");
		printf("영화명:  점박이 한반도의 공룡2\n평점 :  9.16/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=180379&mid=40728#tab");
		break;
	case 131: printf("***********추천영화*************\n");
		printf("영화명:  구스 베이비\n평점 :  9.06/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=149278&mid=41029#tab");
		break;
	case 132: printf("***********추천영화*************\n");
		printf("영화명:  슈퍼 빼꼼:스파이 대작전\n평점 :  8.15/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=94183&mid=34357#tab");
		break;
	case 141: printf("***********추천영화*************\n");
		printf("영화명:  토이 스토리3\n평점 :  9.38/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=66463&mid=12404#tab");
		break;
	case 142: printf("***********추천영화*************\n");
		printf("영화명:  언더독\n평점 :  9.47/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=144318&mid=41075#tab");
		break;
	case 211: printf("***********추천영화*************\n");
		printf("영화명:  어바웃 타임\n평점 :  9.22/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=92075&mid=22030#tab");
		break;
	case 212: printf("***********추천영화*************\n");
		printf("영화명:  뷰티 인사이드\n평점 :  8.25/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=129050&mid=27694#tab");
		break;
	case 221: printf("***********추천영화*************\n");
		printf("영화명:  스파이더맨: 파 프롬홈\n평점 :  9.05/10\n상영여부:  o\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=173123&mid=42823#tab");
		break;
	case 222: printf("***********추천영화*************\n");
		printf("영화명:  아저씨\n평점 :  9.23/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=71509&mid=13246#tab");
		break;
	case 231: printf("***********추천영화*************\n");
		printf("영화명:  프린세스 다이어리\n평점 :  8.09/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=38739&mid=3409#tab");
		break;
	case 232: printf("***********추천영화*************\n");
		printf("영화명:  극한직업\n평점 :  9.20/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=167651&mid=40949#tab");
		break;
	case 241: printf("***********추천영화*************\n");
		printf("영화명:  세 얼간이\n평점 :  9.34/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=73372&mid=32318#tab");
		break;
	case 242: printf("***********추천영화*************\n");
		printf("영화명:  걷기왕\n평점 :  8.52/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=145804&mid=32048#tab");
		break;
	case 311: printf("***********추천영화*************\n");
		printf("영화명:  미 비포 유\n평점 :  8.78/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=137915&mid=30445#tab");
		break;
	case 312: printf("***********추천영화*************\n");
		printf("영화명:  오직 그대만\n평점 :  9.12/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=82219&mid=16184#tab");
		break;
	case 321: printf("***********추천영화*************\n");
		printf("영화명:  존윅 3: 파라벨룸\n평점 :  8.67/10\n상영여부:  o\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=181698&mid=42713#tab");
		break;
	case 322: printf("***********추천영화*************\n");
		printf("영화명:  강철비\n평점 :  8.73/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=155665&mid=36785#tab");
		break;
	case 331: printf("***********추천영화*************\n");
		printf("영화명:  마카담 스토리\n평점 :  8.66/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=139488&mid=29444#tab");
		break;
	case 332: printf("***********추천영화*************\n");
		printf("영화명:  수상한 그녀\n평점 :  9.09/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=107924&mid=22491#tab");
		break;
	case 341: printf("***********추천영화*************\n");
		printf("영화명:  위플래쉬\n평점 :  8.87/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=119632&mid=26076#tab");
		break;
	case 342: printf("***********추천영화*************\n");
		printf("영화명:  생일\n평점 :  9.02/10\n상영여부:  x\n예고편 사이트:https://movie.naver.com/movie/bi/mi/mediaView.nhn?code=174050&mid=41704#tab");
		break;
	

	}







}
//영화 예약 함수

void moviereserve(int a,movie * kk,int b)//b=cinema받기
{
	
	printf("예매자명을 입력하시오:   ");
	scanf("%s", (kk->tickets[a][kk->count[a]]).name);
	printf("예매자 전화번호를 입력하시오(-없이 숫자만 입력!!!):    ");
	scanf("%s", (kk->tickets[a][kk->count[a]]).phonenum);
	(kk->tickets[a][kk->count[a]]).cinema = b;
	(kk->tickets[a][kk->count[a]]).seatnum = (kk->count[a]) + 1;
	if (a == 0)
		strcpy((kk->tickets[a][kk->count[a]]).time, "7시50분");
	 else
		strcpy((kk->tickets[a][kk->count[a]]).time, "11시50분");
	(kk->count[a])++;


}