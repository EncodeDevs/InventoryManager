#pragma once
#include "Item.h"
#include <vector>

class Inventory
{
private:
	Item items[5];
	int currentSlot = 0;
public:
	Inventory();
	~Inventory();

	void setItem(Item item, int index);
	Item getItem(int index);
	void removeItem(int index);
	
	int getCurrentSlot();
	void setCurrentSlot(int slot);
	Item getCurrentItem();
	
	void increaseSlot();
	void increaseSlot(int value);
	void decreaseSlot();
	void decreaseSlot(int value);

	bool isValidSlot(int slot);

	bool isFull();
	vector<int> getEmptySlots();
	int getMaxSlots();
	void clear();
};