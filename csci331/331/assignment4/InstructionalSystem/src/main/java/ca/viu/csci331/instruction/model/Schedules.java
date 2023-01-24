package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Schedules
{
	private LinkedList <Schedule> schedules = new LinkedList <Schedule> ();
	private final int capacity;
	private int numberOfSchedules;
	
	public Schedules(int cap)
	{
		capacity = cap;
		numberOfSchedules = 0;
	}
	
	public void add(Schedule newS)
	{
		if (numberOfSchedules == capacity)
		{
			System.out.print("Error: Schedules database is at it's capacity, please try again later\n");
		}
		else
		{
			boolean c = false;
			for (int i = 0; ((i < numberOfSchedules) && (!c)); i++)
			{
				if ((newS.getRoom() == schedules.get(i).getRoom()) && (newS.getDay() == schedules.get(i).getDay()) && (((schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() >= newS.getHour() * 60 + newS.getMinute()) && (schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() < newS.getHour() * 60 + newS.getMinute() + newS.getDur())) || ((newS.getHour() * 60 + newS.getMinute() >= schedules.get(i).getHour() * 60 + schedules.get(i).getMinute()) && (newS.getHour() * 60 + newS.getMinute() < schedules.get(i).getHour() * 60 + schedules.get(i).getMinute() + schedules.get(i).getDur()))))
					c = true;
			}
			if (c)
				System.out.println("Error: new schedule interlaps with one of previously added, please try again");
			else
			{
				schedules.add(newS);
				numberOfSchedules++;
			}
		}
	}
	
	public void remove(Schedule s)
	{
		if (schedules.contains(s))
		{
			int i = schedules.indexOf(s);
			schedules.remove(i);
			numberOfSchedules--;
		}
		else
		{
			System.out.print("Error: no such schedule found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		Schedule temp = new Schedule();
		System.out.print("All added schedules:\n");
		for (int i = 0; i < numberOfSchedules; i++)
		{
			temp = schedules.get(i);
			System.out.print(i);
			System.out.println(":");
			temp.show();
		}
	}
	
	public LinkedList <Schedule> checkRoom(Room r)
	{
		LinkedList <Schedule> ans = new LinkedList <Schedule>();
		for (int i = 0; i < numberOfSchedules; i++)
		{
			if (schedules.get(i).getRoom() == r)
			{
				ans.add(schedules.get(i));
			}
		}
		return ans;
	}
}
