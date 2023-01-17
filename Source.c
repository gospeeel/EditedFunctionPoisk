#define _CRT_SECURE_NO_WARNINGS
#include <locale.h> //������������ ���� �����������
#include <stdio.h> //������������ ���� ��� ������� �����/������
#include <stdlib.h> //������������ ���� ����������� ����������
#include <string.h> //������������ ��� ��� ������ �� ��������
#include <malloc.h> //������������ ��������� � ������������ ������
#include <conio.h>//������������ ���� ��� �������� ���������� ���������� ������������

typedef struct pc //���������� ���������
{
	char manufacturer[20], formfactor[20], typesize[20], color[20], availability[20];
	int height, dlina;
	float shirina;

}PC;

int zapis(char* filename, PC* comp, int k);//������ � ����
int chtenie(char* filename);//������ �� �����
int pechat(PC* comp, int k);//����� ���� ������
PC sortirovka(PC* comp, int k);//���������� �� �����
PC dobavlenie(PC* comp, int k);//���������� ������� � �������
int dobavlenie_file(char* filename, PC* comp, int k);//���������� ������� � ����

int main() {
	system("chcp 1251");
	system("cls"); //�������� ������
	setlocale(LC_ALL, "RUS");//�����������
	PC* comp = NULL;//���������
	int k;//���-�� ��������
	int vibor;//����� � ����
	char filename[100];//�������� �����


	//����


	while (1) {
		system("cls");
		printf("1 - ���������� ������� �� � ���� ������ \n"
			"2 - ������ � ���� \n"
			"3 - ������ �� ����� \n"
			"4 - ����� ���������� � �������� ��, ���������� � ���� ������ \n"
			"5 - ���������� �������� �� ����� \n"
			"6 - ����� �������� �� �� ������������� \n"  
			"7 - ����� �������� �� �� �����������\n"
			"8 - ���������� ������� �� � ���� \n"
			"9 - ���������� ������ \n");
		printf("������� ����� ����: ");
		scanf("%d", &vibor);
		system("cls");
		switch (vibor) {
		case 1:
			printf("������� ���������� ��������:");
			scanf("%d", &k);
			comp = realloc(comp, k * sizeof(PC));//��������� ������������ ������ ��� ���������� ����������
			dobavlenie(comp, k);
			//Print(comp, k);
			break;

		case 2:
			printf("������� ��� ����� ��� ������:");
			scanf("%s", &filename);
			zapis(filename, comp, k);
			break;

		case 3:
			printf("������� ��� ����� ��� ������:");
			scanf("%s", &filename);
			chtenie(filename);
			system("pause");
			break;

		case 4:
			pechat(comp, k);
			break;

		case 5:
			sortirovka(comp, k);
			system("pause");
			break;

		case 6:
			poisk_manufacturer(comp, k);
			system("pause");
			break;
		
		case 7:
			poisk_typesize(comp, k);
			system("pause");
			break;

		case 8:
			printf("������� ��� ����� ��� ������:");
			scanf("%s", &filename);
			dobavlenie_file(filename, comp, k);
			break;

		case 9:
			return -1;
			break;

		default:
			puts("������ ����� ���������� �����������");

		}

	}
	free(comp);
	system("pause");
}

int zapis(char* filename, PC* comp, int k)
{
	FILE* f;
	int i;
	if ((f = fopen(filename, "wt")) == NULL)
	{
		fprintf(stderr, "���� ������ ������� ��� ������\n");
		system("pause");
		return -1;
	}

	else
	{
		for (i = 0; i < k; i++)
		{
			fprintf(f, "%2i. �������������: %s \n����-������ �����: %s \n����������: %s \n����: %s \n������: %i \n�����: %i \n������: %.1f \n������� ��������� � ��.: %s \n", i + 1, comp[i].manufacturer, comp[i].formfactor, comp[i].typesize, comp[i].color, comp[i].height, comp[i].dlina, comp[i].shirina, comp[i].availability);
			system("pause");
		}
		fclose(f);
		printf("************************************\n"
			"* ������ ������� �������� � ���� *\n"
			"************************************\n");
		system("pause");
	}
	return 0;
}

int chtenie(char* filename)//������ �� �����
{
	///������ �����
	printf("�������� ������ �����\n");
	FILE* input;
	char file[200];
	input = fopen(filename, "r"); //�������� ����� ��� ������
	if (input != NULL) //�������� �� ������������� � �������� �����
	{
		printf("* ���� ������� ������. *\n");
		while (!feof(input))
		{
			fgets(file, 200, input);
			if (!feof(input))
			{
				puts(file);
			}
		}
		return 1;
	}
	else
	{
		printf("��������� ������� ����\n");
		system("pause");
		return -1;
	}
	fclose(input); //�������� �����
	return 0;
}

