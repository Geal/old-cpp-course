#ifndef RESULT_INC
#define RESULT_INC

#include "option.hpp"

template<class T, class U>
class Result {
  public:
    virtual bool       is_ok()     = 0;
    virtual T          get()       = 0;
    virtual U          get_error() = 0;
    virtual Option<T>* to_option() = 0;
    virtual            ~Result<T,U>() {}
};

template<class T, class U>
class Ok: public Result<T,U> {
  private:
    T value;
  public:
                       Ok<T>(T value) { this->value = value;       }
    virtual bool       is_ok()        { return true;               }
    virtual T          get()          { return value;              }
    virtual U          get_error()    { throw;                     }
    virtual Option<T>* to_option()    { return new Some<T>(value); }
};

template<class T, class U>
class Err: public Result<T,U> {
  private:
    U error;
  public:
                       Err<U>(U error) { this->error = error;  }
    virtual bool       is_ok()         { return false;         }
    virtual T          get()           { throw;                }
    virtual U          get_error()     { return error;         }
    virtual Option<T>* to_option()     { return new None<T>(); }
};

#endif
