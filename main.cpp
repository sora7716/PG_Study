#include <iostream>
#include <vector>

/// <summary>
/// フィボナッチ数列
/// </summary>
/// <param name="num">数字</param>
/// <returns></returns>
std::vector<int> FibonacciSequence(int fibonacciLength) {
	//数列
	std::vector<int> sequence;
	//数字が0より小さい場合と1の場合は数列をそのまま返す
	if (fibonacciLength <= 0) {
		return sequence;
	} else if (fibonacciLength == 1) {
		return sequence;
	}
	//長さを設定
	sequence.resize(fibonacciLength);
	//フィボナッチ数列の初期値を設定
	sequence[1] = 1;
	//フィボナッチ数列を生成
	for (int i = 2;i < fibonacciLength;i++) {
		sequence[i] = sequence[i - 1] + sequence[i - 2];
	}
	return sequence;
}

int main() {
	//フィボナッチ数列の長さ
	int fibonacciLength = 10;
	for (auto fibonacci : FibonacciSequence(fibonacciLength)) {
		std::cout << fibonacci << ",";
	}
	return 0;
}