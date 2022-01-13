#include<stdio.h>
#include<stdlib.h>

void again()
{
	char again;
	printf("\n再來一局?   n)否  y)是   ");
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
			printf("再輸入一次");
			printf("\n再來一局?   n)否  y)是   ");
			scanf(" %c", &again);
		}
	}
}