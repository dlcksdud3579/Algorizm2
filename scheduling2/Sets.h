#pragma once
class Sets
{
public:
	Sets(int sz);
	void weightedUnion(int i, int j);
	void SimpleUnion(int i, int j);
	int	CollapsingFind(int i);
	int SimpleFind(int i);
	void setLocation(int index, int value) { location[index] = value;}
	int getLocation(int index ){return  location[index]; }
	~Sets();
private:
	int *parent;
	int *location;
	int n; // number of set elements

};

