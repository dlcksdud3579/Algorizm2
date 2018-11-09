#pragma once
class Sets
{
public:
	Sets(int sz);
	void weightedUnion(int i, int j);
	void SimpleUnion(int i, int j);
	int	CollapsingFind(int i);
	int SimpleFind(int i);
	~Sets();
private:
	int *parent;
	int n; // number of set elements

};

