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
/// 挿入ソート
/// </summary>
/// <param name="lists">リスト</param>
void InsertionSort(int* lists) {
	//挿入ソート開始
	for (int i = 0; i < kListSize; i++) {
		int temp = lists[i]; //挿入する値を一時保存
		int index = i - 1;
		while (index >= 0 && lists[index] > temp) {
			lists[index + 1] = lists[index];//右に移動
			index--;
		}
		lists[index + 1] = temp;
	}
}

int main() {
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//ソートするリスト
	int lists[kListSize] = {};
	//リストの初期化
	for (int i = 0; i < kListSize; i++) {
		lists[i] = rand() % 100; // 0〜99の乱数を生成
	}
	//ソート前のリストを出力
	printf("ソート前のリスト:");
	ListPrint(lists);

	//挿入ソートの実行
	InsertionSort(lists);

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}