#include "MainForm.h"

using namespace HoughSystemApp;
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

