#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <math.h>

/// <summary>
/// 少し止めてから文字を出力
/// </summary>
/// <param name="string">出力する文字</param>
/// <param name="waitTime">止める時間(秒)</param>
void PrintfWaitString(const char* string, float waitTime) {
	printf("\n%s", string);
	for (int i = 0;i < 3;i++) {
		printf(".");
		Sleep(fabsf(waitTime * 1000.0f));
	}
	printf("\n\n");
}

int main() {
	//入力する文字
	char inputChar = '\0';
	//何文字後を出力したいか
	int nextNum = 0;
	//n文字後のアルファベット
	char nextAlphabet = '\0';
	//入力された文字がアルファベットの最後の文字がどうか
	bool isLastAlphabet = false;
	//終了
	bool isFinished = false;
	//現在のアルファベットの位置
	int currentAlphabetIndex = 0;
	//待ち時間
	float waitTime = 0.5f;
	//更新
	while (true) {
		printf("[n文字後の文字を表示するプログラム]\n\n");
		printf("アルファベットを入力してください。(大文字でも小文字でも可。!で終了)\n");

		//文字の取得
		while (true) {
			printf("アルファベット:");
			//文字の読み込み
			inputChar = getchar();
			//入力文字の冗長
			char inputBuffer = '\0';
			//改行を排除
			while ((inputBuffer = getchar()) != '\n') {
				inputChar = inputBuffer;
			}

			//実行中の文字を表示
			PrintfWaitString("[実行中]", waitTime);

			//もしアルファベットの最後の文字だったら
			if (toupper(inputChar) == 'Z') {
				printf("%cは最後の文字です。%c以外のアルファベットを入力してください\n", inputChar, inputChar);
				isLastAlphabet = true;
				break;//ループを抜ける
			}

			//探索結果を表示
			if (isalpha(inputChar)) {
				//入力した文字を表示
				printf("入力した文字:%c\n\n", inputChar);
				break;//ループを抜ける
			} else if (inputChar == '!') {
				//終了
				isFinished = true;
				break;//ループを抜ける
			}
			else {
				//入力した文字を表示
				printf("A-Yもしくはa-zのアルファベットを入力してください\n\n");
			}
		}

		//終了していたら
		if (isFinished) {
			//終了
			break;
		}

		//何文字後を表示するかを取得
		while (!isLastAlphabet) {
			printf("%cの何文字後を表示するか数字で入力してください\n", inputChar);
			printf("数字:");
			//何文字後を表示するかを取得
			scanf_s("%d", &nextNum);
			nextAlphabet = inputChar + nextNum;

			//n文字後のアルファベットが範囲外だった場合
			if (!isalpha(nextAlphabet)) {
				//次のアルファベットが範囲外の場合
				printf("そのようなアルファベットはありません。数字を入力しなおしてください\n");
			} else {
				break;//ループを抜ける
			}
		}

		if (!isLastAlphabet) {
			//実行中の文字を表示
			PrintfWaitString("[実行中]", waitTime);
			//最終結果を表示
			printf("入力した文字%cの1文字後のアルファベットは%cです\n", inputChar, nextAlphabet);
		}

		//初期化
		PrintfWaitString("[初期化]", waitTime);
		//入力する文字
		inputChar = '\0';
		//何文字後を出力したいか
		nextNum = 0;
		//n文字後のアルファベット
		nextAlphabet = '\0';
		//現在のアルファベットの位置
		currentAlphabetIndex = 0;
		//入力された文字がアルファベットの最後の文字がどうか
		isLastAlphabet = false;
	}
	return 0;
}