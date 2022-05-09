#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>

class Item
{
private:
	std::string m_ItemId;
	int m_Price;
	int m_Count;
public:
	Item(std::string id, int price, int count):
		m_ItemId(id), m_Count(count), m_Price(price)
	{}
	int getCount() const {
		return m_Count;
	}
	std::string getItemId() const {
		return m_ItemId;
	}
	int getPrice() const {
		return m_Price;
	}
	bool operator==(const Item & obj2) const
	{
		if (this->getItemId().compare(obj2.getItemId()) == 0)
			return true;
		else
			return false;
	}
};

std::vector<Item> getItemList()
{
	std::vector<Item> vecOfItems ;
	vecOfItems.push_back(Item("D121", 100, 2));
	vecOfItems.push_back(Item("D122", 12, 5));
	vecOfItems.push_back(Item("D123", 28, 6));
	vecOfItems.push_back(Item("D124", 8, 10));
	vecOfItems.push_back(Item("D125", 99, 3));
	return vecOfItems;
}

bool priceComparision(Item & obj, int y)
{
	if (obj.getPrice() == y)
		return true;
	else
		return false;
}

template <typename T>
struct GenericComparator
{
	typedef int (T::*GETTER)() const;
	GETTER m_getterFunc;
	int m_data;
	GenericComparator(GETTER getterFunc, int data)
	{
		m_getterFunc = getterFunc;
		m_data = data;
	}
	bool operator()(const Item & obj)
	{
		if ((obj.*m_getterFunc)() == m_data)
			return true;
		else
			return false;
	}
};

bool IsLesser10 (int i) {
	return (i < 10);
}

int main()
{

	std::vector<int> vecData{1, 2, 3, 4, 5};

	std::vector<int>::iterator it1;
	it1 = std::find(vecData.begin(), vecData.end(), 2);
	if (it1 != vecData.end()){
		std::cout<<"Using find searching for a number: ";
		std::cout << *it1 << std::endl;
	}
	it1 = std::find_if(vecData.begin(), vecData.end(), IsLesser10);
	if (it1 != vecData.end()){
		std::cout<<"Using find if searching for the first number which fits the criteria: ";
		std::cout << *it1 << std::endl;
	}
	std::cout<<"-------\n";
	std::vector<Item> vecOfItems = getItemList();
	std::vector<Item>::iterator it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D126", 99, 0));
	std::cout<<"Using find: "<<std::endl;
	if (it != vecOfItems.end())
		std::cout << "Found with ID :: " << it->getItemId() << " Price ::" << it->getPrice() << " Count :: " << it->getCount() << std::endl;
	else
		std::cout << "Item with ID :: D126 not Found" << std::endl;

	it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D124", 99, 0));
	if (it != vecOfItems.end())
		std::cout << "Found with ID :: " << it->getItemId() << " Price ::" << it->getPrice() << " Count :: " << it->getCount() << std::endl;
	else
		std::cout << "Item with ID :: D124 not Found" << std::endl;
	std::cout<<"-------\n";
	std::cout<<"Using find if: "<<std::endl;
	it = std::find_if(vecOfItems.begin(), vecOfItems.end(), [](Item const & obj) {
		return obj.getPrice() == 28;
	} );

	if (it != vecOfItems.end())
		std::cout << "Found with ID :: " << it->getItemId() << " Price ::" << it->getPrice() << " Count :: " << it->getCount() << std::endl;
	else
		std::cout << "Item not Found" << std::endl;

	it = std::find_if(vecOfItems.begin(), vecOfItems.end(), std::bind(priceComparision, std::placeholders::_1 , 28));
	if (it != vecOfItems.end())
		std::cout << "Found with ID :: " << it->getItemId() << " Price ::" << it->getPrice() << " Count :: " << it->getCount() << std::endl;
	else
		std::cout << "Item not Found" << std::endl;

	it = std::find_if(vecOfItems.begin(), vecOfItems.end(), GenericComparator<Item>(&Item::getPrice, 99));
	if (it != vecOfItems.end())
		std::cout << "Found with ID :: " << it->getItemId() << " Price ::" << it->getPrice() << " Count :: " << it->getCount() << std::endl;
	else
		std::cout << "Item not Found" << std::endl;

	return 0;
}