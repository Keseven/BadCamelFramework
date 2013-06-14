#include <Oasis.h>

#include <Windows.h>

 int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Oasis::Root root(Oasis::IntVector2(400, 400), "Test");
	Oasis::IntVector2 v;
	Oasis::Texture t;
	t.loadFromFile("..\\..\\..\\..\\..\\Demonstration\\Media\\HelloWorld.png");
	Oasis::Sprite s;
	s.setTexture(t);

	root.Run();

	return 0;
};