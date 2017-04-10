#!/usr/bin/env python
import socket
from pyqtgraph.Qt import QtGui, QtCore
import numpy as np
import pyqtgraph as pg

UDP_IP = "0.0.0.0"
UDP_PORT = 8888

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))

print "start"
x = np.array([])
y = np.array([])
mn = np.array([])
av = np.array([])
mx = np.array([])

## graph
#QtGui.QApplication.setGraphicsSystem('raster')
app = QtGui.QApplication([])
#mw = QtGui.QMainWindow()
#mw.resize(800,800)

win = pg.GraphicsWindow(title="Basic plotting examples")
win.resize(1000,600)
win.setWindowTitle('pyqtgraph example: Plotting')
pg.setConfigOptions(antialias=True)
p = win.addPlot(title="Updating plot")
wraw = p.plot(pen='w')
wmin = p.plot(pen='g')
wavg = p.plot(pen='y')
wmax = p.plot(pen='r')


def recv():
    global x, y, mn, av, mx
    data, addr  = sock.recvfrom(1024) # buffer size is 1024 bytes
    m=int(data[0:9])
    w=int(data[10:19])/10
    x=np.append(x, m)
    y=np.append(y, w)
    if len(mn)==0 or w < mn[-1]:
        mn=np.append(mn, w)
    else:
        mn=np.append(mn, mn[-1])
    if len(mx)==0 or w > mx[-1]:
 	mx=np.append(mx, w)
    else:
        mx=np.append(mx, mx[-1])

    avgd=10
    if len(y) < avgd:
	av=np.append(av, w)
    else:
        avg=0
        for i in range(-1, -1*avgd-1, -1):
            avg=avg+y[i]
        avg=avg/avgd
        av=np.append(av, avg)

#    l=len(x)
#    print("x:"+str(m)+",y:"+str(w)+",mn:"+str(mn[-1])+",L:"+str(l))
    wraw.setData(x, y)
    wmin.setData(x, mn)
    wmax.setData(x, mx)
    wavg.setData(x, av)

tmr = QtCore.QTimer()
tmr.timeout.connect(recv)
tmr.start(50)

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()

