#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define ROW 9
#define COL 9
#define MINE_COUNT 10
void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2]){
	//
	for (int row = 0; row < ROW + 2; row++){
		for (int col = 0; col < COL + 2; col++){
			show_map[row][col] = '*';
		}
	}
	for (int row = 0; row < ROW + 2; row++){
		for (int col = 0; col < COL + 2; col++){
			mine_map[row][col] = '0';
		}
	}
	/*memset(show_map, '*', (ROW + 2)*(COL + 2));
	memset(mine_map, '0', (ROW + 2)*(COL + 2));*/
	//��������
	int num = MINE_COUNT;
	while (num>0){
		int row = rand() % 9 + 1;
		int col = rand() % 9 + 1;
		if (mine_map[row][col] == '1'){
			continue;
		}
		else{
			mine_map[row][col] = '1';
		}
		num--;
	}
}
void Printf(char map[ROW + 2][COL + 2]){
	printf(" |");
	for (int i = 1; i <= COL; i++){
		printf("%d", i);
	}
	printf("\n");
	/*for (int i = 1; i <= COL;i++){
	printf("--");
	}*/
	printf("-----------\n");
	for (int row = 1; row <= ROW; row++){
		printf("%d|", row);
		for (int col = 1; col <= COL; col++){
			printf("%c", map[row][col]);
		}
		printf("\n");
	}


}
void updata_map(char show_map[ROW + 2][COL + 2],
	char mine_map[ROW + 2][COL + 2], int row, int col){
	int mine_count =
		(mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0') + (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0') + (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col - 1] - '0') + (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col + 1] - '0');
	show_map[row][col] = mine_count + '0';
}
void game(){
	//�趨������ά����ֱ�Ϊ�������ҿ��ĵ�ͼ
	char mine_map[ROW + 2][COL + 2];
	char show_map[ROW + 2][COL + 2];
	//�����̽��г�ʼ��,��'0'��ʾû���ף��á�1����ʾ����
	//�á�*����ʾ�����չʾ�ĵ�ͼ
	Init(mine_map, show_map);
	Printf(show_map);
	int black_not_count = 0;
	while (1){
		printf("����������");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (mine_map[row][col] == '1'){
			printf("������ˣ���Ϸ����\n");
			Printf(mine_map);
			break;
		}
		black_not_count++;
		if (black_not_count == ROW*COL - MINE_COUNT){
			printf("ɨ�׳ɹ�\n");
			Printf(mine_map);
			break;
		}
		updata_map(show_map, mine_map, row, col);
		Printf(show_map);
	}
}
int start(){
	printf("==========\n");
	printf("1,��ʼ��Ϸ\n");
	printf("0,�˳���Ϸ\n");
	printf("==========\n");
	int num = 0;
	scanf("%d", &num);
	return num;
}
int main(){
	srand((unsigned int)time(0));
	int choice = start();
	while (1){
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("�˳���Ϸ\n");
			break;
		}
		else{
			printf("�Ƿ�����\n");
		}
	}
	system("pause");
	return 0;
}
