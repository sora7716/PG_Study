#include <iostream>
#include <cmath>
#include <random>

//二次元のベクトル
typedef struct Vector2 {
	float x;
	float y;
}Vector2;

int main() {
	//ランダムエンジンの初期化
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());

	//半径
	float radius = 2.0f;
	//円周率
	float pi = 0.0f;
	//点の打つ数
	int maxPointNum = 10;//点を打つ最大値
	int circleInPointCount = 0;//円の中にある数

	std::cout << "モンテカルロ法は乱数を使う計算方法の一つです." << std::endl;
	std::cout << "ここでは円周率の近似値をモンテカルロ法を使って求めてみます。" << std::endl;
	std::cout << "打つ点の数を入力してください。" << std::endl;

	//点の打つ最大値を入力
	std::cin >> maxPointNum;

	//モンテカルロ法を使用して円周率を計算
	for (int i = 0; i < maxPointNum; i++) {
		//-radius~radiusの範囲でランダムに点を打つ
		std::uniform_real_distribution<float>distribution(-radius, radius);

		//点の位置を設定
		Vector2 pos = { distribution(randomEngine),distribution(randomEngine) };

		//円の中にあるかを調べる
		if (std::sqrt(std::pow(pos.x, 2.0f) + std::pow(pos.y, 2.0f)) <= radius) {
			circleInPointCount++;
		}

		//円周率を計算
		pi = 4.0f * (static_cast<float>(circleInPointCount) / static_cast<float>(i));

		//1000個以上の数を試行する場合は1000の倍数ずつ計算結果を出力する
		if (i % 1000 == 0 && i != 0) {
			std::printf("     %d個の点から計算した円周率は%fです。\n", i, pi);
		}
	}

	std::printf("今回計算した最終的な円周率は%.8fです。\n", pi);
	std::cout << "続行するには何かキーを押してください . . ." << std::endl;
	(void)getchar();//改行を削除
	(void)getchar();//次のキーを押されたら終了する
	return 0;
}