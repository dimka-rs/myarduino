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
av1 = np.array([])
av2 = np.array([])
mx = np.array([])

## graph
#QtGui.QApplication.setGraphicsSystem('raster')
app = QtGui.QApplication([])
#mw = QtGui.QMainWindow()
#mw.resize(800,800)

win = pg.GraphicsWindow(title="UDP reader")
win.resize(1000,600)
win.setWindowTitle('pyqtgraph app')
pg.setConfigOptions(antialias=True)
p = win.addPlot(title="Weight readings")
wraw = p.plot(pen='b')
wmin = p.plot(pen='g')
wav1 = p.plot(pen='y')
wav2 = p.plot(pen='w')
wmax = p.plot(pen='r')


def recv():
    global x, y, mn, mx, av1, av2
    data, addr  = sock.recvfrom(1024) # buffer size is 1024 bytes
    m=int(data[0:9])
    w=int(data[10:20])
    if len(x) > 0 and m < x[-1]:
        print("reset data! arduino has been restarted!")
        x=[]
        y=[]
        mn=[]
        mx=[]
        av1=[]
        av2=[]
    x=np.append(x, m)
    ## scaling
    w=(w+450)/1.2528
    y=np.append(y, w)
    av1d=10
    av2d=100
    if len(y) < av1d:
        mn=np.append(mn, w)
        mx=np.append(mx, w)
        av1=np.append(av1, w)
    else:
	av1t=0
        mnt=y[-1]
        mxt=y[-1]
        for i in range(-1, -1*av1d-1, -1):
            av1t=av1t+y[i]
            if y[i] < mnt:
                mnt=y[i]
            if y[i] > mxt:
                mxt=y[i]

        av1t=round((av1t-mnt-mxt)/(av1d-2))
        av1=np.append(av1, av1t)
        mn=np.append(mn, mnt)
        mx=np.append(mx, mxt)

    if len(y) < av2d:
        av2=np.append(av2, w)
    else:
        av2t=0
        for i in range(-1, -1*av2d-1, -1):
            av2t=av2t+y[i]
        av2t=round(av2t/av2d)
        av2=np.append(av2, av2t)
## limit graph length
    if len(y) > 300:
       x=np.delete(x, 0)
       y=np.delete(y, 0)
       mn=np.delete(mn, 0)
       mx=np.delete(mx, 0)
       av1=np.delete(av1, 0)
       av2=np.delete(av2, 0)

    wraw.setData(x, y)
    wmin.setData(x, mn)
    wmax.setData(x, mx)
    wav1.setData(x, av1)
    wav2.setData(x, av2)

tmr = QtCore.QTimer()
tmr.timeout.connect(recv)
tmr.start(20)

## Start Qt event loop unless running in interactive mode or using pyside.
if __name__ == '__main__':
    import sys
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtGui.QApplication.instance().exec_()

