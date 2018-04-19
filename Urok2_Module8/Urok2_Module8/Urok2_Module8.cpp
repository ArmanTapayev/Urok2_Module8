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
	printf("� ������ 10 �������.\n");
	printf("��� ���������� �������� 0.\n");
	do
	{

		printf("������� ����� �������.\n");
		scanf("%d", &n);
		cin.get();
		switch (n)
		{
			case 1:
			{
				/*1. � �������� ������ �������� ������ ������ ������ ��������� �� ���� ��������. 
				����� ��� �������� ��������.*/
				char string1[50];
				printf("� �������� ������ ���������� �������� ������ ������ ������ ��������� �� ���� ��������. ����� ��� �������� ��������. \n");
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
				/*2. � �������� ������ ��������� ���������� ������ ��������, 
				�������� � ��� ������*/

				char string1[50];
				printf("� �������� ������ ���������� ��������� ���������� ������ ��������, �������� � ��� ������. \n");
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
				printf("� �������� ������ ������ %d ��������� ��������.\n", k);
				system("pause");
				system("cls");

			}break;

			case 3:
			{
				/*3. � �������� ������ ����������� � �������� ������� ��� �����. 
				������������� ���� ��������� �������*/
				char string1[50];
				char *first, *last, *start;
				int flag = 0, i = 0;
				printf("� �������� ������ ���������� ����������� ��� ����� � �������� ������� .\n");
				printf("������� ������ � ������������� � ���� ��������.\n");
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
				printf("������ � �������� �������:\n");
				printf("%s\n", string1);

				system("pause");
				system("cls");
			}break;

			case 4:
			{
				/*4. � �������� ������ ��������� ���������� ����, 
				���������� ������ �������� ������� �����. 
				������������� ���� ��������� �������.*/

				char string1[50];
				printf("� �������� ������ ��������� ���������� ����, ���������� ������ �������� ������� �����.\n");
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

				printf("���������� ����, ���������� ������ �������� ������� �����:\n");
				printf("%d\n", downCase);
				system("pause");
				system("cls");
			}break;

			case 5:
			{
				/*5. �� �������� ������ �������� ������ ����, �������� � ��� ������. 
				������������� ���� ��������� �������.*/
				char string1[50];
				printf("������� ������ ��������, ���������� �������� ������ ����, �������� � ��� ������. \n");
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
				/*6. ��� ������ ��������. ����������, ������� ��������� �������� ����������� � ���. 
				������� �� �� �����*/

				char string1[50];
				printf("� ��������� ������� �������� ���������� ���������� ������� ��������� �������� ����������� � ��� \n");
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
				printf("� ������ ������ %d ��������� ��������.\n", k);

				system("pause");
				system("cls");
			}break;

			case 7:
			{
				/*7. ��� ������ ��������. ���������� ����� ������� ������������������ ������ ������ ���� �.*/
				char string1[50];
				printf("������� ������ ��������, ����� ������� ���� ������������������ ������ ������ ���� �. \n");
				printf("���������� ���������� ����� ������� ����� ������������������.\n");
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
				/*8. ��� ������ ��������, ����� ������� ���� ������������� � ������������� ������. 
				������� �� ����� ������� ��������, ������������� ������ ���� ������.*/
				
				char string1[50];
				printf("������� ������ ��������, ����� ������� ���� ������������� � ������������� ������. \n");
				printf("���������� ������� �� ����� ������� ��������, ������������� ������ ���� ������.\n");
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
				/*9. ��� ������ ��������, ���������� �����. ���������� ���������� ��������� �������� 
				� ��������� ���� � ������ ����� �������� � ���.*/
				char string1[50];
				printf("� �������� ������� �������� ���������� ���������� ��������� �������� � ��������� ���� � ������ ����� �������� � ���.\n");
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

				printf("���������� �������� ����: %d\n", downCase);
				printf("���������� ��������� ����: %d\n", upCase);
				printf("����� ���������� ��������: %d\n", len);

				printf("���������� ��������� �������� ���� � ������ ����� ��������: %0.2f\n", (float)downCase / len);
				printf("���������� ��������� ��������� ���� � ������ ����� ��������: %0.2f\n", (float)upCase / len);

				system("pause");
				system("cls");
			}break;

			case 10:
			{
				/*10. ��� ������ ��������, ����� ������� ���� ���� ������������� � ���� ������������� ������.
				������� �� ����� ��� �������, ������������� ������ ���� ������*/

				char string1[20];
				printf("������� ������, ����� ������� ���� ���� ������������� � ���� ������������� ������. \n");
				printf("���������� ������� �� ����� ��� �������, ������������� ������ ���� ������. \n");
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