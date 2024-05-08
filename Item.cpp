#include "Item.h"

Item::Item(string id, string name, bool isItem)
{
	this->id = id;
	this->name = name;
	this->isItem = isItem;
}

Item::~Item()
{
}