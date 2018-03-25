#ifndef CPPGO_CURRENCY_H
#define CPPGO_CURRENCY_H

#include <string>
#include <iostream>

using namespace std;
enum signType {
    plus, minus
};

class illegalParameterValue {
public:
    illegalParameterValue(const string &themessage) :
            message("Illegal parameter value") {
        message=themessage;
    }

    illegalParameterValue(char *theMessage) {
        message = theMessage;
    }

    void outputMessage() {
        cout << message << endl;
    }

private:
    string message;
};

class currency {
    friend ostream& operator<<(ostream&, const currency&);
public:
    currency(signType theSign = signType::plus,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);

    ~currency() {}

    void setValue(signType, unsigned long, unsigned int);

    void setValue(double);

    signType getSign() const {
        if (amount < 0)
            return signType::minus;
        else
            return signType::plus;
    }

    unsigned long getDollars() const {
        if (amount < 0) return (-amount) / 100;
        else return amount / 100;
    }

    unsigned int getCents() const {
        if (amount < 0) return -amount - getDollars() * 100;
        else
            return amount - getDollars() * 100;
    }

    currency operator+(const currency&) const;

    currency &operator+=(const currency &x) {
        amount += x.amount;
        return *this;
    }

    currency add(const currency &) const;

    currency &increment(const currency &x) {
        amount += x.amount;
        return *this;
    }

    void output(ostream &) const;
private:
    long amount;
};


#endif //CPPGO_CURRENCY_H
