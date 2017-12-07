#ifndef VECTOR_H
#define VECTOR_H

struct vectorItem {
	int val;
	vectorItem *prev;
};

class vector {
public:

	vectorItem *topItem;
	//int topIdx;

	vector();
  ~vector();
  bool empty();
  int back();
  void pop_back();
  void push_back(int item);
};

#endif
