#include <Oasis.h>

#include <Windows.h>

using namespace Oasis;

 int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	Root root(IntVector2(400, 400), "Test");
	
	Texture t;
	t.loadFromFile("..\\..\\..\\..\\..\\Demonstration\\Media\\HelloWorld.png");

	Sprite *s1  = root.getSpriteManager()->createItem();
	s1->setTexture(&t, IntRectangle(0, 0, 20, 20));

	Sprite *s2  = root.getSpriteManager()->createItem();
	s2->setTexture(&t, IntRectangle(0, 0, 20, 20));

	s2->move(20, 20);

	root.Run();

	return 0;
};