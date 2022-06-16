// ContainerMap v0.2
#include <iostream>

#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

map<int, int> Numbers;

void AddData(int _Key, int _Value);

int main(void)
{
	Numbers[0] = 0;
	Numbers[1] = 10;
	Numbers.insert(make_pair(3, 30));

	Numbers[1] = 100;

	AddData(2, 200);

	/*
	Numbers.insert(make_pair(2, 200));

	iter->second = 200;
	*/

	for (auto iter = Numbers.begin();
		iter != Numbers.end(); ++iter)
		cout << iter->second << endl;

	return 0;
}

void AddData(int _Key, int _Value)
{
	auto iter = Numbers.find(_Key);

	if (iter == Numbers.end())
		Numbers.insert(make_pair(_Key, _Value));
	else
		iter->second = _Value;
}