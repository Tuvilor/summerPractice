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
	int wid = Graphics::GetWid();
	int heg = Graphics::GetHeg();

	int amountOfEnemyBolls;
	cout << "������� ���������� ��������� �����: ";
	cin >> amountOfEnemyBolls;
	Gun gun(0, 0, wid/2, heg/2);

	Boll boll(1);
	boll.enemyBollSpawn(amountOfEnemyBolls);


	Graphics::Osi();


	cin.get();
	return 0;
}