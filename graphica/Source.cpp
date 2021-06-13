#include "Graphics.h"
#include "GunGame.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	SetConsoleTitle("Graphics");
	system("mode con cols=55 lines=30"); //���������� ������ ���� � �����������
	HANDLE HandleCons = ::GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hWnd = GetConsoleWindow(); //�������� ������ �� ����

	Graphics::InitGraphics(hWnd);
	Sleep(50);

	//----------------������ ������ Graphics---------------------

	int wid = Graphics::GetWid();
	int heg = Graphics::GetHeg();

	Graphics::Osi();

	cin.get();
	
	return 0;
}