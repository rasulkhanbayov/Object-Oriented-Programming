#include "enor.h"

using namespace std;

Enor::Enor(const string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

void Enor::next(){
   _end = _sx == abnorm;
   if(!_end){
    _cur.number = _dx.number;
    _cur.balance = 0;
    while(_sx==norm && _dx.number == _cur.number){
        _cur.balance += _dx.sum;
        read();
    }
   }
}

void Enor::read()
{
    _x >> _dx.number >> _dx.date >> _dx.sum;
    if ( _x.fail() ) _sx = abnorm;
    else _sx= norm;
}
