#ifndef PSANDS_CISP430_INTEGERDATAITEM_H
#define PSANDS_CISP430_INTEGERDATAITEM_H

#include "AbstractDataItem.h"

namespace psands_cisp430_a4
{
	class IntegerDataItem :
		public AbstractDataItem
	{
	private:
		int _data;

	protected:
		bool isLessThan(const AbstractDataItem * item) const override;
		bool isEqual(const AbstractDataItem * item) const override;
		bool isGreaterThan(const AbstractDataItem * item) const override;

	public:
		IntegerDataItem();
		IntegerDataItem(const int data);
		IntegerDataItem(const IntegerDataItem & item);

		int getData() const;

		void copyData(const AbstractDataItem * item) override;
	};
}

#endif // !PSANDS_CISP430_INTEGERDATAITEM_H
