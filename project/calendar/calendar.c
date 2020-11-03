#include <stdio.h>
#include<string.h>
int isyoon(int);

int main() {
	int year; // ����� �Է� ����
	int month; // ����� �Է� ����
	int i; // for���� ����
	int j; // for���� ����
	int k; // ����� ����
	int sum = 0; // ������ ��� �� ��� ����
	int chk = 0; // ���� Ȯ�� ����
	int dayLen;
	char day[31][100][100];
	int n; //��¥
	int m;  //����
	int c;
	int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // �⺻ 1~12�� �ϼ�
	printf("����� ��,�� �Է� ex)2018 03 : ");
	scanf("%d %d", &year, &month);


	//�˰���

	//���� Ȯ��
	if (isyoon(year)) {
		chk = 1;
		basicyear[1]++;
	}
	else
		chk = 0;

	//0����� �۳���� ��ĥ���� ��
	sum = 365;
	for (i = 1; i < year; i++) {
		if (isyoon(i))
			sum += 366;
		else
			sum += 365;
	}

	//�Է��� �ޱ��� ��ĥ���� 
	for (i = 0; i < month - 1; i++) {
		sum += basicyear[i];
	}

	//1��1�� ���� �������� ���
	k = sum % 7;

	//���
	printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
	printf("===================================================\n");

	//���� ���Ͽ� ���� ����
	for (j = 0; j < k; j++) {
		printf("\t");
	}

	for (i = 1; i <= basicyear[month - 1]; i++) {

		printf("%d\t", i);
		if (k == 6) {
			k = -1;
			printf("\n");
		}
		k++;
	}
	printf("\n");
	dayLen = sizeof(day) / sizeof(int);

	while (1) {
		printf("��¥ �Է�(�Է� ��Ҵ� 0) : ");
		scanf("%d", &n);
		if (n == 0)
			break;

		int c = 0;
		for (m = 0; ; m++, c++) {
			printf("���� �Է�(�Է� ��Ҵ� stop) : ");
			scanf("%s", &day[n + 1][m]);
			if (!strcmp(day[n + 1][m], "stop"))
				break;
		}
		printf("���� ���\n");

		for (m = 0; m<c; m++)
			printf("%s\n", day[n + 1][m]);
	}
	return 0;
}

int isyoon(int a) {
	if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}