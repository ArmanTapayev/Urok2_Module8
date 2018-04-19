#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<string.h>
#include<time.h>

#include "Header.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n;
	printf("В работе 10 заданий.\n");
	printf("Для завершения наберите 0.\n");
	do
	{

		printf("Введите номер задания.\n");
		scanf("%d", &n);
		cin.get();
		switch (n)
		{
			case 1:
			{
				/*1. В заданной строке заменить каждый символ строки следующим по коду символом. 
				Букву «я» заменить пробелом.*/
				char string1[50];
				printf("В заданной строке необходимо заменить каждый символ строки следующим по коду символом. Букву «я» заменить пробелом. \n");
				gets_s(string1);

				int len = strlen(string1);

				for (int i = 0; i < len; i++)
				{
					string1[i]++;
					if (string1[i] == 'z')
						string1[i] = ' ';
				}
				printf("%s\n", string1);
				system("pause");
				system("cls");

				system("pause");
				system("cls");

			}break;

			case 2:
			{
				/*2. В заданной строке посчитать количество разных символов, 
				входящих в эту строку*/

				char string1[50];
				printf("В заданной строке необходимо посчитать количество разных символов, входящих в эту строку. \n");
				gets_s(string1);

				int len = strlen(string1);
				int k = 0, flag = 1;
				for (int i = 0; i < len; i++)
				{
					for (int j = len - 1; j >= 0; j--)
					{
						if (i != j && *(string1 + i) == *(string1 + j))// (*(string1 + i)==' '||*(string1 + j) == ' ')
						{
							flag = 0;
							break;
						}
						else if (i == j)
							break;
					}
					if (flag)
						k++;
					flag = 1;
				}
				printf("В заданную строку входит %d различных символов.\n", k);
				system("pause");
				system("cls");

			}break;

			case 3:
			{
				/*3. В заданной строке расположить в обратном порядке все слова. 
				Разделителями слов считаются пробелы*/
				char string1[50];
				char *first, *last, *start;
				int flag = 0, i = 0;
				printf("В заданной строке необходимо расположить все слова в обратном порядке .\n");
				printf("Введите строку с разделителями в виде пробелов.\n");
				gets_s(string1);

				start = string1;
				while (*start)
				{
					if (!flag)
					{
						if (*start != ' ')
						{
							flag = 1;
							first = start;
						}
					}
					else
					{
						if (*start == ' ' || !*(start + 1))
						{
							flag = 0;
							last = start - 1;
							if (!*(start + 1))
								last = start;
							swapString(first, last);
						}
					}
					start++;
				}

				swapString(string1, start - 1);
				printf("Строка в обратном порядке:\n");
				printf("%s\n", string1);

				system("pause");
				system("cls");
			}break;

			case 4:
			{
				/*4. В заданной строке посчитать количество слов, 
				содержащих только строчные русские буквы. 
				Разделителями слов считаются пробелы.*/

				char string1[50];
				printf("В заданной строке посчитать количество слов, содержащих только строчные русские буквы.\n");
				gets_s(string1);

				int len = strlen(string1);
				int downCase = 0, flag = 1;

				for (int i = 0; i<len; i++)
				{
					while (*(string1 + i) != ' '&& *(string1 + i) != '\0')
					{
						flag = 1;
						if (!(*(string1 + i) >= 'a' && *(string1 + i) <= 'z'))
						{
							for (; *(string1 + i) != ' ' && *(string1 + i) != '\0'; i++)
							{
							}
							flag = 0;
							break;
						}
						i++;
					}
					if (flag)
						downCase++;
					flag = 0;
				}

				printf("Количество слов, содержащих только строчные русские буквы:\n");
				printf("%d\n", downCase);
				system("pause");
				system("cls");
			}break;

			case 5:
			{
				/*5. По заданной строке получить массив слов, входящих в эту строку. 
				Разделителями слов считаются пробелы.*/
				char string1[50];
				printf("Введите массив символов, необходимо получить массив слов, входящих в эту строку. \n");
				gets_s(string1);

				char *p = strtok(string1, " ");

				while (p != NULL)
				{
					printf("%s\n", p);
					p = strtok(NULL, " ");
				}

				system("pause");
				system("cls");

			}break;

			case 6:
			{
				/*6. Дан массив символов. Подсчитать, сколько различных символов встречается в нем. 
				Вывести их на экран*/

				char string1[50];
				printf("В введенном массиве символов необходимо определить сколько различных символов встречается в нем \n");
				gets_s(string1);

				int len = strlen(string1);
				int k = 0, flag = 1;
				for (int i = 0; i < len; i++)
				{
					for (int j = len - 1; j >= 0; j--)
					{
						if (i != j && *(string1 + i) == *(string1 + j))
						{
							flag = 0;
							break;
						}
						else if (i == j)
							break;
					}
					if (flag)
						k++;
					flag = 1;
				}
				printf("В массив входит %d различных символов.\n", k);

				system("pause");
				system("cls");
			}break;

			case 7:
			{
				/*7. Дан массив символов. Подсчитать самую длинную последовательность подряд идущих букв а.*/
				char string1[50];
				printf("Введите массив символов, среди которых есть последовательности подряд идущих букв а. \n");
				printf("Необходимо подсчитать самую длинную такую последовательность.\n");
				gets_s(string1);

				int len = strlen(string1);
				int max = 0, k = 1;

				for (int i = 0; i<len - 1; i++)
				{
					if (*(string1 + i) == 'a')
					{
						while (*(string1 + i + 1) == 'a')
						{
							k++;
							i++;
						}

					}
					if (max < k)
						max = k;
					k = 1;
				}
				printf("max=%d\n", max);
				system("pause");
				system("cls");
			}break;

			case 8:
			{
				/*8. Дан массив символов, среди которых есть открывающиеся и закрывающиеся скобки. 
				Вывести на экран массивы символов, расположенные внутри этих скобок.*/
				
				char string1[50];
				printf("Введите массив символов, среди которых есть открывающиеся и закрывающиеся скобки. \n");
				printf("Необходимо вывести на экран массивы символов, расположенные внутри этих скобок.\n");
				gets_s(string1);

				int len = strlen(string1);

				for (int i = 0; *(string1 + i) != '\0'; i++)
				{
					if (*(string1 + i) == '(')
					{
						++i;
						while (*(string1 + i) != ')')
						{
							printf("%c", *(string1 + i));
							i++;
						}
						printf("\n");
					}
				}
				printf("\n");

				system("pause");
				system("cls");
			}break;

			case 9:
			{
				/*9. Дан массив символов, содержащий текст. Определить процентное отношение строчных 
				и прописных букв к общему числу символов в нем.*/
				char string1[50];
				printf("В заданном массиве символов определить процентное отношение строчных и прописных букв к общему числу символов в нем.\n");
				gets_s(string1);

				int len = strlen(string1);

				int downCase = 0, upCase = 0;
				for (int i = 0; i<50; i++)
				{
					if (*(string1 + i) >= 'a' && *(string1 + i) <= 'z')
						downCase++;
					if (*(string1 + i) >= 'A' && *(string1 + i) <= 'Z')
						upCase++;
				}

				printf("Количество строчных букв: %d\n", downCase);
				printf("Количество прописных букв: %d\n", upCase);
				printf("Общее количество символов: %d\n", len);

				printf("Процентное отношение строчных букв к общему числу символов: %0.2f\n", (float)downCase / len);
				printf("Процентное отношение прописных букв к общему числу символов: %0.2f\n", (float)upCase / len);

				system("pause");
				system("cls");
			}break;

			case 10:
			{
				/*10. Дан массив символов, среди которых есть одна открывающаяся и одна закрывающаяся скобка.
				Вывести на экран все символы, расположенные внутри этих скобок*/

				char string1[20];
				printf("Введите строку, среди которых есть одна открывающаяся и одна закрывающаяся скобка. \n");
				printf("Необходимо вывести на экран все символы, расположенные внутри этих скобок. \n");
				gets_s(string1);

				int len = strlen(string1);

				for (int i = 0; *(string1 + i) != '\0'; i++)
				{
					if (*(string1 + i) == '(')
					{
						++i;
						while (*(string1 + i) != ')')
						{
							printf("%c", *(string1 + i));
							i++;
						}
					}
				}
				printf("\n");

				system("pause");
				system("cls");
			}break;
		}
	} while (n != 0);
}