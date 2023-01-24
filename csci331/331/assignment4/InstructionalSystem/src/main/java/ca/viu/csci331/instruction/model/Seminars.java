package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Seminars
{
	private LinkedList <Seminar> seminars = new LinkedList <Seminar> ();
	private final int capacity;
	private int numberOfSeminars;
	
	public Seminars(int cap)
	{
		capacity = cap;
		numberOfSeminars = 0;
	}
	
	public void add(Seminar newS)
	{
		if (numberOfSeminars == capacity)
		{
			System.out.print("Error: Seminars database is at it's capacity, please try again later\n");
		}
		else
		{
			seminars.add(newS);
			numberOfSeminars++;
		}
	}
	
	public void cancel(Seminar s)
	{
		if (seminars.contains(s))
		{
			int i = seminars.indexOf(s);
			seminars.remove(i);
			numberOfSeminars--;
		}
		else
		{
			System.out.print("Error: no such seminar found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		Seminar temp = new Seminar();
		System.out.print("All added seminars:\n");
		for (int i = 0; i < numberOfSeminars; i++)
		{
			temp = seminars.get(i);
			System.out.print(i);
			System.out.println(":");
			temp.show();
		}
	}
	
	public Seminar searchByID(String id)
	{
		Seminar temp = new Seminar();
		for (int i = 0; i < numberOfSeminars; i++)
		{
			temp = seminars.get(i);
			if (temp.getID() == id)
			{
				return temp;
			}
		}
		temp = new Seminar();
		temp.setID("No such Seminar found");
		return temp;
	}
	
	public void setIns(String semID, Instructor newIns)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfSeminars) && (!c)); i++)
		{
			if (seminars.get(i).getID() == semID)
			{
				seminars.get(i).setIns(newIns);
				c = true;
			}
		}
	}
	
	public void setC(String semID, Course newC)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfSeminars) && (!c)); i++)
		{
			if (seminars.get(i).getID() == semID)
			{
				seminars.get(i).setC(newC);
				c = true;
			}
		}
	}
	
	public void addSch(String semID, Schedule newS)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfSeminars) && (!c)); i++)
		{
			if (seminars.get(i).getID() == semID)
			{
				seminars.get(i).addValidSchedule(newS);
				c = true;
			}
		}
	}
	
	public void removeSch(String semID, Schedule s)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfSeminars) && (!c)); i++)
		{
			if (seminars.get(i).getID() == semID)
			{
				seminars.get(i).removeSchedule(s);
				c = true;
			}
		}
	}
	
	public void show(String semID)
	{
		for (int i = 0; i < numberOfSeminars; i++)
		{
			if (seminars.get(i).getID() == semID)
			{
				seminars.get(i).showSch();
			}
		}
	}
	
	public boolean checkSch(Schedule s)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfSeminars) && (!c)); i++)
		{
			c = seminars.get(i).checkSch(s);
		}
		return c;
	}
}
