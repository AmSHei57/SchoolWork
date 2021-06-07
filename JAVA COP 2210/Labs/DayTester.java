// Lab Assignment # 3
// Exercise # 2.14
// Driver: 5771314                                                  
// Navigator: 5771314
// Date: Wednesday, 9/28/16

package daytester;

/**
 *
 * @author aminspects
 */
public class DayTester {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
 
 Day today = new Day(2016,9,21);
 Day tenlater = today.addDays(10);
 
 System.out.println("Today's date is " + today);
 System.out.println("The date ten days later is " +tenlater); 
        
 int dayDiff;
        dayDiff = tenlater.daysFrom(today);
 System.out.println("The diffence between the two dates is "
         + dayDiff);
    
    
    }
    
    
}
