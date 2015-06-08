#!/usr/bin/env python3

#####################################
# Student Name: Tianfu Yuan
# Student ID: 300228072
# NWEN 241 Assignment 1 - client
#####################################
# Sample client program
import os
import sys
import socket

#
# get the name of our program to use in error messages
#
progname = os.path.basename(sys.argv[0])

############################################################################
# WRITE CODE: get the hostname or IP address of the server from the 
# command line. If no command line parameter is given, prompt the user 
# for the information
#

host = input('Please enter the server IP or hostname: ')
#
# WRITE CODE: get the filename requested from the server from the 
# command line. If no command line parameter is given, prompt the user 
# for the information
#
filename = input('Please enter the filename that you want to open: ')
#
# End of input parameters
############################################################################
#
# The same port as used by the server
#
port = 50007

############################################################################
# This section opens a socket connection to the remote machine
# You probably don't need to make changes here
#
s = None
for res in socket.getaddrinfo(host, port, socket.AF_UNSPEC, socket.SOCK_STREAM):
    af, socktype, proto, canonname, sa = res
    print("Connecting to", sa)
    try:
        s = socket.socket(af, socktype, proto)
    except socket.error as msg:
        s = None
        continue
    try:
        s.connect(sa)
    except socket.error as msg:
        s.close()
        s = None
        continue
    break
if s is None:
    print('could not open socket')
    sys.exit(1)
############################################################################

	
############################################################################
#
# Send an 'utf-8' encoded version of the 'filename' to the remote machine
#
s.sendall(filename.encode('utf-8'))
#
# WRITE CODE: get response from remote machine and display the result
#
while True:
     #recieve the data from the server
     data = s.recv(4096)
   
     if not data:
         break
     #print out the data that recieved from server
     print(data.decode('utf-8'))
     print('Data recieved from ' + '"' + filename + '"')
############################################################################
#
# Close the socket now that we're finished with it
#
s.close()

