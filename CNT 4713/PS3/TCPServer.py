from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
import sys, time,os     
     
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
            fileName = message.split()[1]
            print (fileName + "\n")
            conditionalGet(connectionSocket)
            #staticpage(connectionSocket)
            sendtxtfile(fileName,connectionSocket)

            connectionSocket.close()
        except IOError:
            print("Not Found %s" % fileName)
            error404(connectionSocket)
            connectionSocket.close()
        except KeyboardInterrupt:
            print("\nInterrupted by CTRL-C")
            break
    serverSocket.close()

def staticpage(cs):
    cs.send(('''
HTTP/1.1 200 ok
content-type: text/plain
content-length: 18

Under Construction
\r\n
''').encode()) 

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
                
def conditionalGet(cs):
    if len(sys.argv) < 5:
        print("Usage: TCPServer.py host resource 'date' port")
        sys.exit()
    #python -u TCPServer.py ocelot.aul.fiu.edu /~ashei012/cop4226/clipboard.html "Sat Sep 24 23:19:28 2016" port

    print("open {0} {1}".format(sys.argv[1], sys.argv[4]))
    time.sleep(2)
    print("GET %s HTTP/1.1" % sys.argv[2] )
    print("Host: %s" % sys.argv[1] )
    print("If-modified-since: %s" % sys.argv[3])
    print()
    time.sleep(2)
    
    print("last modified: %s" % time.ctime(os.path.getmtime("blt.txt")))
    if(time.ctime(os.path.getmtime("blt.txt")) == sys.argv[3]):
        print("Not Modified")
        cs.send(('''HTTP/1.1 304 Not Modified\r\n''').encode())
    else:    
        print("Modified")
        cs.send('''HTTP/1.1 200 ok
                    Last-Modified: %s
                    \r\n'''% time.ctime(os.path.getmtime("blt.txt")).encode())            
main()