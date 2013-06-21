#include <Oasis.h>

#include <Windows.h>

 int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Oasis::Root root(Oasis::IntVector2(400, 400), "Test");
	Oasis::IntVector2 v;
	Oasis::Texture t;
	t.loadFromFile("..\\..\\..\\..\\..\\Demonstration\\Media\\HelloWorld.png");
	Oasis::Sprite *s  = root.getSpriteManager()->createItem("test");
	s->setTexture(&t, Oasis::IntRectangle(0, 0, 20, 20));

	root.Run();

	return 0;
};