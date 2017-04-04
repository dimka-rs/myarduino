#!/usr/bin/env python
import socket

UDP_IP = "0.0.0.0"
UDP_PORT = 8888

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print "start"
weight = []
i = 0
wmin=0
wmax=0

while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    m=int(data[0:9])
    w=int(data[10:19])
    if w < wmin or wmin == 0:
        wmin = w
    if w > wmax or wmax == 0:
        wmax = w
    #print "m=",m,", w=",w
    if i < 10:
        #print "i: ", i
        weight.append(w)
        i = i + 1
    else:
        avg = 0
        for w in weight:
            avg = avg + w
        avg = avg / 10
        print "time=",m,"average=",avg,"min=",wmin,"max=",wmax,"delta=",wmax-wmin
        weight = []
        i = 0

