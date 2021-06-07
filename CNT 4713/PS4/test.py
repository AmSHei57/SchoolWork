t#FTPClient.py

from socket import socket, AF_INET, SOCK_STREAM
from ast import literal_eval
import time

def send(socket, msg): 
	print ("===>sending: " + msg)
	socket.send(msg.encode() + "\r\n".encode())
	recv = socket.recv(1024).decode()
	print ("<===receive: " + recv)
	return recv
	
serverName = 'ftp.cs.fiu.edu'
serverPort = 21
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName, serverPort))
message=""
condition = True
while condition:
	line = clientSocket.recv(1024).decode().lstrip()
	message += line
	condition = line[0:4] != "220 "
print (message)
message = send(clientSocket,"USER anonymous")
clientSocket.send("PASS ashei012@fiu.edu\r\n".encode())
message=""
condition = True
while condition:
	line = clientSocket.recv(1024).decode().lstrip()
	message += line
	print (line)
	condition = line[0:4] != "230 "
print (message)
message = send(clientSocket,"TYPE A")
message = send(clientSocket,"PASV")
start = message.find("(")
end  = message.find(")")
tuple = message[start+1:end].split(',')
print (tuple)
#build the port from the last two numbers
port = int(tuple[4])*256 + int(tuple[5])
print (port)
dataSocket = socket(AF_INET, SOCK_STREAM)
dataSocket.connect((serverName, port))
message = send(clientSocket,"LIST")
message = dataSocket.recv(2048).decode()
print (message)
message = clientSocket.recv(2048).decode()
print (message)
dataSocket.close()
message = send(clientSocket,"QUIT")
clientSocket.close()