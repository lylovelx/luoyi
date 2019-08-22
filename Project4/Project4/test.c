
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define ROW 3
#define COL 3
char g_broad[ROW][COL];
//���̳�ʼ��
void Init(char broad[ROW][COL]){
	for (int row = 0; row < ROW; row++){
		for (int col = 0; col < COL; col++){
			broad[row][col] = ' ';
		}
	}
}
//��ӡ����
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
	//�������
	printf("         \n");
	printf("�������");
	while (1){
		int row = 0;
		int col = 0;
		scanf("%d%d", &row, &col);
		if (row<0 || row >= ROW || col<0 || col >= COL){
			printf("�Ƿ�����\n,����������");
			continue;
		}
		if (broad[row][col] != ' '){
			printf("�������Ѿ����ӣ�����������\n");
			continue;
		}
		broad[row][col] = '*';
		break;
	}
}
void ComputerMove(char broad[ROW][COL]){
	//��������
	printf("         \n");
	while (1){
		int row = rand() % ROW;
		int col = rand() % COL;
		if (broad[row][col] != ' '){
			//��λ���Ѿ���ռ�ã������������
			continue;
		}
		broad[row][col] = '+';
		break;
	}
}
//�ж������Ƿ�����
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
	//���������
	for (int row = 0; row< COL; row++){
		if (broad[row][0] == broad[row][1] &&
			broad[row][0] == broad[row][2] && broad[row][0] != ' '){
			return broad[row][0];
		}
	}
	//���������
	for (int col = 0; col < COL; col++){
		if (broad[0][col] == broad[1][col] &&
			broad[0][col] == broad[2][col] && broad[0][col] != ' '){
			return broad[0][col];
		}
	}
	//����һ���Խ���
	if (broad[0][0] == broad[1][1]
		&& broad[0][0] == broad[2][2] && broad[0][0] != ' '){
		return broad[0][0];
	}
	//���ڶ����Խ���
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

		//��ӡ����
		Printf(g_broad);
		//������Ӽ����Ϸ�Ƿ����
		PlayMove(g_broad);
		winner = CheckWinner(g_broad);
		//'x'�������ʤ����'o'�������ʤ����'q'������壬' '����ʤ��δ��
		if (winner != ' '){
			break;
		}
		//�������Ӽ����Ϸ�Ƿ����
		ComputerMove(g_broad);
		winner = CheckWinner(g_broad);
		if (winner != ' '){
			break;
		}
	}
	Printf(g_broad);
	if (winner == '*'){
		printf("���ʤ��\n");
	}
	else if (winner == '+'){
		printf("����ʤ��\n");
	}
	else if (winner == 'q'){
		printf("����\n");
	}
	else{
		printf("����ɵ����\n");
	}
}
int Menu(){
	printf("===========\n");
	printf("1, ��ʼ��Ϸ\n");
	printf("0, �˳���Ϸ\n");
	printf("===========\n");
	int choice = 0;
	scanf("%d", &choice);
	while (1){
		if (choice != 1 && choice != 0){
			printf("�Ƿ�����\n");
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
