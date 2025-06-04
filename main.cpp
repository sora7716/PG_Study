#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string>
/// <summary>
/// 改行を削除
/// </summary>
/// <param name="input">入力</param>
void DeleteReturn(char* input) {
	//文字入力の冗長
	char inputBuffer = '\0';
	//改行を排除
	while ((inputBuffer = getchar()) != '\n') {
		input = &inputBuffer;
	}

}

int main() {
	//乱数生成器の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//さいころ2つ分
	int diceRoll[2] = {};
	//最終結果を表示
	std::string result = "\0";
	//プレイヤーの答え
	char playerAnswer = '\0';
	while (true) {
		printf("丁を選ぶ場合は0を入力\n半を選ぶ場合は1を入力\n");
		//プレイヤーの答え(受け取る)
		playerAnswer = getchar();
		//改行を削除
		DeleteReturn(&playerAnswer);

		//数字かどうかと数字が0または1かどうかのチェック
		if (!isdigit(playerAnswer)) {
			printf("数字を入力してください\n");
			continue;
		} else if (atoi(&playerAnswer) > 2) {
			printf("0または1を入力してください\n");
			continue;
		}

		//プレイヤーの答えを整数に変換
		int playerAnswerInt = atoi(&playerAnswer);

		//さいころの数分ループさせる
		for (int i = 0; i < 2; i++) {
			//さいころを振る
			diceRoll[i] = rand() % 6 + 1;
			printf("賽の目 : %d\n", diceRoll[i]);
		}

		//さいころの合計を計算
		int diceRollSum = diceRoll[0] + diceRoll[1];
		printf("賽の目の合計 : %d\n", diceRollSum);

		//勝ち負けを判別
		if (diceRollSum % 2 == 0) {
			if (playerAnswerInt == 0) {
				result = "勝ち";
			} else {
				result = "負け";
			}
		} else {
			if (playerAnswerInt == 0) {
				result = "負け";
			} else {
				result = "勝ち";
			}
		}

		printf("結果 : %s", result.c_str());

		//再度プレイするかどうかの確認
		int isFinish = -1;
		printf("\nもう一度プレイしますか？(0:はい, 1:いいえ)\n");
		scanf_s("%d", &isFinish);
		if (isFinish == 0) {
			break;
		} else {
			continue;
		}
	}
	return 0;
}