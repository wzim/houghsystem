#include "MainForm1.h"

using namespace UlamSquare;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MainForm mainForm;
	Application::Run(%mainForm);
}