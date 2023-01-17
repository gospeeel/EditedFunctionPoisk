#define _CRT_SECURE_NO_WARNINGS
#include <locale.h> //заголовочный файл локализации
#include <stdio.h> //заголовочный файл для функция ввода/вывода
#include <stdlib.h> //заголовочный файл стандартной библиотеки
#include <string.h> //заголовочный фал для работы со строками
#include <malloc.h> //динамическое выделение и освобождение памяти
#include <conio.h>//заголовочный файл для создания текстового интерфейса пользователя

typedef struct pc //объявление структуры
{
	char manufacturer[20], formfactor[20], typesize[20], color[20], availability[20];
	int height, dlina;
	float shirina;

}PC;

int zapis(char* filename, PC* comp, int k);//запись в файл
int chtenie(char* filename);//чтение из файла
int pechat(PC* comp, int k);//вывод базы данных
PC sortirovka(PC* comp, int k);//сортировка по цвету
PC dobavlenie(PC* comp, int k);//добавление корпуса в систему
int dobavlenie_file(char* filename, PC* comp, int k);//добавление корпуса в файл

int main() {
	system("chcp 1251");
	system("cls"); //очищение экрана
	setlocale(LC_ALL, "RUS");//локализация
	PC* comp = NULL;//указатель
	int k;//кол-во корпусов
	int vibor;//выбор в меню
	char filename[100];//название файла


	//меню


	while (1) {
		system("cls");
		printf("1 - Добавление Корпуса ПК в базу данных \n"
			"2 - Запись в файл \n"
			"3 - Чтение из файла \n"
			"4 - Вывод информации о Корпусах ПК, занесенных в базу данных \n"
			"5 - Сортировка Корпусов по цвету \n"
			"6 - Поиск Корпусов ПК по производителю \n"
			"7 - Поиск Корпусов ПК по типоразмеру\n"
			"8 - Добавление Корпуса ПК в файл \n"
			"9 - Завершение работы \n");
		printf("Введите пункт меню: ");
		scanf("%d", &vibor);
		system("cls");
		switch (vibor) {
			char A[21];
			char B[21];
			int p = 0;
		case 1:
			printf("Введите количество корпусов:");
			scanf("%d", &k);
			comp = realloc(comp, k * sizeof(PC));//выделение динамической памяти для количества пассажиров
			dobavlenie(comp, k);
			//Print(comp, k);
			break;

		case 2:
			printf("Введите имя файла для чтения:");
			scanf("%s", &filename);
			zapis(filename, comp, k);
			break;

		case 3:
			printf("Введите имя файла для чтения:");
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
			printf("Введите название производителя: ");
			rewind(stdin);
			gets(A);
			for (int i = 0; i < k; i++) {
				p = poisk_manufacturer(comp, k, i, A);
				if (p != -1) printf("%i|Производитель:%s\nФорм-фактор:%s\nТипоразмер:%s\nЦвет:%s\nВысота:%i\nДлина:%i\nШирина:%.1f\nНаличие подсветки и пр.:%s\n", p + 1, comp[p].manufacturer, comp[p].formfactor, comp[p].typesize, comp[p].color, comp[p].height, comp[p].dlina, comp[p].shirina, comp[p].availability);
			}
			system("pause");
			p = - 1;
			break;

		case 7:
			printf("Введите типоразмер корпуса: ");
			rewind(stdin);
			gets(B);
			for (int i = 0; i < k; i++) {
				p = poisk_typesize(comp, k, i, B);
				if (p != -1) printf("%i|Производитель:%s\nФорм-фактор:%s\nТипоразмер:%s\nЦвет:%s\nВысота:%i\nДлина:%i\nШирина:%.1f\nНаличие подсветки и пр.:%s\n", p + 1, comp[p].manufacturer, comp[p].formfactor, comp[p].typesize, comp[p].color, comp[p].height, comp[p].dlina, comp[p].shirina, comp[p].availability);
			}
			system("pause");
			break;

		case 8:
			printf("Введите имя файла для чтения:");
			scanf("%s", &filename);
			dobavlenie_file(filename, comp, k);
			break;

		case 9:
			return -1;
			break;

		default:
			puts("Данный выбор невозможно осуществить");

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
		fprintf(stderr, "Файл нельзя открыть для записи\n");
		system("pause");
		return -1;
	}

	else
	{
		for (i = 0; i < k; i++)
		{
			fprintf(f, "%2i. Производитель: %s \nФорм-фактор платы: %s \nТипоразмер: %s \nЦвет: %s \nВысота: %i \nДлина: %i \nШирина: %.1f \nНаличие подсветки и пр.: %s \n", i + 1, comp[i].manufacturer, comp[i].formfactor, comp[i].typesize, comp[i].color, comp[i].height, comp[i].dlina, comp[i].shirina, comp[i].availability);
			system("pause");
		}
		fclose(f);
		printf("************************************\n"
			"* Данные успешно записаны в файл *\n"
			"************************************\n");
		system("pause");
	}
	return -1;
}

int chtenie(char* filename)//чтение из файла
{
	///Чтение файла
	printf("Начинаем чтение файла\n");
	FILE* input;
	char file[200];
	input = fopen(filename, "r"); //открытие файла для чтения
	if (input != NULL) //проверка на существование и открытие файла
	{
		printf("* Файл успешно открыт. *\n");
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
		printf("Неудалось открыть файл\n");
		system("pause");
		return -1;
	}
	fclose(input); //закрытие файла
	return 0;
}

PC dobavlenie(PC* comp, int k)//заполнение бд пользователем
{
	for (int i = 0; i < k; i++)
	{
		//ввод в систему пассажиров
		printf("Введите Производителя Корпуса ПК: ");
		scanf("%s", &comp[i].manufacturer);
		printf("Введите Форм-фактор платы: ");
		scanf("%s", &comp[i].formfactor);
		printf("Введите Типоразмер Корпуса: ");
		scanf("%s", &comp[i].typesize);
		printf("Введите Цвет Корпуса: ");
		scanf("%s", &comp[i].color);
		printf("Введите высоту Корпуса ПК в см: ");
		scanf("%i", &comp[i].height);
		printf("Введите длину Корпуса ПК в см: ");
		scanf("%i", &comp[i].dlina);
		printf("Введите ширину Корпуса ПК в см: ");
		scanf("%f", &comp[i].shirina);
		printf("Введите наличие подсветки Корпуса ПК и пр.: ");
		scanf("%s", &comp[i].availability);
		printf("\n");
	}
	return*comp;
}

int pechat(PC* comp, int k)//вывод всех элементов
{
	for (int i = 0; i < k; i++)
		printf("%2i. Производитель: %s \nФорм-фактор платы: %s \nТипоразмер: %s \nЦвет: %s \nВысота: %i \nДлина: %i \nШирина: %.1f \nНаличие подсветки и пр.: %s \n", i + 1, comp[i].manufacturer, comp[i].formfactor, comp[i].typesize, comp[i].color, comp[i].height, comp[i].dlina, comp[i].shirina, comp[i].availability);
	//вывод пассажиров
	system("pause");
	return 0;
}

PC sortirovka(PC* comp, int k)//сортировка
{
	struct pc tmp;
	printf("\n");
	printf("\t\t\t » Сортировка по цвету корпуса \n");
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
	FILE* add; //указатель на файл
	if ((add = fopen(filename, "a")) == NULL) //проверка на возможность открыть файл для добавления данных
	{
		fprintf(stderr, "Невозможно открыть файл для записи элемента.\n");
		return -1;
	}
	else
	{
		for (int i = k + 1; i < k + 2; i++)
		{
			//ввод корпусов. в файл
			printf("Введите Производителя Корпуса ПК: ");
			scanf("%s", &comp[i].manufacturer);
			printf("\n");
			printf("Введите Форм-фактор платы: ");
			scanf("%s", &comp[i].formfactor);
			printf("\n");
			printf("Введите Типоразмер Корпуса: ");
			scanf("%s", &comp[i].typesize);
			printf("\n");
			printf("Введите Цвет Корпуса: ");
			scanf("%s", &comp[i].color);
			printf("\n");
			printf("Введите высоту Корпуса ПК в см: ");
			scanf("%i", &comp[i].height);
			printf("\n");
			printf("Введите длину Корпуса ПК в см: ");
			scanf("%i", &comp[i].dlina);
			printf("\n");
			printf("Введите ширину Корпуса ПК в см: ");
			scanf("%f", &comp[i].shirina);
			printf("\n");
			printf("Введите наличие подсветки Корпуса ПК и пр.: ");
			scanf("%s", &comp[i].availability);
			printf("\n");
			printf("*************************************\n"
				"*                                   *\n"
				"* Данные успешно добавлены в файл.  *\n"
				"*                                   *\n"
				"*************************************\n");
		}
		fprintf(add, "Производитель: %s \nФорм-фактор: %s \nТипоразмер: %s \nЦвет: %s \nВысота: %i \nДлина: %i \nШирина: %.1f \nНаличие подсветки и пр.: %s", comp[k + 1].manufacturer, comp[k + 1].formfactor, comp[k + 1].typesize, comp[k + 1].color, comp[k + 1].height, comp[k + 1].dlina, comp[k + 1].shirina, comp[k + 1].availability);
	}

	fclose(add); //закрытие файла
	return 1;
}

int poisk_manufacturer(PC* comp, int k, int i, char* A) {
	if (strcmp(comp[i].manufacturer, A) == 0) {
		return i;
	}
	return -1;
}
int poisk_typesize(PC* comp, int k, int i, char* B) {
		if (strcmp(comp[i].typesize, B) == 0) {
			return i;
		}
	return -1;
}
