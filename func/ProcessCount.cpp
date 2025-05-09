#include "ProcessCount.h"

//初期化
void ProcessCount::Initialize(){
	processCountTable.push_back(&ProcessCount::ProcessCountForIf);
	processCountTable.push_back(&ProcessCount::ProcessCountForSwitch);
}

//更新
void ProcessCount::Update(int index){
	(this->*processCountTable[index])();
}

//keepExecutionTimesのゲッター
std::vector<double> ProcessCount::GetKeepExecutionTimes() const{
	return keepExecutionTimes;
}

//if文の実行時間を計測
void ProcessCount::ProcessCountForIf() {
	//実行時間
	double executionTime = 0.0;
	for (int i = 0;i <= kProcessCount;i++) {
		//プログラム開始から時間をクロック単位で取得
		executionTime = clock();
		if (true) {
			//何もしない
		}
		printf("%dループの経過時間 : %lf\n", i, executionTime / CLOCKS_PER_SEC);
	}
	//最後にif文のかかった時間を出力
	printf("かかった時間%lf\n", executionTime / CLOCKS_PER_SEC);
	//時間を保管
	keepExecutionTimes.push_back(executionTime / CLOCKS_PER_SEC);
}

//switch文の実行時間を計測
void ProcessCount::ProcessCountForSwitch() {
	//実行時間
	double executionTime = 0.0;
	for (int i = 0;i <= kProcessCount;i++) {
		//プログラム開始から時間をクロック単位で取得
		executionTime = clock();
		switch (true) {
		case true:
			//何もしない
			break;
		}
		printf("%dループの経過時間 : %lf\n", i, executionTime / CLOCKS_PER_SEC);
	}
	//最後にswitch文のかかった時間を出力
	printf("かかった時間%lf\n", executionTime / CLOCKS_PER_SEC);
	//時間を保管
	keepExecutionTimes.push_back(executionTime / CLOCKS_PER_SEC);
}

