#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//勝利カウント
typedef struct WinCount {
	int player1;
	int player2;
	int player3;
}WinCount;

//じゃんけんの手
enum Hand {
	kGu = 1,
	kChoki,
	kPa,
	kHandCount,
};

/// <summary>
/// プレイヤーvs プレイヤー
/// </summary>
/// <param name="winner">勝者/param>
/// <param name="loser">敗者</param>
/// <returns></returns>
int PvP(Hand winner, Hand loser) {
	if (winner == kGu && loser == kChoki) {
		return 1;
	} else if (winner == kChoki && loser == kPa) {
		return 1;
	} else if (winner == kPa && loser == kGu) {
		return 1;
	}
	return 0;
}

/// <summary>
/// じゃんけん
/// </summary>
/// <param name="player1">プレイヤー1</param>
/// <param name="player2">プレイヤー2</param>
/// <param name="player3">プレイヤー3</param>
/// <returns>勝利カウント</returns>
WinCount Battle(Hand player1, Hand player2, Hand player3) {
	//勝利カウント
	WinCount winCount = { 0,0,0 };
	winCount.player1 += PvP(player1, player2);
	winCount.player1 += PvP(player1, player3);
	winCount.player2 += PvP(player2, player3);
	winCount.player2 += PvP(player2, player1);
	winCount.player3 += PvP(player3, player1);
	winCount.player3 += PvP(player3, player2);
	return winCount;
}

/// <summary>
/// プレイヤーの手を表示する関数(Hand関数を文字に変換)
/// </summary>
/// <param name="player"></param>
/// <returns></returns>
void PrintfHand(const char* playerName, Hand player) {
	if (player == kGu) {
		printf("%sはグー  です\n", playerName);
	} else if (player == kChoki) {
		printf("%sはチョキです\n", playerName);
	} else {
		printf("%sはパー  です\n", playerName);
	}
}

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

/// <summary>
/// プレイヤーの手を取得する関数
/// </summary>
/// <param name="player">プレイヤー</param>
/// <returns>手</returns>
Hand GetHand(Hand player) {
	if (player == kHandCount) {
		return static_cast<Hand>(rand() % (static_cast<int>(kHandCount) - 1) + 1);
	}
}

int main() {
	//ランド関数の初期化
	srand(unsigned int(time(nullptr)));
	//手の入力
	char inputHand = '\0';
	//inputHandをHand型に変換するための変数
	Hand me = kHandCount;
	//終了するかを確認するための変数
	char finishedCommand = '\0';

	//じゃんけんのループ
	while (true) {
		//自分の手を入力するループ
		while (true) {
			printf("手を入力してください(1…グー,2…チョキ,3…パー)\n");
			printf("あなたの手:");
			//数字を入力
			inputHand = getchar();
			//改行を排除
			DeleteReturn(&inputHand);

			if (!isdigit(inputHand) || inputHand == '0') {
				printf("正しい数字を入力してください\n");
				//初期化
				inputHand = '\0';
				continue;//次のループへ
			} else {
				//char型をHand型に変換
				me = static_cast<Hand>(inputHand - '0');

				//Hand型に直したときにkHandCountより大きい場合
				if (me > kHandCount) {
					printf("正しい数字を入力してください\n");
					//初期化
					inputHand = '\0';
					me = kHandCount;
					continue;//次のループへ
				} else {
					printf("\n");//見やすくするための改行
					break;//ループを抜ける
				}
			}
		}

		//プレイヤー1
		Hand player1 = kHandCount;
		//手を取得
		player1 = GetHand(player1);

		//プレイヤー2
		Hand player2 = kHandCount;
		//手を取得
		player2 = GetHand(player2);

		//出した手を表示
		PrintfHand("あなた     ", me);
		PrintfHand("プレイヤー1", player1);
		PrintfHand("プレイヤー2", player2);
		printf("\n");//見やすくするための改行

		//戦う(勝利カウントを計測)
		WinCount winCount = Battle(me, player1, player2);
		//勝利カウントを表示
		printf("あなた     :%d勝\nプレイヤー1:%d勝\nプレイヤー2:%d勝\n", winCount.player1, winCount.player2, winCount.player3);

		//ループを続けるか
		printf("まだ続けますか?\, やめる場合はqを入力してください。続ける場合はそれ以外のキーを入力して下さい\n");
		//入力を受け取る
		finishedCommand = getchar();
		//改行を排除
		DeleteReturn(&finishedCommand);

		//qが入力されたら終了
		if (finishedCommand == 'q') {
			break;
		} else {
			//値の初期化
			winCount = { 0,0,0 };
			me = kHandCount;
			player1 = kHandCount;
			player2 = kHandCount;
			finishedCommand = '\0';
		}
	}
	return 0;
}