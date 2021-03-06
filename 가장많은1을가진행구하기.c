﻿//2차원배열의 각행들중 가장많은 1을 갖고잇는 행구하기 
//# 모든 배열의 원소는 1또는 0으로 구성되어잇다 
//# 각행들은 1을 좌측정렬되어잇다 

//1번째 방법 2중 for문으로 각행을 싹 확인후 1의 개수 구해서 최대값 구하기 
//O(N^2)시간을 갖는다 
/*
#include<stdio.h>
int main() {
	int arr[10][10] = {
		{1,1,1,1,1,1,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0},
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,0},
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0}
	};
	int max = -1, maxrow = 0;
	for (int i = 0; i < 10; i++) {
		int c = 0;
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == 1) {
				c++;
			}
			else {
				break;
			}
		}
		if (max < c) {
			max = c;
			maxrow = i;
		}
	}
	printf("%d %d",max , maxrow);


	return 0;
}
*/

//2번째 방법 전체 행을 0번째부터 확인하는게아닌 
// 이전에 검사햇던 행들중 가장 1을 많이갖는 행의 가장 오른쪽에잇는 1의 인덱스 +1 번부터 검사 

// #어차피 1을 가장많이 갖는거를 찾는거라 굳이 모든 행들의 0번째부터 검사할필요가없다 
// # 실행시간이 O(n)으로 대폭 감소한다.
// # 코드 길이까지 대폭감소한다 .
// # ver1 은 한행에서도 원소가 1일때마다 row를 바꿔주고  ver2,ver3는 한행에대해서는 카운트를 다하고 마지막에 넣어준다.
// # ver1,ver2,ver3는 기본적인 논리는 동일하다
#include<stdio.h>
int ver1(int(*)[10]);
int ver2(int(*)[10]);
int ver3(int(*)[10]);
int main() {
	int arr[10][10] = {
		{1,1,1,1,1,1,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0},
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,0,0},
		{1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{1,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,0},
		{1,1,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,0,0,0}
	};
	printf("ver1 : %d\n", ver1(arr));
	printf("ver2 : %d\n", ver2(arr));
	printf("ver3 : %d\n", ver3(arr));

	return 0;
}
int ver1(int(*arr)[10]) {
	int j = 0, row = 0, c = 0;
	for (int i = 0; i < 10; i++) {
		for (; j < 10; j++) {
			c++;
			if (arr[i][j] == 0) break;
			else row = i;
		}
		if (j == 10) {
			printf("ver1 실행횟수: %d\n", c);
			return row;
		}
	}
	printf("ver1 실행횟수: %d\n", c);
	return row;
}
int ver2(int(*arr)[10]) {
	int i = 0, j = 0, c = 0, row;
	while (1) {
		while (arr[i][j] == 1) {
			c++;
			j++;
			if (j == 10) {
				printf("ver2 반복횟수: %d\n", c);
				return i;
			}
		}
		row = i;
		while (arr[i][j] == 0) {
			c++;
			i++;
			if (i == 10) {
				printf("ver2 반복횟수: %d\n", c);
				return row;
			}
		}
	}
}
int ver3(int(*arr)[10]) {
	int i = 0, j = 0, row = 0, c = 0;
	while ((i < 10) && (j < 10)) {
		c++;
		if (arr[i][j] == 0) i++;
		else {
			row = i;
			j++;
		}
	}
	printf("ver3 반복횟수: %d\n", c);

	return row;
}