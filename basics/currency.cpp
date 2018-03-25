
#include "currency.h"
#include <iostream>

currency::currency(signType theSign, unsigned long theDollars,
                   unsigned int theCents) {
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    if (theCents > 99)
        throw illegalParameterValue("Cents should be <100");
    amount = theDollars * 100 + theCents;
    if (theSign == signType::minus)
        amount = -amount;
}

void currency::setValue(double theAmount) {
    if (theAmount < 0)
        amount = (long) ((theAmount - 0.001) * 100);
    else
        amount = (long) ((theAmount + 0.001) * 100);
}

currency currency::add(const currency &x) const {
    currency y;
    y.amount = amount + x.amount;
    return y;
}
void currency::output(ostream& out) const
{// Insert currency value into stream out.
    long theAmount = amount;
    if (theAmount < 0) {out << '-';
        theAmount = -theAmount;}
    long dollars = theAmount / 100; // dollars
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100; // cents
    if (cents < 10) out << '0';
    out << cents;
}

currency currency::operator+(const currency& x) const
{// Add x and *this.
    currency result;
    result.amount = amount + x.amount;
    return result;
}
// overload <<
ostream& operator<<(ostream& out, const currency& x)
{x.output(out); return out;}