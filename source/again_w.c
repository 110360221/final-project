#include<stdio.h>
#include<stdlib.h>

void again()
{
	char again;
	printf("\n�A�Ӥ@��?   n)�_  y)�O   ");
	scanf(" %c", &again);

	while (again != 'n' || again != 'y')
	{
		if (again == 'y')
		{
			system("cls");
			main();
		}
		else if (again == 'n')
			exit(0);
		else
		{
			printf("�A��J�@��");
			printf("\n�A�Ӥ@��?   n)�_  y)�O   ");
			scanf(" %c", &again);
		}
	}
}