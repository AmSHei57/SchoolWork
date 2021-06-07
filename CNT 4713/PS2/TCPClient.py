
from socket import socket, SOCK_STREAM, AF_INET
serverName = 'localhost'
serverPort = 1998
clientSocket = socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
message = input('Input lowercase sentence: ')
clientSocket.send(message.encode())
modifiedMessage = clientSocket.recv(2048).decode()
print('From Server: ', modifiedMessage)
clientSocket.close()