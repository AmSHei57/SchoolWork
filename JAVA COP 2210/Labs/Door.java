// Lab Assignment # 3
// Exercise # 1.1
// Driver: 5771314                                                  
// Navigator: 5771314
// Date: Wednesday, 9/28/16
package door;

/**
 *
 * @author aminspects
 */
public class Door {
 
 private String State ;
 private String Name ;
 
 public Door(String Front, String Open){
 
 Name = Front;
 State = Open;     
 }
 
 public String getName(){
     
     return Name;
 };
 public String getState(){
     
     return State;
 };
 public void setName(String newName){
     Name = newName;
 }
 public void setState(String newState){
     State = newState;
 }
public static String state1(String open){
 
return open;
}
 public static String state2(String close){
     
 return close;    
 }
 public static void main(String[] args) {
 
     Door frontDoor = new Door("Front", "open");
      System.out.println("The front door is " + frontDoor.getState());
      System.out.println("Expected:  open");
      Door backDoor = new Door("Back", "closed");
      System.out.println("The back door is " + backDoor.getState());
      System.out.println("Expected:  closed");        
     
      frontDoor.setState("closed");
      System.out.println("The front door is now " + frontDoor.getState());
      
      backDoor.setState("open");
      System.out.println("The back door is " + backDoor.getState());
      System.out.println("Expected:  open");
      
      frontDoor.setName("eli");
      System.out.println("The door's new name is " + frontDoor.getName());
     
      Door sideDoor = new Door("Side", "closed");
     sideDoor.setState("open");
     System.out.println("The side door is " + sideDoor.getState());
 }
 
}

