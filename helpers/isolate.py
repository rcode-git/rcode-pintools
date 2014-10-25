#!/usr/bin/python
import sys


undesired = sys.argv[1]
desired = sys.argv[2]

print "Undesired: %s"%(undesired)
print "Desired: %s"%(desired)

undesired_addrs = open(undesired,'r').read().split('\n')
desired_addrs = open(desired,'r').read().split('\n')


interesting = filter(lambda x: x not in undesired_addrs , desired_addrs)

for addr in interesting:
    print addr


