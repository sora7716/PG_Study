#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//二次元のベクトル
typedef struct Vector2 {
	float x;
	float y;
}Vector2;

int main() {
	//ランド関数の初期化
	srand(static_cast<unsigned int>(time(nullptr)));
	//円周率
	float pi = 0.0f;
	//点の打つ数
	int maxPointNum = 10;//点を打つ最大値
	int circleInPointCount = 0;//円の中にある数

	printf("モンテカルロ法は乱数を使う計算方法の一つです.\n");
	printf("ここでは円周率の近似値をモンテカルロ法を使って求めてみます。\n");
	printf("打つ点の数を入力してください。\n");

	//点の打つ最大値を入力
	scanf_s("%d", &maxPointNum);

	//モンテカルロ法を使用して円周率を計算
	for (int i = 0; i < maxPointNum; i++) {
		//点の位置を設定
		Vector2 pos = {
			((float)rand() / RAND_MAX) * 2.0f - 1.0f,
			((float)rand() / RAND_MAX) * 2.0f - 1.0f
		};

		//円の中にあるかを調べる
		if (powf(pos.x, 2.0f) + powf(pos.y, 2.0f) <= 1.0f) {
			circleInPointCount++;
		}

		//円周率を計算
		pi = 4.0f * (static_cast<float>(circleInPointCount) / static_cast<float>((i)));

		//1000個以上の数を試行する場合は1000の倍数ずつ計算結果を出力する
		if (i % 1000 == 0 && i != 0) {
			printf("%d個の点から計算した円周率は%fです。\n", i, pi);
		}
	}

	printf("今回計算した最終的な円周率は%fです。\n", pi);
	printf("続行するには何かキーを押してください . . .");
	(void)getchar();//改行を削除
	(void)getchar();//次のキーを押されたら終了する
	return 0;
}