#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//21�I

typedef struct user
{
	char name;
	int time[6];      //��n�����쪺��P
	int total;        //�`�M
}user;
user banker;
user player;

int card[13] = { 4 }; //���J�P�Ѿl�ƥ� 0~12
char num[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };   //�j�p 0~12, T = 10

char ans;		      //�O�_�n�P������

void showall(user a)	  //��ܩҦ��P
{
	int i;
	if (a.name == 'b')
	{

		printf("���a�Ҧ����P : ");
		for (i = 0; i < 5; i++)
			printf("%c ", num[banker.time[i] - 1]);
		printf("���a���`�M : %d \n", banker.total);
	}
	else if (a.name == 'p')
	{

		printf("���a�Ҧ����P : ");
		for (i = 0; i < 5; i++)
			printf("%c ", num[player.time[i] - 1]);
		printf("���a���`�M : %d \n", player.total);
	}
}

void first2(user a)  //���o2�i�P
{
	int i;
	if (a.name == 'b')
	{
		for (i = 0; i < 2; i++)
		{
			banker.time[i] = rand() % 13 + 1; //1~13
			if (banker.time[i] > 10)
				banker.total = banker.total + 10;
			else
				banker.total = banker.total + banker.time[i];
			card[banker.time[i] - 1]--;
		}
	}
	else if (a.name == 'p')
	{
		for (i = 0; i < 2; i++)
		{
			player.time[i] = rand() % 13 + 1;
			if (player.time[i] > 10)
				player.total = player.total + 10;
			else
				player.total = player.total + player.time[i];
			card[player.time[i] - 1]--;
		}
	}
}

void again() //�O�_�A�Ӥ@��
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

int main()
{
	int i, j;

	banker.total = 0;
	player.total = 0;
	banker.name = 'b';
	player.name = 'p';

	for (i = 0; i < 6; i++)
	{
		banker.time[i] = 0;
		player.time[i] = 0;
	}

	srand(time(NULL));
	printf("�}�l�C��\n�o�P\n\n");

	first2(banker);
	first2(player);

	printf("(T = 10)\n");
	printf("���a���P : *  %c\n\n", num[banker.time[1] - 1]);				//�����D���a���Ĥ@�i�P
	printf("���a���P : %c %c\n\n", num[player.time[0] - 1], num[player.time[1] - 1]);

	printf("�O�_�n�P?  n)�_  y)�O  ");
	scanf(" %c", &ans);

	while (ans != 'n' && ans != 'y')
	{
		printf("�A��J�@��\n");
		printf("�O�_�n�P?  n)�_  y)�O  ");
		scanf(" %c", &ans);
	}

	i = 2;
	j = 2;
	while (ans == 'y')
	{
		player.time[i] = rand() % 13 + 1;
		if (player.time[i] > 10)
			player.total = player.total + 10;
		else
			player.total = player.total + player.time[i];
		card[player.time[i] - 1]--;
		printf("\n�A���P : %c \n", num[player.time[i] - 1]);
		i++;
		j++;
		if (player.total <= 21 && player.time[4] != 0)
		{
			showall(player);
			printf("���a�L�����A���a���\n");
			again();
		}
		if (player.total > 21)
		{
			showall(player);
			printf("\n���a���\n");
			again();
		}
		printf("�O�_�n�P?  n)�_  y)�O  ");
		scanf(" %c", &ans);
	}

	for (i = 0; i < j; i++)  //A�۰ʧP�_��1��11
	{
		if (player.time[i] == 1 && player.total <= 11)
		{
			player.total += 10;
		}
	}

	printf("������a\n");
	j = 2;
	if (banker.total < 18)
	{
		i = 2;
		while (banker.total < 16)
		{
			banker.time[i] = rand() % 13 + 1;
			if (banker.time[i] > 10)
				banker.total = banker.total + 10;
			else
				banker.total = banker.total + banker.time[i];
			card[banker.time[i] - 1]--;
			printf("\n���a���P : %c \n", num[banker.time[i] - 1]);
			i++;
			j++;
			if (banker.total <= 21 && banker.time[4] != 0)
			{
				showall(banker);
				printf("���a�L�����A���a���\n");
				again();
			}
			if (banker.total > 21)
			{
				showall(banker);
				printf("\n���a���\n");
				again();
			}
		}
	}
	for (i = 0; i < j; i++)
	{
		if (banker.time[i] == 1 && banker.total <= 11)
		{
			banker.total += 10;
		}
	}

	printf("\n����ȵP\n\n");

	showall(banker);
	showall(player);

	if (player.total > banker.total && player.total <= 21 && banker.total <= 21)
		printf("���a���!\n");
	else if (banker.total > player.total && banker.total <= 21 && player.total <= 21)
		printf("���a���!\n");
	else if (banker.total == player.total && banker.total <= 21 && player.total <= 21)
		printf("���襭��!\n");
	else
		printf("no one wins\n");
	printf("\n");

	again();

	system("pause");
	return 0;
}