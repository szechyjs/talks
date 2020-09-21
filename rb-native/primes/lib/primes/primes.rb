require 'prime'

module Primes
  def self.get_primes7(n)
    return [] if n < 2
    return [2] if n == 2

    # do only odd numbers starting at 3
    s = 3.upto(n + 1).select(&:odd?)

    mroot = n**0.5
    half = s.length
    i = 0
    m = 3
    until m > mroot
      if s[i]
        j = (m * m - 3) / 2
        s[j] = nil
        until j >= half
          s[j] = nil
          j += m
        end
      end
      i += 1
      m = 2 * i + 3
    end
    [2] + s.compact
  end

  def self.get_primes(n)
    Prime.each(n).map {_1}
  end
end
