#pragma once

/*
�N���X��:CLIConstants
�T�v:���b�Z�[�W���̌Œ�l��ۊǂ���N���X
�쐬��:10��3��(��)
�쐬��:���c�C�V
*/
ref class CLIConstants {
public:
	System::String^ MESSAGE_FAILD_TO_READ_JSON = "�t�@�C����ǂ߂��߂܂���ł����B\n�w�肳�ꂽ�t�@�C���ɂ��Č������Ă��������B";
	System::String^ MESSAGE_INVALID_VALUE = "���͂���Ă���l�������ł�";
	System::String^ MESSAGE_HAVE_NOT_VIEW_TABLE_YET = "���JSON��ǂݍ��ނ��A\n�s��w�肵�ĕ\���쐬���Ă�������";
	System::String^ MESSAGE_ALL_CLEAR = "���ׂč폜���܂�\n��낵���ł����H";
	System::String^ MESSAGE_EMPTY_NODE_NAME = "�m�[�h������ł��B\n�l����͂��ĉ�����";
	System::String^ MESSAGE_CREATE_JSON_ERROR = "���͂��ꂽJSON�\���ŃG���[���������܂����B\n�m�F���Ă�������";
	System::String^ MESSAGE_CREATED = "JSON�쐬�����I�I";
	System::String^ MESSAGE_NOT_SELECTED_CELL= "�Z����I�����Ă�������";

	System::String^ MESSAGE_FAILED_TO_CONNECT_DB = "DB�ɐڑ��ł��܂���ł����B\nDB�����m�F���ĉ�����";
	System::String^ MESSAGE_FAILED_TO_CONNECT_MySQL = "MySQL�ɐڑ��ł��܂���ł����B\nMySQL���N�����Ă��邱�Ƃ��m�F���ĉ�����";
	System::String^ MESSAGE_FAILED_TO_ROGIN = "DB�ւ̃��O�C���Ɏ��s���܂����B";
	System::String^ MESSAGE_INVALID_QUERY = "�����ȃN�G�����������܂����B\n���ʂ�Ԃ��N�G������͂��ĉ�����";
	System::String^ MESSAGE_QUERY_SYNTAX_ERROR = "���͂��ꂽ�N�G���ɕ��@�I�Ȍ�肪����܂��B\n�m�F���Ă�������";
};