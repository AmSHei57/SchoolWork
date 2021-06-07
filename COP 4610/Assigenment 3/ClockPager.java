package nachos.vm;
import nachos.machine.Machine;
import nachos.machine.TranslationEntry;
import java.util.HashSet;
import java.util.LinkedList;

public  class ClockPager extends MemoryManager{

	private HashSet<Integer> uPages = new HashSet<Integer>();
	private LinkedList<Integer> fPages= new LinkedList<Integer>();

	public ClockPager() {	
		for (int i = 0; i < Machine.processor().getNumPhysuPages(); i++)
			fPages.add(i);
	}
	
	
	protected void removePage(int ppn) {	
		uPages.remove(new Integer(ppn));
		fPages.add(new Integer(ppn));
	}
	
	public TranslationEntry swapIn(PageItem item) {
	}
	
	public void swapOut(int ppn) {	
	}

    }
