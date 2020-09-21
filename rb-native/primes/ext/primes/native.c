#include <ruby.h>
#include <primesieve.h>

extern VALUE get_primes(int);

VALUE Primes = Qnil;

static VALUE method_get_primes_native(VALUE self, VALUE num) {
    Check_Type(num, T_FIXNUM);
    int count = NUM2INT(num);
    return get_primes(count);
}

static VALUE method_get_primesieve_primes(VALUE self, VALUE num) {
    Check_Type(num, T_FIXNUM);
    size_t size, i;
    int* primes = primesieve_generate_primes(0, NUM2ULL(num), &size, INT_PRIMES);
    VALUE rubyPrimes = rb_ary_new2(size);
    for (i = 0; i < size; i++) {
        rb_ary_store(rubyPrimes, i, INT2NUM(primes[i]));
    }
    primesieve_free(primes);
    return rubyPrimes;
}

static VALUE method_get_primesieve_count(VALUE self, VALUE num) {
    Check_Type(num, T_FIXNUM);
    return ULL2NUM(primesieve_count_primes(0, NUM2ULL(num)));
}

void Init_primes_ext() {
    Primes = rb_define_module("Primes");
    rb_define_singleton_method(Primes, "get_primes_native", method_get_primes_native, 1);
    rb_define_singleton_method(Primes, "get_primesieve", method_get_primesieve_primes, 1);
    rb_define_singleton_method(Primes, "get_primesieve_count", method_get_primesieve_count, 1);
}
