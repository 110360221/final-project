#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//21點

typedef struct user
{
	char name;
	int time[6];      //第n次拿到的手牌
	int total;        //總和
}user;
user banker;
user player;

int card[13] = { 4 }; //撲克牌剩餘數目 0~12
char num[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };   //大小 0~12, T = 10
char ten[] = { 10 };

void showall(user a)	  //0 = banker, 1 = player, 2 = both
{
	if (a.name == 'b')
	{
		int i;
		printf("莊家所有的牌 : ");
		for (i = 0; i < 5; i++)
			printf("%c ", num[banker.time[i] - 1]);
		printf("莊家的總和 : %d \n", banker.total);
	}
	else if (a.name == 'p')
	{
		int i;
		printf("玩家所有的牌   : ");
		for (i = 0; i < 5; i++)
			printf("%c ", num[player.time[i] - 1]);
		printf("玩家的總和 : %d \n", player.total);
	}
}

int main()
{
	char ans;		      //是否要牌的答案
	int i,j;

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
	printf("開始遊戲\n發牌\n\n");

	for (i = 0; i < 2; i++)   //一開始雙方掀各發2張牌
	{
		banker.time[i] = rand() % 13 + 1; //1~13
		if (banker.time[i] > 10)
			banker.total = banker.total + 10;
		else
			banker.total = banker.total + banker.time[i];
		card[banker.time[i] - 1]--;
	}

	for (i = 0; i < 2; i++)
	{
		player.time[i] = rand() % 13 + 1;
		if (player.time[i] > 10)
			player.total = player.total + 10;
		else
			player.total = player.total + player.time[i];
		card[player.time[i] - 1]--;
	}

	printf("(T = 10)\n");
	printf("莊家的牌 : *  %c\n\n", num[banker.time[1]-1]);				//不知道莊家的第一張牌
	printf("玩家的牌   : %c %c\n\n", num[player.time[0]-1], num[player.time[1]-1]);

	printf("是否要牌?  n)否  y)是  ");
	scanf(" %c", &ans);

	while(ans != 'n' && ans != 'y')
	{
		printf("再輸入一次");
		printf("是否要牌?  n)否  y)是  ");
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
		printf("\n你的牌 : %c \n", num[player.time[i] - 1]);
		i++;
		j++;
		if (player.total <= 21 && player.time[4] != 0)
		{
			showall(player);
			printf("玩家過五關，玩家獲勝\n");
			return 0;
		}
		if (player.total > 21)
		{
			showall(player);
			printf("\n莊家獲勝\n");
			return 0;
		}
		printf("是否要牌?  n)否  y)是  ");
		scanf(" %c", &ans);
	}

	for (i = 0; i < j; i++)
	{
		if (player.time[i] == 1 && player.total <= 11)
		{
			player.total += 10;
		}
	}
		
	printf("輪到莊家\n");
	j = 2;
	if(banker.total < 18)
	{
		i = 2;
		while (banker.total < 17)
		{
			banker.time[i] = rand() % 13 + 1;
			if (banker.time[i] > 10)
				banker.total = banker.total + 10;
			else
				banker.total = banker.total + banker.time[i];
			card[banker.time[i] - 1]--;
			printf("\n莊家的牌 : %c \n", num[banker.time[i] - 1]);
			i++;
			j++;
			if (banker.total <= 21 && banker.time[4] != 0)
			{
				showall(banker);
				printf("莊家過五關，莊家獲勝\n");
				return 0;
			}
			if (banker.total > 21)
			{
				showall(banker);
				printf("\n玩家獲勝\n");
				return 0;
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

	printf("\n雙方掀牌\n\n");
	
	showall(banker);
	showall(player);

	if (player.total > banker.total && player.total <= 21 && banker.total <= 21)
		printf("玩家獲勝!\n");
	else if (banker.total > player.total && banker.total <= 21 && player.total <= 21)
		printf("莊家獲勝!\n");
	else if(banker.total == player.total && banker.total <= 21 && player.total <= 21)
		printf("雙方平手!\n");
	else
		printf("no one wins\n");
	printf("\n");

	system("pause");
	return 0;
}