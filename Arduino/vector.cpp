#include <Arduino.h>

#include "vector.h"

using namespace std;

vector::vector() {
	topItem = NULL;
	//topIdx = 3;
}

vector::~vector() {
	while(!empty()) {
		pop_back();
	}
}

bool vector::empty() {
	return topItem == NULL;
}

int vector::back() {
	//assert(!isEmpty());
	return topItem->val;
}

void vector::pop_back() {
	//assert(!isEmpty());

	vectorItem *tmp = topItem;
	topItem = tmp->prev;
	delete tmp;
	// if (topIdx == 0) {
	// 	topIdx = 3;
	// 	vectorItem *tmp = topItem;
	// 	topItem = tmp->prev;
	// 	delete[] tmp->arr;
	// 	delete tmp;
	// }
	// else {
	// 	topIdx--;
	// }
}

void vector::push_back(int item) {
	vectorItem *tmp = new vectorItem;
	tmp->val = item;
	//tmp->prev = NULL;

	tmp->prev = topItem;
	topItem = tmp;

	// if (botItem==NULL) {
	// 	assert(topItem == NULL);
	// 	botItem = tmp;
	// }
	// else {
	// 	tmp->prev = topItem;
	// }
	// topItem = tmp;
	// if (topIdx == 3) {
	// 	topIdx = 0;
	// 	vectorItem *tmp = new vectorItem;
	// 	tmp->arr = new int[4];
	// 	tmp->arr[topIdx]=item;
	// 	tmp->prev = topItem;
	// 	topItem = tmp;
	// }
	// else {
	// 	topIdx++;
	// 	topItem->arr[topIdx] = item;
	// }
}
