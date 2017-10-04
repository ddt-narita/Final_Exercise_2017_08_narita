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
	const std::string Message_check_bro_error = "�Z��̃Z���ɃL�[����łȂ����̂Ƌ�̂��̂����݂��Ă��܂��B�m�F���ĉ������B";
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

	const std::string MESSAGE_FAILED_TO_CONNECT_DB = "���͂���Ă���DB�ɐڑ��ł��܂���ł����BDB�����m�F���ĉ������B";
	const std::string MESSAGE_CANNOT_CONNECT_MySQL = "MySQL�ɐڑ��ł��܂���ł����BMySQL���N�����Ă��邱�Ƃ��m�F���ĉ�����";
	const std::string MESSAGE_INVALID_QUERY = "���͂��ꂽ�N�G���������ł��B���ʂ�Ԃ��N�G������͂��ĉ�����";
	const std::string MESSAGE_ARRAY_ERROR = "�z���JSON�쐬�̍ۂɃL�[�̓������v�f��������܂����B�m�F���Ă��������B";
	const std::string MESSAGE_OBJECT_ARRAY_ERROR = "�I�u�W�F�N�g�z��̍쐬�̍ۂɃL�[�̂Ȃ��v�f��������܂����B�m�F���Ă��������B";

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

	//utf8��SJIS�ɕϊ�����֐�
	//�t�@�C���̕����R�[�h��utf8�ł���A�t�H�[���Ŏg��������SJIS�̂���
	std::string UTF8toSjis(std::string srcUTF8) {
		//Unicode�֕ϊ���̕����񒷂𓾂�
		int lenghtUnicode = MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, NULL, 0);
		//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
		wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
		//UTF8����Unicode�֕ϊ�
		MultiByteToWideChar(CP_UTF8, 0, srcUTF8.c_str(), srcUTF8.size() + 1, bufUnicode, lenghtUnicode);
		//ShiftJIS�֕ϊ���̕����񒷂𓾂�
		int lengthSJis = WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
		//�K�v�ȕ�����ShiftJIS������̃o�b�t�@���m��
		char* bufShiftJis = new char[lengthSJis];
		//Unicode����ShiftJIS�֕ϊ�
		WideCharToMultiByte(CP_THREAD_ACP, 0, bufUnicode, lenghtUnicode + 1, bufShiftJis, lengthSJis, NULL, NULL);
		std::string strSJis(bufShiftJis);
		delete bufUnicode;
		delete bufShiftJis;
		return strSJis;
	}

	//SJIS����utf8�ɕϊ�����֐�
	//�t�H�[���Ŏg��������SJIS�ł���AJSON�t�@�C���̕����R�[�h��utf8�̂���
	std::string SjistoUTF8(std::string srcSjis) {
		//Unicode�֕ϊ���̕����񒷂𓾂�
		int lenghtUnicode = MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, NULL, 0);
		//�K�v�ȕ�����Unicode������̃o�b�t�@���m��
		wchar_t* bufUnicode = new wchar_t[lenghtUnicode];
		//ShiftJIS����Unicode�֕ϊ�
		MultiByteToWideChar(CP_THREAD_ACP, 0, srcSjis.c_str(), srcSjis.size() + 1, bufUnicode, lenghtUnicode);
		//UTF8�֕ϊ���̕����񒷂𓾂�
		int lengthUTF8 = WideCharToMultiByte(CP_UTF8, 0, bufUnicode, -1, NULL, 0, NULL, NULL);
		//�K�v�ȕ�����UTF8������̃o�b�t�@���m��
		char* bufUTF8 = new char[lengthUTF8];
		//Unicode����UTF8�֕ϊ�
		WideCharToMultiByte(CP_UTF8, 0, bufUnicode, lenghtUnicode + 1, bufUTF8, lengthUTF8, NULL, NULL);
		std::string strUTF8(bufUTF8);
		delete bufUnicode;
		delete bufUTF8;
		return strUTF8;
	}

	/*
	�֐���:StrToC_str
	�T�v:System::String^����std::string�ɕϊ����ĕԂ��֐�
	����:String^ �ϊ���
	�ԋp�l:string �ϊ���̕�����
	�쐬��:9��15��(��)
	�쐬��:���c�C�V
	*/
	std::string StrToc_str(System::String^ temp) {
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	}

	/*
	�֐���:ArrayToVector
	�T�v:array<String^>^����vector<string>�ւ̕ϊ�
	����:array<String^>^ arr�@�ϊ����̔z��
	�ԋp�l:vector<string> vec�@�ϊ���̔z��
	�쐬��:9��30��
	�쐬��:���c�C�V
	*/
	std::vector<std::string> ArrayToVector(cli::array<System::String^>^ ar) {
		//�ԋp����z��������̔z��̒����Ŋm��
		std::vector<std::string> vec(ar->Length);
		//�z��̒������J��Ԃ�
		for (int i = 0; i < ar->Length; i++) {
			//String^��string�ɕϊ����đ��
			vec[i] = StrToc_str(ar[i]);
		}
		//�쐬�����z���ԋp����
		return vec;
	}

	/*
	�֐���:vectorToArray
	�T�v:vector<string>����array<String^>^�ւ̕ϊ�
	����:vector<string> vec�@�ϊ����̔z��
	�ԋp�l:array<String^>^ arr�@�ϊ���̔z��
	�쐬��:9��30��
	�쐬��:���c�C�V
	*/
	cli::array<System::String^>^ vectorToArray(std::vector<std::string> vec) {
		//�ԋp����z��������̔z��̒������Ŋm��
		cli::array<System::String^>^ retArr = gcnew cli::array<System::String^>(vec.size());
		//�z��̒������J��Ԃ�
		for (int i = 0; i < retArr->Length; i++) {
			//�e�v�f��ϊ����đ��
			retArr[i] = gcnew System::String(vec[i].c_str());
		}
		//�쐬�����z���ԋp����
		return retArr;
	}
};

static Constants constants;

#endif // !__Constants
