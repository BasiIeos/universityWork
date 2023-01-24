package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Seminar
{
	private String seminarID = new String();
	private Course course = new Course();
	private int capacity;
	private Instructor instructor = new Instructor();
	private LinkedList <Schedule> schedules = new LinkedList <Schedule> ();
	
	public Seminar()
	{
	}
	
	public Seminar(String id, Course c, int cap, Instructor i)
	{
		seminarID = id;
		course = c;
		capacity = cap;
		instructor = i;
	}
	
	public String getID()
	{
		return seminarID;
	}
	
	public void setID(String newID)
	{
		seminarID = newID;
	}
	
	public void setIns(Instructor newIns)
	{
		instructor = newIns;
	}
	
	public void setC(Course newC)
	{
		course = newC;
	}
	
	public int getCap()
	{
		return capacity;
	}
	
	public void addValidSchedule(Schedule newS)
	{
		if (schedules.size() == capacity)
		{
			System.out.print("Error: seminar ");
			System.out.print(seminarID);
			System.out.println(" is at it's capacity, please try again later");
		}
		else
		{
			boolean c = true;
			Schedule temp = new Schedule();
			for (int i = 0; ((i < schedules.size()) && (c)); i++)
			{
				temp = schedules.get(i);
				if ((temp.getDay() == newS.getDay()) && (((temp.getHour() * 60 + temp.getMinute() >= newS.getHour() * 60 + newS.getMinute()) && (temp.getHour() * 60 + temp.getMinute() < newS.getHour() * 60 + newS.getMinute() + newS.getDur())) || ((newS.getHour() * 60 + newS.getMinute() >= temp.getHour() * 60 + temp.getMinute()) && (newS.getHour() * 60 + newS.getMinute() < temp.getHour() * 60 + temp.getMinute() + temp.getDur()))))
				{
					c = false;
				}
			}
			if (c)
			{
				schedules.add(newS);
			}
			else
			{
				System.out.print("Error: can't add new schedule because it interfered with others. Please try a different one");
			}
			
		}
	}
	
	public void removeSchedule(Schedule s)
	{
		if (schedules.contains(s))
		{
			int i = schedules.indexOf(s);
			schedules.remove(i);
		}
		else
		{
			System.out.print("Error: no such schedule found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		System.out.print("Seminar's ID:");
		System.out.println(seminarID);
		System.out.print("Seminar's course:\n");
		course.show();
		System.out.print("Seminar's capacity:");
		System.out.println(capacity);
		System.out.print("Seminar's instructor:\n");
		instructor.show();
		System.out.print("All added schedules:\n");
		Schedule temp = new Schedule();
		for (int i = 0; i < schedules.size(); i++)
		{
			temp = schedules.get(i);
			System.out.println(i);
			temp.show();
		}
	}
	
	public void showSch()
	{
		System.out.print("All added schedules:\n");
		Schedule temp = new Schedule();
		for (int i = 0; i < schedules.size(); i++)
		{
			temp = schedules.get(i);
			System.out.println(i);
			temp.show();
		}
	}
	
	public boolean checkSch(Schedule s)
	{
		boolean c = false;
		for (int i = 0; ((i < schedules.size()) && (!c)); i++)
		{
			if ((s.getRoom() == schedules.get(i).getRoom()) && (s.getDay() == schedules.get(i).getDay()) && 
					(((schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() >= s.getHour() * 60 + s.getMinute()) && (schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() < s.getHour() * 60 + s.getMinute() + s.getDur())) || ((s.getHour() * 60 + s.getMinute() >= schedules.get(i).getHour() * 60 + schedules.get(i).getMinute()) && (s.getHour() * 60 + s.getMinute() < schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() + schedules.get(i).getDur()))))
			{
				c = true;
			}
		}
		return c;
	}
}
