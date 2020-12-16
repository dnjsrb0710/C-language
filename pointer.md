# Pointer

>## 포인터란?
>- 포인터의 정의는 실행중인 프로세스의 임의의 주소를를 말한다.
>- c언어는 포인터를 이용하여 프로세스의 원하는 영역에 접근될 수 있다. 이를 통해 기계어나 어셈블리 언어처럼 메모리를 직접 조작할 수 있게 된다.

>### 포인터 변수란?
>-  다른 객체(변수)의 메모리 주소를 저장하는 변수를 말한다. 포인터 변수선언은 변수명 앞에 *를 추가하여 선언한다.
> 
```
예:
int *ip; -- 정수형 포인터 변수
char *cp; -- 문자형 포인터 변수
double *dp; -- 실수형 포인터 변수

```

> 포인터 변수는 * , **&** 연산자와 함께 사용할 수 있으며 그 의미는 다음과 같다.
> - &(주소 연산자) : 변수에 할당된 메모리의 시작주소를 반환하는 연산자
> - *(포인터 연산자) : 포인터 변수가 가리키는 곳의 내용을 참조하는 연산자

```
실행 예시 

double dNum, *dp; -- 변수와 포인터 변수 선언

dNum = 7.5;
printf("dNum :%1f, &dNum: %p \n\n, dNum,&dNum);

dp = &dNum; -- 포인터 변수에 변수의 주소 할당
printf("*dp : %1f, dp : %p \n", *dp , dp);


```