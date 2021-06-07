from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
def main():
    global out
    serverSocket = socket(AF_INET, SOCK_STREAM)
    serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)    
    serverPort = 1998
    serverSocket.bind(('',serverPort))
    serverSocket.listen(1)
    print("Interrupt with CTRL-C")
    while True:
        try:
            print ("Ready to serve...")
            connectionSocket, addr = serverSocket.accept()
            print("Connection from %s port %s" % addr)
            message = connectionSocket.recv(4096).decode()
            print(message)
            filename = message.split()[1]
            print (filename + "\n")
            
            #connectionSocket.send(staticpage().encode())
            
            connectionSocket.send(sendtxtfile(filename).encode())
            
            connectionSocket.close()
        except IOError:
            print("Not Found %s" % filename)
            connectionSocket.send(('''HTTP/1.0 404 NOT FOUND\r\n''').encode);
            connectionSocket.close()
        except KeyboardInterrupt:
            print("\nInterrupted by CTRL-C")
            break
    serverSocket.close()

def staticpage():
    return '''
HTTP/1.1 200 ok
content-type: text/plain
content-length: 18

Under Construction'''

def sendtxtfile(fn):
    f = open(fn[1:])
    out = f.read()
    print (out + "\n")
    
    return '''  
HTTP/1.1 200 ok
content-type: text/html

<html>
<body>
<h2>%s</h2>
</body>
</html>''' % (out)

main()