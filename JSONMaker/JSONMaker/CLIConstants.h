#pragma once

/*
クラス名:CLIConstants
概要:メッセージ等の固定値を保管するクラス
作成日:10月3日(火)
作成者:成田修之
*/
ref class CLIConstants {
public:
	System::String^ MESSAGE_FAILD_TO_READ_JSON = "ファイルを読めこめませんでした。\n指定されたファイルについて見直してください。";
	System::String^ MESSAGE_INVALID_VALUE = "入力されている値が無効です";
	System::String^ MESSAGE_HAVE_NOT_VIEW_TABLE_YET = "先にJSONを読み込むか、\n行列指定して表を作成してください";
	System::String^ MESSAGE_ALL_CLEAR = "すべて削除します\nよろしいですか？";
	System::String^ MESSAGE_EMPTY_NODE_NAME = "ノード名が空です。\n値を入力して下さい";
	System::String^ MESSAGE_CREATE_JSON_ERROR = "入力されたJSON構造でエラーが発生しました。\n確認してください";
	System::String^ MESSAGE_CREATED = "JSON作成完了！！";
	System::String^ MESSAGE_NOT_SELECTED_CELL= "セルを選択してください";

	System::String^ MESSAGE_FAILED_TO_CONNECT_DB = "DBに接続できませんでした。\nDB名を確認して下さい";
	System::String^ MESSAGE_FAILED_TO_CONNECT_MySQL = "MySQLに接続できませんでした。\nMySQLが起動していることを確認して下さい";
	System::String^ MESSAGE_FAILED_TO_ROGIN = "DBへのログインに失敗しました。";
	System::String^ MESSAGE_INVALID_QUERY = "無効なクエリが投げられました。\n結果を返すクエリを入力して下さい";
	System::String^ MESSAGE_QUERY_SYNTAX_ERROR = "入力されたクエリに文法的な誤りがあります。\n確認してください";
};