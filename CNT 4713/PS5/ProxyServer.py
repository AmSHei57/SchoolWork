from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
import sys, time,os, urllib

def main():
    TCP_Server()
    

def TCP_Server():
    global website
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
            website = connectionSocket.recv(4096).decode()
            print(website)
            
            # for element in website:
                # if website == "e" and website-1 == "b"and element-2 == "u" and element-3 == "t"and element-4 == "u" and element-5 == "o" and element-6 == "y": 
            connectionSocket.send(('''
HTTP/1.1 200 ok
content-type: text/plain
content-length: 29

You do not access to Youtube!
\r\n
''').encode()) 
                    
            
            connectionSocket.close()
        except IOError:
            print("Not Found %s" % fileName)
            error404(connectionSocket)
            connectionSocket.close()
        except KeyboardInterrupt:
            print("\nInterrupted by CTRL-C")
            break
    serverSocket.close()


def sendtxtfile(fn,cs):
    f = open(fn[1:])
    out = f.read()
    print (out + "\n")
    
    cs.send(('''  
HTTP/1.1 200 ok
content-type: text/html

<html>
<body>
<h1>%s</h1>
</body>
</html>
\r\n
''' % (out)).encode()) 

def error404(cs):
    cs.send(('''HTTP/1.1 404 Not Found
                content-type: text/html
                content-length: 13

                <html>
                <body>
                <h1>404 Not Found</h1>
                </body>
                </html> \r\n''').encode())
                

main()