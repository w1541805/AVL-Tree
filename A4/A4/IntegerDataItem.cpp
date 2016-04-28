#include "IntegerDataItem.h"

bool psands_cisp430_a4::IntegerDataItem::isLessThan(const AbstractDataItem * item) const
{
	return this->getData() < ((IntegerDataItem *)item)->getData();
}

bool psands_cisp430_a4::IntegerDataItem::isLessThan(const AbstractDataItem & item) const
{
	return this->isLessThan(&item);
}

bool psands_cisp430_a4::IntegerDataItem::isEqual(const AbstractDataItem * item) const
{
	return this->getData() == ((IntegerDataItem *)item)->getData();
}

bool psands_cisp430_a4::IntegerDataItem::isEqual(const AbstractDataItem & item) const
{
	return this->isEqual(&item);
}

bool psands_cisp430_a4::IntegerDataItem::isGreaterThan(const AbstractDataItem * item) const
{
	return this->getData() > ((IntegerDataItem *)item)->getData();
}

bool psands_cisp430_a4::IntegerDataItem::isGreaterThan(const AbstractDataItem & item) const
{
	return this->isGreaterThan(&item);
}

psands_cisp430_a4::IntegerDataItem::IntegerDataItem()
{
	this->_data = 0;
}

psands_cisp430_a4::IntegerDataItem::IntegerDataItem(const int data)
{
	this->_data = data;
}

psands_cisp430_a4::IntegerDataItem::IntegerDataItem(const IntegerDataItem & item) : IntegerDataItem(item.getData())
{
}

int psands_cisp430_a4::IntegerDataItem::getData() const
{
	return this->_data;
}

void psands_cisp430_a4::IntegerDataItem::copyData(const AbstractDataItem * item)
{
	this->_data = ((IntegerDataItem *)item)->getData();
}

void psands_cisp430_a4::IntegerDataItem::copyData(const AbstractDataItem & item)
{
	this->copyData(&item);
}
