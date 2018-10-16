#include "AdjList.h"



AdjList::AdjList(int _rowNum)
{
	rowList = new Llist*[_rowNum];
	for (int i = 0; i < _rowNum; i++)
	{
		rowList[i] = new Llist();
	}
	this->rowNum = _rowNum;

}
void AdjList::InsertNode(int rowNum, Node* inPutNode)
{
	rowList[rowNum]->InsertNode(inPutNode);
}
string AdjList::toString()
{
	string result = "";
	std::ostringstream ostr;

	for (int i = 0; i < rowNum; i++)
	{
		ostr << to_string(i) << ": ";
		ostr << rowList[i]->toString() << "\n";
	}

	return ostr.str();
}
Llist* AdjList::getList(int _rowNum)
{
	return this->rowList[_rowNum];
}
AdjList::~AdjList()
{
	for (int i = 0; i < rowNum; i++)
	{
		rowList[i]->freeList(rowList[i]->getFirstNode());
	}
	delete (rowList);
}
