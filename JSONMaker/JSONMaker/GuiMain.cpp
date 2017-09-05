#include "GuiMain.h"

using namespace JSONMaker;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew GuiMain());
	return 0;
}