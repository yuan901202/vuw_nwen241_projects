#!/usr/bin/env python3

#####################################
# Student Name: Tianfu Yuan
# Student ID: 300228072
# NWEN 241 Assignment 1 - server
#####################################

# Sample server program
import os
import sys
import socket
import signal

#
# get the name of our program to use in error messages
#
progname = os.path.basename(sys.argv[0])

############################################################################
# WRITE CODE: get the IP address of the server from the command line. 
# If no command line parameter is given, prompt the user for the information
#
host = None
############################################################################
#
# Arbitrary non-privileged port
#
port = 50007    
          
############################################################################
# This section opens a socket connection to the remote machine
# You probably don't need to make changes here
#
s = None
for res in socket.getaddrinfo(host, port, socket.AF_UNSPEC,socket.SOCK_STREAM, 0, socket.AI_PASSIVE):
    af, socktype, proto, canonname, sa = res
    print ('Listening on', sa)
    try:
        s = socket.socket(af, socktype, proto)
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
    except socket.error as msg:
        s = None
        continue
    try:
        s.bind(sa)
        s.listen(1)
    except socket.error as msg:
        s.close()
        s = None
        continue
    break
if s is None:
    print ('could not open socket')
    sys.exit(1)
#
# We're going to listen for socket connections in an infinite loop
# We need a signal handler to catch Ctrl-C
#
def handler(signum, frame):
    s.close()
    sys.exit(1)

signal.signal(signal.SIGINT, handler)
############################################################################

while True:
    print('Waiting for connection...')
    conn, addr = s.accept()
    print ('Connection from', addr)
    while True:
        data = conn.recv(4096)
        if not data: 
              break
        print (data.decode('utf-8'))
        ####################################################################
        #
        # WRITE CODE: process incoming request here
        #
        filename = data.decode('utf-8')
        
        #open & read the file from "data" directory
        file = open ('../data/' + filename, 'r')
        data = file.read()
        
        #send the data to connected client
        conn.send (data.encode('utf-8'))
       
        #close the file when finished the read
        file.close() 
        print ('The data has been send to', addr)
        ####################################################################
    conn.close()

s.close()
sys.exit()
