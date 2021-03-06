#include <iostream>

using namespace std;

class Box
{
public:
	int length;
	int width;
	int height;

	int getVolume()
	{
		return length * width * height;
	}

	void setLength(int l)
	{
		length = l;
	}

	void setWidth(int w)
	{
		width = w;
	}

	void setHeight(int h)
	{
		height = h;
	}

};

int main()
{
	Box box1;
	Box box2;

	box1.setLength(10);
	box1.setWidth(5);
	box1.setHeight(20);
	box1.getVolume();
	cout << box1.getVolume() << endl;

	box2.setLength(20);
	box2.setWidth(10);
	box2.setHeight(40);
	box2.getVolume();
	cout << box2.getVolume() << endl;

	system("PAUSE");
	return 0;
}