#include <ruby.h>
#include <stdio.h>

static VALUE method_hello_world(VALUE self)
{
    printf("Hello, World!\n");
    return Qnil;
}

void Init_hello_ext()
{
    VALUE hello = rb_define_module("HelloExt");
    rb_define_singleton_method(hello, "hello_world", method_hello_world, 0);
}
