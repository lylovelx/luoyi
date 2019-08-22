
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define ROW 3
#define COL 3
char g_broad[ROW][COL];
//棋盘初始化
void Init(char broad[ROW][COL]){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			broad[row][col] = ' ';
		}
	}
}
//打印棋盘
void Printf(char broad[ROW][COL]){
	for (int row = 0; row < ROW; row++){
		printf("|%c|%c|%c|\n", broad[row][0],
			broad[row][1], broad[row][2]);
		if (row == 2){
			printf("");
		}
		else{
			printf("--------\n");
		}

	}
}
void PlayMove(char broad[ROW][COL]){
	//玩家落子
	printf("         \n");
	printf("玩家落子");
	while (1){
		int row = 0;
		int col = 0;
		scanf("%d%d", &row, &col);
		if (row<0 || row >= ROW || col<0 || col >= COL){
			printf("非法输入\n,请重新输入");
			continue;
		}
		if (broad[row][col] != ' '){
			printf("此坐标已经落子，请重新输入\n");
			continue;
		}
		broad[row][col] = '*';
		break;
	}
}
void ComputerMove(char broad[ROW][COL]){
	//电脑落子
	printf("         \n");
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (broad[row][col] != ' '){
			//此位置已经被占用，生成随机数。
			continue;
		}
		broad[row][col] = '+';
		break;
	}
}
//判断棋盘是否已满
int IsFull(char broad[ROW][COL]){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			if (broad[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
char CheckWinner(char broad[ROW][COL]){
	//检查所有行
	for (int row = 0; row< COL; row++){
		if (broad[row][0] == broad[row][1] &&
			broad[row][0] == broad[row][2] && broad[row][0] != ' '){
			return broad[row][0];
		}
	}
	//检查所有列
	for (int col = 0; col < COL; col++){
		if (broad[0][col] == broad[1][col] &&
			broad[0][col] == broad[2][col] && broad[0][col] != ' '){
			return broad[0][col];
		}
	}
	//检查第一条对角线
	if (broad[0][0] == broad[1][1]
		&& broad[0][0] == broad[2][2] && broad[0][0] != ' '){
		return broad[0][0];
	}
	//检查第二条对角线
	if (broad[0][2] == broad[1][1] && broad[0][2] == broad[2][0] && broad[0][2] != ' '){
		return broad[0][2];
	}
	if (IsFull(g_broad)){
		return 'q';
	}
	return ' ';
}
void Game(){
	Init(g_broad);
	char winner = ' ';
	while (1){

		//打印棋盘
		Printf(g_broad);
		//玩家落子检查游戏是否结束
		PlayMove(g_broad);
		winner = CheckWinner(g_broad);
		//'x'代表玩家胜利，'o'代表电脑胜利，'q'代表和棋，' '代表胜负未分
		if (winner != ' '){
			break;
		}
		//电脑落子检查游戏是否结束
		ComputerMove(g_broad);
		winner = CheckWinner(g_broad);
		if (winner != ' '){
			break;
		}
	}
	Printf(g_broad);
	if (winner == '*'){
		printf("玩家胜利\n");
	}
	else if (winner == '+'){
		printf("电脑胜利\n");
	}
	else if (winner == 'q'){
		printf("和棋\n");
	}
	else{
		printf("程序傻逼了\n");
	}
}
int Menu(){
	printf("===========\n");
	printf("1, 开始游戏\n");
	printf("0, 退出游戏\n");
	printf("===========\n");
	int choice = 0;
	scanf("%d", &choice);
	while (1){
		if (choice != 1 && choice != 0){
			printf("非法输入\n");
			break;
		}
		else{
			return choice;
		}
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int a = Menu();
		if (a == 1){
			printf("      \n");
			Game();
		}
		if (a == 0){
			printf("goodbye\n");
		}
	}
	system("pause");
	return 0;
}
