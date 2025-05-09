#include "func/ProcessCount.h"
#include <memory>

int main(void) {
	//文字
	const char* resultTexts[] = { "if    ","switch" };
	//ダブルポインタ
	char** ppResultTexts = const_cast<char**>(resultTexts);
	//プロセルの計測するクラスの生成
	std::unique_ptr<ProcessCount> processCount = std::make_unique<ProcessCount>();
	//プロセスの計測を初期化
	processCount->Initialize();
	//実行時間を計測
	for (int i = 0;i < 2;i++) {
		processCount->Update(i);
	}
	//横線を表示
	printf("----------------------------------------\n");
	for (int i = 0;i < processCount->GetKeepExecutionTimes().size();i++) {
		//最終結果を表示
		printf("かかった時間%s   : %.8lf\n", *ppResultTexts, processCount->GetKeepExecutionTimes()[i]);
		ppResultTexts++;
	}
	return 0;
}