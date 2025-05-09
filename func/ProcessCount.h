#pragma once
#include <time.h>
#include <stdio.h>
#include <vector>

/// <summary>
/// 実行したときのプロセス時間を計測するクラス
/// </summary>
class ProcessCount{
public://メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ProcessCount() = default;
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~ProcessCount() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	/// <param name="index">検索</param>
	void Update(int index);

	/// <summary>
	/// keepExecutionTimesのゲッター
	/// </summary>
	/// <returns>keepExecutionTimes</returns>
	std::vector<double> GetKeepExecutionTimes() const;
private://メンバ関数
	/// <summary>
	/// if文の実行時間を計測
	/// </summary>
	void ProcessCountForIf();

	/// <summary>
	/// switch文の実行時間を計測
	/// </summary>
	void ProcessCountForSwitch();
private://定数
	//実行回数
	static const int kProcessCount = 100000;
private://メンバ変数
	//実行時間を保管
	std::vector<double> keepExecutionTimes;
	// メンバ関数ポインタの配列を正しく宣言
	std::vector<void(ProcessCount::*)()>processCountTable;
};