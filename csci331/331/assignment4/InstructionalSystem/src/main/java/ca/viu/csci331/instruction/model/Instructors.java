package main.java.ca.viu.csci331.instruction.model;

import java.util.*;

public class Instructors
{
	private LinkedList <Instructor> instructors = new LinkedList <Instructor> ();
	private final int capacity;
	private int numberOfInstructors;
	
	public Instructors(int cap)
	{
		capacity = cap;
		numberOfInstructors = 0;
	}
	
	public void hire(Instructor newI)
	{
		if (numberOfInstructors == capacity)
		{
			System.out.println("Error: Instructors database is at it's capacity, please try again later\n");
		}
		else
		{
			boolean c = false;
			for (int i = 0; ((i < numberOfInstructors) && (!c)); i++)
			{
				if (instructors.get(i).getEmail() == newI.getEmail())
					c = true;
			}
			if (c)
			{
				System.out.println("Error: This instructor is already in the system\n");
			}
			else
			{
				instructors.add(newI);
				numberOfInstructors++;
			}
		}
	}
	
	public void terminate(Instructor i)
	{
		if (instructors.contains(i))
		{
			int j = instructors.indexOf(i);
			instructors.remove(j);
			numberOfInstructors--;
		}
		else
		{
			System.out.println("Error: no such instructor found. Please check your data and try again\n");
		}
	}
	
	public void show()
	{
		Instructor temp = new Instructor();
		System.out.println("All hired instructors:\n");
		for (int i = 0; i < numberOfInstructors; i++)
		{
			temp = instructors.get(i);
			System.out.print(i);
			System.out.println(":");
			temp.show();
		}
	}
	
	public Instructor searchByName(String n)
	{
		Instructor temp = new Instructor();
		for (int i = 0; i < numberOfInstructors; i++)
		{
			temp = instructors.get(i);
			if (temp.getName() == n)
			{
				return temp;
			}
		}
		temp = new Instructor();
		temp.setName("No such Instructor found");
		return temp;
	}
	
	public Instructor searchByID(String id)
	{
		Instructor temp = new Instructor();
		for (int i = 0; i < numberOfInstructors; i++)
		{
			temp = instructors.get(i);
			if (temp.getID() == id)
			{
				return temp;
			}
		}
		temp = new Instructor();
		temp.setName("No such Instructor found");
		return temp;
	}
	
	public void setName(String id, String newName)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfInstructors) && (!c)); i++)
		{
			if (instructors.get(i).getID() == id)
			{
				instructors.get(i).setName(newName);
				c = true;
			}
		}
	}
	
	public void setEmail(String id, String newEmail)
	{
		boolean c = false;
		for (int i = 0; ((i < numberOfInstructors) && (!c)); i++)
		{
			if (instructors.get(i).getID() == id)
			{
				instructors.get(i).setEmail(newEmail);
				c = true;
			}
		}
	}
}
