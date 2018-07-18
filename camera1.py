import subprocess
import os
import ffmpy
import time
#import subprocess
#import multiprocessing
import paho.mqtt.client as mqtt
import threading


mqttUser = "iotdevice"
mqttPass = "password"

def stream1(camera, fileout, instance):
    global ffProcesses
    ffProcesses.append(ffmpy.FFmpeg(
        inputs = {camera: '-y -hide_banner -loglevel panic'},
        outputs = {fileout: '-c:v copy -c:a copy -t 10'}
    ))
    try:
        ffProcesses[instance].run()
    except ffmpy.FFRuntimeError as e:
        if e.exit_code and e.exit_code != 255:
            raise
    

def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe("cameras/nvr/record")

def on_message(client, userdata, msg):
    global instances
    global cameras
    global outfile
    print("Instances: ", instances)
    print(msg.topic+" " + str(msg.payload))
    if (str(msg.payload) == "record"):
        print("Record Received")
        client.publish("cameras/nvr", "record")
        p = []
        for i in len(cameras)-1:
            p.append(threading.Thread(target=stream1, args=(cameras[i], outfile[i], i)))
            instances = instances+1
            print("Starting recorder instance ", i)
            p[i].start()


    elif (str(msg.payload) == "stop"):
        print("Stop recieved")
        client.publish("cameras/nvr", "stop")
        print("Stopping job")
        if (threading.activeCount() > 1):
            for i in range(threading.activeCount()-1):
                ffProcesses[i].process.terminate()
            instances = 1

def on_log(client, userdata, level, buf):
    print("log: ", buf)


def main():
    global ffProcesses
    ffProcesses = []
    global instances
    instances = 1

    global cameras
    global outfile
    cameras = []
    outfile = []
    cameras.append("rtsp://admin:pass@192.168.1.17:554/cam/realmonitor?channel=1&subtype=0")
    cameras.append("rtsp://admin:pass@192.168.1.16:554/cam/realmonitor?channel=1&subtype=0")
    outfile.append('test1.mp4')
    outfile.append('test2.mp4')

    client = mqtt.Client(client_id="NVR-Client")
    client.username_pw_set(mqttUser, password=mqttPass)
    client.on_connect = on_connect
    client.on_message = on_message
    #client.on_log = on_log

    client.connect("192.168.3.2", 1883)


    client.loop_forever()

main()