#include <ruby.h>

extern int get_primes(int);

VALUE Primes = Qnil;

static VALUE method_get_primes_native(VALUE self, VALUE num)
{
    Check_Type(num, T_FIXNUM);
    int count = NUM2INT(num);
    int retval = get_primes(count);
    return INT2NUM(retval);
}

void Init_primes_ext()
{
    Primes = rb_define_module("Primes");
    rb_define_singleton_method(Primes, "get_primes_native", method_get_primes_native, 1);
}
