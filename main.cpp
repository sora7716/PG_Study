#include <stdio.h>

//元号
enum EraNumber :int {
	kReiwa,
	kHeisei,
	kShowa,
	kTaisho,
	kMeiji,
	kEraNumberCount,
};

int main() {
	//元号の名前
	const char* eraNumbaerName[static_cast<int>(kEraNumberCount)] = { "令和","平成","昭和","大正","明治" };
	//元号の名前のダブルポインタ
	char** pp_eraNumberName = const_cast<char**>(eraNumbaerName);
	//元号を受け取る
	EraNumber inputEraNumber = kEraNumberCount;
	//元号の開始年数(西暦)
	int startEraNumbers[static_cast<int>(kEraNumberCount)] = { 2019,1989,1926,1912,1868 };
	//最終的な西暦
	int westernCalendar = 0;
	//n年の何年かを受け取る
	int inputYear = 0;
	//ループをやめるかどうかを入力する
	char inputFinishedLoop = '\0';

	//元号を入力して西暦を求めるプログラムのループを開始
	while (inputFinishedLoop != '!') {
		//プログラムの説明
		printf("元号を入力すると西暦を出力するプログラムです\n例えば昭和100年なども計算できます。\n\n");

		//元号を入力するループ
		while (true) {
			//元号の選択
			printf("元号を選択してください : 0:令和　1:平成 2:昭和 3:大正　4:明治\n元号:");
			//年号を入力
			scanf_s("%d", &inputEraNumber);
			if (inputEraNumber > kMeiji) {
				printf("設定されていない元号が入力されました\n");
				continue;
			} else {
				//年号を算出
				pp_eraNumberName += static_cast<int>(inputEraNumber);
				//入力された年号の名前を出力
				printf("%sですね\n", *pp_eraNumberName);
				break;//ループを抜ける
			}
		}

		//年号の年数を入力するループ
		while (true) {
			printf("%s年かを設定してください:", *pp_eraNumberName);
			scanf_s("%d", &inputYear);
			//元号ごとに西暦を計算
			switch (inputEraNumber) {
				//令和
			case kReiwa:
				westernCalendar += inputYear + startEraNumbers[static_cast<int>(kReiwa)] - 1;
				break;
				//平成
			case kHeisei:
				westernCalendar += inputYear + startEraNumbers[static_cast<int>(kHeisei)] - 1;
				break;
				//昭和
			case kShowa:
				westernCalendar += inputYear + startEraNumbers[static_cast<int>(kShowa)] - 1;
				break;
				//大正
			case kTaisho:
				westernCalendar += inputYear + startEraNumbers[static_cast<int>(kTaisho)] - 1;
				break;
				//明治
			case kMeiji:
				westernCalendar += inputYear + startEraNumbers[static_cast<int>(kMeiji)] - 1;
				break;
			}
			printf("%s%d年の西暦は%d年です\n", *pp_eraNumberName, inputYear, westernCalendar);

			//ループをやめるかどうか
			printf("ループをやめますか?\nやめる場合は!を入力してください:続ける場合は!以外の文字を入力してください\n");
			printf("文字を入力:");
			inputFinishedLoop = getchar();
			//入力処理の冗長
			char inputBuffer = '\0';
			//改行を排除
			while ((inputBuffer = getchar()) != '\n') {
				inputFinishedLoop = inputBuffer;
			}
			//inputFinishedLoopがヌル文字以外が入っていた場合
			if (inputFinishedLoop != '\0') {
				//値の初期化
				inputFinishedLoop = '\0';//ヌル文字を入れる
				westernCalendar = 0;//ゼロに初期化
				inputEraNumber = kEraNumberCount;//元号の数を入れる
				inputYear = 0;//年数をゼロに初期化
				pp_eraNumberName = const_cast<char**>(eraNumbaerName);//元号の名前のポインタを初期化
				printf("\n\n");
				break;
			}
		}
	}
	return 0;
}