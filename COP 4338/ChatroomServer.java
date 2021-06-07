
package cop.pkg4338.assignment.pkg1;

import java.io.*;
import java.net.*;
import java.util.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ChatroomServer 
{
    private int port;
    private ArrayList<ChatroomService> users = new ArrayList<>();
    private Lock messageChangeLock = new ReentrantLock();
    private Condition messageCondition = messageChangeLock.newCondition();
    private String accountName;
    private PrintWriter out;
    private Scanner in;
    
    public ChatroomServer(int portNumber)
    {
        port = portNumber;
    }
    
    public void run()
    {
        try
        {
            ServerSocket server = new ServerSocket(port);
            while(true)
            {
                Socket s = server.accept();
                ChatroomService cs = new ChatroomService(s);
                new Thread(cs).start();
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
    //Could not figure out how to send messages to everyone
    public void toAll(String message) throws InterruptedException
    {
       
    }
    
    public class ChatroomService implements Runnable
    {       
        private Socket s;
    
        public ChatroomService(Socket aSocket)
        {
            s = aSocket;
        }
 
        public void run()
        {
            try
            {
                try
                {
                    in = new Scanner(s.getInputStream());
                    out = new PrintWriter(s.getOutputStream());
                    out.write("What's you name?");
                    out.flush();
                    accountName = in.nextLine();
                    users.add(this);
                    executeMessage("Welcome to the Chatroom, " + accountName);
                    executeMessage("To leave disconenect type LOGOUT");

                    doService();            
                }
                catch (InterruptedException ex) 
                { 
                    Logger.getLogger(ChatroomService.class.getName()).log(Level.SEVERE, null, ex);
                }         
                finally 
                {  
                    users.remove(this);
                    s.close();
                }
            }
            catch (IOException exception)
            {
                exception.printStackTrace();
            }
    }

    public void doService() throws IOException, InterruptedException
    {      
       String message = null;
       while (in.hasNextLine())
       { 
          message = in.nextLine();
          if (message.equals("LOGOUT")) 
          {
            executeMessage("User [" + accountName + "] has left the Chatroom.");
            return;
          }         
          else
          {
            executeMessage(accountName + ": " + message);
          }
       }
    }
 
    public void executeMessage(String message) throws InterruptedException
    {
        messageChangeLock.lock();
        try
        {
            out.println(message);
            out.flush();
            messageCondition.signalAll();
        }
        finally
        {
            messageChangeLock.unlock();
        }
    }  

}
    public static void main(String[] args) throws IOException 
    {
       final int PORT = 4044;
       new ChatroomServer(PORT).run();
    }
    
}
