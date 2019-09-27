#include"MenuPrincipal.h"
#include<cstdlib>
#include<ctime>
using namespace System;
using namespace System::Windows::Forms;
int main() {
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Project2::MenuPrincipal());
	return 0;
}
