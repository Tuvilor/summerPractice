#include "Graphics.h"
#include "GunGame.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");
	SetConsoleTitle("Graphics");
	system("mode con cols=150 lines=60"); //���������� ������ ���� � �����������
	HANDLE HandleCons = ::GetStdHandle(STD_OUTPUT_HANDLE);
	HWND hWnd = GetConsoleWindow(); //�������� ������ �� ����

	Graphics::InitGraphics(hWnd);
	Sleep(50);

	//----------------������ ������ Graphics---------------------

	int wid = Graphics::GetWid();
	int heg = Graphics::GetHeg();


	Sphere sp(0, 0, 10);
	Sphere::VisSphere(&sp, 1);

	Matrix mt;

	Gun gun(0, 0, wid/2, heg/2);

	Graphics::Osi();


	cin.get();
	
	return 0;
}