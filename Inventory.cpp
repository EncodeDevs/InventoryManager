#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::setItem(Item item, int index)
{
	this->items[index] = item;
}

Item Inventory::getItem(int index)
{
	return this->items[index];
}

void Inventory::removeItem(int index)
{
	this->setItem(ITEM_AIR, index);
}

int Inventory::getCurrentSlot()
{
	return this->currentSlot;
}

void Inventory::setCurrentSlot(int slot)
{
	if (!this->isValidSlot(slot)) return;
	this->currentSlot = slot;
}

Item Inventory::getCurrentItem()
{
	return this->getItem(this->currentSlot);
}

void Inventory::increaseSlot()
{
	this->increaseSlot(1);
}

void Inventory::increaseSlot(int value)
{
	int newslot = this->currentSlot + value;
	if (newslot > this->getMaxSlots() - 1) newslot = 0;
	this->setCurrentSlot(newslot);
}

void Inventory::decreaseSlot()
{
	this->decreaseSlot(1);
}

void Inventory::decreaseSlot(int value)
{
	int newslot = this->currentSlot - value;
	if (newslot < 0) newslot = this->getMaxSlots();
	this->setCurrentSlot(newslot);
}

bool Inventory::isValidSlot(int slot)
{
	return slot > 0 && slot < this->getMaxSlots();
}

bool Inventory::isFull()
{
	return sizeof(this->getEmptySlots()) >= this->getMaxSlots();
}

vector<int> Inventory::getEmptySlots()
{
	vector<int> result;
	for (int i = 0; i < this->getMaxSlots(); i++)
	{
		if (this->getItem(i).id == ITEM_AIR.id)
		{
			result.push_back(i);
		}
	}
	return result;
}

int Inventory::getMaxSlots()
{
	return sizeof(this->items);
}