PC dobavlenie(PC* comp, int k)//���������� �� �������������
{
	for (int i = 0; i < k; i++)
	{
		//���� � ������� ����������
		printf("������� ������������� ������� ��: ");
		scanf("%s", &comp[i].manufacturer);
		printf("������� ����-������ �����: ");
		scanf("%s", &comp[i].formfactor);
		printf("������� ���������� �������: ");
		scanf("%s", &comp[i].typesize);
		printf("������� ���� �������: ");
		scanf("%s", &comp[i].color);
		printf("������� ������ ������� �� � ��: ");
		scanf("%i", &comp[i].height);
		printf("������� ����� ������� �� � ��: ");
		scanf("%i", &comp[i].dlina);
		printf("������� ������ ������� �� � ��: ");
		scanf("%f", &comp[i].shirina);
		printf("������� ������� ��������� ������� �� � ��.: ");
		scanf("%s", &comp[i].availability);
		printf("\n");
	}
	return*comp;
}

int pechat(PC* comp, int k)//����� ���� ���������
{
	for (int i = 0; i < k; i++)
		printf("%2i. �������������: %s \n����-������ �����: %s \n����������: %s \n����: %s \n������: %i \n�����: %i \n������: %.1f \n������� ��������� � ��.: %s \n", i + 1, comp[i].manufacturer, comp[i].formfactor, comp[i].typesize, comp[i].color, comp[i].height, comp[i].dlina, comp[i].shirina, comp[i].availability);
	//����� ����������
	system("pause");
	return 0;
}

PC sortirovka(PC* comp, int k)//����������
{
	struct pc tmp;
	printf("\n");
	printf("\t\t\t � ���������� �� ����� ������� \n");
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k - i - 1; j++)
		{
			if (strcmp(comp[j].color, comp[j + 1].color) > 0)
			{
				tmp = comp[j];
				comp[j] = comp[j + 1];
				comp[j + 1] = tmp;
			}
		}
	}
	return *comp;
}

int dobavlenie_file(char* filename, PC* comp, int k)
{
	FILE* add; //��������� �� ����
	if ((add = fopen(filename, "a")) == NULL) //�������� �� ����������� ������� ���� ��� ���������� ������
	{
		fprintf(stderr, "���������� ������� ���� ��� ������ ��������.\n");
		return -1;
	}
	else
	{
		for (int i = k + 1; i < k + 2; i++)
		{
			//���� ��������. � ����
			printf("������� ������������� ������� ��: ");
			scanf("%s", &comp[i].manufacturer);
			printf("\n");
			printf("������� ����-������ �����: ");
			scanf("%s", &comp[i].formfactor);
			printf("\n");
			printf("������� ���������� �������: ");
			scanf("%s", &comp[i].typesize);
			printf("\n");
			printf("������� ���� �������: ");
			scanf("%s", &comp[i].color);
			printf("\n");
			printf("������� ������ ������� �� � ��: ");
			scanf("%i", &comp[i].height);
			printf("\n");
			printf("������� ����� ������� �� � ��: ");
			scanf("%i", &comp[i].dlina);
			printf("\n");
			printf("������� ������ ������� �� � ��: ");
			scanf("%f", &comp[i].shirina);
			printf("\n");
			printf("������� ������� ��������� ������� �� � ��.: ");
			scanf("%s", &comp[i].availability);
			printf("\n");
			printf("*************************************\n"
				"*                                   *\n"
				"* ������ ������� ��������� � ����.  *\n"
				"*                                   *\n"
				"*************************************\n");
		}
		fprintf(add, "�������������: %s \n����-������: %s \n����������: %s \n����: %s \n������: %i \n�����: %i \n������: %.1f \n������� ��������� � ��.: %s", comp[k + 1].manufacturer, comp[k + 1].formfactor, comp[k + 1].typesize, comp[k + 1].color, comp[k + 1].height, comp[k + 1].dlina, comp[k + 1].shirina, comp[k + 1].availability);
	}

	fclose(add); //�������� �����
	return 1;
}

int poisk_manufacturer(PC* comp, int k) {
	system("cls");
	char A[21];
	printf("������� �������� ������������� �������: ");
	rewind(stdin);
	gets(A);
	for (int p = 0; p < k; p++) {
		if (strcmp(comp[p].manufacturer, A) == 0) {
			printf("%i|�������������:%s\n����-������:%s\n����������:%s\n����:%s\n������:%i\n�����:%i\n������:%.1f\n������� ��������� � ��.:%s\n", p + 1, comp[p].manufacturer, comp[p].formfactor, comp[p].typesize, comp[p].color, comp[p].height, comp[p].dlina, comp[p].shirina, comp[p].availability);

		}
	}
	return 0;
}

int poisk_typesize(PC* comp, int k) {
	system("cls");
	char B[21];
	printf("������� ���������� �������: ");
	rewind(stdin);
	gets(B);
	for (int p = 0; p < k; p++) {
		if (strcmp(comp[p].typesize, B) == 0) {
			printf("%i|�������������:%s\n����-������:%s\n����������:%s\n����:%s\n������:%i\n�����:%i\n������:%.1f\n������� ��������� � ��.:%s\n", p + 1, comp[p].manufacturer, comp[p].formfactor, comp[p].typesize, comp[p].color, comp[p].height, comp[p].dlina, comp[p].shirina, comp[p].availability);

		}
	}
	return 0;
}

