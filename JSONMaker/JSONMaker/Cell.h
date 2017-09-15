#pragma once
namespace narita {

	ref class Cell
	{
	public:
		int col;
		int row;
		System::String^ text;
	public:
		Cell();
		Cell(int row, int col);

		Cell^ operator=(const Cell^ e);
	};

}