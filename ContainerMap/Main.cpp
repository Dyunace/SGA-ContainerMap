// ContainerMap v0.3
#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};

	Vector3(const float& _x, const  float& _y)
		: x(_x), y(_y), z(0.0f) {};

	Vector3(const float& _x, const  float& _y, const float& _z)
		: x(_x), y(_y), z(_z) {};
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Object
{
	Transform Info;

	Object() {};

	Object(const Transform& _Info) : Info(_Info) {};
};

struct Player : public Object
{
	Player() {};

	Player(const Transform& _Info) : Object(_Info) {};
};

map<string, list<Object*>> Objects;

void Initialize();
void AddObject(string _Key, Object* _Object);

int main(void)
{
	Initialize();

	Transform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	AddObject("Player", new Player(Info));

	/*
	for (auto iter = Objects.begin()->second.begin();
		iter != Objects.begin()->second.end(); ++iter)
	{
		cout << (*iter)->Info.Position.x << endl;
		cout << (*iter)->Info.Position.y << endl;
		cout << (*iter)->Info.Position.z << endl;
	}
	*/

	for (auto iter = Objects.begin();
		iter != Objects.end(); ++iter)
	{
		cout << "Key Name : " << iter->first << endl;

		for (auto iter2 = iter->second.begin();
			iter2 != iter->second.end(); ++iter2)
		{
			cout << "Pos X : " << (*iter2)->Info.Position.x << endl;
			cout << "Pos Y : " << (*iter2)->Info.Position.y << endl;
			cout << "Pos Z : " << (*iter2)->Info.Position.z << endl << endl;
		}
	}

	return 0;
}

void Initialize()
{
	Transform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}

void AddObject(string _Key, Object* _Object)
{
	auto iter = Objects.find(_Key);

	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	else
		iter->second.push_back(_Object);
}
