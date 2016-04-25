#ifndef PSANDS_CISP430_ABSTRACTDATAITEM_H
#define PSANDS_CISP430_ABSTRACTDATAITEM_H

namespace psands_cisp430_a4
{
	class AbstractDataItem
	{
	protected:
		virtual bool isLessThan(const AbstractDataItem * item) const = 0;
		virtual bool isEqual(const AbstractDataItem * item) const = 0;
		virtual bool isGreaterThan(const AbstractDataItem * item) const = 0;
	public:
		AbstractDataItem();

		virtual void copyData(const AbstractDataItem * item) = 0;
	};
}

#endif // !PSANDS_CISP430_ABSTRACTDATAITEM_H

