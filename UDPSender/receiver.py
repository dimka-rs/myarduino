#!/usr/bin/env python
import socket

UDP_IP = "0.0.0.0"
UDP_PORT = 8888

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print "start"
weight = []
i = 1

while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    #print "received message:", data
    if i <= 10:
        #print "i: ", i
        weight.append(int(data))
        i = i + 1
    else:
        avg = 0
        for w in weight:
            avg = avg + w
        avg = avg / 10
        print "average: ", avg
        weight = []
        i = 0

