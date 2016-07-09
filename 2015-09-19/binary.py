from fractions import Fraction
import sys
 
pows = {2**i for i in range(200)}
 
for l in sys.stdin:
    a = Fraction(l)
    if a.denominator in pows:
        print "Exact."
    else:
        print "Some precision lost."