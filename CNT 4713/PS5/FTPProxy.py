def processRequest(tcpSocket, ftpCmdSocket, post_data, ftpServerName):
    parsed = mod_html.create_parsed(post_data)
    result = ""
    if "filename" in parsed:
        filename = parsed["filename"]
        status = ftpSimpleCommand(ftpCmdSocket,"CWD"+filename)
        if status.split()[0] == "550":
            result += getDataListing(ftpCmdSocket,ftpServerName,"RETR"+filename)
        else:
            result += ftpSimpleCommand(ftpCmdSocket,"PWD")
            result += getDataListing(ftpCmdSocket,ftpServerName,"LIST")
    sendDynamicPage(tcpSocket,result,"text/html")
    
    def main():
        serverSocket = openTcpSocket(12012)
        ftpServerName = 'ftp.swfwmd.state.fl.us'
        ftpCommandSocket = ftpLogin(ftpServerName)
        buf = ""
        key = None