#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//名前の最大の長さ
const unsigned int kMaxTextLength = 1 << 10;

int main() {
	//名前
	char name[kMaxTextLength] = "";
	//掛け金.
	int bet = 0;
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//サイコロ
	int dice[2][3] = {};
	//役職
	char role[kMaxTextLength] = "";

	printf("君の名前を教えてくれないかい?\n");
	//名前の入力
	scanf_s("%s", name, kMaxTextLength);

	printf("%sくんだね。よろしく。今回はワシが親でいくよ\n\n", name);

	printf("まずは掛け金を100から10000ペリカで決めてくれ\n");
	//掛け金の入力
	scanf_s("%d", &bet);

	printf("では%sくん、サイコロを振ってくれ\n\n", name);

	printf("続行するには何かキーを押してください . . .");
	(void)getchar();//改行を読み飛ばすため
	(void)getchar();//実際の入力待ち

	//サイコロを振る
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			dice[i][j] = rand() % 6 + 1; // 1から6の乱数を生成
		}
	}

	//自分の出目を表示
	printf("出目は%d, %d, %d\n", dice[0][0], dice[0][1], dice[0][2]);

	if (dice[0][0] == dice[0][1] && dice[0][0] == dice[0][2]) {
		strcpy_s(role, "ゾロ目");
		if (dice[0][0] == 1) {
			strcpy_s(role, "ピンゾロ");
		}
	} else if (dice[0][0] == dice[0][1] && dice[0][0] != dice[0][2]) {
		sprintf_s(role, "%dの目", dice[0][2]);
	} else if (dice[0][0] == dice[0][2] && dice[0][0] != dice[0][1]) {
		sprintf_s(role, "%dの目", dice[0][1]);
	} else if (dice[0][1] == dice[0][2] && dice[0][1] != dice[0][1]) {
		sprintf_s(role, "%dの目", dice[0][1]);
	}
	printf("%sだね。次はワシがサイコロを振ろう\n\n", role);

	printf("続行するには何かキーを押してください . . .");
	(void)getchar();//実際の入力待ち
	return 0;
}