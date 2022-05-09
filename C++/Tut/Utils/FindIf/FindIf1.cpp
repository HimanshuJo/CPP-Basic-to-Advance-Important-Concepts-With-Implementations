/*
std::find and std::find_if algorithms are used to find first element in the given range.

In this article we will see how to use std::find and std::find_if algorithm with user defined datatypes i.e. Classes & Structures.

Internally std::find algorithm uses the == operator for comparisons. 
For built-in data types like int, std::string etc operator == is by default available but for user defined data types 
i.e classes & struct we need to define == operator.
*/

class Item
{
private:
    std::string  m_ItemId;
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
        if(this->getItemId().compare(obj2.getItemId()) == 0)
            return true;
        else
            return false;
    }
};

std::vector<Item> getItemList()
{
    std::vector<Item> vecOfItems ;
    vecOfItems.push_back(Item("D121",100,2));
    vecOfItems.push_back(Item("D122",12,5));
    vecOfItems.push_back(Item("D123",28,6));
    vecOfItems.push_back(Item("D124",8,10));
    vecOfItems.push_back(Item("D125",99,3));
    return vecOfItems;
}

/*
As std::find uses the == operator for comparision, therefore we have define opeartor == in the Item class.

Lets search for the Item object with Id “126”,
*/

std::vector<Item> vecOfItems = getItemList();
std::vector<Item>::iterator it;
it = std::find(vecOfItems.begin(), vecOfItems.end(), Item("D123",99,0));
if(it != vecOfItems.end())
    std::cout<<"Found with Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
else
    std::cout<<"Item with ID :: D126 not Found"<<std::endl;

/*
As we have hard coded the comparison logic of two Item objects in operator == i.e. based on the Id.
So, what if we need to search for the Item object with specific price, we can not use the == operator for it. How to do it?

Here comes the std::find_if algorithm in picture,

std::find_if finds first element in the given range based on the custom comparator passed. For example,

Lets first create a comparator function,
*/

bool priceComparision(Item & obj, int y)
{
    if(obj.getPrice() == y)
        return true;
    else
        return false;
}

std::vector<Item> vecOfItems = getItemList();
std::vector<Item>::iterator it;
it = std::find_if(vecOfItems.begin(), vecOfItems.end(), std::bind(priceComparision,  std::placeholders::_1 , 28) );
if(it != vecOfItems.end())
    std::cout<<"Item Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
else
    std::cout<<"Item not Found"<<std::endl;

/*
But what if we need to search Item object based on count ? 
Then based on above approach we need to create a different comparator function for it. So, what can we do to improve it?

Lets create a Generic Comparator functor for searching based on any property of a class,
*/

template <typename T>
struct GenericComparator
{
    typedef  int (T::*GETTER)() const;
    GETTER m_getterFunc;
    int m_data;
    GenericComparator(GETTER getterFunc, int data)
    {
        m_getterFunc = getterFunc;
        m_data = data;
    }

    bool operator()(const T  & obj)
    {
        if((obj.*m_getterFunc)() == m_data)
            return true;
        else
            return false;
    }
};

std::vector<Item> vecOfItems = getItemList();
std::vector<Item>::iterator it;
it = std::find_if(vecOfItems.begin(), vecOfItems.end(),  GenericComparator<Item>(&Item::getPrice, 99)   );
if(it != vecOfItems.end())
    std::cout<<"Item Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
else
    std::cout<<"Item not Found"<<std::endl;

/*
What if we don’t want to define this Generic Comparator functor, the how we can find Item object easily with std::find_if ?

Its using lambda functions,
*/

std::vector<Item> vecOfItems = getItemList();
std::vector<Item>::iterator it;
it = std::find_if(vecOfItems.begin(), vecOfItems.end(), [](Item const& obj){
        return obj.getPrice() == 28;
    } );
if(it != vecOfItems.end())
    std::cout<<"Item Price ::"<<it->getPrice()<<" Count :: "<<it->getCount()<<std::endl;
else
    std::cout<<"Item not Found"<<std::endl;