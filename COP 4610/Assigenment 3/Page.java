package nachos.vm;

import nachos.machine.*;
import nachos.threads.*;
import nachos.userprog.*;
import nachos.vm.*;

public class Page{
	PageItem pageItem;
	TranslationEntry tEntry;

	public Page(PageItem pageItem, TranslationtEntry tEntry){
		this.pageItem = pageItem;
		this.tEntry = tEntry;
	}
}