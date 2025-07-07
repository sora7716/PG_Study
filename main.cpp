#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//リストの要素数
const int kListSize = 10;

//リストの出力
void ListPrint(int* lists) {
	for (int i = 0; i < kListSize; i++) {
		printf("%d,", lists[i]);
	}
	printf("\n");
}

/// <summary>
/// シェルソート
/// </summary>
/// <param name="lists">リスト</param>
void ShellSort(int* lists) {
	//検索範囲
	int range = kListSize;

	while (range > 0) {
		//検索範囲分の挿入ソートを実行
		for (int i = range; i < kListSize; i++) {
			int temp = lists[i];
			int index = i - 1;
			while (index >= range && lists[index - range] > temp) {
				lists[index] = lists[index - range];
				index -= range;
			}
			lists[index] = temp;
		}

		//検索範囲を半分にする
		if (range / 2 != 0) {
			range /= 2;
		} else if (range == 1) {
			range = 0;// ループを終了するために0に設定
		} else {
			range = 1;// 1に設定して次のループで終了
		}
	}
}



int main() {
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//ソートするリスト
	int lists[kListSize] = {};
	//検索範囲
	int range = kListSize - 1;
	//リストの初期化
	for (int i = 0; i < kListSize; i++) {
		lists[i] = rand() % 100; // 0〜99の乱数を生成
	}
	//ソート前のリストを出力
	printf("ソート前のリスト:");
	ListPrint(lists);

	//シェルソートを実行
	ShellSort(lists);

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}