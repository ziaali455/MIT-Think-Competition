import statistics
import serial
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

plt.ion()
fig = plt.figure()


i = 0
x = list()
y = list()
i = 0
ser = serial.Serial('/dev/cu.usbmodem1411', 115200)
ser.close()
ser.open()
while True:

    data = ser.readline()
    print(data.decode())
    myList = []  # creates empty list
    for index in range(10):  # loops index from 0 to 9
        myList.append(float(ser.readline().decode()))
    distance = (statistics.mean(myList))
    x.append(i)
    y.append(distance)

    plt.title("Social Distancing Data for Cashier Table")
    plt.ylabel("Distance from cashier table (cm)")
    plt.xlabel("Time elapsed (seconds)")
    plt.xscale("linear", x=1000000)
    plt.scatter(i, distance) #makes scatterplot
    i += 1
    plt.show()
    plt.pause(0.0001)