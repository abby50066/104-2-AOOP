#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>

using namespace std;

class Form;

struct Bound_form {
    const Form& f;
    double val;
};

class Form {
private:
    friend ostream& operator<<(ostream& , const Bound_form& );

    int prc;
    int fmt;

public:
    explicit Form(int p = 6, int f = 0) : prc{p}, fmt{f} { }

    Bound_form operator()(double d) const { return Bound_form{*this, d}; }

    Form& scientific() { fmt = ios_base::scientific; return *this; }
    Form& fixed() { fmt = ios_base::fixed; return *this; }
    Form& precision(int p) { prc = p; return *this; }
};

ostream& operator<<(ostream& os, const Bound_form& bf)
{
    ostringstream s;
    s.precision(bf.f.prc);
    s.setf((std::ios_base::fmtflags)bf.f.fmt, ios_base::floatfield);
    s << bf.val;
    return os << s.str();
}

#endif
