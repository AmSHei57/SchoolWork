package nachos.vm;
import nachos.machine.Machine;
import nachos.machine.TranslationEntry;
import java.util.HashSet;
import java.util.LinkedList;

public  class ClockPager extends MemoryManager{


	private HashSet<Integer> usedPages = new HashSet<Integer>();
	private LinkedList<Integer> freePages= new LinkedList<Integer>();

	public ClockPager() {	
	
		for (int i = 0; i < Machine.processor().getNumPhysPages(); i++)
			freePages.add(i);

	}
	
	
	protected void removePage(int ppn) {	

		usedPages.remove(new Integer(ppn));
		freePages.add(new Integer(ppn));

	}
	
	public TranslationEntry swapIn(PageItem item) {

		//X.X

	}
	
	public void swapOut(int ppn) {	

		//O.O

	}

    }
