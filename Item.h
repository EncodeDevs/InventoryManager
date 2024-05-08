#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item
{
public:
	string id;
	string name;

	bool isItem;

	Item(string id, string name, bool isItem);
	~Item();
};

const Item ITEM_AIR = Item("air", "Air", false);