#include "MyForm.h"

using namespace ControlTest;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew MyForm());
	return 0;
}