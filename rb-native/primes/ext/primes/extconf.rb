require 'mkmf'

find_header('primesieve.h')
find_library('primesieve', 'primesieve_generate_primes')

create_makefile('primes/primes_ext')
