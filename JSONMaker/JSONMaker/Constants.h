#pragma once

#ifndef __Constants
#define __Constants

#include <string>
#include <fstream>
#include <iostream>
#include "boost\property_tree\ptree.hpp"
#include <windows.h>
#include "boost\property_tree\json_parser.hpp"

class Constants {
public:
	const std::string Message_check_bro_error = "兄弟のセルにキーが空でないものと空のものが混在しています。確認して下さい。";
	static const int CODE_UTF8 = 0;
	static const int CODE_SJIS = 1;
	static const int LEVEL_PARENT = 0;
	static const int COLUMN_ONE = 0;

	static const int FROM_MAINFORM = 0;
	static const int FROM_PARENT_BUTTON = 1;
	static const int FROM_CHILD_BUTTON = 2;
	static const int FROM_BIGBRO_BUTTON = 3;
	static const int FROM_BRO_BUTTON = 4;

	static const int IS_SUB_FORM = 1;

	const std::string STR_INVALID_CELL = "";
	const std::string STR_NOVALUE = "";

	const std::string STR_DB_HOST_NAME = "tcp://127.0.0.1:3306";
	const std::string STR_DB_USER_NAME = "root";
	const std::string STR_DB_PASSWD = "";

	const std::string MESSAGE_FAILED_TO_CONNECT_DB = "入力されているDBに接続できませんでした。DB名を確認して下さい。";
	const std::string MESSAGE_CANNOT_CONNECT_MySQL = "MySQLに接続できませんでした。MySQLが起動していることを確認して下さい";
	const std::string MESSAGE_INVALID_QUERY = "入力されたクエリが無効です。結果を返すクエリを入力して下さい";
	const std::string MESSAGE_ARRAY_ERROR = "配列のJSON作成の際にキーの入った要素が見つかりました。確認してください。";
	const std::string MESSAGE_OBJECT_ARRAY_ERROR = "オブジェクト配列の作成の際にキーのない要素が見つかりました。確認してください。";

	const int CODE_DB_ERROR = 1049;
	const int CODE_MYSQL_ERROR = 2003;
	const int CODE_ROGIN_ERROR = 1045;
	const int CODE_QUERY_SYNTAX_ERROR = 1064;
	const int CODE_INVALID_QUERY_ERROR = 0;
	
	
	void fileout(std::string str)
	{
		std::string filename = "debug.txt";
		std::ofstream ofs;
		ofs.open(filename, std::ios::app);
		ofs << str << std::endl;
		ofs.close();
	}

	void jsonfileout(boost::property_tree::ptree json) {
		std::stringstream ss;
		boost::property_tree::write_json(ss, json);
		fileout(ss.str());
	}

	//utf8をSJISに変換する関数
	//ファイルの文字コードがutf8であり、フォームで使う文字列がSJISのため
	std::string UTF8toSjis(std::string srcUTF8) {
		//Unicodeへ変換後の文字列長を得る
		int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);
		//必要な分だけUnicode文字列のバッファを確保
		wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
		//UTF8からUnicodeへ変換
		MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);
		//ShiftJISへ変換後の文字列長を得る
		int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
		//必要な分だけShiftJIS文字列のバッファを確保
		char* bufShiftJis = new char[lengthSJis];
		//UnicodeからShiftJISへ変換
		WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);
		std::string strSJis(bufShiftJis);
		delete bufUnicode;
		delete bufShiftJis;
		return strSJis;
	}

	//SJISからutf8に変換する関数
	//フォームで使う文字列がSJISであり、JSONファイルの文字コードがutf8のため
	std::string SjistoUTF8(std::string srcSjis) {
		//Unicodeへ変換後の文字列長を得る
		int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);
		//必要な分だけUnicode文字列のバッファを確保
		wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
		//ShiftJISからUnicodeへ変換
		MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);
		//UTF8へ変換後の文字列長を得る
		int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
		//必要な分だけUTF8文字列のバッファを確保
		char* bufUTF8 = new char[lengthUTF8];
		//UnicodeからUTF8へ変換
		WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);
		std::string strUTF8(bufUTF8);
		delete bufUnicode;
		delete bufUTF8;
		return strUTF8;
	}

	/*
	関数名:StrToC_str
	概要:System::String^からstd::stringに変換して返す関数
	引数:String^ 変換元
	返却値:string 変換後の文字列
	作成日:9月15日(金)
	作成者:成田修之
	*/
	std::string StrToc_str(System::String^ temp) {
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	}

	/*
	関数名:ArrayToVector
	概要:array<String^>^からvector<string>への変換
	引数:array<String^>^ arr　変換元の配列
	返却値:vector<string> vec　変換後の配列
	作成日:9月30日
	作成者:成田修之
	*/
	std::vector<std::string> ArrayToVector(cli::array<System::String^>^ ar) {
		//返却する配列を引数の配列の長さで確保
		std::vector<std::string> vec(ar->Length);
		//配列の長さ分繰り返す
		for (int i = 0; i < ar->Length; i++) {
			//String^をstringに変換して代入
			vec[i] = StrToc_str(ar[i]);
		}
		//作成した配列を返却する
		return vec;
	}

	/*
	関数名:vectorToArray
	概要:vector<string>からarray<String^>^への変換
	引数:vector<string> vec　変換元の配列
	返却値:array<String^>^ arr　変換後の配列
	作成日:9月30日
	作成者:成田修之
	*/
	cli::array<System::String^>^ vectorToArray(std::vector<std::string> vec) {
		//返却する配列を引数の配列の長さ分で確保
		cli::array<System::String^>^ retArr = gcnew cli::array<System::String^>(vec.size());
		//配列の長さ分繰り返す
		for (int i = 0; i < retArr->Length; i++) {
			//各要素を変換して代入
			retArr[i] = gcnew System::String(vec[i].c_str());
		}
		//作成した配列を返却する
		return retArr;
	}
};

static Constants constants;

#endif // !__Constants
