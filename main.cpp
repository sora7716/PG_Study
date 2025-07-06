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

	//挿入ソート開始
	while (range > 0) {
		//ここは挿入ソート
		for (int i = 0; i < kListSize; i++) {
			int temp = lists[i]; //挿入する値を一時保存
			int index = i - 1;
			while (index >= 0 && lists[index] > temp) {
				lists[index + 1] = lists[index];//右に移動
				index--;
			}
			lists[index + 1] = temp;
		}

		//ここがシェルソートで追加された部分
		if (range / 2 != 0) {
			range /= 2; //範囲を半分にする
		} else if (range == 1) {
			range = 0;//範囲が1のときは終了
		} else {
			range = 1;//範囲が偶数のときは1にする
		}
	}

	//ソート後のリストを出力
	printf("ソート後のリスト:");
	ListPrint(lists);
	return 0;
}